#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaIguaisF(Fila<int> *F1, Fila<int> *F2) {
    if (F1->total != F2->total) {
        cout << "\n> As filas não são iguais!";
        return;
    }

    while (!vaziaF(F1) && !vaziaF(F2)) {
        int x = desenfileiraF(F1);
        int y = desenfileiraF(F2);
        if (x != y) {
            cout << "\n> As filas não são iguais!";
            return;
        }
    }
    cout << "\n> As filas são iguais!";
}

void VerificaIguaisP(Pilha<int> *P1, Pilha<int> *P2) {
    if (P1->topo != P2->topo) {
        cout << "\n> As pilhas não são iguais!";
        return;
    }
    while (!vaziaP(P1) && !vaziaP(P2)) {
        int x = desempilhaP(P1);
        int y = desempilhaP(P2);
        if (x != y) {
            cout << "\n> As pilhas não são iguais!";
            return;
        }
    }
    cout << "\n> As pilhas são iguais!";
}

void VerificaIguaisPF(Fila<int> *F, Pilha<int> *P) { // COMPARAR AQUI DA ERRADO....
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux, 10);

    if (F->total != P->topo + 1) {
        cout << "\n> A fila e a pilha não são iguais!";
        return;
    }

    while(!vaziaP(P)){
        int z = desempilhaP(P);
        empilhaP(Paux, z);
    }

    while(!vaziaP(Paux)){
        int h = desempilhaP(Paux);
        empilhaP(P, h);
    }

    while (!vaziaP(P) && !vaziaF(F)) {
        int x = desempilhaP(P);
        int y = desenfileiraF(F);
        if (x != y) {
            cout << "\n> A fila e a pilha não são iguais!";
            return;
        }
    }
    cout << "\n> A fila e a pilha são iguais!";
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);
    Pilha<int>* P1 = new Pilha<int>();
    inicializaP(P1, 10);
    Fila<int>* F1 = new Fila<int>();
    inicializaF(F1, 10);

    enfileiraF(F, 0);
    enfileiraF(F, 2);
    enfileiraF(F, 9);
    enfileiraF(F, 3);
    enfileiraF(F, 8);
    enfileiraF(F, 7);

    enfileiraF(F1, 0);
    enfileiraF(F1, 2);
    enfileiraF(F1, 9);
    enfileiraF(F1, 3);
    enfileiraF(F1, 8);
    enfileiraF(F1, 5);

    empilhaP(P, 0);
    empilhaP(P, 2);
    empilhaP(P, 9);
    empilhaP(P, 3);
    empilhaP(P, 8);
    empilhaP(P, 7);

    empilhaP(P1, 1);
    empilhaP(P1, 2);
    empilhaP(P1, 2);
    empilhaP(P1, 3);
    empilhaP(P1, 4);
    empilhaP(P1, 5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesP(P1, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    mostrarSimplesF(F1, "");

    VerificaIguaisF(F, F1);
    cout << endl;
    VerificaIguaisP(P, P1);
    cout << endl;
    VerificaIguaisPF(F, P);

}
