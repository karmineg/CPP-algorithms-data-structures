/*2. Crie as seguintes funções:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

void stringInvertida(No<char>** L1) {
    cout << ">> String invertida: ";
    No<char>** Laux = new No<char>*();
    while(*L1 != NULL) {
        char C = removeFim(L1);
        cout << C;
        adicionarFim(Laux, C);
    } while(*Laux != NULL) adicionarFim(L1, removeFim(Laux));
}

void removerChar(No<char>** L1, char(*funcao)(No<char>**)) {
    if(*L1 != NULL) cout << "!!! Caractere '" << funcao(L1) << "' removido  com sucesso !!!";
    else cout << "!!! Lista de caracteres ESTÁ VAZIA !!!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declaração padrão para criar uma lista
    No<char>** L1 = new No<char>*();

    do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                      #" << endl;
        cout << "# 1 - Insira um caractere       #" << endl;
        cout << "# 2 - Remova último caractere   #" << endl;
        cout << "# 3 - Remova primeiro caractere #" << endl;
        cout << "# 4 - Mostrar lista normal      #" << endl;
        cout << "# 5 - Mostrar string INVERTIDA  #" << endl;
        cout << "#################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu) {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: {
                char C;
                cout << ">> Digite um caractere: ";
                cin >> C;
                adicionarFim(L1, C);
                cout << "!!! Adicionado com sucesso !!!";
                break;
            }

            case 2:
                removerChar(L1, removeFim);
                break;

            case 3:
                removerChar(L1, removeInicio);
                break;

            case 4:
                mostrar(*L1, "Lista de caracteres");
                break;

            case 5:
                stringInvertida(L1);
                break;

            default:
                cout << "!!! Opção inválida !!!";
        } getchar();
    } while(menu != 0);
}
