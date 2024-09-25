#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

float medianaF(Fila<float>* F) {
    int n = F->total;
    float mediana = 0;
    float meio1 = 0;
    float meio2 = 0;
    Fila<float>* aux = new Fila<float>();
    inicializaF(aux, n);

    for(int i = 0; i < n; i++) {
        enfileiraF(aux, F->dados[F->inicio]);
        desenfileiraF(F);
    }

    for(int i = 0; i < n; i++) {
        if(n % 2 == 0) {
            if(i == n/2 - 1) { meio1 = aux->dados[aux->inicio]; }
            if(i == n/2) { meio2 = aux->dados[aux->inicio]; }
            mediana = ((meio1 + meio2) / 2);
        }
        else {
            if(i == n/2) {
                meio1 = aux->dados[aux->inicio];
                mediana = meio1;
            }
        }
        enfileiraF(F, aux->dados[aux->inicio]);
        desenfileiraF(aux);
    }

    if(n % 2 == 0) {
        cout << "\n\nElementos do meio: " << meio1 << " e " << meio2;
    }
    else {
        cout << "\n\nElemento do meio: " << meio1;
    }

    cout << "\nMediana: ";
    return mediana;
}

float medianaP(Pilha<float>* P) {
    int n = P->topo + 1;
    float mediana = 0;
    float meio1 = 0;
    float meio2 = 0;
    Pilha<float>* aux = new Pilha<float>();
    inicializaP(aux, n);

    for(int i = 0; i < n; i++) {
        empilhaP(aux, P->dados[P->topo]);
        desempilhaP(P);
    }

    for(int i = 0; i < n; i++) {
        if(n % 2 == 0) {
            if(i == n/2 - 1) { meio1 = aux->dados[aux->topo]; }
            if(i == n/2) { meio2 = aux->dados[aux->topo]; }
            mediana = ((meio1 + meio2) / 2);
        }
        else {
            if(i == n/2) {
                meio1 = aux->dados[aux->topo];
                mediana = meio1;
            }
        }
        empilhaP(P, aux->dados[aux->topo]);
        desempilhaP(aux);
    }

    if(n % 2 == 0) { cout << "\n\nElementos do meio: " << meio1 << " e " << meio2; }
    else { cout << "\n\nElemento do meio: " << meio1; }

    cout << "\nMediana: ";
    return mediana;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<float>* P = new Pilha<float>();
    inicializaP(P, 10);
    Fila<float>* F = new Fila<float>();
    inicializaF(F, 10);

    enfileiraF(F, (float)0);
    enfileiraF(F, (float)2);
    enfileiraF(F, (float)9);
    enfileiraF(F, (float)3);
    enfileiraF(F, (float)9);
    enfileiraF(F, (float)8);
    enfileiraF(F, (float)5);
    enfileiraF(F, (float)8);

    empilhaP(P, (float)1);
    empilhaP(P, (float)2);
    empilhaP(P, (float)2);
    empilhaP(P, (float)3);
    empilhaP(P, (float)5);
    empilhaP(P, (float)4);
    empilhaP(P, (float)5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");

    cout << fixed << setprecision(2); // PARA SER EM DUAS CASAS DEPOIS DA VÍRGULA
    cout << medianaP(P) << endl;
    cout << fixed << setprecision(2);
    cout << medianaF(F) << endl;
}
