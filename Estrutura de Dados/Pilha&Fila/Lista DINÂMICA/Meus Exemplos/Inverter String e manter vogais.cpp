#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

bool vogal(char c) {
    char mc = tolower(c);
    return (mc == 'a' || mc == 'e' || mc == 'i' || mc == 'o' || mc == 'u');
}

void InverteP(Pilha<char>* P){
    Pilha<char>* Paux1 = new Pilha<char>();
    inicializaP(Paux1, P->tam);
    Pilha<char>* Paux2 = new Pilha<char>();
    inicializaP(Paux2, P->tam);
    Pilha<char>* Paux3 = new Pilha<char>();
    inicializaP(Paux3, P->tam);
    Pilha<char>* Paux4 = new Pilha<char>();
    inicializaP(Paux4, P->tam);
    Pilha<char>* Paux5 = new Pilha<char>();
    inicializaP(Paux5, P->tam);
    int tam = P->topo + 1;

    for(int i = 0; i < tam; i++) {
        char x = desempilhaP(P);
        if(vogal(x)) {
            empilhaP(Paux1, x);
            empilhaP(Paux2, char(i));
        } else empilhaP(Paux3, x);
    }

    while(!vaziaP(Paux1)){
        empilhaP(Paux4, desempilhaP(Paux1));
    }

    while(!vaziaP(Paux2)){
        empilhaP(Paux5, desempilhaP(Paux2));
    }

    char y = desempilhaP(Paux5);
    for(int i = 0; i < tam; i++) {
        if(i == y) {
            char z = desempilhaP(Paux4);
            cout << z << ", ";
            y = desempilhaP(Paux5);
        } else {
            char v = desempilhaP(Paux3);
            cout << v << ", ";
        }
    }
}

void InverteF(Fila<char>* F ){
    Fila<char>* Faux1 = new Fila<char>();
    inicializaF(Faux1, F->tam);
    Fila<char>* Faux2 = new Fila<char>();
    inicializaF(Faux2, F->tam);
    Pilha<char>* Paux = new Pilha<char>();
    inicializaP(Paux, F->tam);
    int tam = F->total;

    for(int i = 0; i < tam; i++) {
        char x = desenfileiraF(F);
        if(vogal(x)) {
            enfileiraF(Faux1, x);
            enfileiraF(Faux2, char(i));
        } else empilhaP(Paux, x);
    }

    char y = desenfileiraF(Faux2);
    for(int i = 0; i < tam; i++) {
        if(i == y) {
            char z = desenfileiraF(Faux1);
            cout << z << ", ";
            y = desenfileiraF(Faux2);
        } else {
            char v = desempilhaP(Paux);
            cout << v << ", ";
        }
    }
}

void InvertePF(Pilha<char>* P) {
    Fila<char>* FA = new Fila<char>();
    inicializaF(FA, P->tam);
    Fila<char>* FB = new Fila<char>();
    inicializaF(FB, P->tam);
    Fila<char>* FC = new Fila<char>();
    inicializaF(FC, P->tam);

    int tam = P->topo + 1;
    for(int i = 0; i < tam; i++) {
        char x = desempilhaP(P);
        if(vogal(x)) {
            enfileiraF(FA, x);
            enfileiraF(FB, char(i));
        } else enfileiraF(FC, x);
    }

    while(!vaziaF(FC)){
        empilhaP(P, desenfileiraF(FC));
    }

    char z = desenfileiraF(FB);
    for(int i = 0; i < tam; i++) {
        if(i == z) {
            char y = desenfileiraF(FA);
            cout << y << ", ";
            z = desenfileiraF(FB);
        } else {
            char v = desempilhaP(P);
            cout << v << ", ";
        }
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 10);
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 10);
    Pilha<char>* P2 = new Pilha<char>();
    inicializaP(P2, 10);

    string C, expr;
    cout << "> Insira um string: ";
    cin >> C;
    for (int i = 0; i < C.length(); i++) {
        char S = C[i];
        empilhaP(P, S);
        empilhaP(P2, S);
        enfileiraF(F, S);
    }

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
