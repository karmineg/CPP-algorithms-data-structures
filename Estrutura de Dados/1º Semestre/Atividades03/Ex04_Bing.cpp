/*4. Desenvolva as seguintes fun��es:
a) Fun��o para testar se duas pilhas P1 e P2 s�o iguais.
b) Fun��o para retornar o n�mero de elementos da pilha que possuem valor par.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamica.hpp"

void adicionaItem(Pilha* P, string num) {
    int elem;
    cout << ">> Insira um valor para pilha " << num << ": ";
    cin >> elem;
    empilhaP(P, elem);
}

void contarPares(Pilha *P, string num) {
    if(P->topo == NULL) {
        cout << ">> N�O H� ITENS na pilha " << num << "!!! :,(";
        return;
    }
    int cont = 0;
    NoPilha *no = P->topo;
    while(no != NULL) {
        if((no->dado) % 2 == 0) cont += 1;
        no = no->prox;
    }

    if(cont == 0) {
        cout << ">> N�O tem n�meros pares na pilha " << num << "!!! >:(";
    } else if(cont == 1) {
        cout << ">> H� apenas um n�mero par na pilha " << num << "... :(";
    } else {
        cout << ">> H� " << cont << " n�meros pares na pilha " << num << "... :)";
    }
}

void analisaP(Pilha *P1, Pilha *P2) {
    NoPilha *no1 = P1->topo;
    NoPilha *no2 = P2->topo;
    string erro = "";
    if(no1 == NULL && no2 != NULL) erro = "a pilha 1 est� VAZIA... Insira itens!!";
    else if(no1 != NULL && no2 == NULL) erro = "a pilha 2 est� VAZIA... Insira itens!!";
    else if(no1 == NULL && no2 == NULL) erro = "ambas as pilhas est�o VAZIAS... Insira itens!!";
    while(erro == "") {
        if(no1->dado == no2->dado) {
            if(no1->prox == NULL && no2->prox == NULL) { // A an�lise chegou ao final de ambas as pilhas simultaneamente, logo � IGUAL
                break;
            } else if(no1->prox != NULL && no2->prox != NULL) { // Se ainda n�o chegamos ao final de uma das pilhas, CONTINUAR a an�lise
                // Passando para o pr�ximo
                no1 = no1->prox;
                no2 = no2->prox;
            } else { // Se chegamos ao final de uma das pilhas, AUTOMATICAMENTE as pilhas N�O s�o iguais
                erro = "N�O possuem o mesmo tamanho";
            }
        } else {
            erro = "ao percorrer a partir do topo, dois correspondentes n�o s�o iguais";
        }
    } if(erro == "") {
        cout << "Ambas as pilhas s�o IGUAIS!!\n\n";
    } else {
        cout << "As pilhas N�O s�o iguais, pois " << erro << "... :(\n\n";
    } mostraP(P1, "1");
    cout << endl;
    mostraP(P2, "2");
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P1, P2;

    do
    {
        system("cls");
        cout << "################MENU DE OP��ES#################" << endl;
        cout << "# 0 - Sair                                    #" << endl;
        cout << "# 1 - Inserir elementos na pilha um           #" << endl;
        cout << "# 2 - Inserir elementos na pilha dois         #" << endl;
        cout << "# 3 - Ver se as pilhas s�o iguais             #" << endl;
        cout << "# 4 - Conferir quantidade de pares nas pilhas #" << endl;
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
                adicionaItem(&P1, "1");
                break;

            case 2:
                adicionaItem(&P2, "2");
                break;

            case 3:
                analisaP(&P1, &P2);

                break;

            case 4:
                contarPares(&P1, "1");
                cout << endl;
                contarPares(&P2, "2");
                break;

        }; getchar();
    }
    while(menu != 0);
}
