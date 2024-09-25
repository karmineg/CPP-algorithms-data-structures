#include<iostream>
using namespace std;
#include "descritor-template.hpp"

bool par(int n) {
    return (n % 2 == 0);
}

ListaD<int>* InverteLD(ListaD<int>* L){
    ListaD<int> LD, Laux1, Laux2;
    NoD<int>* N = L->inicio;
    int tam = L->tam;

    while(N != NULL) {
        if(par(N->dado)) {
            Laux1.adFim(N->dado);
        } else Laux2.adInicio(N->dado);
        N = N->prox;
    }

    N = L->inicio;
    while(N != NULL) {
        if(par(N->dado)) {
            LD.adFim(Laux1.inicio->dado);
            Laux1.removeInicio();
        } else {
            LD.adFim(Laux2.inicio->dado);
            Laux2.removeInicio();
        }
        N = N->prox;
    }

    L->destruir();
    *L = LD.copiaLista();

    return L;
}

ListaS<int>* InverteLS(ListaS<int>* L){
    ListaS<int> LS, Laux1, Laux2;
    No<int>* N = L->inicio;
    int tam = L->tam;

    while(N != NULL) {
        if(par(N->dado)) {
            Laux1.adFim(N->dado);
        } else Laux2.adInicio(N->dado);
        N = N->prox;
    }

    N = L->inicio;
    while(N != NULL) {
        if(par(N->dado)) {
            LS.adFim(Laux1.inicio->dado);
            Laux1.removeInicio();
        } else {
            LS.adFim(Laux2.inicio->dado);
            Laux2.removeInicio();
        }
        N = N->prox;
    }

    L->destruir();
    *L = LS.copiaLista();

    return L;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<int> L;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.adFim(9);
            L.mostrarSimples("Lista Duplamente");

            L = *InverteLD(&L);
            cout << endl;
            L.mostrarSimples("Lista Duplamente após inversão");

            break;
        }

        case 1: {
            ListaS<int> L;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.adFim(9);
            L.mostrarSimples("Lista Simplesmente");

            L = *InverteLS(&L);
            cout << endl;
            L.mostrarSimples("Lista Simplesmente após inversão");

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
