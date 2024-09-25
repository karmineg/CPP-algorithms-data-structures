#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaS<int>* Repeticoes(ListaS<int>* L){
    ListaS<int> Lrepetidos;
    No<int> *N = L->inicio;

    while(N != NULL) {
        int cont = 0;
        No<int> *M = L->inicio;
        while(M != NULL) {
            if(M->dado == N->dado) {
                cont++;
            }
            M = M->prox;
        }
        if(cont > 1) {
            Lrepetidos.adFim(N->dado);
        }
        N = N->prox;
    }
    cout << endl;
    Lrepetidos.mostrarSimples("Elementos que se repetem");

    No<int> *R = Lrepetidos.inicio;
    while(R != NULL) {
        L->removeVariosVal(R->dado);
        R = R->prox;
    }
    return L;
}

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

    L = *Repeticoes(&L);
    cout << endl;
    L.mostrarSimples("Lista Simplesmente após função");

}
