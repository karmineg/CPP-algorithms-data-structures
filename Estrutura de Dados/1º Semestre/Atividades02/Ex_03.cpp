/*3. Fa�a um programa que cadastre em uma estrutura do tipo pilha v�rios n�meros, sendo no m�ximo 6, ao remover
um n�mero desta estrutura o mesmo deve ser empilhado em outra pilha, conforme o crit�rio: se o n�mero for
par na pilha dos pares, se for �mpar na pilha dos �mpares. No menu de op��es deve ter uma alternativa para zerar
as tr�s pilhas, mostrar pilha inicial, a dos pares e a dos �mpares.*/

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
            if(!cheiaP(pP)) { // Se o partido Progressista N�O estiver cheio, pode inserir novos itens...
                empilhaP(pP, lastElem);
                cout << "!!! Inserido na pilha PAR... Agora essa pilha tem " << (pP->topo + 1) << " elemento(s)!!";
            } else { // ... caso contr�rio � necess�rio ESVAZIAR TUDO
                cout << "!!! Pilha par est� cheia... ESVAZIE TUDO !!!";
            }
        } else {
            if(!cheiaP(pI)) { // Se o partido Imperialista N�O estiver cheio, pode inserir novos itens...
                empilhaP(pI, lastElem);
                cout << "!!! Inserido na pilha �MPAR... Agora essa pilha tem " << (pI->topo + 1) << " elemento(s)!!";
            } else { // ... caso contr�rio � necess�rio ESVAZIAR TUDO
                cout << "!!! Pilha �mpar est� cheia... ESVAZIE TUDO!!!";
            }
        }
    } else {
        cout << "!!! PILHA J� EST� VAZIA... Coloque novos elementos !!!";
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
        cout << "###############MENU DE OP��ES###############" << endl;
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
                if(!verificaInicializacaoP(&P)) { // Se a pilha AINDA n�o foi inicializada (ou seja, se � a primeira intera��o do usu�rio ou as pilhas foram DESTRU�DAS)
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
                    cout << "!!! PILHA EST� CHEIA, remova o �ltimo elemento ou esvazie tudo !!!";
                } break;

            case 2:
                tirarDaPilha(&P, &pP, &pI);
                break;

            case 3:
                mostraP(&P, "Principal");
                cout << endl;
                mostraP(&pP, "Par");
                cout << endl;
                mostraP(&pI, "�mpar");
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
