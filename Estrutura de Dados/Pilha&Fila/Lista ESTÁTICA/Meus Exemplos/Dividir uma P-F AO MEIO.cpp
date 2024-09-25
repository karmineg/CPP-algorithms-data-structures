#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void divideFila(Fila<int>* F) {
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 10);
    int meio;
    int tam = F->tam;

    if(tam % 2 != 0) meio = (tam/2 + 0.5);
    else meio = tam/2 - 2;

    for (int i = 0; i < meio; i++) {
        enfileiraF(Faux, desenfileiraF(F));
    }

    mostrarSimplesF(Faux, "dividida parte 1");
    cout << endl;
    mostrarSimples(F, "dividida parte 2");
    cout << endl;
}

void dividePilha(Pilha<int>* P) {
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux, 10);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 10);
    int tam = P->tam;
    int meio;

    if(tam % 2 != 0) meio = (tam/2 + 0.5);
    else meio = tam/2 - 2;

    for (int i = 0; i < meio; i++) {
        empilhaP(Paux, desempilhaP(P));
    }

    while(vaziaP(Paux) == false) {
        empilhaP(Paux2, desempilhaP(Paux));
    }

    mostrarSimplesP(Paux2, "dividida parte 1");
    cout << endl;
    mostrarSimplesP(P, "dividida parte 2");
    cout << endl;
}

void divideFilaPilha(Fila<int>* F) {
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(Paux,10);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 10);
    int meio;
    int tam = F->tam;

    if(tam % 2 != 0) meio = (tam/2 + 0.5);
    else meio = tam/2 - 2;

    for (int i = 0; i < meio; i++) {
        empilhaP(Paux, desenfileiraF(F));
    }

    while(vaziaP(Paux) == false) {
        empilhaP(Paux2, desempilhaP(Paux));
    }

    mostrarSimplesP(Paux2, "dividida parte 1");
    cout << endl;
    mostrarSimplesF(F, "dividida parte 2");
    cout << endl;
}

void dividePilhaFila(Pilha<int>* P) {
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 10);
    int meio;
    int tam = P->tam;

    if(tam % 2 != 0) meio = (tam/2 + 0.5);
    else meio = tam/2 - 2;

    for (int i = 0; i < meio; i++) {
        enfileiraF(Faux, desempilhaP(P));
    }

    mostrarSimplesF(Faux, "dividida parte 1");
    cout << endl;
    mostrarSimplesP(P, "dividida parte 2");
    cout << endl;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);

    enfileiraF(F, 1);
    enfileiraF(F, 2);
    enfileiraF(F, 3);
    enfileiraF(F, 4);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    cout << "Fila e pilha originais:" << endl;
    mostrarSimplesF(F, "de números");
    cout << endl;
    mostrarSimplesP(P, "de números");
    cout << endl;

    /*cout << endl << "Dividindo a fila somente usando filas:" << endl;
    divideFila(F);

    cout << endl << "Dividindo a pilha somente usando pilhas:" << endl;
    dividePilha(P);

    cout << endl << "Dividindo a fila usando pilha auxiliar:" << endl;
    divideFilaPilha(F);*/

    cout << endl << "Dividindo a pilha usando fila auxiliar:" << endl;
    dividePilhaFila(P);

}
