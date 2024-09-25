#include<iostream>
using namespace std;

#include "pilha-dinamica.hpp"

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    // **************************
    // ORDENANDO LISTA DE NÚMEROS

    No<int> *P = nullptr;

    P = adicionaP(P, 20);
    P = adicionaP(P, 10);
    P = adicionaP(P, 40);
    P = adicionaP(P, 30);
    mostraP(P, "de números (TOPO para BASE)");

    P = ordenaP(P, true);
    mostraP(P, "de números CRESCENTE (TOPO para BASE)");

    P = ordenaP(P, false);
    mostraP(P, "de números DECRESCENTE (TOPO para BASE)");


    // **************************
    // ORDENANDO LISTA DE STRINGS

    No<string> *Ps = nullptr;

    string S = "Ricardo";
    Ps = adicionaP(Ps, S);

    S = "Augusto";
    Ps = adicionaP(Ps, S);

    S = "Karmine";
    Ps = adicionaP(Ps, S);

    S = "Geremia";
    Ps = adicionaP(Ps, S);

    cout << "\n=====================================\n";
    mostraP(Ps, "de nomes (TOPO para BASE)");

    Ps = ordenaP(Ps, true);
    mostraP(Ps, "de nomes CRESCENTE (desde TOPO)");
}
