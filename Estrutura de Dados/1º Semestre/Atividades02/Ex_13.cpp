/*13. Crie um programa para intercalar duas pilhas P1 e P2 conforme o exemplo abaixo. Note que as pilhas P1 e P2
possuem o mesmo tamanho, mas o número de elementos armazenados em cada uma é diferente.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

void adicionaItem(Pilha* P, Pilha* Paux, int num) {
    if(!verificaInicializacaoP(P)) { // Se a pilha AINDA não foi inicializada (ou seja, se é a primeira interação do usuário ou as pilhas foram DESTRUÍDAS)
        inicializaP(P, 6);
    }
    if(!verificaInicializacaoP(Paux)) {
        inicializaP(Paux, 12);
    }
    if(!cheiaP(P)) {
        int elem;
        cout << ">> Insira um valor para pilha " << num << ": ";
        cin >> elem;
        empilhaP(P, elem);
    } else {
        cout << "!!! PILHA " << num << " ESTÁ CHEIA, remova o último elemento ou esvazie tudo !!!";
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P1, P2, Paux;

    do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Sair                            #" << endl;
        cout << "# 1 - Inserir elementos na pilha um   #" << endl;
        cout << "# 2 - Inserir elementos na pilha dois #" << endl;
        cout << "# 3 - Intercalar pilhas               #" << endl;
        cout << "# 4 - Zerar todas as pilhas           #" << endl;
        cout << "#######################################" << endl;
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
                adicionaItem(&P1, &Paux, 1);
                break;

            case 2:
                adicionaItem(&P2, &Paux, 2);
                break;

            case 3:
                mostraP(&P1, "1");
                cout << endl;
                mostraP(&P2, "2");
                cout << endl;
                // Enquanto a pilha P1 tiver elementos, vai desempilhando e colocando, em seguida, também desempilhando da pilha P2
                while(!vaziaP(&P1)) {
                    int dado1 = desempilhaP(&P1);
                    empilhaP(&Paux, dado1);
                    if(!vaziaP(&P2)) {
                        int dado2 = desempilhaP(&P2);
                        empilhaP(&Paux, dado2);
                    }
                } // Se a pilha P1 estiver vazia, mas ainda tem elementos em P2, desempilha todo o resto
                while(!vaziaP(&P2)) {
                    empilhaP(&Paux, desempilhaP(&P2));
                }
                mostraP(&Paux, "auxiliar");
                break;

            case 4:
                destroiP(&P1);
                destroiP(&P2);
                destroiP(&Paux);
                cout << ">> Todas as pilhas foram ESVAZIADAS!";
                break;

        }; getchar();
    }
    while(menu != 0);


}
