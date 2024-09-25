/*9. Dados duas listas L1 e L2, crie uma função para computar a lista L3 que é a intersecção de L1 e L2.
Exemplo:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

void Interseccao(No<int>*L1, No<int>*L2, No<int>**L3) {
    destruir(L3);
    No<int>* Laux = L2;

    while(L1 != NULL) {
        int num = L1->dado;
        if(!existeValor(*L3, num)) {
            while(L2 != NULL) {
                if(num == L2->dado) {
                    adicionarFim(L3, num);
                    break;
                } L2 = L2->prox;
            } L2 = Laux;
        }
        L1 = L1->prox;
    }
    int qtd = quantosItens(*L3);
    if(qtd == 0) cout << "> Não há nenhum elemento em comum entre L1 e L2!";
    else if(qtd == 1) cout << "> Foi encontrado um elemento em comum! Adicionado em L3!";
    else cout << "Foi encontrado " << qtd << " elementos em comum! Adicionado em L3!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declaração padrão para criar uma lista
    No<int>** L1 = new No<int>*();
    No<int>** L2 = new No<int>*();
    No<int>** L3 = new No<int>*();

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES############" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Inserir na lista 1            #" << endl;
        cout << "# 2 - Inserir na lista 2            #" << endl;
        cout << "# 3 - Remover elemento da lista 1   #" << endl;
        cout << "# 4 - Remover elemento da lista 2   #" << endl;
        cout << "# 5 - Fazer interseccção das listas #" << endl;
        cout << "# 6 - Mostrar listas                #" << endl;
        cout << "#####################################" << endl;
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
                cout << ">> Digite um valor numérico: ";
                cin >> num;
                adicionarFim(L1, num);
                cout << "!!! Adicionado com sucesso na lista 1!!!";
                getchar();
                break;
            }

            case 2: {
                int num;
                cout << ">> Digite um valor numérico: ";
                cin >> num;
                adicionarFim(L2, num);
                cout << "!!! Adicionado com sucesso na lista 2!!!";
                getchar();
                break;
            }

            case 3:
                if(*L1 != NULL) cout << "> Valor " << removeFim(L1) << " retirado com sucesso da lista 1!";
                else cout << "> Lista 1 JÁ está vazia!!!";
                break;

            case 4:
                if(*L2 != NULL) cout << "> Valor " << removeFim(L2) << " retirado com sucesso da lista 2!";
                else cout << "> Lista 2 JÁ está vazia!!!";
                break;

            case 5:
                Interseccao(*L1, *L2, L3);
                break;

            case 6:
                mostrar(*L1, "Lista 1", "      Número", 0);
                mostrar(*L2, "Lista 2", "      Número", 0);
                mostrar(*L3, "Lista 3 (intersecção)", "      Número", 0);
                break;

        }; getchar();
    }
    while(menu != 0);
}
