#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaS<int>* RemoverRepetidos(ListaS<int>* L){
    if(L->inicio == NULL || L->inicio->prox == NULL){
        return L;
    }
    No<int> *aux = L->inicio;
    while(aux != NULL){
        No<int> *comp = aux->prox;
        while(comp != NULL){
            if(aux->dado == comp->dado){
                L->removeUmVal(aux->dado);
                break;
            }
            comp = comp->prox;
        }
        aux = aux->prox;
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
    L.adFim(5);
    L.mostrarSimples("Lista Simplesmente");

    L = *RemoverRepetidos(&L);
    cout << endl;
    L.mostrarSimples("Lista Simplesmente após função");

}
