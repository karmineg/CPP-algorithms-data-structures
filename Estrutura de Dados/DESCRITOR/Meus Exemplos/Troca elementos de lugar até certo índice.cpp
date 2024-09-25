#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaS<int> Troca(ListaS<int>* L, int I){
    ListaS<int> Ltrocados;
    No<int> *N = L->inicio;

    for(int i = 0; i <= I; i++) {
        Ltrocados.adFim(N->dado);
        N = N->prox;
    }
    for(int i = 0; i <= I; i++) {
        L->removeInicio();
    }
    ListaS<int> Lnew = L->unirLista(Ltrocados);
    return Lnew;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int I;

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

    do {
        cout << "\n> Digite um valor para índice que deseja fazer a troca: ";
        cin >> I;
        if(I < 0) cout << "> O índice insirido para I deve ser maior ou igual a 0!\n\n";
        else if(I > L.tam - 1) cout << "> O índice insirido para I deve ser menor do que o tamanho da lista!\n\n";
        else break;
    } while(true);

    L = Troca(&L, I);
    cout << endl;
    L.mostrarSimples("Lista Simplesmente após função");

}
