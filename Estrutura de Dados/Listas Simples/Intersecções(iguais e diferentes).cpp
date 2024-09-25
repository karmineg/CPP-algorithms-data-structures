#include<iostream>
using namespace std;
#include "descritor-template.hpp"

bool intMenor(int N, int M) { return N < M; }
bool intMaior(int N, int M) { return N > M; }

void mostraDifD(ListaD<int>* L1, ListaD<int>* L2) {
    // Lógica: #1 realizar a intersecção das listas
    //         #2 eliminar os elementos da intersecção na primeira lista, gerando nova lista
    //         #3 ordenar lista resultante

    ListaD<int> Laux = L1->intersectLista(*L2); // #1
    ListaD<int> Ldif1 = L1->copiaLista();
    ListaD<int> Ldif2 = L2->copiaLista();

    NoD<int>* N = Laux.inicio;
    while(N != NULL) {
        Ldif1.removeVariosVal(N->dado); // #2
        Ldif2.removeVariosVal(N->dado);
        N = N->prox;
    }

    Ldif1.ordenar(intMenor); // #3
    Ldif2.ordenar(intMaior);
    Ldif1.mostrarSimples("Lista de diferentes (que tem em L1 e não em L2)");
    cout << endl;
    Ldif2.mostrarSimples("Lista de diferentes (que tem em L2 e não em L1)");
}

void mostraDifS(ListaS<int>* L1, ListaS<int>* L2) {
    // Lógica: #1 realizar a intersecção das listas
    //         #2 eliminar os elementos da intersecção na primeira lista, gerando nova lista
    //         #3 ordenar lista resultante

    ListaS<int> Laux = L1->intersectLista(*L2); // #1
    ListaS<int> Ldif1 = L1->copiaLista();
    ListaS<int> Ldif2 = L2->copiaLista();

    No<int>* N = Laux.inicio;
    while(N != NULL) {
        Ldif1.removeVariosVal(N->dado); // #2
        Ldif2.removeVariosVal(N->dado);
        N = N->prox;
    }

    Ldif1.ordenar(intMenor); // #3
    Ldif2.ordenar(intMaior);
    Ldif1.mostrarSimples("Lista de diferentes (que tem em L1 e não em L2)");
    cout << endl;
    Ldif2.mostrarSimples("Lista de diferentes (que tem em L2 e não em L1)");
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<int> L1, L2;
            L1.adFim(5);
            L1.adFim(2);
            L1.adFim(3);
            L1.adFim(4);
            L1.adFim(1);
            L1.adFim(9);
            L2.adFim(8);
            L2.adFim(6);
            L2.adFim(7);
            L2.adFim(4);
            L2.adFim(1);
            L2.adFim(5);
            L1.mostrarSimples("Lista 1 Duplamente");
            cout << endl;
            L2.mostrarSimples("Lista 2 Duplamente");
            cout << endl;
            ListaD<int> L3 = L1.intersectLista(L2);
            L3.mostrarSimples("Lista Intersecção");
            cout << endl;
            mostraDifD(&L1, &L2);

            break;
        }

        case 1: {
            ListaS<int> L1, L2;
            L1.adFim(5);
            L1.adFim(2);
            L1.adFim(3);
            L1.adFim(4);
            L1.adFim(1);
            L1.adFim(9);
            L2.adFim(8);
            L2.adFim(6);
            L2.adFim(7);
            L2.adFim(4);
            L2.adFim(1);
            L2.adFim(5);
            L1.mostrarSimples("Lista 1 Simplesmente");
            cout << endl;
            L2.mostrarSimples("Lista 2 Simplesmente");
            cout << endl;
            ListaS<int> L3 = L1.intersectLista(L2);
            L3.mostrarSimples("Lista Intersecção");
            cout << endl;
            mostraDifS(&L1, &L2);

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
