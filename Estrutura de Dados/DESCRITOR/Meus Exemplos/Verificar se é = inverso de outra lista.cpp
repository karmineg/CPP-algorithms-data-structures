#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void VerificaInverso(ListaS<int> *L1, ListaS<int> *L2) {
    if(L1->tam != L2->tam) {
        cout << "\n> As listas não são o inverso uma da outra!";
        return;
    }
    ListaS<int> aux;
    No<int> *N = L2->inicio;
    while(N != NULL) {
        aux.adInicio(N->dado);
        N = N->prox;
    }

    N = L1->inicio;
    No<int> *M = aux.inicio;
    while(N != NULL && M != NULL) {
        if(N->dado != M->dado) {
            cout << "\n> As listas não são o inverso uma da outra!";
            return;
        }
        N = N->prox;
        M = M->prox;
    }
    cout << "\n> As listas são o inverso uma da outra!";
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
    L2.adFim(2);
    L2.adFim(1);
    L2.adFim(4);
    L2.adFim(3);
    L2.adFim(2);
    L2.adFim(5);

    L1.mostrarSimples("Lista 1");
    cout << endl;
    L2.mostrarSimples("Lista 2");

    VerificaInverso(&L1, &L2);

}
