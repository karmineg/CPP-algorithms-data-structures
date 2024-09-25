#include<iostream>
using namespace std;

#include "template.hpp"

No<int> *adicionaItem(No<int> *P) {
    No<int> *Paux = nullptr;
    int elem;
    cout << "> Insira um valor: ";
    cin >> elem;
    while(P != NULL) {
        int itemT = P->dado;
        if(elem > itemT) { // Se o elemento a adicionar é MAIOR que o do topo, tira o elemento do topo de ORD e empilha em AUX
            Paux = adicionar(Paux, itemT);
            P = remover(P);
        } else { // Caso contrário (elem. é MENOR OU IGUAL ao topo), adiciona o elemento no ORD e coloca todos os itens do AUX de volta no ORD
            P = adicionar(P, elem);
            break;
        }
    } if(P == NULL) { // Se todos os elementos de ORD foram colocados no AUX, o elemento atual é o ÚLTIMO (logo o maior)
        P = adicionar(P, elem);
    } while(Paux != NULL) {
        P = adicionar(P, Paux->dado);
        Paux = remover(Paux);
    } cout << "!!! Elemento adicionado COM SUCESSO !!! :)";
    return P;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int> *P = nullptr;

    do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES#########" << endl;
        cout << "# 0 - Sair                     #" << endl;
        cout << "# 1 - Inserir valores na pilha #" << endl;
        cout << "# 2 - Mostrar pilha            #" << endl;
        cout << "################################" << endl;
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
                P = adicionaItem(P);
                break;

            case 2:
                mostrar(P, "de números");
                break;

        }; getchar();
    }
    while(menu != 0);
}
