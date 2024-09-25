/*2. Empregando pilha, construa um programa para ordenar uma sequência de valores inteiros fornecidos pelo
usuário. Faça uso de duas pilhas: ORD e AUX. O objetivo é organizar a pilha ORD de modo que nenhum item seja
empilhado sobre outro menor, fazendo uso da pilha auxiliar AUX.
a) O usuário pode informar quantos valores inteiros ele desejar.
b) Ao final, o programa deve mostrar a pilha ORD.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamica.hpp"

void adicionaItem(Pilha* P, Pilha* Paux) {
    int elem;
    cout << "> Insira um valor: ";
    cin >> elem;

    // adicionar 4
    // ORD: 10, 6, 3, 2
    // AUX:
    while(!vaziaP(P)) {
        int itemT = desempilhaP(P);
        if(elem > itemT) { // Se o elemento a adicionar é MAIOR que o do topo, tira o elemento do topo de ORD e empilha em AUX
            empilhaP(Paux, itemT);
        } else { // Caso contrário (elem. é MENOR OU IGUAL ao topo), adiciona o elemento no ORD e coloca todos os itens do AUX de volta no ORD
            empilhaP(P, itemT);
            empilhaP(P, elem);
            break;
        }
    } if(vaziaP(P)) { // Se todos os elementos de ORD foram colocados no AUX, o elemento atual é o ÚLTIMO (logo o maior)
        empilhaP(P, elem);
    } // Recolocação dos itens de AUX em ORD
    while(!vaziaP(Paux)) empilhaP(P, desempilhaP(Paux));
    cout << "!!! Elemento adicionado COM SUCESSO !!! :)";
    getchar();

}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha P, Paux;

    do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES#########" << endl;
        cout << "# 0 - Sair                     #" << endl;
        cout << "# 1 - Inserir valores na pilha #" << endl;
        cout << "# 2 - Mostrar pilha            #" << endl;
        cout << "################################" << endl;
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
                adicionaItem(&P, &Paux);
                break;

            case 2:
                if(vaziaP(&P)) cout << "Adicione um valor na pilha antes!!!";
                else mostraP(&P, "dos valores");
                break;

        }; getchar();
    }
    while(menu != 0);
}
