#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

bool buscaFila(Fila<int>* F, int valor){
    bool encontrado = false;
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, F->tam);

    while(!vaziaF(F)) {
        int x = desenfileiraF(F);
        if( x == valor) encontrado = true;
        enfileiraF(Faux, x);
    }
    while(!vaziaF(Faux)){
        enfileiraF(F, desenfileiraF(Faux));
    }
    return encontrado;
}

void removeRepetidosF(Fila<int>* F, Fila<int>* aux) {
    while(!vaziaF(F)){
        int N = desenfileiraF(F);
        while(!buscaFila(aux, N)) enfileiraF(aux, N);
    } while(!vaziaF(aux))
        enfileiraF(F, desenfileiraF(aux));
}

bool buscaPilha(Pilha<int>* P, int valor) {
    bool encontrado = false;
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux, P->tam);

    while(!vaziaP(P)) {
        int x = desempilhaP(P);
        if( x == valor) encontrado = true;
        empilhaP(Paux, x);
    }
    while(!vaziaP(Paux)){
        empilhaP(P, desempilhaP(Paux));
    }
    return encontrado;
}

void removeRepetidosP(Pilha<int>* P, Pilha<int>* aux) {
    while(!vaziaP(P)){
        int N = desempilhaP(P);
        if(!buscaPilha(aux, N)) empilhaP(aux, N);
    }
    while(!vaziaP(aux))
        empilhaP(P, desempilhaP(aux));
}

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
    enfileiraF(F, 0);
    enfileiraF(F, 2);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 1);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");

    Pilha<int>* Pr = new Pilha<int>();
    inicializaP(Pr, 10);
    Fila<int>* Fr = new Fila<int>();
    inicializaF(Fr, 10);

    removeRepetidosP(P, Pr);
    removeRepetidosF(F, Fr);
    cout << endl;
    cout << endl;
    mostrarSimplesP(P, "após a função");
    cout << endl;
    mostrarSimplesF(F, "após a função");
}
