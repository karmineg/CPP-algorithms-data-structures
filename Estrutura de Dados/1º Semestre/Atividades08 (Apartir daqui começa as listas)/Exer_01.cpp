/*1. Crie um menu para executar as operações sobre uma lista que armazena valores do tipo string.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

#include "lista-template.hpp"

string novaS(string d) {
    string novo = "";
    for(int i = 0; i < d.length(); i++) {
        novo += toupper(d[i]);
    } return novo; // Aqui, sempre vai ser retornado a string TODA MAIÚSCULA
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declaração padrão para criar uma lista
    No<string>** L = nullptr;

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES############" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Inicializar lista             #" << endl;
        cout << "# 2 - Inserir na lista              #" << endl;
        cout << "# 3 - Inserir em posição específica #" << endl;
        cout << "# 4 - Remover elemento da lista     #" << endl;
        cout << "# 5 - Buscar elemento               #" << endl;
        cout << "# 6 - Mostrar lista                 #" << endl;
        cout << "# 7 - Obliterar lista               #" << endl;
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

            case 1:
                L = new No<string>*();
                cout << "> Lista inicializada com sucesso!";
                break;

            case 2: {
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else {
                    string text;
                    cout << "> Digite um texto para adicionar na lista: ";
                    cin >> text;
                    adicionarFim(L, text);
                    cout << "> Texto adicionado na lista com sucesso!";
                    getchar();
                } break;
            }

            case 3:{
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else {
                    string texto;
                    cout << "> Digite um texto para adicionar na lista: ";
                    cin >> texto;

                    int i;
                    cout << "> Digite um índice para adicionar o texto na lista: ";
                    cin >> i;

                    adicionarPosicao(L, texto, i);
                    getchar();
                } break;
            }

            case 4:{
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else {
                    removeFim(L);
                    cout << "> Valor removido com sucesso!";
                    getchar();
                } break;
            }

            case 5: {
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else {
                    string texti;
                    cout << "> Digite um texto para buscar na lista: ";
                    cin >> texti;
                    buscarEMostrar(*L, texti, novaS);
                    getchar();
                } break;
            }

            case 6:
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else mostrar(*L, "Lista de String: ");
                break;

            case 7:
                if(L == NULL) cout << "Lista NÃO foi inicializada!!";
                else {
                destruir(L);
                cout << "> Lista destruída com sucesso!";
                } break;

        }; getchar();
    }
    while(menu != 0);
}
