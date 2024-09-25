#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "template.hpp"

No<int> *adicionaItem(No<int> *P) {
    int elem;
    cout << ">> Insira um valor: ";
    cin >> elem;
    return adicionar(P, elem);
}

No<int> *removeItem(No<int>* P) {
    if(P == NULL) cout << ">> Pilha 1 está VAZIA... Preencha com elementos!!";
    else {
        cout << "!!! Seguinte item foi removido da pilha 1: " << P->dado;
        return remover(P);
    } return P;
}

No<int> *copiaPilha(No<int> *P1, No<int> *P2) {
    No<int> *Paux = nullptr;
    P2 = destruir(P2);
    while(P1 != NULL) {
        Paux = adicionar(Paux, P1->dado);
        P1 = P1->prox;
    }
    while(Paux != NULL) {
        P2 = adicionar(P2, Paux->dado);
        Paux = remover(Paux);
    } cout << ">> Cópia efetuada com SUCESSO!!";
    return P2;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int> *P1 = nullptr;
    No<int> *P2 = nullptr;

    do
    {
        system("cls");
        cout << "##########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Inserir valores na pilha 1 #" << endl;
        cout << "# 2 - Remover valores na pilha 1 #" << endl;
        cout << "# 3 - Copiar para pilha 2        #" << endl;
        cout << "# 4 - Mostrar pilhas             #" << endl;
        cout << "##################################" << endl;
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
                P1 = adicionaItem(P1);
                break;

            case 2:
                P1 = removeItem(P1);
                break;

            case 3: // FAZER A CÓPIA DOS ITENS
                P2 = copiaPilha(P1, P2);
                break;

            case 4:
                if(P1 == NULL) cout << "Adicione um valor na pilha antes!!!";
                else {
                    mostrar(P1, "original");
                    mostrar(P2, "cópia");
                }
                break;

        }; getchar();
    }
    while(menu != 0);
}
