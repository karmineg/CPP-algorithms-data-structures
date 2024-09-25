/*4. Uma empresa precisa de um sistema para gerenciar a impress�o de documentos no servidor. Cada documento a
ser impresso possui os seguintes dados:
� Nome - nome do arquivo;
� Tamanho - tamanho do arquivo em megabyte (MB);
� Quantidade de p�ginas;
� Ano � ano em que o arquivo foi criado;
� Prioridade � prioridade de impress�o (U-urgente, P-priorit�rio, N-normal).
Quando um documento � enviado para o servidor de impress�o da empresa, ele � adicionado em uma das
seguintes filas:
� FilaU � armazena os documentos com prioridade=U.
� FilaP � armazena os documentos com prioridade=P.
� FilaN � armazena os documentos com prioridade=N.
Para realizar a impress�o dos documentos, o servidor realiza o atendimento das filas com base na prioridade
de impress�o:
1. Primeiramente, os documentos da FilaU devem ser impressos;
2. Posteriormente, n�o havendo documentos na FilaU, os documentos da FilaP devem ser impressos;
3. Por fim, quando n�o h� documentos na FilaU e na FilaP, os documentos da FilaN devem ser impressos.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filadinamica-template.hpp"

struct Documento {
    string nome;
    float tam;
    int pag;
    int ano;
};

void mostrarDoc(NoF<Documento>* F, string prio) {
    if(F == NULL) cout << "\n\n!!! N�O h� documentos " << prio << " a serem mostrados !!!";
    else {
        cout << "\n\n>> Lista de documentos " << prio << "\n";
        cout << "     Endere�o |         Nome | Qtd. p�ginas |      Tamanho |     Ano\n";
        cout << "--------------|--------------|--------------|--------------|---------\n";
        while(F != NULL) {
            Documento D = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(13) << D.nome << " |";
            cout << setfill(' ') << std::setw(13) << D.pag << " |";
            cout << setfill(' ') << std::setw(13) << D.tam << " |";
            cout << setfill(' ') << std::setw(8) << D.ano << endl;
            F = F->prox;
        }
    }
}

void informDoc(NoF<Documento>* Fu, NoF<Documento>* Fp, NoF<Documento>* Fn) {
    int totalD = 0;
    int totalP = 0;
    while(Fu != NULL) {
        totalD++;
        totalP += (Fu->dado).pag;
        Fu = Fu->prox;
    } while(Fp != NULL) {
        totalD++;
        totalP += (Fp->dado).pag;
        Fp = Fp->prox;
    } while(Fn != NULL) {
        totalD++;
        totalP += (Fn->dado).pag;
        Fn = Fn->prox;
    }
    cout << ">> Total de documentos: " << totalD << endl;
    cout << ">> Total de p�ginas: " << totalP << endl;
}

void mostrarFila(NoF<Documento>* F, string prio) {
    if(F == NULL) cout << "\n\n!!! N�O h� documentos " << prio << " a serem mostrados !!!";
    else {
        int total = 0;
        NoF<string> *nomeMaiorT = nullptr;
        NoF<string> *nomeMenorP = nullptr;
        int maiorT = 0, menorP = NULL;
        int qtdT = 0, qtdP = 0;
        while(F != NULL) {
            Documento D = F->dado;
            total++;
            // An�lise do tamanho
            if(D.tam >= maiorT) {
                if(D.tam > maiorT) { // Se o tamanho do documento atual for maior que o maior at� ent�o, fazemos a substitui��o e destruimos a fila de nomes!!
                    maiorT = D.tam;
                    nomeMaiorT = destroiF(nomeMaiorT);
                    qtdT = 0;
                } nomeMaiorT = adicionaF(nomeMaiorT, D.nome); // Adiciona o nome do documento
                qtdT++;
            }

            // An�lise do n�mero de p�ginas
            if(menorP == NULL) {
                menorP = D.pag;
                nomeMenorP = adicionaF(nomeMenorP, D.nome);
                qtdP++;
            } else {
                if(D.pag <= menorP) {
                    if(D.pag < menorP) { // Se o tamanho do documento atual for maior que o maior at� ent�o, fazemos a substitui��o e destruimos a fila de nomes!!
                        menorP = D.pag;
                        nomeMenorP = destroiF(nomeMenorP);
                        qtdP = 0;
                    } nomeMenorP = adicionaF(nomeMenorP, D.nome); // Adiciona o nome do documento
                    qtdP++;
                }
            }
            F = F->prox;
        }

        // Mostrar informa��es
        cout << "\n>> Lista de documentos " << prio << "\n";
        cout << "      Total de documentos | " << total << endl;
        cout << "--------------------------|--------------------------" << endl;
        cout << " Documento com maior tam. | " << nomeMaiorT->dado << endl;
        nomeMaiorT = nomeMaiorT->prox;
        while(nomeMaiorT != NULL) {
            cout << "                          | " << nomeMaiorT->dado << endl;
            nomeMaiorT = nomeMaiorT->prox;
        }
        cout << "--------------------------|--------------------------" << endl;
        cout << " Doc. com menor num. pag. | " << nomeMenorP->dado << endl;
        nomeMenorP = nomeMenorP->prox;
        while(nomeMenorP != NULL) {
            cout << "                          | " << nomeMenorP->dado << endl;
            nomeMenorP = nomeMenorP->prox;
        }
    }
    getchar();
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    char prio;

    NoF<Documento>* Fu = nullptr;
    NoF<Documento>* Fp = nullptr;
    NoF<Documento>* Fn = nullptr;

    do
    {
        system("cls");
        cout << "##################MENU DE OP��ES#################" << endl;
        cout << "# 0 - Sair                                      #" << endl;
        cout << "# 1 - Enviar documento para a impress�o         #" << endl;
        cout << "# 2 - Mostrar o nome dos documentos armazenados #" << endl;
        cout << "# 3 - Imprimir documento                        #" << endl;
        cout << "# 4 - Mostrar total de p�ginas e documentos     #" << endl;
        cout << "# 5 - Mostrar as informa��es dos documentos     #" << endl;
        cout << "#################################################" << endl;
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
                cout << "!!! Dados para o documento !!!\n>> Informe o nome do documento: ";
                getline(cin, nome);
                // Tamanho
                float tam;
                do {
                    cout << ">> Informe o tamanho do documento(MB): ";
                    cin >> tam;
                    if(tam < 0) cout << "!!! O tamanho n�o pode ser nulo !!!\n";
                    else break;
                } while(true);
                // P�ginas
                int pag;
                do {
                    cout << ">> Informe a quantidade de p�ginas do documento: ";
                    cin >> pag;
                    if(pag < 0) cout << "!!! A quantidade de p�ginas n�o pode ser nula !!!\n";
                    else break;
                } while(true);
                // Ano
                int ano;
                do {
                    cout << ">> Informe o ano do documento: ";
                    cin >> ano;
                        if(ano > 2023) cout << "!!! Ano inserido � superior ao atual ano !!!\n";
                        else if(ano <= 0) cout << "!!! Ano N�O pode ser NULO ou NEGATIVO !!!\n";
                        else break;
                } while(true);
                // Prioridade
                do {
                    cout << ">> Informe a prioridade do documento ('U' para urgente, 'P' para priorit�rio, 'N' para normal): ";
                   cin >> prio;
                    prio = toupper(prio);
                    if(prio != 'U' && prio != 'P' && prio != 'N') cout << "!!! Op��o inserida INV�LIDA !!!\n";
                    else break;
                } while(true);

                Documento D = { nome, tam, pag, ano };
                if (prio == 'U') Fu = adicionaF(Fu, D);
                if (prio == 'P') Fp = adicionaF(Fp, D);
                if (prio == 'N') Fn = adicionaF(Fn, D);

                cout << "Documento adicionado!!!";
                getchar();
                break;

            } case 2:
                cout << "!!! LISTA DE DOCUMENTOS !!!";
                mostrarDoc(Fu, "urgentes");
                mostrarDoc(Fp, "priorit�rios");
                mostrarDoc(Fn, "normais");
                break;

            case 3:
                if (Fu != NULL) {
                    cout << "Documento de prioridade urgente " << (Fu->dado).nome << " foi impresso!";
                    Fu = removeF(Fu);
                }
                else {
                    if (Fp != NULL) {
                       cout << "Documento de prioridade priorit�rio " << (Fp->dado).nome << " foi impresso!";
                        Fp = removeF(Fp);
                    }
                    else if (Fn != NULL){
                        cout << "Documento de prioridade normal " << (Fn->dado).nome << " foi impresso!";
                        Fn = removeF(Fn);
                    }
                    else cout << "N�o h� nenhum documento dispon�vel para imprimir!";
                }

                break;

            case 4: {
                informDoc(Fu, Fp, Fn);
                break;

            } case 5:
                do {
                   cout << "Qual fila voc� deseja acessar?('U' para urgente, 'P' para priorit�rio, 'N' para normal)\n";
                    cin >> prio;
                    prio = toupper(prio);
                    if(prio != 'U' && prio != 'P' && prio != 'N') cout << "!!! Op��o inserida INV�LIDA !!!\n";
                    else break;
                } while(true);

                if (prio == 'U') mostrarFila(Fu, "urgentes");
                if (prio == 'P') mostrarFila(Fp, "priorit�rios");
                if (prio == 'N') mostrarFila(Fn, "normais");
                break;

        }; getchar();
    }
    while(menu != 0);
}
