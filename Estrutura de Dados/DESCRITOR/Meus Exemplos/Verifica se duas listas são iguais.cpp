#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void VerificaIguais(ListaS<int> *L1, ListaS<int> *L2) {
    if(L1->tam != L2->tam) {
        cout << "\n> As listas não são iguais!";
        return;
    }

    No<int> *N1 = L1->inicio;
    No<int> *N2 = L2->inicio;
    while(N1 != NULL && N2 != NULL) {
        if(N1->dado != N2->dado) {
            cout << "\n> As listas não são iguais!";
            return;
        }
        N1 = N1->prox;
        N2 = N2->prox;
    }
    cout << "\n> As listas são iguais!";
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

    L1.mostrarSimples("Lista 1");
    cout << endl;
    L2.mostrarSimples("Lista 2");

    VerificaIguais(&L1, &L2);

}
