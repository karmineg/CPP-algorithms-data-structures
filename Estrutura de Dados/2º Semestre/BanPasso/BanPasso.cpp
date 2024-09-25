#include<iostream>
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
    if(P == NULL) cout << tipo << " est� VAZIA !!!\n\n";
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
    if(F == NULL) cout << tipo << " est� VAZIA !!!\n\n";
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

void adicionarNaFila(NoF<Pessoa>** F, string tipo, Pessoa P) {
    int codigo = P.codigo;
    if(buscaF(*F, codigo)) cout << "> J� existe esta pessoa na fila " << tipo << "!";
    else {
        *F = adicionaF(*F, P);
        cout << "\n> " << P.nome << " (C�digo: " << P.codigo << ") adicionado com sucesso na fila " << tipo << "!";
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

void depositoOuSaque(NoF<Pessoa>** F, No<Pessoa>* Cadastro, string tipo) {
    Pessoa P = (*F)->dado;
    *F = removeF(*F);
    No<Pessoa>* p = buscaERetornaNo(Cadastro, P.codigo);

    cout << "< Fila " << tipo << " (C�digo: " << P.codigo << ", Nome: " << P.nome << ")\n\n";
    char O;
    do {
        cout << "> Insira se deseja realizar saque (S) ou dep�sito (D): ";
        cin >> O;
        O = toupper(O);
        if(O != 'S' && O != 'D') cout << "> Opera��o inv�lida!\n";
        else break;
    } while(true);

    if(O == 'S') {
        if(P.saldo <= 0) cout << "> Seu saldo est� negativo ou nulo, s� � poss�vel realizar dep�sito!\n";
        else {
            float total = SaldoTotal(Cadastro);
            float S;
            do {
                cout << "> Insira quanto voc� quer sacar (em reais): ";
                cin >> S;
                if(S > total*0.8) cout << "> Saque � maior que o saldo do limite imposto pelo banco (" << total*0.8 << ")\n";
                else if(S <= 0) cout << "> Saque n�o pode ser nulo ou negativo!\n";
                else break;
            } while(true);

            cout << "> Saque efetuado com sucesso!";
            (p->dado).saldo -= S;
        }
    } else {
        float D;
        do {
            cout << "> Deposite uma determinada quantia: ";
            cin >> D;
            if(D <= 0) cout << "> Dep�sito n�o pode ser negativo ou nulo!\n";
            break;
        } while(true);

        cout << "> Dep�sito efetuado com sucesso!";
        (p->dado).saldo += D;
    } getchar();
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Pessoa>* Cadastro = nullptr;
    NoF<Pessoa>* FP = nullptr;
    NoF<Pessoa>* FN = nullptr;
    NoF<Pessoa>* FD = nullptr;

    do {
        system("cls");
        cout << "#######MENU DE OP��ES#########" << endl;
        cout << "# 0 - Sair                   #" << endl;
        cout << "# 1 - Cadastrar cliente      #" << endl;
        cout << "# 2 - Adicionar cliente      #" << endl;
        cout << "# 3 - Mostrar clientes       #" << endl;
        cout << "# 4 - Atender cliente        #" << endl;
        cout << "# 5 - Mostrar dados do banco #" << endl;
        cout << "##############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "Programa finalizado.";
                break;

            case 1: {
                // Nome
                string nome;
                cout << "> Informe o nome da pessoa: ";
                getline(cin, nome);

                // C�digo
                int codigo;
                do {
                    cout << "> Informe o c�digo da pessoa: ";
                    cin >> codigo;
                    if(buscaP(Cadastro, codigo)) cout << "> C�digo inserido j� pertence � um cliente existente!\n";
                    else break;
                } while(true);

                // Idade
                int idade;
                do {
                    cout << "> Informe a idade da pessoa: ";
                    cin >> idade;
                    if(idade < 0) cout << "> Idade n�o pode ser negativa!\n";
                    else break;
                } while(true);

                // Saldo
                float saldo;
                cout << "> Informe o saldo(R$): ";
                cin >> saldo;

                Pessoa P = { nome, codigo, idade, saldo };
                Cadastro = adicionaOrdenado(Cadastro, P, false);
                cout << "\n> Novo cliente adicionado com sucesso!";
                getchar();
                break;

            } case 2: {

                int codigo;
                cout << "> Insira um c�digo: ";
                cin >> codigo;


                No<Pessoa>* pessoa = buscaERetornaNo(Cadastro, codigo);
                if(pessoa == NULL) cout << "> Pessoa n�o foi encontrada com c�digo inserido!\n";
                else {
                    Pessoa P = pessoa->dado;
                    if(P.idade >= 60) adicionarNaFila(&FP, "priorit�ria", P);
                    else {
                        if(P.saldo >= 0) adicionarNaFila(&FN, "n�o priorit�ria", P);
                        else adicionarNaFila(&FD, "de devedores", P);
                    }
                }
                getchar();
                break;

            } case 3: {
                char tipo;
                do {
                    cout << "> Informe se deseja mostrar pilha (P) ou filas (F): ";
                    cin >> tipo;
                    tipo = toupper(tipo);
                    if(tipo != 'P' && tipo != 'F') cout << "\n> Caractere inserido inv�lido!\n";
                    else break;
                } while(true);

                if(tipo == 'P') mostrarPessoasP(Cadastro, "Pilha de clientes (da base para topo)");
                else {
                    mostrarPessoasF(FP, "Fila priorit�ria");
                    mostrarPessoasF(FN, "Fila n�o priorit�ria");
                    mostrarPessoasF(FD, "Fila devedora");
                } getchar();
                break;
            }

            case 4:
                if(FP != NULL) depositoOuSaque(&FP, Cadastro, "priorit�ria");
                else {
                    if(FN != NULL) depositoOuSaque(&FN, Cadastro, "n�o priorit�ria");
                    else {
                        if(FD != NULL) depositoOuSaque(&FD, Cadastro, "de devedores");
                        else cout << "> N�o existe clientes nas filas!";
                    }
                }
                break;

            case 5: {
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
                if(totalC == 0) cout << "> N�o h� clientes armazenados!";
                else {
                    cout << " Total de clientes                    | " << totalC << endl;
                    cout << "--------------------------------------|-------\n";
                    cout << " Total de clientes com saldo negativo | " << totalCN << endl;
                    cout << "--------------------------------------|-------\n";
                    cout << " Saldo total em reais                 | " << totalS << endl;
                    cout << "--------------------------------------|-------\n";
                    cout << " M�dia de saldo em reais              | " << totalS/(float)(totalC);
                }
                break;
            }
            default:
                cout << "> Op��o inv�lida!";

        }; getchar();
    }
    while(menu != 0);
}
