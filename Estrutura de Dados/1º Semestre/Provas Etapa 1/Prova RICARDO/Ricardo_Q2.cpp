#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;

#include "pilha-fila-dinamica-template.hpp"

void inverterP(No<int>** P) {
    int K = 0;
    do {
        cout << ">> Insira um n�mero natural n�o-nulo K: ";
        cin >> K;
        if(K <= 0) cout << "!!! N�mero INV�LIDO !!!\n";
        else break;
    } while(true);

    No<int>** Paux = new No<int>*(), // PILHA auxiliar
    ** Faux = new No<int>*(); // FILA auxiliar
    while(*P != NULL) adicionar(Paux, removeP(P));

    // Adicionar K elementos de pilha aux. na fila aux.
    int cont = 0;
    while(*Paux != NULL) {
        adicionar(Faux, removeP(Paux));
        cont++;
        if(cont == K) break;
    }
    // Adicionar elementos da fila aux. na pilha principal
    while(*Faux != NULL) adicionar(P, removeP(Faux));

    // Remover excedente da pilha aux. e colocar na pilha principal
    while(*Paux != NULL) adicionar(P, removeP(Paux));
    cout << "!!! Invertido com sucesso, confira na op��o 'Mostrar' !!!";
    getchar();
}

main() {
    system ("color FD");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int>** P = new No<int>*();
    do {
        system("cls");
        cout << "#############MENU DE OP��ES#############" << endl;
        cout << "# 0 - Sair                             #" << endl;
        cout << "# 1 - Adicionar n�mero na pilha        #" << endl;
        cout << "# 2 - Inverter elementos at� �ndice... #" << endl;
        cout << "# 3 - Mostrar pilha                    #" << endl;
        cout << "########################################" << endl;
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
                int num;
                cout << ">> Insira um n�mero: ";
                cin >> num;
                adicionar(P, num);
                cout << "!!! Adicionado novo n�mero !!!\n";
                getchar();
                break;
            }

            case 2:
                inverterP(P);
                break;

            case 3: { // REMOVER ELEMENTOS REPETIDOS (Parte mais importante)
                mostrar(*P, "Pilha de n�meros (da base para topo)");
                break;
            }

            default:
                cout << "> Op��o inv�lida!";

        }; getchar();
    }
    while(menu != 0);
}
