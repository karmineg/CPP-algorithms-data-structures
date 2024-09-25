#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"
#include"fila-dinamica.hpp"

NoF<int>* TrocaF(NoF<int>* F, int I){
    NoF<int>* Faux = nullptr;
    NoF<int>* Faux0 = nullptr;
    NoF<int>* Faux1 = nullptr;

    for(int i = 0; i < I; i++){
        Faux0 = adicionaF(Faux0, F->dado);
        F = removeF(F);
    }
    while(F != NULL){
        Faux = adicionaF(Faux, F->dado);
        F = removeF(F);
    }

    int Imax = I - 1;
    while(Imax >= 0) {
        for(int i = 0; i < Imax; i++){
            Faux1 = adicionaF(Faux1, Faux0->dado);
            Faux0 = removeF(Faux0);
        }

        F = adicionaF(F, Faux0->dado);
        Faux0 = removeF(Faux0);

        Imax--;
        if(Imax == -1) break;

        for(int i = 0; i < Imax; i++){
            Faux0 = adicionaF(Faux0, Faux1->dado);
            Faux1 = removeF(Faux1);
        }

        F = adicionaF(F, Faux1->dado);
        Faux1 = removeF(Faux1);
        Imax--;
        if(Imax == -1) break;
    }

    while(Faux != NULL){
        F = adicionaF(F, Faux->dado);
        Faux = removeF(Faux);
    }
    return F;
}

No<int>* TrocaP(No<int>* P, int I){
    No<int>* Paux = nullptr;
    No<int>* Paux0 = nullptr;

    while(P != NULL) {
        Paux = adicionaP(Paux, P->dado);
        P = removeP(P);
    }
    for(int i = 0; i < I; i++) {
        Paux0 = adicionaP(Paux0, Paux->dado);
        Paux = removeP(Paux);
    }
    while(Paux0 != NULL) {
        P = adicionaP(P, Paux0->dado);
        Paux0 = removeP(Paux0);
    }
    while(Paux != NULL) {
        P = adicionaP(P, Paux->dado);
        Paux = removeP(Paux);
    }
    return P;
}

No<int>* TrocaPF(No<int>* PF, int I) {
    NoF<int>* Faux = nullptr;
    NoF<int>* Faux0 = nullptr;
    int tot = quantosItens(PF);

    for(int i = I; i < tot; i++) {
        Faux = adicionaF(Faux, PF->dado);
        PF = removeP(PF);
    }

    while(PF != NULL) {
        Faux0 = adicionaF(Faux0, PF->dado);
        PF = removeP(PF);
    }

    while(Faux0 != NULL) {
        PF = adicionaP(PF, Faux0->dado);
        Faux0 = removeF(Faux0);
    }

    int Imax = tot - I - 1;
    while(Imax >= 0) {
        for(int i = 0; i < Imax; i++) {
            Faux0 = adicionaF(Faux0, Faux->dado);
            Faux = removeF(Faux);
        }

        PF = adicionaP(PF, Faux->dado);
        Faux = removeF(Faux);

        Imax--;
        if(Imax == -1) break;

        for(int i = 0; i < Imax; i++) {
            Faux = adicionaF(Faux, Faux0->dado);
            Faux0 = removeF(Faux0);
        }

        PF = adicionaP(PF, Faux0->dado);
        Faux0 = removeF(Faux0);

        Imax--;
        if(Imax == -1) break;
    }
    return PF;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<int>* P = nullptr;
    No<int>* PF = nullptr;
    NoF<int>* F = nullptr;

    F = adicionaF(F, 1);
    F = adicionaF(F, 2);
    F = adicionaF(F, 3);
    F = adicionaF(F, 4);
    F = adicionaF(F, 5);
    F = adicionaF(F, 6);

    P = adicionaP(P, 1);
    P = adicionaP(P, 2);
    P = adicionaP(P, 3);
    P = adicionaP(P, 4);
    P = adicionaP(P, 5);
    P = adicionaP(P, 6);

    PF = adicionaP(PF, 1);
    PF = adicionaP(PF, 2);
    PF = adicionaP(PF, 3);
    PF = adicionaP(PF, 4);
    PF = adicionaP(PF, 5);
    PF = adicionaP(PF, 6);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesP(PF, "");
    cout << endl;
    mostrarSimplesF(F, "");

    int I;
    int qtd = quantosItens(P);
    do {
        cout << "\n> Digite um valor para índice que deseja fazer a troca: ";
        cin >> I;
        if(I < 0) cout << "> O índice insirido para I deve ser maior ou igual a 0!\n\n";
        else if(I > qtd) cout << "> O índice insirido para I deve ser menor do que o tamanho da pilha/fila!\n\n";
        else break;
    } while(true);

    F = TrocaF(F, I);
    P = TrocaP(P, I);
    PF = TrocaPF(PF, I);
    cout << endl;
    cout << endl;
    mostrarSimplesP(P, "trocada");
    cout << endl;
    mostrarSimplesP(PF, "F trocada");
    cout << endl;
    mostrarSimplesF(F, "trocada");
}
