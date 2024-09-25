#include<iostream>
using namespace std;
#include "descritor-template.hpp"

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    ListaS<int> L;
    L.adFim(5);
    L.adFim(2);
    L.adFim(3);
    L.adFim(4);
    L.adFim(1);
    L.adFim(2);
    L.adFim(9);
    L.adFim(4);
    L.mostrarSimples("Lista Simplesmente");
    cout << endl;

    if(L.tam < 3) L.mostrarSimples("Apenas últimos elementos da lista");
    else {
        No<int> *N = L.inicio;
        for(int i = 0; i < L.tam - 3; i++) {
            N = N->prox;
        }
        cout << "> Os três últimos elementos da lista são: ";
        while(N != NULL) {
            cout << N->dado << ", ";
            N = N->prox;
        }
        cout << endl;
    }

}
