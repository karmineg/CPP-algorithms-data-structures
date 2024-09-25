/*2. Crie as seguintes fun��es:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

void InverteLista(No<int>** L, int i) {
    int cont = 0;
    while(cont != i){
        adicionarFim(L, (*L)->dado);
        removeInicio(L);
        cont++;
    }
    cout << "> Lista invertida com sucesso! Confira em 'mostrar'!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int>** L = new No<int>*();

    do
    {
        system("cls");
        cout << "######################MENU DE OP��ES####################" << endl;
        cout << "# 0 - Sair                                             #" << endl;
        cout << "# 1 - Inserir um valor na lista                        #" << endl;
        cout << "# 2 - Remover um valor da lista                        #" << endl;
        cout << "# 3 - Mostrar lista                                    #" << endl;
        cout << "# 4 - Deslocar in�cio da lista pro final at� �ndice... #" << endl;
        cout << "########################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu) {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: {
                int num;
                cout << ">> Digite um valor num�rico: ";
                cin >> num;
                adicionarFim(L, num);
                cout << "!!! Adicionado com sucesso !!!";
                getchar();
                break;
            }

            case 2:
                if(*L != NULL) cout << "> Valor " << removeFim(L) << " retirado com sucesso!";
                else cout << "> Lista J� est� vazia!!!";
                break;

            case 3:
                mostrar(*L, "Lista de n�meros", "      N�mero", 0);
                break;

            case 4:
                if (*L == NULL) cout << "> A lista est� vazia!";
                else {
                    int i;
                    do {
                        cout << "> Digite um valor para o �ndice: ";
                        cin >> i;
                        if(i >= quantosItens(*L)) cout << "> O �ndice inserido excede o tamanho da lista!\n";
                        else break;
                    } while(true);
                    InverteLista(L, i);
                    getchar();
                }
                break;

            default:
                cout << "!!! Op��o inv�lida !!!";
        } getchar();
    } while(menu != 0);
}
