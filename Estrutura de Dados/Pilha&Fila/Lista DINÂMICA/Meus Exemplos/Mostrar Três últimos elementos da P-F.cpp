#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);

    enfileiraF(F, 0);
    enfileiraF(F, 2);
    enfileiraF(F, 9);
    enfileiraF(F, 3);
    enfileiraF(F, 8);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    cout << endl;

    if(F->total < 3) mostrarSimplesF(F, "apenas últimos elementos da fila");
    else {
        for(int i = 0; i < F->total - 3; i++) {
            desenfileiraF(F);
        }
        mostrarSimplesF(F, "três últimos elementos da fila são");
    }

    cout << endl;
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux, 10);

    int tam = P->topo + 1;
    if(tam < 3) mostrarSimplesP(P, "apenas últimos elementos da pilha");
    else {
        while(!vaziaP(P)){
            empilhaP(Paux, desempilhaP(P));
        }

       for(int i = 0; i < tam - 3; i++) {
            desempilhaP(Paux);
        }
        mostrarSimplesP(Paux, "três últimos elementos da fila são");
    }

}
