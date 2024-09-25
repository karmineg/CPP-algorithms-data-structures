/*9. Faça um programa que usa uma pilha para armazenar o código das cidades que fazem parte de um caminho.
• Inicialmente, o usuário deve informar o número de cidades;
• Depois, o usuário deve informar o código de cada cidade e incluir na pilha;
• Criar uma funcionalidade de busca de um código na pilha: para fazer a busca deve usar uma pilha auxiliar;
a cada item verificado na pilha principal que for diferente do código procurado, deve incluir na pilha
auxiliar; após encontrar o valor, deve retornar os valores da pilha auxiliar para a pilha principal.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

void adicionaItem(Pilha* P, Pilha* Paux, int tam) {
    if(!verificaInicializacaoP(P)) { // Se a pilha AINDA não foi inicializada (ou seja, se é a primeira interação do usuário ou as pilhas foram DESTRUÍDAS)
        inicializaP(P, tam);
    }
    if(!verificaInicializacaoP(Paux)) {
        inicializaP(Paux, tam);
    }
    if(!cheiaP(P)) {
        int elem;
        cout << ">> Insira o código da cidade: ";
        cin >> elem;
        empilhaP(P, elem);
    } else {
        cout << "!!! PILHA ESTÁ CHEIA, remova o último elemento ou esvazie tudo !!!";
    }
}

void retornarPilha(Pilha* P, Pilha* Paux) {
    while(!vaziaP(Paux)) {
        empilhaP(P, desempilhaP(Paux));
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P, Paux;
    int tam;

    cout << "Digite o número de cidades: ";
    cin >> tam;

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                         #" << endl;
        cout << "# 1 - Inserir código para a cidade #" << endl;
        cout << "# 2 - Buscar código                #" << endl;
        cout << "# 3 - Mostrar códigos              #" << endl;
        cout << "# 4 - Eliminar todos os códigos    #" << endl;
        cout << "####################################" << endl;
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
                adicionaItem(&P, &Paux, tam);
                break;

            case 2:
                if(!verificaInicializacaoP(&P)) { // Se a pilha AINDA não foi inicializada (ou seja, se é a primeira interação do usuário ou as pilhas foram DESTRUÍDAS)
                    cout << ">> Inicie a pilha de códigos ANTES de fazer uma busca!!!";
                } else {
                    int cBusc;
                    cout << ">> Digite um código para verificar se existe na pilha: ";
                    cin >> cBusc;
                    while(!vaziaP(&P)) {
                        int cPil = desempilhaP(&P);
                        if(cPil == cBusc) {
                            cout << ">> ENCONTRADO o código na pilha (Índice " << (P.topo + 1) << ")\n";
                            empilhaP(&P, cPil);
                            retornarPilha(&P, &Paux);
                            getchar();
                            break;
                        } else {
                            empilhaP(&Paux, cPil);
                        }
                    } if(vaziaP(&P)) {
                        cout << ">> NÃO foi encontrado o código na pilha...";
                        retornarPilha(&P, &Paux);
                        getchar();
                    }
                }
                break;

            case 3:
                mostraP(&P, "cidade");
                break;

            case 4:
                destroiP(&P);
                cout << ">> Todos os códigos foram obliterados!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
