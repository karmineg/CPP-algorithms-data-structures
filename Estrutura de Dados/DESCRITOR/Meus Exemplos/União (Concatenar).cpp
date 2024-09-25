#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaS<int> concatenar_pares(ListaS<int> L1, ListaS<int> L2) {
    ListaS<int> Lnew;
    No<int> *N = L1.inicio;

    while(N != NULL) {
        if(N->dado % 2 == 0) {
            Lnew.adFim(N->dado);
        }
        N = N->prox;
    }

    N = L2.inicio;
    while(N != NULL) {
        if(N->dado % 2 == 0) {
            Lnew.adFim(N->dado);
        }
        N = N->prox;
    }
    return Lnew;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int I;

    ListaS<int> L1, L2;
    L1.adFim(5);
    L1.adFim(2);
    L1.adFim(3);
    L1.adFim(4);
    L1.adFim(1);
    L1.adFim(2);
    L1.adFim(9);
    L2.adFim(4);
    L2.adFim(7);
    L2.adFim(10);
    L2.adFim(11);
    L2.adFim(12);
    L2.adFim(13);

    ListaS<int> L3 = L1.unirLista(L2);
    ListaS<int> L4 = concatenar_pares(L1, L2);

    L1.mostrarSimples("Lista 1");
    cout << endl;
    L2.mostrarSimples("Lista 2");
    cout << endl;
    L3.mostrarSimples("Lista concatenada");
    cout << endl;
    L4.mostrarSimples("Lista concatenada apenas pares");

}
