/*6. Crie uma fun��o para copiar os dados pilha P1 para P2. Esta fun��o deve preservar os dados armazenados em P1,
ou seja, ap�s a execu��o da fun��o, P1 e P2 devem possuir os mesmos elementos e na mesma ordem.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamica.hpp"

void adicionaItem(Pilha* P) {
    int elem;
    cout << ">> Insira um valor: ";
    cin >> elem;
    empilhaP(P, elem);

}

void removeItem(Pilha* P) {
    int item = desempilhaP(P);
    if(item == NULL) cout << ">> Pilha 1 est� VAZIA... Preencha com elementos!!";
    else cout << ">> Seguinte item foi removido da pilha 1: " << item;
}

void copiaPilha(Pilha *P1, Pilha *P2, Pilha *Paux) {
    destroiP(P2);
    NoPilha *no = P1->topo;
    while(no != NULL) {
        empilhaP(Paux, no->dado);
        no = no->prox;
    }
    while(!vaziaP(Paux)) {
        empilhaP(P2, desempilhaP(Paux));
    } cout << ">> C�pia efetuada com SUCESSO!!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P1, P2, Paux;

    do
    {
        system("cls");
        cout << "##########MENU DE OP��ES##########" << endl;
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
                adicionaItem(&P1);
                break;

            case 2:
                removeItem(&P1);
                break;

            case 3: // FAZER A C�PIA DOS ITENS
                copiaPilha(&P1, &P2, &Paux);
                break;

            case 4:
                if(vaziaP(&P1)) cout << "Adicione um valor na pilha antes!!!";
                else {
                    mostraP(&P1, "original");
                    mostraP(&P2, "c�pia");
                }
                break;

        }; getchar();
    }
    while(menu != 0);
}
