#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

Pilha<int>* concatenarP(Pilha<int>* P1, Pilha<int>* P2) {
    Pilha<int> *Paux = new Pilha<int>(),
               *P1aux = new Pilha<int>(),
               *P2aux = new Pilha<int>();
    inicializaP(Paux, 20);
    inicializaP(P1aux, 20);
    inicializaP(P2aux, 20);

    while(!vaziaP(P1)) empilhaP(P1aux, desempilhaP(P1));
    while(!vaziaP(P2)) empilhaP(P2aux, desempilhaP(P2));

    while(!vaziaP(P1aux)) {
        int z = desempilhaP(P1aux);
        empilhaP(Paux, z);
        empilhaP(P1, z);
    }
    while(!vaziaP(P2aux)) {
        int z = desempilhaP(P2aux);
        empilhaP(Paux, z);
        empilhaP(P2, z);
    }

    return Paux;
}

Fila<int>* concatenarF(Fila<int>* F1, Fila<int>* F2) {
    Fila<int> *Faux = new Fila<int>(),
              *F1aux = new Fila<int>(),
              *F2aux = new Fila<int>();
    inicializaF(Faux, 20);
    inicializaF(F1aux, 20);
    inicializaF(F2aux, 20);

    while(!vaziaF(F1)) enfileiraF(F1aux, desenfileiraF(F1));
    while(!vaziaF(F2)) enfileiraF(F2aux, desenfileiraF(F2));

    while(!vaziaF(F1aux)) {
        int z = desenfileiraF(F1aux);
        enfileiraF(Faux, z);
        enfileiraF(F1, z);
    }
    while(!vaziaF(F2aux)) {
        int z = desenfileiraF(F2aux);
        enfileiraF(Faux, z);
        enfileiraF(F2, z);
    }
    return Faux;
}

Pilha<int>* concatenar_paresP(Pilha<int>* P1, Pilha<int>* P2) {
    Pilha<int> *Paux = new Pilha<int>(),
               *P1aux = new Pilha<int>(),
               *P2aux = new Pilha<int>();
    inicializaP(Paux, 20);
    inicializaP(P1aux, 20);
    inicializaP(P2aux, 20);

    while(!vaziaP(P1)) empilhaP(P1aux, desempilhaP(P1));
    while(!vaziaP(P2)) empilhaP(P2aux, desempilhaP(P2));

    while(!vaziaP(P1aux)) {
        int z = desempilhaP(P1aux);
        if(z % 2 == 0) empilhaP(Paux, z);
        empilhaP(P1, z);
    }
    while(!vaziaP(P2aux)) {
        int z = desempilhaP(P2aux);
        if(z % 2 == 0) empilhaP(Paux, z);
        empilhaP(P2, z);
    }

    return Paux;
}

Fila<int>* concatenar_paresF(Fila<int>* F1, Fila<int>* F2) {
    Fila<int> *Faux = new Fila<int>(),
              *F1aux = new Fila<int>(),
              *F2aux = new Fila<int>();
    inicializaF(Faux, 20);
    inicializaF(F1aux, 20);
    inicializaF(F2aux, 20);

    while(!vaziaF(F1)) enfileiraF(F1aux, desenfileiraF(F1));
    while(!vaziaF(F2)) enfileiraF(F2aux, desenfileiraF(F2));

    while(!vaziaF(F1aux)) {
        int z = desenfileiraF(F1aux);
        if(z % 2 == 0) enfileiraF(Faux, z);
        enfileiraF(F1, z);
    }
    while(!vaziaF(F2aux)) {
        int z = desenfileiraF(F2aux);
        if(z % 2 == 0) enfileiraF(Faux, z);
        enfileiraF(F2, z);
    }
    return Faux;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P1 = new Pilha<int>;
    inicializaP(P1, 10);
    Fila<int>* F1 = new Fila<int>;
    inicializaF(F1, 10);
    Pilha<int>* P2 = new Pilha<int>;
    inicializaP(P2, 10);
    Fila<int>* F2 = new Fila<int>;
    inicializaF(F2, 10);

    enfileiraF(F1, 0);
    enfileiraF(F1, 2);
    enfileiraF(F1, 9);
    enfileiraF(F1, 3);

    enfileiraF(F2, 7);
    enfileiraF(F2, 3);
    enfileiraF(F2, 8);
    enfileiraF(F2, 5);
    enfileiraF(F2, 6);

    empilhaP(P1, 2);
    empilhaP(P1, 3);
    empilhaP(P1, 4);
    empilhaP(P1, 5);

    empilhaP(P2, 1);
    empilhaP(P2, 2);
    empilhaP(P2, 6);
    empilhaP(P2, 3);

    mostrarSimplesF(F1, "F1");
    cout << endl;
    mostrarSimplesF(F2, "F2");
    cout << endl;
    mostrarSimplesP(P1, "P1");
    cout << endl;
    mostrarSimplesP(P2, "P2");

    Pilha<int>* P3 = new Pilha<int>;
    Pilha<int>* P4 = new Pilha<int>;
    Fila<int>* F3 = new Fila<int>;
    Fila<int>* F4 = new Fila<int>;
    inicializaP(P3, 20);
    inicializaP(P4, 20);
    inicializaF(F3, 20);
    inicializaF(F4, 20);

    P3 = concatenarP(P1, P2);
    F3 = concatenarF(F1, F2);
    P4 = concatenar_paresP(P1, P2);
    F4 = concatenar_paresF(F1, F2);

    cout << endl;
    cout << endl;
    cout << endl;
    mostrarSimplesF(F3, "F3");
    cout << endl;
    mostrarSimplesP(P3, "P3");
    cout << endl;
    mostrarSimplesF(F4, "F4");
    cout << endl;
    mostrarSimplesP(P4, "P4");

    cout << endl << endl;
    mostrarSimplesF(F1, "F1");
    cout << endl;
    mostrarSimplesF(F2, "F2");
    cout << endl;
    mostrarSimplesP(P1, "P1");
    cout << endl;
    mostrarSimplesP(P2, "P2");

}
