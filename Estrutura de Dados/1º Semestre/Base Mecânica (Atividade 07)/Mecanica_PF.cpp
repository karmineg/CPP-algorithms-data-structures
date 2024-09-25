#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;

#include "pilha-template.hpp"
#include "filadinamica-template.hpp"

struct PJ {
    string id;
    string placa;
};

struct PF {
    char C;
    PJ X; //---> Herdando atributos de PJ
};

template<typename TP> struct Ficha {
    TP pessoa;
    float valor;
    int qtdP;
};

template<typename N> No<Ficha<N>>* criarFicha(No<Ficha<N>>* ficha, N pessoa, string tipo, string espc) {
    cout << "!!! ATENDIMENTO de pessoas " << tipo << espc << " !!!\n\n";
    // Valor
    float valor;
    do {
        cout << ">> Informar valor em reais: ";
        cin >> valor;
        if(valor <= 0) cout << "!!! Valor N�O pode ser nulo ou negativo !!!\n";
        else break;
    } while(true);
    // N�mero de pe�as
    int qtd;
    do {
        cout << ">> Informe o n�mero de pe�as que foram trocadas: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade N�O pode ser nulo ou negativo !!!\n";
        else break;
    } while(true);

    // Criar ficha
    cout << "!!! Nova ficha adicionada na pilha das pessoas " << tipo << "!!!";
    Ficha<N> F = { pessoa, valor, qtd };
    return adicionaP(ficha, F);
}

// Pegar informa��es de placa e ID nas filas
PJ pjF(NoF<PF>* N) { // Pegar informa��es de PJ dos f�sicos
    return (N->dado).X;
}

PJ pjJ(NoF<PJ>* N) { // Pegar informa��es de PJ dos jur�dicos
    return N->dado;
}

// Pegar informa��o de placa nas PILHAS
string placaF(Ficha<PF> F) { // Pegar placa do f�sico
    return F.pessoa.X.placa;
}

string placaJ(Ficha<PJ> F) { // Pegar placa do jur�dico
    return F.pessoa.placa;
}

void InformPF(NoF<PF>* Fp, NoF<PF>* Fn) {
    int totalN = 0, totalP = 0;
    while(Fp != NULL) {
        totalP++;
        Fp = Fp->prox;
    } while(Fn != NULL) {
        totalN++;
        Fn = Fn->prox;
    }
    cout << " Total de pessoas priorit�rias     | " << totalP << endl;
    cout << "-----------------------------------|-------\n";
    cout << " Total de pessoas N�O priorit�rias | " << totalN << endl;
    cout << "-----------------------------------|-------\n";
    cout << " Total de pessoas f�sicas          | " << (totalP + totalN);
}

template<typename N> void mostrarOrdens(N* O, string tipo, string tipoID, PJ(*dado)(N*)) {
    cout << ">> Lista de pessoas " << tipo;
    if(O != NULL) {
        cout << "\n";
        cout << "     Endere�o |      Placa |          " << tipoID << "\n";
        cout << "--------------|------------|---------------\n";
        while(O != NULL) {
            PJ D = dado(O);//F->dado;
            cout << setfill(' ') << std::setw(13) << O << " |";
            cout << setfill(' ') << std::setw(11) << D.placa << " |";
            cout << setfill(' ') << std::setw(14) << D.id << endl;
            O = O->prox;
        }
    } else cout << " est� VAZIA!!!\n";
    cout << endl;
}

void pilhaInvertida(No<Ficha<PF>> *carroPF) {
    // Inverter a pilha em uma pilha auxiliar
    No<Ficha<PF>>* PFinv = nullptr;
    while(carroPF != NULL) {
        PFinv = adicionaP(PFinv, carroPF->dado);
        carroPF = carroPF->prox;
    }

    // Mostrar ap�s o processo
    cout << ">> Lista de fichas de pessoas f�sicas: \n";
    cout << "\n";
    cout << "     Endere�o |      Placa |         CPF |   Aderido ao pacote |    Valor do servi�o | N. de pe�as\n";
    cout << "--------------|------------|-------------|---------------------|---------------------|-------------\n";
    while(PFinv != NULL) {
        Ficha<PF> D = PFinv->dado;
        string cond;
        //string valorS = "R$ " + to_string(floor(D.valor)) + "," + itos(floor((D.valor*100) % 100);

        if(D.pessoa.C == 'S') cond = "Sim";
        else cond = "N�o";
        cout << setfill(' ') << std::setw(13) << PFinv << " |";
        cout << setfill(' ') << std::setw(11) << D.pessoa.X.placa << " |";
        cout << setfill(' ') << std::setw(12) << D.pessoa.X.id << " |";
        cout << setfill(' ') << std::setw(20) << cond << " |";
        cout << setfill(' ') << std::setw(20) << D.valor << " |";
        cout << setfill(' ') << std::setw(12) << D.qtdP << endl;
        PFinv = removeP(PFinv);
    } cout << endl;
}

