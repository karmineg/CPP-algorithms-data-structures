#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void divideListaD(ListaD<int>* L){
    ListaD<int> LD;
    NoD<int>* N = L->inicio;
    int tam = L->tam;
    if(tam % 2 != 0) tam = (tam/2 + 0.5); // se tam é IMPAR aumenta 1.5 (por exemplo 5 = 2.5 + 0.5 = 3, apartir do indice 3 vamos dividir ela - 0, 1, 2, 3)
    else tam = tam/2 - 1; // se for PAR divide soma 1 (por exemplo 6 = 3 - 1 = 2, apartir do indice 2 vamos dividir ela - 0, 1, 2)

    for(int i = 0; i <= tam; i++){ // aquilo tudo acima é por causa do <= tam...
        LD.adFim(N->dado);
        L->removeIni();
        N = N->prox;
    }
    cout << endl;
    LD.mostrarSimples("Lista Dividida parte 1");
    cout << endl;
    L->mostrarSimples("Lista Dividida parte 2");
}

void divideListaS(ListaS<int>* L){
    ListaS<int> LS;
    No<int>* N = L->inicio;
    int tam = L->tam;
    if(tam % 2 != 0) tam = (tam/2 + 0.5); // se tam é IMPAR aumenta 1.5 (por exemplo 5 = 2.5 + 0.5 = 3, apartir do indice 3 vamos dividir ela - 0, 1, 2, 3)
    else tam = tam/2 - 1; // se for PAR divide soma 1 (por exemplo 6 = 3 - 1 = 2, apartir do indice 2 vamos dividir ela - 0, 1, 2)

    for(int i = 0; i <= tam; i++){ // aquilo tudo acima é por causa do <= tam...
        LS.adFim(N->dado);
        L->removeIni();
        N = N->prox;
    }
    cout << endl;
    LS.mostrarSimples("Lista Dividida parte 1");
    cout << endl;
    L->mostrarSimples("Lista Dividida parte 2");
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
            divideListaD(&L);

            break;
        }

        case 1: {
            ListaS<int> L;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.mostrarSimples("Lista Simplesmente");
            divideListaS(&L);

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
