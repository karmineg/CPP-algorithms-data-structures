/*3. Faça um programa que cadastre em uma estrutura do tipo pilha vários números, sendo no máximo 6, ao remover
um número desta estrutura o mesmo deve ser empilhado em outra pilha, conforme o critério: se o número for
par na pilha dos pares, se for ímpar na pilha dos ímpares. No menu de opções deve ter uma alternativa para zerar
as três pilhas, mostrar pilha inicial, a dos pares e a dos ímpares.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

#include "pilha.hpp"

void tirarDaPilha(Pilha *P, Pilha *pP, Pilha *pI) {
    if(!vaziaP(P)) {
        int lastElem = desempilhaP(P);
        if(lastElem % 2 == 0) {
            if(!cheiaP(pP)) { // Se o partido Progressista NÃO estiver cheio, pode inserir novos itens...
                empilhaP(pP, lastElem);
                cout << "!!! Inserido na pilha PAR... Agora essa pilha tem " << (pP->topo + 1) << " elemento(s)!!";
            } else { // ... caso contrário é necessário ESVAZIAR TUDO
                cout << "!!! Pilha par está cheia... ESVAZIE TUDO !!!";
            }
        } else {
            if(!cheiaP(pI)) { // Se o partido Imperialista NÃO estiver cheio, pode inserir novos itens...
                empilhaP(pI, lastElem);
                cout << "!!! Inserido na pilha ÍMPAR... Agora essa pilha tem " << (pI->topo + 1) << " elemento(s)!!";
            } else { // ... caso contrário é necessário ESVAZIAR TUDO
                cout << "!!! Pilha ímpar está cheia... ESVAZIE TUDO!!!";
            }
        }
    } else {
        cout << "!!! PILHA JÁ ESTÁ VAZIA... Coloque novos elementos !!!";
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int menu = -1;

    Pilha P, pP, pI;

    do
    {
        system("cls");
        cout << "###############MENU DE OPÇÕES###############" << endl;
        cout << "# 0 - Sair                                 #" << endl;
        cout << "# 1 - Inserir elementos na pilha principal #" << endl;
        cout << "# 2 - Remover valor da pilha principal     #" << endl;
        cout << "# 3 - Mostrar todas as pilhas              #" << endl;
        cout << "# 4 - Zerar todas as pilhas                #" << endl;
        cout << "############################################" << endl;
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
                if(!verificaInicializacaoP(&P)) { // Se a pilha AINDA não foi inicializada (ou seja, se é a primeira interação do usuário ou as pilhas foram DESTRUÍDAS)
                    inicializaP(&P, 6);
                    inicializaP(&pP, 6);
                    inicializaP(&pI, 6);
                }
                if(!cheiaP(&P)) {
                    int elem;
                    cout << ">> Insira um valor: ";
                    cin >> elem;
                    empilhaP(&P, elem);
                } else {
                    cout << "!!! PILHA ESTÁ CHEIA, remova o último elemento ou esvazie tudo !!!";
                } break;

            case 2:
                tirarDaPilha(&P, &pP, &pI);
                break;

            case 3:
                mostraP(&P, "Principal");
                cout << endl;
                mostraP(&pP, "Par");
                cout << endl;
                mostraP(&pI, "Ímpar");
            break;

            case 4:
                destroiP(&P);
                destroiP(&pP);
                destroiP(&pI);
                cout << "> Todas as pilhas foram ESVAZIADAS!";
            break;

        }; getchar();
    }
    while(menu != 0);
}
