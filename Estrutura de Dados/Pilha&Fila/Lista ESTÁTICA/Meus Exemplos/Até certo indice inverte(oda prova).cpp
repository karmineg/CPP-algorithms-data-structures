#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void TrocaF(Fila<int>* F, int I){
    Fila<int> *Faux = new Fila<int>(),
              *Faux0 = new Fila<int>(),
              *Faux1 = new Fila<int>();
    inicializaF(Faux, F->total);
    inicializaF(Faux0, F->total);
    inicializaF(Faux1, F->total);

    for(int i = 0; i < I; i++) enfileiraF(Faux0, desenfileiraF(F));
    while(!vaziaF(F)) enfileiraF(Faux, desenfileiraF(F));

    int Imax = I - 1;
    while(Imax >= 0) {
        for(int i = 0; i < Imax; i++) enfileiraF(Faux1, desenfileiraF(Faux0));
        enfileiraF(F, desenfileiraF(Faux0));
        Imax--;
        if(Imax == -1) break;

        for(int i = 0; i < Imax; i++) enfileiraF(Faux0, desenfileiraF(Faux1));
        enfileiraF(F, desenfileiraF(Faux1));
        Imax--;
        if(Imax == -1) break;
    }

    while(!vaziaF(Faux)) enfileiraF(F, desenfileiraF(Faux));
}

void TrocaP(Pilha<int>* P, int I){
    Pilha<int> *Paux = new Pilha<int>(),
               *Paux0 = new Pilha<int>();
    int tot = P->topo + 1;
    inicializaP(Paux, tot);
    inicializaP(Paux0, tot);

    while(!vaziaP(P)) empilhaP(Paux, desempilhaP(P));
    for(int i = 0; i < I; i++) empilhaP(Paux0, desempilhaP(Paux));
    while(!vaziaP(Paux0)) empilhaP(P, desempilhaP(Paux0));
    while(!vaziaP(Paux)) empilhaP(P, desempilhaP(Paux));
}

void TrocaPF(Pilha<int>* PF, int I) {
    Fila<int> *Faux = new Fila<int>(),
              *Faux0 = new Fila<int>();
    int tot = PF->topo + 1;
    inicializaF(Faux, tot);
    inicializaF(Faux0, tot);

    for(int i = I; i < tot; i++) enfileiraF(Faux, desempilhaP(PF));
    while(!vaziaP(PF)) enfileiraF(Faux0, desempilhaP(PF));
    while(!vaziaF(Faux0)) empilhaP(PF, desenfileiraF(Faux0));

    int Imax = tot - I - 1;
    while(Imax >= 0) {
        for(int i = 0; i < Imax; i++) enfileiraF(Faux0, desenfileiraF(Faux));
        empilhaP(PF, desenfileiraF(Faux));
        Imax--;
        if(Imax == -1) break;

        for(int i = 0; i < Imax; i++) enfileiraF(Faux, desenfileiraF(Faux0));
        empilhaP(PF, desenfileiraF(Faux0));
        Imax--;
        if(Imax == -1) break;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    Pilha<int>* PF = new Pilha<int>();
    Fila<int>* F = new Fila<int>();
    inicializaP(P, 10);
    inicializaP(PF, 10);
    inicializaF(F, 10);

    enfileiraF(F, 1);
    enfileiraF(F, 2);
    enfileiraF(F, 3);
    enfileiraF(F, 4);
    enfileiraF(F, 5);
    enfileiraF(F, 6);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);
    empilhaP(P, 6);

    empilhaP(PF, 1);
    empilhaP(PF, 2);
    empilhaP(PF, 3);
    empilhaP(PF, 4);
    empilhaP(PF, 5);
    empilhaP(PF, 6);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesP(PF, "");
    cout << endl;
    mostrarSimplesF(F, "");

    int I;
    do {
        cout << "\n> Digite um valor para índice que deseja fazer a troca: ";
        cin >> I;
        if(I < 0) cout << "> O índice insirido para I deve ser maior ou igual a 0!\n\n";
        else if(I > 6) cout << "> O índice insirido para I deve ser menor do que o tamanho da pilha/fila!\n\n";
        else break;
    } while(true);

    TrocaF(F, I);
    TrocaP(P, I);
    TrocaPF(PF, I);
    cout << endl;
    cout << endl;
    mostrarSimplesP(P, "trocada (base -> topo)");
    cout << endl;
    mostrarSimplesP(PF, "F trocada (base -> topo)");
    cout << endl;
    mostrarSimplesF(F, "trocada");
}
