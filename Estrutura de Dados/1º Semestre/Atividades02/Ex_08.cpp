/*8. Desenvolva as seguintes fun��es:
� Fun��o para testar se duas pilhas P1 e P2 s�o iguais.
� Fun��o para retornar o n�mero de elementos da pilha que possuem valor par.
Observa��o: Use uma pilha auxiliar e as opera��es de empilha/desempilha para implementar as fun��es, ou
seja, n�o � permitido acessar o vetor da pilha diretamente (pilha->dados[i]).
*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

void adicionaItem(Pilha* P, Pilha* Paux, int num) {
    if(!verificaInicializacaoP(P)) { // Se a pilha AINDA n�o foi inicializada (ou seja, se � a primeira intera��o do usu�rio ou as pilhas foram DESTRU�DAS)
        inicializaP(P, 6);
    }
    if(!verificaInicializacaoP(Paux)) {
        inicializaP(Paux, 6);
    }
    if(!cheiaP(P)) {
        int elem;
        cout << ">> Insira um valor para pilha " << num << ": ";
        cin >> elem;
        empilhaP(P, elem);
    } else {
        cout << "!!! PILHA " << num << " EST� CHEIA, remova o �ltimo elemento ou esvazie tudo !!!";
    }
}

void retornarPilhas(Pilha* P1, Pilha* P2, Pilha* Paux) {
    while(!vaziaP(Paux)) {
        int dado = desempilhaP(Paux);
        empilhaP(P1, dado);
        empilhaP(P2, dado);
    }
}

void contarPares(Pilha *P, Pilha *Paux, int num) {
    int cont = 0;
    while(!vaziaP(P))
    {
        int dado = desempilhaP(P);
        cont += (1 - abs(dado % 2));
        empilhaP(Paux, dado);
    }

    if(cont == 0) {
        cout << ">> N�O tem n�meros pares na pilha " << num << "!!! >:(";
    } else if(cont == 1) {
        cout << ">> H� apenas um n�mero par na pilha " << num << "... :(";
    } else {
        cout << ">> H� " << cont << " n�meros pares na pilha " << num << "... :)";
    }

    while(!vaziaP(Paux))
    {
        int dado = desempilhaP(Paux);
        empilhaP(P, dado);
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P1, P2, Paux;

    do
    {
        system("cls");
        cout << "################MENU DE OP��ES#################" << endl;
        cout << "# 0 - Sair                                    #" << endl;
        cout << "# 1 - Inserir elementos na pilha um           #" << endl;
        cout << "# 2 - Inserir elementos na pilha dois         #" << endl;
        cout << "# 3 - Ver se as pilhas s�o iguais             #" << endl;
        cout << "# 4 - Zerar todas as pilhas                   #" << endl;
        cout << "# 5 - Conferir quantidade de pares nas pilhas #" << endl;
        cout << "###############################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                adicionaItem(&P1, &Paux, 1);
                break;

            case 2:
                adicionaItem(&P2, &Paux, 2);
                break;

            case 3:
                if(P1.topo != P2.topo) {
                    cout << ">> As pilhas N�O tem a mesma quantidade de itens... logo N�O s�o iguais!\n";
                } else {
                    int isEqual = 1;
                    while(!vaziaP(&P1)) {
                        int dado1 = desempilhaP(&P1);
                        int dado2 = desempilhaP(&P2);
                        if(dado1 != dado2) {
                            cout << ">> As pilhas N�O s�o iguais... H�, pelo menos, um elemento n�o em comum... :(\n\n";
                            empilhaP(&P1, dado1);
                            empilhaP(&P2, dado2);
                            retornarPilhas(&P1, &P2, &Paux);
                            mostraP(&P1, "1");
                            cout << endl;
                            mostraP(&P2, "2");
                            isEqual = 0;
                            break;
                        } else {
                            empilhaP(&Paux, dado1);
                        }
                    } if(isEqual) {
                        cout << ">> As pilhas S�O iguais!!! Mesma quantidade de elementos e os elementos nas mesmas ordens!!\n\n";
                        mostraP(&Paux, "auxiliar");
                        retornarPilhas(&P1, &P2, &Paux);
                    }
                }
                break;

            case 4:
                destroiP(&P1);
                destroiP(&P2);
                cout << ">> Todas as pilhas foram ESVAZIADAS!";
                break;

            case 5:
                contarPares(&P1, &Paux, 1);
                cout << endl;
                contarPares(&P2, &Paux, 2);
                break;

        }; getchar();
    }
    while(menu != 0);
}
