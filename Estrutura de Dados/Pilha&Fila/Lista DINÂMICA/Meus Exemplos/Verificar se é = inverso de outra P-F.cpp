#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaInversoP(Pilha<int>* P1, Pilha<int>* P2) {
    if (P1->topo != P2->topo) {
        cout << "\n> As pilhas não são o inverso uma da outra!";
        return;
    }

    while (!vaziaP(P1) && !vaziaP(P2)) {
        int x = desempilhaP(P1);
        int y = desempilhaP(P2);
        if (x != y) {
            cout << "\n> As pilhas não são o inverso uma da outra!";
            return;
        }
    }
    cout << "\n> As pilhas são o inverso uma da outra!";
}

void VerificaInversoF(Fila<int>* F1, Fila<int>* F2) {
    if (F1->total != F2->total) {
        cout << "\n> As filas não são o inverso uma da outra!";
        return;
    }

    while (!vaziaF(F1) && !vaziaF(F2)) {
        int x = desenfileiraF(F1);
        int y = desenfileiraF(F2);
        if (x != y) {
            cout << "\n> As filas não são o inverso uma da outra!";
            return;
        }
    }
    cout << "\n> As filas são o inverso uma da outra!";
}

void VerificaInversoPF(Pilha<int>* P, Fila<int>* F) {
    if (P->topo + 1 != F->total) {
        cout << "\n> A pilha e a fila não são o inverso uma da outra!";
        return;
    }

    while (!vaziaP(P) && !vaziaF(F)) {
        int x = desempilhaP(P);
        int y = desenfileiraF(F);
        if (x != y) {
            cout << "\n> A pilha e a fila não são o inverso uma da outra!";
            return;
        };
    }
    cout << "\n> A pilha e a fila são o inverso uma da outra!";
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P1 = new Pilha<int>();
    inicializaP(P1, 10);
    Fila<int>* F1 = new Fila<int>();
    inicializaF(F1, 10);
    Pilha<int>* P2 = new Pilha<int>();
    inicializaP(P2, 10);
    Fila<int>* F2 = new Fila<int>();
    inicializaF(F2, 10);

    enfileiraF(F1, 0);
    enfileiraF(F1, 2);
    enfileiraF(F1, 9);
    enfileiraF(F1, 3);
    enfileiraF(F1, 8);
    enfileiraF(F1, 5);

    enfileiraF(F2, 5);
    enfileiraF(F2, 8);
    enfileiraF(F2, 3);
    enfileiraF(F2, 9);
    enfileiraF(F2, 2);
    enfileiraF(F2, 0);

    empilhaP(P1, 1);
    empilhaP(P1, 2);
    empilhaP(P1, 2);
    empilhaP(P1, 3);
    empilhaP(P1, 4);
    empilhaP(P1, 5);

    empilhaP(P2, 5);
    empilhaP(P2, 4);
    empilhaP(P2, 3);
    empilhaP(P2, 2);
    empilhaP(P2, 2);
    empilhaP(P2, 1);

    mostrarSimplesP(P1, "1");
    cout << endl;
    mostrarSimplesF(F1, "1");
    cout << endl;
    mostrarSimplesP(P2, "2");
    cout << endl;
    mostrarSimplesF(F2, "2");
    cout << endl;

    VerificaInversoP(P1, P2);
    cout << endl;
    VerificaInversoF(F1, F2);
    cout << endl;
    VerificaInversoPF(P1, F1);

}
