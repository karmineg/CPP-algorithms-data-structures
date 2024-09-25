#include<iostream>
using namespace std;
#include "descritor-template.hpp"

struct Elemento {
    int dado;
    int freq;
};

void moda(ListaS<int>* L) {
    ListaS<Elemento> Laux;

    No<int> *N = L->inicio;
    while(N != NULL) {
        bool encontrado = false;
        No<Elemento> *M = Laux.inicio;
        while(M != NULL) {
            if(M->dado.dado == N->dado) {
                M->dado.freq++;
                encontrado = true;
                break;
            }
            M = M->prox;
        }
        if(!encontrado) {
            Elemento e;
            e.dado = N->dado;
            e.freq = 1;
            Laux.adFim(e);
        }
        N = N->prox;
    }
    int max_freq = 0;
    No<Elemento> *M = Laux.inicio;
    while(M != NULL) {
        if(M->dado.freq > max_freq) {
            max_freq = M->dado.freq;
        }
        M = M->prox;
    }

    bool todos_iguais = true;
    M = Laux.inicio;
    while(M != NULL) {
        if(M->dado.freq != max_freq) {
            todos_iguais = false;
            break;
        }
        M = M->prox;
    }

    bool nenhum_repete = true;
    M = Laux.inicio;
    while(M != NULL) {
        if(M->dado.freq > 1) {
            nenhum_repete = false;
            break;
        }
        M = M->prox;
    }

    if(todos_iguais) {
        cout << "> Todos os elementos se repetem igualmente." << endl;
    }
    else if(nenhum_repete) {
        cout << "> Nenhum elemento se repete." << endl;
    }
    else {
        cout << "> Os elementos mais repetidos são: ";
        M = Laux.inicio;
        while(M != NULL) {
            if(M->dado.freq == max_freq) {
                cout << M->dado.dado << ", ";
            }
            M = M->prox;
        }
        cout << endl;
        cout << "> Ele(s) se repete(m) " << max_freq << " vezes." << endl;
    }
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
    L.adFim(9);
    L.adFim(2);
    L.adFim(4);
    L.adFim(5);
    L.adFim(2);
    L.mostrarSimples("Lista Simplesmente");
    cout << endl;

    if(L.tam == 0){
        cout << "> Lista VAZIA!";
    }
    else {
        moda(&L);
    }
}
