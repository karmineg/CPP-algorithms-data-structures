#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaIguaisF(Fila<int> *F1, Fila<int> *F2) {

    if (F1->total != F2->total) {
        cout << "\n> As filas NÃO são INVERSOS uma da outra!";
        return;
    }

    Fila<int> *F1aux = new Fila<int>();
    Pilha<int> *P2aux = new Pilha<int>();
    Pilha<int> *P2aux0 = new Pilha<int>();
    inicializaF(F1aux, 10);
    inicializaP(P2aux, 10);
    inicializaP(P2aux0, 10);

    while(!vaziaF(F2)) empilhaP(P2aux, desenfileiraF(F2));

    bool igual = true;
    while (!vaziaF(F1)) {
        if (espiaF(F1) != espiaP(P2aux)) {
            igual = false;
            break;
        }
        enfileiraF(F1aux, desenfileiraF(F1));
        empilhaP(P2aux0, desempilhaP(P2aux));
    }
    while(!vaziaF(F1)) {
        enfileiraF(F1aux, desenfileiraF(F1));
        empilhaP(P2aux0, desempilhaP(P2aux));
    }
    if(igual) cout << "\n> As filas SÃO INVERSOS uma da outra!";
    else cout << "\n> As filas NÃO são INVERSOS uma da outra!";

    while(!vaziaF(F1aux)) enfileiraF(F1, desenfileiraF(F1aux));
    while(!vaziaP(P2aux0)) enfileiraF(F2, desempilhaP(P2aux0));
}

void VerificaIguaisP(Pilha<int> *P1, Pilha<int> *P2) {

    Pilha<int> *P1aux = new Pilha<int>(),
               *P2aux = new Pilha<int>();
    inicializaP(P1aux, 10);
    inicializaP(P2aux, 10);

    if (P1->topo != P2->topo) {
        cout << "\n> As pilhas NÃO SÃO o inverso uma da outra!";
        return;
    }

    while(!vaziaP(P2)) empilhaP(P2aux, desempilhaP(P2));

    bool igual = true;
    while (!vaziaP(P1)) {
        if (espiaP(P1) != espiaP(P2aux)) {
            igual = false;
            break;
        }
        empilhaP(P1aux, desempilhaP(P1));
        empilhaP(P2, desempilhaP(P2aux));
    }

    if(igual) cout << "\n> As pilhas SÃO O INVERSO uma da outra!";
    else cout << "\n> As pilhas NÃO SÃO o inverso uma da outra!";

    while(!vaziaP(P1aux)) empilhaP(P1, desempilhaP(P1aux));
    while(!vaziaP(P2aux)) empilhaP(P2, desempilhaP(P2aux));
}

void VerificaIguaisPF(Fila<int> *F, Pilha<int> *P) { // COMPARAR AQUI DA ERRADO....

    if (P->topo + 1 != F->total) {
        cout << "\n> A pilha e a fila NÃO são o inverso uma da outra!";
        return;
    }

    Fila<int> *Faux = new Fila<int>();
    Pilha<int> *Paux = new Pilha<int>();
    inicializaF(Faux, 10);
    inicializaP(Paux, 10);

    bool igual = true;
    while (!vaziaP(P) && !vaziaF(F)) {
        if (espiaP(P) != espiaF(F)) {
            igual = false;
            break;
        };
        empilhaP(Paux, desempilhaP(P));
        enfileiraF(Faux, desenfileiraF(F));
    }
    while(!vaziaF(F)) enfileiraF(Faux, desenfileiraF(F));

    if(igual) cout << "\n> A pilha e a fila SÃO O INVERSO uma da outra!";
    else cout << "\n> A pilha e a fila NÃO são o inverso uma da outra!";

    while(!vaziaF(Faux)) enfileiraF(F, desenfileiraF(Faux));
    while(!vaziaP(Paux)) empilhaP(P, desempilhaP(Paux));
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P1 = new Pilha<int>();
    Fila<int>* F1 = new Fila<int>();
    Pilha<int>* P2 = new Pilha<int>();
    Fila<int>* F2 = new Fila<int>();
    inicializaP(P1, 10);
    inicializaF(F1, 10);
    inicializaP(P2, 10);
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

    mostrarSimplesP(P1, "P1");
    cout << endl;
    mostrarSimplesP(P2, "P2");
    cout << endl;
    mostrarSimplesF(F1, "F1");
    cout << endl;
    mostrarSimplesF(F2, "F2");

    VerificaIguaisP(P1, P2);
    cout << endl;
    VerificaIguaisPF(F1, P1);
    cout << endl;
    VerificaIguaisF(F1, F2);
    cout << endl << endl;

    mostrarSimplesP(P1, "P1");
    cout << endl;
    mostrarSimplesP(P2, "P2");
    cout << endl;
    mostrarSimplesF(F1, "F1");
    cout << endl;
    mostrarSimplesF(F2, "F2");

}
