/*9. Fa�a um programa que usa uma pilha para armazenar o c�digo das cidades que fazem parte de um caminho.
� Inicialmente, o usu�rio deve informar o n�mero de cidades;
� Depois, o usu�rio deve informar o c�digo de cada cidade e incluir na pilha;
� Criar uma funcionalidade de busca de um c�digo na pilha: para fazer a busca deve usar uma pilha auxiliar;
a cada item verificado na pilha principal que for diferente do c�digo procurado, deve incluir na pilha
auxiliar; ap�s encontrar o valor, deve retornar os valores da pilha auxiliar para a pilha principal.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

void adicionaItem(Pilha* P, Pilha* Paux, int tam) {
    if(!verificaInicializacaoP(P)) { // Se a pilha AINDA n�o foi inicializada (ou seja, se � a primeira intera��o do usu�rio ou as pilhas foram DESTRU�DAS)
        inicializaP(P, tam);
    }
    if(!verificaInicializacaoP(Paux)) {
        inicializaP(Paux, tam);
    }
    if(!cheiaP(P)) {
        int elem;
        cout << ">> Insira o c�digo da cidade: ";
        cin >> elem;
        empilhaP(P, elem);
    } else {
        cout << "!!! PILHA EST� CHEIA, remova o �ltimo elemento ou esvazie tudo !!!";
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

    cout << "Digite o n�mero de cidades: ";
    cin >> tam;

    do
    {
        system("cls");
        cout << "###########MENU DE OP��ES###########" << endl;
        cout << "# 0 - Sair                         #" << endl;
        cout << "# 1 - Inserir c�digo para a cidade #" << endl;
        cout << "# 2 - Buscar c�digo                #" << endl;
        cout << "# 3 - Mostrar c�digos              #" << endl;
        cout << "# 4 - Eliminar todos os c�digos    #" << endl;
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
                if(!verificaInicializacaoP(&P)) { // Se a pilha AINDA n�o foi inicializada (ou seja, se � a primeira intera��o do usu�rio ou as pilhas foram DESTRU�DAS)
                    cout << ">> Inicie a pilha de c�digos ANTES de fazer uma busca!!!";
                } else {
                    int cBusc;
                    cout << ">> Digite um c�digo para verificar se existe na pilha: ";
                    cin >> cBusc;
                    while(!vaziaP(&P)) {
                        int cPil = desempilhaP(&P);
                        if(cPil == cBusc) {
                            cout << ">> ENCONTRADO o c�digo na pilha (�ndice " << (P.topo + 1) << ")\n";
                            empilhaP(&P, cPil);
                            retornarPilha(&P, &Paux);
                            getchar();
                            break;
                        } else {
                            empilhaP(&Paux, cPil);
                        }
                    } if(vaziaP(&P)) {
                        cout << ">> N�O foi encontrado o c�digo na pilha...";
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
                cout << ">> Todos os c�digos foram obliterados!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