void SomaServicos(No<Ficha<PF>> *carroPF) {
    float soma = 0;

    while(carroPF != NULL) {
        soma += (carroPF->dado).valor;
        carroPF = carroPF->prox;
    }

    cout << "> Soma de todos os valores dos servi�os realizados na pilha PF � R$ " << soma;
}

void MaiorValor(No<Ficha<PF>> *carroPF) {
    No<string> *CPF = nullptr;
    float maior = 0;
    while(carroPF != NULL) {
        Ficha<PF> D = carroPF->dado;
        float V = D.valor;
        if(maior <= V) {
            if(maior < V) {
                maior = V;
                if(CPF != NULL) CPF = destroiP(CPF);
            } CPF = adicionaP(CPF, D.pessoa.X.id);
        } carroPF = carroPF->prox;
    } mostraP(CPF, "dos CPF das fichas com maior valor");
}

void MenorValor(No<Ficha<PJ>> *carroPJ) {
    No<string> *CNPJ = nullptr;
    float menor = -1;
    while(carroPJ != NULL) {
        Ficha<PJ> D = carroPJ->dado;
        float V = D.valor;
        if(menor == -1) { // Pega o valor da primeira ficha
            menor = V;
            CNPJ = adicionaP(CNPJ, D.pessoa.id);
        } else {
            if(menor <= V) {
                if(menor < V) { // Se o atual valor � MENOR que o valor em menor...
                    menor = V; //... faz a substitui��o ...
                    CNPJ = destroiP(CNPJ); //... e REMOVE os CNPJ registrados at� ent�o!
                } CNPJ = adicionaP(CNPJ, D.pessoa.id);
            }
        } carroPJ = carroPJ->prox;
    } mostraP(CNPJ, "dos CNPJ das fichas com menor valor");
}

template<typename N> No<string>* verificaF(No<Ficha<N>>* n, string (*dado)(Ficha<N>), No<string>* Placa, int* maior) {
    Ficha<N> D = n->dado;
    string placa = dado(D);
    int Q = D.qtdP;
    if(*maior <= Q) {
        if(*maior < Q) {
            *maior = Q;
            if(Placa != NULL) Placa = destroiP(Placa);
        } return adicionaP(Placa, placa);
    } return Placa;
}

