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
    L.adFim(9);
    L.adFim(2);
    L.adFim(4);
    L.adFim(5);
    L.adFim(2);
    L.mostrarSimples("Lista Simplesmente");
    No<int>* N = L.inicio;
    float num = 0;
    while(N != NULL){
        num = (num + N->dado);
        N = N->prox;
    }
    cout << "\n> Soma dos elementos da lista: " << num << endl;

}
