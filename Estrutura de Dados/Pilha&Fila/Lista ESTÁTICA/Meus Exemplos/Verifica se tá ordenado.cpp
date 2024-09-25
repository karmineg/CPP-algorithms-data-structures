#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaCrescenteP(Pilha<int>* P) {
    if (vaziaP(P)) {
        cout << "\n> A pilha está vazia!";
        return;
    }

    if (P->topo == 0) {
        cout << "\n> A pilha está ordenada em crescente!";
        return;
    }

    Pilha<int>* Aux = new Pilha<int>();
    inicializaP(Aux, P->topo + 1);

    int x = desempilhaP(P);
    int z = desempilhaP(P);
    while (!vaziaP(P)) {
        if (x < z) {
            cout << "\n> A pilha não está ordenada em crescente!" << endl;
            return;
        }
        empilhaP(Aux, x);
        x = z;
        z = desempilhaP(P);
    }
    empilhaP(Aux, x);
    empilhaP(Aux, z);
    cout << "\n> A pilha está ordenada em crescente!" << endl;

    while (!vaziaP(Aux)) {
        empilhaP(P, desempilhaP(Aux));
    }
}

void VerificaDecrescenteP(Pilha<int>* P) {
    if (vaziaP(P)) {
        cout << "\n> A pilha está vazia!";
        return;
    }

    if (P->topo == 0) {
        cout << "\n> A pilha está ordenada em decrescente!";
        return;
    }

    Pilha<int>* Aux = new Pilha<int>();
    inicializaP(Aux, P->tam);

    int x = desempilhaP(P);
    int z = desempilhaP(P);
    while (!vaziaP(P)) {
        if (x > z) {
            cout << "\n> A pilha não está ordenada em decrescente!" << endl;
            return;
        }
        empilhaP(Aux, x);
        x = z;
        z = desempilhaP(P);
    }
    empilhaP(Aux, x);
    empilhaP(Aux, z);
    cout << "\n> A pilha está ordenada em decrescente!" << endl;

    while (!vaziaP(Aux)) {
        empilhaP(P, desempilhaP(Aux));
    }
}

void VerificaCrescenteF(Fila<int>* F) {
    if(vaziaF(F)) {
        cout << "\n> A fila está vazia!";
        return;
    }

    if(F->total == 1) {
        cout << "\n> A fila está ordenada em crescente!";
        return;
    }

    int x = desenfileiraF(F);
    int z = desenfileiraF(F);
    while(!vaziaF(F)) {
        if(x > z) {
            cout << "\n> A fila não está ordenada em crescente!" << endl;
            return;
        }
        int x = desenfileiraF(F);
        int z = desenfileiraF(F);
    }
    cout << "\n> A fila está ordenada em crescente!" << endl;

}

void VerificaDecrescenteF(Fila<int>* F) {
    if(vaziaF(F)) {
        cout << "\n> A fila está vazia!";
        return;
    }

    if(F->total == 1) {
        cout << "\n> A fila está ordenada em decrescente!";
        return;
    }

    int x = desenfileiraF(F);
    int z = desenfileiraF(F);
    while(!vaziaF(F)) {
        if(x < z) {
            cout << "\n> A fila não está ordenada em decrescente!" << endl;
            return;
        }
        int x = desenfileiraF(F);
        int z = desenfileiraF(F);
    }
    cout << "\n> A fila está ordenada em decrescente!" << endl;
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
    enfileiraF(F, 3);
    enfileiraF(F, 5);
    enfileiraF(F, 8);
    enfileiraF(F, 9);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    VerificaCrescenteP(P);
    //VerificaDecrescenteP(P);
    //VerificaCrescenteF(F);
    VerificaDecrescenteF(F);
}
