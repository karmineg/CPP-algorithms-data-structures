#include<iostream>
#include<fstream>
using namespace std;
#include"pilha-dinamica.hpp"
#include"fila-dinamica.hpp"

struct Pessoa {
    string nome;
    int codigo;
    int idade;
    float saldo;
};

bool operator<(const Pessoa &P1, const Pessoa &P2) {
    return (P1.nome < P2.nome);
}

bool operator==(const Pessoa &C, const int &codigo) {
    return (codigo == C.codigo);
}

void mostrarPessoasP(No<Pessoa>* P, string tipo) {
    if(P == NULL) cout << tipo << " est� vazia";
    else {
        cout << ">> " << tipo << "\n";
        cout << "     Endere�o |            Nome |    C�digo |     Idade |     Saldo \n";
        cout << "--------------|-----------------|-----------|-----------|-----------\n";
        while(P != NULL) {
            Pessoa p = P->dado;
            cout << setfill(' ') << std::setw(13) << P << " |";
            cout << setfill(' ') << std::setw(16) << p.nome << " |";
            cout << setfill(' ') << std::setw(10) << p.codigo << " |";
            cout << setfill(' ') << std::setw(10) << p.idade << " |";
            cout << setfill(' ') << std::setw(10) << p.saldo << endl;
            P = P->prox;
        } cout << endl;
    }
}

void mostrarPessoasF(NoF<Pessoa>* F, string tipo) {
    if(F == NULL) cout << tipo << " est� vazia\n";
    else {
        cout << ">> " << tipo << "\n";
        cout << "     Endere�o |            Nome |    C�digo |     Idade |     Saldo \n";
        cout << "--------------|-----------------|-----------|-----------|-----------\n";
        while(F != NULL) {
            Pessoa p = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(16) << p.nome << " |";
            cout << setfill(' ') << std::setw(10) << p.codigo << " |";
            cout << setfill(' ') << std::setw(10) << p.idade << " |";
            cout << setfill(' ') << std::setw(10) << p.saldo << endl;
            F = F->prox;
        } cout << endl;
    }
}

float SaldoTotal(No<Pessoa>* Cadastro) {
    float soma = 0;
    while(Cadastro != NULL){
        soma += (Cadastro->dado).saldo;
        Cadastro = Cadastro->prox;
    }
    return soma;
}

void depositoOuSaque(NoF<Pessoa>** F, No<Pessoa>** Cadastro, string tipo, string escolha, float dinheiro) {
    Pessoa P = (*F)->dado;
    *F = removeF(*F);
    No<Pessoa>* p = buscaERetornaNo(*Cadastro, P.codigo);

    cout << "Fila " << tipo << " (C�digo: " << P.codigo << ", Nome: " << P.nome << ")\n\n";

    if(escolha == "S") {
        if(P.saldo <= 0) cout << "Seu saldo est� negativo ou nulo, s� � poss�vel realizar dep�siton";
        else {
            float total = SaldoTotal(*Cadastro);

            if(dinheiro > total*0.8) cout << "Saque � maior que o saldo do limite imposto pelo banco (" << total*0.8 << ")";
            else if(dinheiro <= 0) cout << "Saque n�o pode ser nulo ou negativo";
            else {
                cout << "Saque efetuado com sucesso";
                (p->dado).saldo -= dinheiro;
            }
        }
    } else if(escolha == "D") {
        if(dinheiro <= 0) cout << "Dep�sito n�o pode ser negativo ou nulo";
        else if(dinheiro > 0){
            cout << "Dep�sito efetuado com sucesso";
            (p->dado).saldo += dinheiro;
        }
        else cout << "Op��o de a��o inv�lida para dep�sito ou saque";
    }
}

void adicionarNaFila(NoF<Pessoa>** F, string tipo, Pessoa P) {
    int codigo = P.codigo;
    if(buscaF(*F, codigo)) cout << "J� existe esta pessoa na fila " << tipo;
    else {
        *F = adicionaF(*F, P);
        cout << P.nome << " (C�digo: " << P.codigo << ") adicionado com sucesso na fila " << tipo;
    }
}

