#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void TrocaF(Fila<int>* F, int I){
    I++;
    Fila<int> *Faux = new Fila<int>();
    int tot = F->tam;
    inicializaF(Faux, tot);

    for(int i = 0; i < I; i++) enfileiraF(Faux, desenfileiraF(F));
    while(!vaziaF(Faux)) enfileiraF(F, desenfileiraF(Faux));
}

void TrocaP(Pilha<int>* P, int I){
    I++;
    Pilha<int> *Paux = new Pilha<int>(),
               *Paux0 = new Pilha<int>();
    int tot = P->topo + 1;
    inicializaP(Paux, tot);
    inicializaP(Paux0, tot);

    for(int i = I; i < tot; i++) empilhaP(Paux, desempilhaP(P));
    while(!vaziaP(P)) empilhaP(Paux0, desempilhaP(P));

    while(!vaziaP(Paux)) empilhaP(P, desempilhaP(Paux));
    while(!vaziaP(Paux0)) empilhaP(P, desempilhaP(Paux0));
}

void TrocaPF(Pilha<int>* PF, int I) {
    I++;
    Fila<int> *Faux = new Fila<int>(),
              *Faux0 = new Fila<int>();
    int tot = PF->topo + 1;
    inicializaF(Faux, tot);
    inicializaF(Faux0, tot);

    for(int i = I; i < tot; i++) enfileiraF(Faux, desempilhaP(PF));
    while(!vaziaP(PF)) enfileiraF(Faux0, desempilhaP(PF));

    while(!vaziaF(Faux0)) empilhaP(PF, desenfileiraF(Faux0));
    while(!vaziaP(PF)) enfileiraF(Faux0, desempilhaP(PF));

    while(!vaziaF(Faux)) empilhaP(PF, desenfileiraF(Faux));
    while(!vaziaP(PF)) enfileiraF(Faux, desempilhaP(PF));

    while(!vaziaF(Faux)) empilhaP(PF, desenfileiraF(Faux));
    while(!vaziaF(Faux0)) empilhaP(PF, desenfileiraF(Faux0));
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Pilha<int>* PF = new Pilha<int>();
    inicializaP(PF, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);

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

    empilhaP(PF, 9);
    empilhaP(PF, 2);
    empilhaP(PF, 5);
    empilhaP(PF, 3);
    empilhaP(PF, 6);
    empilhaP(PF, 7);

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
        else if(I > 9) cout << "> O índice insirido para I deve ser menor do que o tamanho da pilha/fila!\n\n";
        else break;
    } while(true);

    TrocaF(F, I);
    TrocaP(P, I);
    TrocaPF(PF, I);
    cout << endl;
    cout << endl;
    mostrarSimplesP(P, "trocada");
    cout << endl;
    mostrarSimplesP(PF, "F trocada");
    cout << endl;
    mostrarSimplesF(F, "trocada");
}
