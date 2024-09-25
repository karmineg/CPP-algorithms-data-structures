#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"

No<int>* RemoveImpares(No<int>* P) {
    /*No<int>* Paux = nullptr;
    while(P != NULL) {
        if(P->dado % 2 == 0) {
            Paux = adicionaP(Paux, P->dado);
        }
        P = P->prox;
    }
    destroiP(P);
    return Paux;*/

    if(P == NULL) return P; // DE FORMA RECURSIVA
    int valor = P->dado;
    P = removeP(P);
    P = RemoveImpares(P);
    if(valor % 2 == 0) {
        P = adicionaP(P, valor);
    }
    return P;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<int>* P = nullptr;

    P = adicionaP(P, 1);
    P = adicionaP(P, 2);
    P = adicionaP(P, 3);
    P = adicionaP(P, 4);
    P = adicionaP(P, 5);
    P = adicionaP(P, 6);

    mostrarSimplesP(P, "antes da função");

    P = RemoveImpares(P);
    cout << endl;
    mostrarSimplesP(P, "após função");

    P = destroiP(P);

}
