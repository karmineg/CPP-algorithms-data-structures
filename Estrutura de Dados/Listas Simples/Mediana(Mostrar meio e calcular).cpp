#include<iostream>
using namespace std;
#include "descritor-template.hpp"

float mediana(ListaS<float>* L) {
    int n = L->tam;

    No<float> *N = L->inicio;
    for(int i = 0; i < n/2 - 1; i++) {
        N = N->prox;
    }
    if(n % 2 == 0) {
        cout << "\nElementos do meio: " << N->dado << " e " << N->prox->dado;
        cout << "\nMediana: ";
        return (N->dado + N->prox->dado) / 2;
    }
    else {
        cout << "\nElemento do meio: " << N->prox->dado;
        cout << "\nMediana: ";
        return N->prox->dado;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    ListaS<float> L;
    L.adFim(5);
    L.adFim(2);
    L.adFim(3);
    L.adFim(4);
    L.adFim(1);
    L.adFim(9);
    L.mostrarSimples("Lista Simplesmente");
    cout << endl;

    if(L.tam == 0){
        cout << "> Lista VAZIA!";
    }
    else {
        cout << fixed << setprecision(2); // PARA SER EM DUAS CASAS DEPOIS DA VÍRGULA
        cout << mediana(&L);
    }
}