void MaiorQtdP(No<Ficha<PF>> *carroPF, No<Ficha<PJ>> *carroPJ) {
    No<string> *Placa = nullptr;
    int* maior = new int(0);
    while(carroPF != NULL && carroPJ != NULL) {
        Placa = verificaF(carroPF, placaF, Placa, maior);
        Placa = verificaF(carroPJ, placaJ, Placa, maior);
        carroPF = carroPF->prox;
        carroPJ = carroPJ->prox;
    }
    // Se ainda tiver fichas de f�sico para analisar
    while(carroPF != NULL) {
        Placa = verificaF(carroPF, placaF, Placa, maior);
        carroPF = carroPF->prox;
    }
    // Se ainda tiver fichas de jur�dicos para analisar
    while(carroPJ != NULL) {
        Placa = verificaF(carroPJ, placaJ, Placa, maior);
        carroPJ = carroPJ->prox;
    }
    mostraP(Placa, "das placas das fichas com maior qtd. de pe�as trocadas");
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    NoF<PF>* Fp = nullptr, * Fn = nullptr;
    NoF<PJ>* Fj = nullptr;
    No<Ficha<PF>>* carroPF = nullptr;
    No<Ficha<PJ>>* carroPJ = nullptr;

    do {
        system("cls");
        cout << "######################################MENU DE OP��ES#####################################" << endl;
        cout << "# 0 - Sair                                                                              #" << endl;
        cout << "# 1 - Criar ordem de servi�o e adicionar na fila                                        #" << endl;
        cout << "# 2 - Atender cliente da fila                                                           #" << endl;
        cout << "# 3 - Mostrar os dados das ordens de servi�o dos clientes                               #" << endl;
        cout << "# 4 - Listar as informa��es sobre as filas de pessoa f�sica                             #" << endl;
        cout << "# 5 - Listar todos os atendimentos realizados para pessoa f�sica                        #" << endl;
        cout << "# 6 - Mostrar a soma dos valores de todos os servi�os j� realizados para pessoa f�sica  #" << endl;
        cout << "# 7 - Mostrar o CPF da pessoa que realizou a revis�o com maior valor                    #" << endl;
        cout << "# 8 - Mostrar o CNPJ da empresa que realizou a revis�o com o menor valor                #" << endl;
        cout << "# 9 - Mostrar a placa do ve�culo que realizou a revis�o com o maior n�mero de pe�as     #" << endl;
        cout << "#########################################################################################" << endl;
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
                // Informar se � pessoa jur�dica ou f�sica
                char P;
                string tipoID;
                do {
                    cout << "> Informe se � pessoa jur�dica ou f�sica ('J' para jur�dica, 'F' para f�sica): ";
                    cin >> P;
                    P = toupper(P);
                    if(P == 'J') {
                        tipoID = "CNPJ";
                        break;
                    } else if(P == 'F') {
                        tipoID = "CPF";
                        break;
                    } else cout << "!!! Op��o inserida inv�lida !!!\n";
                } while(true);

                // Informar ID (CPF para f�sica, CNPJ para jur�dica)
                string id;
                do {
                    cout << "> Insira o " << tipoID << ": ";
                    cin >> id;
                    // Se pessoa for f�sica, (P == 'J') = 0
                    // Caso contr�rio, (P == 'J') = 1
                    if(id.length() != 11 + 3*(P == 'J')) cout << "!!! Quantidade de d�gitos inv�lida !!!\n";
                    else break;
                } while(true);
                // Placa
                string placa;
                do {
                    cout << "> Informe a placa do ve�culo: ";
                    cin >> placa;
                    if(placa.length() != 7) cout << "!!! Quantidade de d�gitos inv�lida !!!\n";
                    else break;
                } while(true);

                PJ PJ = { id, placa };
                if(P == 'F') {
                    char C;
                    do {
                        cout << "> Voc� aderiu ao pacote de revis�es? Sim (S) ou N�o (N): ";
                        cin >> C;
                        C = toupper(C);
                        if(C != 'S' && C != 'N') cout << "!!! Op��o inserida inv�lida !!!\n";
                        else break;
                    } while(true);
                    PF PF = { C, PJ };
                    if(C == 'S') Fp = adicionaF(Fp, PF); // Adiciona na fila das pessoas
                    else Fn = adicionaF(Fn, PF);
                } else Fj = adicionaF(Fj, PJ);

                cout << "\n> Ordem de servi�o registrada!";
                getchar();
                break;
            }

            case 2: { // Ficha ser� EMPILHADA NA PILHA e pessoa ser� REMOVIDA DA FILA
                if(Fp != NULL) { // F�sicas priorit�rias
                    carroPF = criarFicha(carroPF, Fp->dado, "f�sicas", " priorit�rias");
                    Fp = removeF(Fp);
                }
                else {
                    if(Fj != NULL){ // Jur�dicas
                        carroPJ = criarFicha(carroPJ, Fj->dado, "jur�dicas", "");
                        Fj = removeF(Fj);
                    } else {
                        if(Fn != NULL) {
                            carroPF = criarFicha(carroPF, Fn->dado, "f�sicas", " n�o priorit�rias");
                            Fn = removeF(Fn);
                        } else cout << "!!! NENHUMA PESSOA REGISTRADA !!!";
                    }
                }
                getchar();
                break;
            }

            case 3:
                mostrarOrdens(Fp, "f�sicas priorit�rias", " CPF", pjF);
                mostrarOrdens(Fj, "jur�dicas", "CNPJ", pjJ);
                mostrarOrdens(Fn, "f�sicas n�o priorit�rias", " CPF", pjF);
                break;

            case 4:
                InformPF(Fp, Fn);
                break;

            case 5:
                pilhaInvertida(carroPF);
                break;

            case 6:
                SomaServicos(carroPF);
                break;

            case 7:
                MaiorValor(carroPF);
                break;

            case 8:
                MenorValor(carroPJ);
                break;

            case 9:
                MaiorQtdP(carroPF, carroPJ);
                break;

            default:
                cout << "> Op��o inv�lida!";

        }; getchar();
    }
    while(menu != 0);
}
