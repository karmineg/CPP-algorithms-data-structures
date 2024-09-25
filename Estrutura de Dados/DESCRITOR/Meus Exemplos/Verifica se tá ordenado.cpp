#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void VerificaCrescente(ListaS<int> *L) {
    if(L->tam == 0) {
        cout << "\n> A lista está vazia!";
        return;
    }

    if(L->tam == 1) {
        cout << "\n> A lista está ordenada em crescente!";
        return;
    }

    No<int> *N = L->inicio;
    while(N->prox != NULL) {
        if(N->dado > N->prox->dado) {
            cout << "\n> A lista não está ordenada em crescente!";
            return;
        }
        N = N->prox;
    }
    cout << "\n>A lista está ordenada em crescente.";
}

void VerificaDecrescente(ListaS<int> *L) {
    if(L->tam == 0) {
        cout << "\n> A lista está vazia!";
        return;
    }

    if(L->tam == 1) {
        cout << "\n> A lista está ordenada em decrescente!";
        return;
    }

    No<int> *N = L->inicio;
    while(N->prox != NULL) {
        if(N->dado < N->prox->dado) {
            cout << "\n> A lista não está ordenada em decrescente!" << endl;
            return;
        }
        N = N->prox;
    }
    cout << "\n> A lista está ordenada em decrescente!" << endl;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    ListaS<int> L1, L2;
    L1.adFim(5);
    L1.adFim(2);
    L1.adFim(3);
    L1.adFim(4);
    L1.adFim(1);
    L1.adFim(2);
    L1.adFim(9);
    L2.adFim(9);
    L2.adFim(7);
    L2.adFim(5);
    L2.adFim(4);
    L2.adFim(3);
    L2.adFim(2);
    L2.adFim(1);

    L1.mostrarSimples("Lista 1");
    VerificaCrescente(&L1);

    cout << endl;
    L2.mostrarSimples("Lista 2");
    VerificaDecrescente(&L2);

}
