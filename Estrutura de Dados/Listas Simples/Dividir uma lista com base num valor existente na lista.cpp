#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaD<int>* divideListaD(ListaD<int>* L, ListaD<int>* LD, int num){
    bool encontrado = false;
    NoD<int>* N = L->inicio;

    while(N != NULL){
        if(encontrado == true){
            LD->adFim(N->dado);
            L->removeUmVal(N->dado);
        }

        if(N->dado == num) {
            if(N->prox == NULL) {
                    cout << "> Valor inserido está na última posição da Lista, portanto não será possível a divisão da mesma\n";
                    return LD;
            }
            else {
                encontrado = true;
            }
        }
        N = N->prox;
    }
    L->mostrarSimples("Lista Duplamente");
    return LD;
}

ListaS<int>* divideListaS(ListaS<int>* L, ListaS<int>* LS, int num){
    bool encontrado = false;
    No<int>* N = L->inicio;

    while(N != NULL){
        if(encontrado == true){
            LS->adFim(N->dado);
            L->removeUmVal(N->dado);
        }

        if(N->dado == num) {
            if(N->prox == NULL) {
                    cout << "> Valor inserido está na última posição da Lista, portanto não será possível a divisão da mesma\n";
                    return LS;
            }
            else {
                encontrado = true;
            }
        }
        N = N->prox;
    }

    L->mostrarSimples("Lista Simplesmente");
    return LS;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu, num;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<int> L, LD;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.adFim(9);
            L.mostrarSimples("Lista Duplamente");
            cout << "\nDigite um número: ";
            cin >> num;
            LD = *divideListaD(&L, &LD, num);
            cout << endl;
            LD.mostrarSimples("Lista dividida");

            break;
        }

        case 1: {
            ListaS<int> L, LS;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.mostrarSimples("Lista Simplesmente");
            cout << "\nDigite um número: ";
            cin >> num;
            LS = *divideListaS(&L, &LS, num);
            cout << endl;
            LS.mostrarSimples("Lista dividida");

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
