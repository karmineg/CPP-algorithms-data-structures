/*4. Crie uma pilha que permita armazenar dados do tipo string. Para isso, deve-se modificar a estrutura da Pilha, “int
*dados;” para “string *dados;”. Além disso, as demais funções que recebem o valor do tipo inteiro devem ser
alteradas para o tipo string. Exemplos:*/

// MESMA QUE A 2, MAS USANDO STRINGS

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilhaString.hpp"

void buscarElem(Pilha *P) {
    string C = "";
    cout << "Digite um elemento para consultar na pilha: ";
    getline(cin, C);
    int indB = indBuscaP(P, C);
    if(indB == -1) {
        cout << "!!! Elemento NÃO encontrado na pilha... insira outro !!!";
    } else {
        cout << "!!! Elemento ENCONTRADO!! (No índice " << indB << ") !!!";
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int menu = -1;
    Pilha P;

    do
    {
        system("cls");
        cout << "####MENU DE OPÇÕES###" << endl;
        cout << "# 0 - Sair          #" << endl;
        cout << "# 1 - Criar pilha   #" << endl;
        cout << "# 2 - Inserir       #" << endl;
        cout << "# 3 - Remover       #" << endl;
        cout << "# 4 - Consultar     #" << endl;
        cout << "# 5 - Mostrar pilha #" << endl;
        cout << "#####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: // CRIAÇÃO DE PILHAA
                int tam;
                do {
                    cout << ">> Insira o tamanho da nova pilha: ";
                    cin >> tam; // Usuário informa o tamanho, que não pode ser nulo ou negativo!!
                    if(tam <= 0) cout << "!!! VALOR INSERIDO INVÁLIDO !!!\n";
                    else break;
                } while(true);
                if(verificaInicializacaoP(&P)) { // Se pilha já foi inserida antes, destrói a atual e cria a nova
                    destroiP(&P);
                } inicializaP(&P, tam);
                cout << "Nova pilha criada!!!";
                getchar();
            break;

            case 2: // INSERIR ELEMENTO NA PILHA
                if(!cheiaP(&P)) {
                    string elem;
                    cout << ">> Insira um elemento: ";
                    getline(cin, elem);
                    empilhaP(&P, elem);
                     cout << "Elemento adicionado!!!";
                } else {
                    cout << "!!! PILHA ESTÁ CHEIA, remova o último elemento ou esvazie tudo !!!";
                } break;

            case 3: // REMOVER ELEMENTO
                if(!vaziaP(&P)) {
                    desempilhaP(&P);
                    cout << "Elemento removido!!!";
                } else {
                    cout << "!!! PILHA ESTÁ VAZIA... Coloque novos elementos !!!";
                }
            break;

            case 4: // CONSULTAR
                buscarElem(&P);

            break;

            case 5: // MOSTRAR PILHA
                mostraP(&P, "String");

            break;

            default:
                cout << "Opção inválida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
