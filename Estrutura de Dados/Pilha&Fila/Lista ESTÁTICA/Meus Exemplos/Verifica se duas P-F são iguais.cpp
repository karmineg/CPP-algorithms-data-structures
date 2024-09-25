#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaIguaisF(Fila<int> *F1, Fila<int> *F2) {

    if (F1->total != F2->total) {
        cout << "\n> As filas não são iguais!";
        return;
    }

    Fila<int> *F1aux = new Fila<int>(),
              *F2aux = new Fila<int>();
    inicializaF(F1aux, 10);
    inicializaF(F2aux, 10);
    bool igual = true;
    while (!vaziaF(F1)) {
        if (espiaF(F1) != espiaF(F2)) {
            igual = false;
            break;
        }
        enfileiraF(F1aux, desenfileiraF(F1));
        enfileiraF(F2aux, desenfileiraF(F2));
    }
    while(!vaziaF(F1)) {
        enfileiraF(F1aux, desenfileiraF(F1));
        enfileiraF(F2aux, desenfileiraF(F2));
    }
    if(igual) cout << "\n> As filas são iguais!";
    else cout << "\n> As filas não são iguais!";

    while(!vaziaF(F1aux)) enfileiraF(F1, desenfileiraF(F1aux));
    while(!vaziaF(F2aux)) enfileiraF(F2, desenfileiraF(F2aux));
}

void VerificaIguaisP(Pilha<int> *P1, Pilha<int> *P2) {

    if (P1->topo != P2->topo) {
        cout << "\n> As pilhas não são iguais!";
        return;
    }

    Pilha<int> *P1aux = new Pilha<int>(),
               *P2aux = new Pilha<int>();
    inicializaP(P1aux, 10);
    inicializaP(P2aux, 10);
    bool igual = true;
    while (!vaziaP(P1)) {
        if (espiaP(P1) != espiaP(P2)) {
            igual = false;
            break;
        }
        empilhaP(P1aux, desempilhaP(P1));
        empilhaP(P2aux, desempilhaP(P2));
    }
    if(igual) cout << "\n> As pilhas são iguais!";
    else cout << "\n> As pilhas não são iguais!";

    while(!vaziaP(P1aux)) empilhaP(P1, desempilhaP(P1aux));
    while(!vaziaP(P2aux)) empilhaP(P2, desempilhaP(P2aux));
}

void VerificaIguaisPF(Fila<int> *F, Pilha<int> *P) {

    if (F->total != P->topo + 1) {
        cout << "\n> A fila e a pilha não são iguais!";
        return;
    }

    Fila<int>* Faux = new Fila<int>();
    Fila<int>* Faux0 = new Fila<int>();
    Pilha<int>* Paux = new Pilha<int>();
    inicializaF(Faux, 10);
    inicializaF(Faux0, 10);
    inicializaP(Paux, 10);

    while(!vaziaP(P)) enfileiraF(Faux, desempilhaP(P));
    while(!vaziaF(Faux)) empilhaP(P, desenfileiraF(Faux));

    bool igual = true;
    while (!vaziaP(P) && !vaziaF(F)) {
        if (espiaP(P) != espiaF(F)) {
            igual = false;
            break;
        }
        enfileiraF(Faux0, desempilhaP(P));
        enfileiraF(Faux, desenfileiraF(F));
    }
    while(!vaziaF(F)) {
        enfileiraF(Faux0, desempilhaP(P));
        enfileiraF(Faux, desenfileiraF(F));
    }
    if(igual) cout << "\n> A fila e a pilha são iguais!";
    else cout << "\n> A fila e a pilha não são iguais!";

    while(!vaziaF(Faux)) enfileiraF(F, desenfileiraF(Faux));
    while(!vaziaF(Faux0)) empilhaP(P, desenfileiraF(Faux0));
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

    /*enfileiraF(F, 1);
    enfileiraF(F, 3);
    enfileiraF(F, 0);

    enfileiraF(F1, 0);
    enfileiraF(F1, 1);
    enfileiraF(F1, 2);

    empilhaP(P, 0);
    empilhaP(P, 3);
    empilhaP(P, 0);

    empilhaP(P1, 5);
    empilhaP(P1, 2);
    empilhaP(P1, 0);*/

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesP(P1, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    mostrarSimplesF(F1, "");

    VerificaIguaisP(P, P1);
    cout << endl;
    VerificaIguaisPF(F, P);
    cout << endl;
    VerificaIguaisF(F, F1);
    cout << endl << endl;

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesP(P1, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    mostrarSimplesF(F1, "");

}
