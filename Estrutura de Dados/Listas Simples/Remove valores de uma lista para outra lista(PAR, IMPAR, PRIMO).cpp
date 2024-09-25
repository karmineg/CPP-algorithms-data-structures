#include<iostream>
using namespace std;
#include "descritor-template.hpp"

bool eh_primo(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

void Divide(ListaS<int>* L) {
    ListaS<int> Lpares;
    ListaS<int> Limpares;
    ListaS<int> Lprimos;

    No<int> *N = L->inicio;
    while(N != NULL) {
        if(N->dado % 2 == 0) Lpares.adFim(N->dado);

        else Limpares.adFim(N->dado);

        if(eh_primo(N->dado)) Lprimos.adFim(N->dado);

        N = N->prox;
    }

    cout << endl;
    Lpares.mostrarSimples("Lista de pares");
    cout << endl;
    Limpares.mostrarSimples("Lista de ímpares");
    cout << endl;
    Lprimos.mostrarSimples("Lista de primos");
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

    Divide(&L);

}
