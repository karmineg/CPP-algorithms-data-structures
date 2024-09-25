#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

bool par(int n) {
    return (n % 2 == 0);
}

void InverteP(Pilha<int>* P){
    Pilha<int>* Paux1 = new Pilha<int>();
    inicializaP(Paux1, P->tam);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, P->tam);
    Pilha<int>* Paux3 = new Pilha<int>();
    inicializaP(Paux3, P->tam);
    Pilha<int>* Paux4 = new Pilha<int>();
    inicializaP(Paux4, P->tam);
    Pilha<int>* Paux5 = new Pilha<int>();
    inicializaP(Paux5, P->tam);
    int tam = P->topo + 1;

    for(int i = 0; i < tam; i++) {
        int x = desempilhaP(P);
        if(par(x)) {
            empilhaP(Paux1, x);
            empilhaP(Paux2, i);
        } else empilhaP(Paux3, x);
    }

    while(!vaziaP(Paux1)){
        empilhaP(Paux4, desempilhaP(Paux1));
    }

    while(!vaziaP(Paux2)){
        empilhaP(Paux5, desempilhaP(Paux2));
    }

    int y = desempilhaP(Paux5);
    for(int i = 0; i < tam; i++) {
        if(i == y) {
            int z = desempilhaP(Paux4);
            cout << z << ", ";
            y = desempilhaP(Paux5);
        } else {
            int v = desempilhaP(Paux3);
            cout << v << ", ";
        }
    }
}

void InverteF(Fila<int>* F ){
    Fila<int>* Faux1 = new Fila<int>();
    inicializaF(Faux1, F->tam);
    Fila<int>* Faux2 = new Fila<int>();
    inicializaF(Faux2, F->tam);
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux, F->tam);
    int tam = F->total;

    for(int i = 0; i < tam; i++) {
        int x = desenfileiraF(F);
        if(par(x)) {
            enfileiraF(Faux1, x);
            enfileiraF(Faux2, i);
        } else empilhaP(Paux, x);
    }

    int y = desenfileiraF(Faux2);
    for(int i = 0; i < tam; i++) {
        if(i == y) {
            int z = desenfileiraF(Faux1);
            cout << z << ", ";
            y = desenfileiraF(Faux2);
        } else {
            int v = desempilhaP(Paux);
            cout << v << ", ";
        }
    }
}

void InvertePF(Pilha<int>* P) {
    Fila<int>* FA = new Fila<int>();
    inicializaF(FA, P->tam);
    Fila<int>* FB = new Fila<int>();
    inicializaF(FB, P->tam);
    Fila<int>* FC = new Fila<int>();
    inicializaF(FC, P->tam);

    int tam = P->topo + 1;
    for(int i = 0; i < tam; i++) {
        int x = desempilhaP(P);
        if(par(x)) {
            enfileiraF(FA, x);
            enfileiraF(FB, i);
        } else enfileiraF(FC, x);
    }

    while(!vaziaF(FC)){
        empilhaP(P, desenfileiraF(FC));
    }

    int z = desenfileiraF(FB);
    for(int i = 0; i < tam; i++) {
        if(i == z) {
            int y = desenfileiraF(FA);
            cout << y << ", ";
            z = desenfileiraF(FB);
        } else {
            int v = desempilhaP(P);
            cout << v << ", ";
        }
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);
    Pilha<int>* P2 = new Pilha<int>();
    inicializaP(P2, 10);

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

    empilhaP(P2, 1);
    empilhaP(P2, 2);
    empilhaP(P2, 2);
    empilhaP(P2, 3);
    empilhaP(P2, 4);
    empilhaP(P2, 5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    mostrarSimplesP(P2, "");
    cout << endl;

    cout << "\nPilha após a função: ";
    InverteP(P);
    cout << "\nFila após a função: ";
    InverteF(F);
    cout << "\nPilhaF após a função: ";
    InvertePF(P2);

}
