#include<iostream>
#include<fstream>
using namespace std;
#include"fila-dinamica.hpp"
#include"pilha-dinamica.hpp"

struct Ficha {
    string nome;
    int idade;
    string sexo;
    string placa;
};

struct Velho {
    string nome;
    string placa;
};

void mostrarFichas(No<Ficha>* P, string tipo) {
    if(P == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |          Nome |    Idade |          Sexo |         Placa \n";
        cout << "--------------|---------------|----------|---------------|---------------\n";
        while(P != NULL) {
            Ficha f = P->dado;
            cout << setfill(' ') << std::setw(13) << P << " |";
            cout << setfill(' ') << std::setw(14) << f.nome << " |";
            cout << setfill(' ') << std::setw(9) << f.idade << " |";
            cout << setfill(' ') << std::setw(14) << f.sexo << " |";
            cout << setfill(' ') << std::setw(14) << f.placa << endl;
            P = P->prox;
        } cout << endl;
    }
}

void ListarFichas(No<Ficha>* P, string tipo) {
    if(P == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        No<Ficha>* Paux = nullptr;

        while(P != NULL) {
            Ficha f = P->dado;
            Paux = adicionaP(Paux, f);
            P = P->prox;
        }

        cout << tipo << "\n";
        cout << "     Endereço |          Nome |    Idade |          Sexo |         Placa \n";
        cout << "--------------|---------------|----------|---------------|---------------\n";
        while(Paux != NULL) {
            Ficha f = Paux->dado;
            cout << setfill(' ') << std::setw(13) << Paux << " |";
            cout << setfill(' ') << std::setw(14) << f.nome << " |";
            cout << setfill(' ') << std::setw(9) << f.idade << " |";
            cout << setfill(' ') << std::setw(14) << f.sexo << " |";
            cout << setfill(' ') << std::setw(14) << f.placa << endl;
            Paux = Paux->prox;
        } cout << endl;
    }
}

void ListarInforma(No<Ficha>* P, string tipo) {
    if(P == NULL) cout << "ERRO: Pilha vazia";
    else {
        float totalF = 0, totalM = 0, totalI = 0, totalP = 0;
        while(P != NULL) {
            if((P->dado).sexo == "Feminino") totalF++;
            else totalM++;

            int idade = (P->dado).idade;
            totalP++;
            totalI += idade;
            P = P->prox;
        }

        cout << tipo << "\n";
        cout << " Total de clientes do sexo feminino     | " << totalF << endl;
        cout << "----------------------------------------|---------------\n";
        cout << " Total de clientes do sexo masculino    | " << totalM << endl;
        cout << "----------------------------------------|---------------\n";
        cout << " Média aritmética da idade              | " << totalI/(float)(totalP) << "\n";
    }
}

void PessoaVelha(No<Ficha>* PF, No<Ficha>* PG) {
    if(PF == NULL && PG == NULL) cout << "ERRO: Não há clientes registrados em 'MAIORIDADE'";
    else {
        No<Velho>* V = nullptr;
        int maior = 0;

        while(PF != NULL) {
            Ficha f = PF->dado;
            if(f.idade >= maior) {
                if(f.idade > maior) {
                    maior = f.idade;
                    V = destroiP(V);
                }
                Velho novo = { f.nome, f.placa };
                V = adicionaP(V, novo);
            }
            PF = PF->prox;
        }

        while(PG != NULL) {
            Ficha g = PG->dado;
            if(g.idade >= maior) {
                if(g.idade > maior) {
                    maior = g.idade;
                    V = destroiP(V);
                }
                Velho novo = { g.nome, g.placa };
                V = adicionaP(V, novo);
            }
            PG = PG->prox;
        }

        cout << "Pessoa(s) mais velha(s)\n";
        cout << "            Nome |           Placa \n";
        cout << "-----------------|-----------------\n";
        while(V != NULL) {
            Velho P = V->dado;
            cout << setfill(' ') << std::setw(16) << P.nome << " |";
            cout << setfill(' ') << std::setw(16) << P.placa << endl;
            V = V->prox;
        }
    }
}

void lerArquivo(No<Ficha>* PF, No<Ficha>* PG) {
    cout << "#####################################################\n";
    cout << "##                     VEÍCULOS                    ##\n";
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
            mostrarFichas(PF, "Fichas de Passo Fundo");
            mostrarFichas(PG, "Fichas de outras cidades");
        }
        else if(acao == "LISTAR") {
            ListarFichas(PF, "Fichas de Passo Fundo em ordem");
        }
        else if(acao == "INFORM") {
            ListarInforma(PF, "Informações das fichas de Passo Fundo");
        }
        else if(acao == "REGISTRAR") {
            string nome;
            getline(ss, nome, ' ');

            string num;
            getline(ss, num, ' ');
            int idade = stoi(num);

            string sexo;
            getline(ss, sexo, ' ');

            string placa;
            getline(ss, placa, ' ');

            string cidade;
            getline(ss, cidade);

            if(idade < 0) cout << "ERRO: A idade não pode ser negativa em 'REGISTRAR'";
            else {
                if(sexo != "F" && sexo != "M") cout << "Opção para sexo inválida em 'REGISTRAR'";
                else {
                    string newSexo;
                    if(sexo == "F") newSexo = "Feminino";
                    else newSexo = "Masculino";

                    if(placa.length() != 7) cout << "Valor inserido para placa não corresponde ao de uma placa em 'REGISTRAR'";
                    else {
                        Ficha V = { nome, idade, newSexo, placa };
                        if(cidade == "PF") PF = adicionaP(PF, V);
                        else PG = adicionaP(PG, V);

                        cout << "Ficha da pessoa " << nome << " de idade " << idade << ", foi registrado com a placa " << placa;
                    }
                }
            }
        }
        else if(acao == "MAIORIDADE") {
            PessoaVelha(PF, PG);
        }
        else {
               cout << "Função inválida";
        }
        cout << endl << "========================================================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<Ficha>* PF = nullptr;
    No<Ficha>* PG = nullptr;

    lerArquivo(PF, PG);
}
