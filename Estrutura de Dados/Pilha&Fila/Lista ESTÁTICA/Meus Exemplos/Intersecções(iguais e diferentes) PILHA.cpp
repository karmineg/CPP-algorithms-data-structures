#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void copiaP(Pilha<int>* P1, Pilha<int>* P2) {
    int aux, aux2, aux3;
    Pilha<int>* Paux1 = new Pilha<int>();
    inicializaP(Paux1, 20);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 20);

    while(!vaziaP(P1)) {
        aux = desempilhaP(P1);
        empilhaP(P2, aux);
        empilhaP(Paux1, aux);
    }

    while(!vaziaP(Paux1)) {
        aux2 = desempilhaP(Paux1);
        empilhaP(Paux2, aux2);
    }

    while(!vaziaP(Paux2)) {
        aux3 = desempilhaP(Paux2);
        empilhaP(P1, aux3);
    }
}

int pertenceP(int x, Pilha<int>* P) {
    int aux, aux2, aux3;
    int res = 0;
    Pilha<int>* Paux1 = new Pilha<int>();
    inicializaP(Paux1, 20);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 20);

    while(!vaziaP(P)) {
        aux = desempilhaP(P);
        if(aux == x) {
            res = 1;
        }
        empilhaP(Paux1, aux);
    }

    while(!vaziaP(Paux1)) {
        aux2 = desempilhaP(Paux1);
        empilhaP(Paux2, aux2);
    }

    while(!vaziaP(Paux2)) {
        aux3 = desempilhaP(Paux2);
        empilhaP(P, aux3);
    }
    return res;
}

void interseccaoP(Pilha<int>* P1, Pilha<int>* P2, Pilha<int>* P3) {
    int aux, aux2, aux3, aux4;
    Pilha<int>* Paux1 = new Pilha<int>();
    inicializaP(Paux1, 20);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 20);
    Pilha<int>* Paux3 = new Pilha<int>();
    inicializaP(Paux3, 20);
    Pilha<int>* Paux4 = new Pilha<int>();
    inicializaP(Paux4, 20);

    while(!vaziaP(P1)) {
        aux = desempilhaP(P1);
        if(pertenceP(aux, P2)) {
            empilhaP(Paux3, aux);
        }
        empilhaP(Paux1, aux);
    }

    while(!vaziaP(Paux1)) {
        aux2 = desempilhaP(Paux1);
        empilhaP(Paux2, aux2);
    }

    while(!vaziaP(Paux2)) {
        aux3 = desempilhaP(Paux2);
        empilhaP(P1, aux3);
    }

    while(!vaziaP(Paux3)) {
        aux4 = desempilhaP(Paux3);
        empilhaP(P3, aux4);
    }
}

void diferencaP(Pilha<int>* P1, Pilha<int>* P2, Pilha<int>* P3) {
    int aux, aux2, aux3;
    Pilha<int>* Paux1 = new Pilha<int>();
    inicializaP(Paux1, 20);
    Pilha<int>* Paux2 = new Pilha<int>();
    inicializaP(Paux2, 20);

    while(!vaziaP(P1)) {
        aux = desempilhaP(P1);
        if(!pertenceP(aux, P2)) {
            empilhaP(P3, aux);
        }
        empilhaP(Paux1, aux);
    }

    while(!vaziaP(Paux1)) {
        aux = desempilhaP(Paux1);
        empilhaP(Paux2, aux);
    }

    while(!vaziaP(Paux2)) {
        aux = desempilhaP(Paux2);
        empilhaP(P1, aux);
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Pilha<int>* P1 = new Pilha<int>();
    inicializaP(P1, 10);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    empilhaP(P1, 0);
    empilhaP(P1, 2);
    empilhaP(P1, 9);
    empilhaP(P1, 3);
    empilhaP(P1, 7);
    empilhaP(P1, 5);

    Pilha<int>* Pa = new Pilha<int>();
    inicializaP(Pa,10);
    copiaP(P,Pa);
    Pilha<int>* Pa1 = new Pilha<int>();
    inicializaP(Pa1,10);
    copiaP(P1,Pa1);

    Pilha<int>* Pi = new Pilha<int>();
    inicializaP(Pi, 10);
    interseccaoP(Pa,Pa1,Pi);
    mostrarSimplesP(Pi, "Comum");

    Pilha<int>* Pd = new Pilha<int>();
    inicializaP(Pd,10);
    diferencaP(Pa,Pa1,Pd);
    cout << endl;
    mostrarSimplesP(Pd, "Diferentes");

}
