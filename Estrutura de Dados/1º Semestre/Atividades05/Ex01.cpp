/*1. Dada uma fila dinâmica F, implemente uma função para inverter a ordem dos elementos F. Para inverter a ordem
dos elementos, faça uso de uma pilha dinâmica P.
O menu deve conter as seguintes opções:
− Incluir na fila
− Remover da fila
− Mostrar fila
− Inverter fila*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filadinamica-template.hpp"
#include "pilha-template.hpp"

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    float num;

    No<float>* P = nullptr;
    NoF<float>* F = nullptr;

    do
    {
        system("cls");
        cout << "#####MENU DE OPÇÕES####" << endl;
        cout << "# 0 - Sair            #" << endl;
        cout << "# 1 - Incluir na fila #" << endl;
        cout << "# 2 - Remover da fila #" << endl;
        cout << "# 3 - Mostrar fila    #" << endl;
        cout << "# 4 - Inverter fila   #" << endl;
        cout << "#######################" << endl;
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
                cout << "Digite um número: ";
                cin >> num;

                F = adicionaF(F, num);
                cout << "Elemento " << num << " foi adicionado no nó " << F;
                getchar();
                break;

            case 2:
                if (F == NULL) cout << "Essa fila já está vazia!";
                else {
                    cout << "Elemento " << F->dado << " foi removido!";
                    F = removeF(F);
                }

                break;

            case 3:
                mostraF(F, "de números");
                break;

            case 4:
                if (F == NULL) cout << "Essa fila está vazia!";
                else {
                // Primeiramente, esvaziamos a fila, inserindo os itens na pilha
                  while(F != NULL) {
                    P = adicionaP(P, F->dado);
                    F = removeF(F);
                  }
                // Após isso, fazemos o contrário (esvaziamos a PILHA)
                  while(P != NULL) {
                    F = adicionaF(F, P->dado);
                    P = removeP(P);
                  }
                  cout << "Pilha invertida com SUCESSO\nVerifique na opção 'Mostra'";
                }

                break;

        }; getchar();
    }
    while(menu != 0);
}