void lerArquivo(No<Pessoa>* Cadastro, NoF<Pessoa>* FP, NoF<Pessoa>* FN, NoF<Pessoa>* FD) {
    cout << "#####################################################\n";
    cout << "##                     BANPASSO                    ##\n";
    cout << "#####################################################\n\n";

    string arch = "entrada.txt";
    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) {
        string linha;
        getline(leitor, linha);

        string acao;
        stringstream ss(linha);
        getline(ss, acao, ' ');

        if(acao == "MOSTRAR") {
            string C;
            getline(ss, C);

            if(C == "P") mostrarPessoasP(Cadastro, "Pilha de clientes (da base para topo)");
            else {
                mostrarPessoasF(FP, "Fila priorit�ria");
                mostrarPessoasF(FN, "Fila n�o priorit�ria");
                mostrarPessoasF(FD, "Fila devedora");
            }
        }
        else if(acao == "CADASTRAR") {
            string nome;
            getline(ss, nome, ' ');

            string c;
            getline(ss, c, ' ');
            int codigo = stoi(c);

            string i;
            getline(ss, i, ' ');
            int idade = stoi(i);

            string s;
            getline(ss, s);
            float saldo = stof(s);

            if(buscaP(Cadastro, codigo)) cout << "C�digo inserido (" << codigo <<") j� pertence � um cliente existente";
            else {
                if(idade < 0) cout << "Idade n�o pode ser negativa";
                else {
                    Pessoa P = { nome, codigo, idade, saldo };
                    Cadastro = adicionaOrdenado(Cadastro, P, false);
                    cout << "Cliente " << nome <<" (" << idade << " anos) de c�digo "<< codigo << " adicionado com RS" << saldo;
                }
            }
        }
        else if(acao == "ATENDER") {
            string T;
            getline(ss, T, ' ');

            string n;
            getline(ss, n);
            float saldo = stof(n);

            if(FP != NULL) depositoOuSaque(&FP, &Cadastro, "priorit�ria", T, saldo);
            else {
                if(FN != NULL) depositoOuSaque(&FN, &Cadastro, "n�o priorit�ria", T, saldo);
                else {
                    if(FD != NULL) depositoOuSaque(&FD, &Cadastro, "de devedores", T, saldo);
                    else cout << "N�o existe clientes nas filas";
                }
            }
        }
        else if(acao == "MOSTRARDADOS") {
            int totalC = 0;
            int totalCN = 0;
            float totalS = 0;
            No<Pessoa> *C = Cadastro;
            while(C != NULL) {
                float saldo = (C->dado).saldo;
                totalC++;
                if(saldo < 0) totalCN++;
                totalS += saldo;
                C = C->prox;
            }
            if(totalC == 0) cout << "N�o h� clientes armazenados";
            else {
                cout << " Total de clientes                    | " << totalC << endl;
                cout << "--------------------------------------|-------\n";
                cout << " Total de clientes com saldo negativo | " << totalCN << endl;
                cout << "--------------------------------------|-------\n";
                cout << " Saldo total em reais                 | " << totalS << endl;
                cout << "--------------------------------------|-------\n";
                cout << " M�dia de saldo em reais              | " << totalS/(float)(totalC);
                }
        }
        else if(acao == "ADICIONAR") {
            string n;
            getline(ss, n);
            int codigo = stoi(n);

            No<Pessoa>* pessoa = buscaERetornaNo(Cadastro, codigo);
            if(pessoa == NULL) cout << "Pessoa n�o foi encontrada com c�digo (" << codigo <<") inserido";
            else {
                Pessoa P = pessoa->dado;
                if(P.idade >= 60) adicionarNaFila(&FP, "priorit�ria", P);
                else {
                    if(P.saldo >= 0) adicionarNaFila(&FN, "n�o priorit�ria", P);
                    else adicionarNaFila(&FD, "de devedores", P);
                }
            }
        }
        else {
               cout << "Fun��o inv�lida";
        }
        cout << endl << "======================================================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<Pessoa>* Cadastro = nullptr;
    NoF<Pessoa>* FP = nullptr;
    NoF<Pessoa>* FN = nullptr;
    NoF<Pessoa>* FD = nullptr;

    lerArquivo(Cadastro, FP, FN, FD);
}
