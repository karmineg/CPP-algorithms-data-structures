#include<iostream>
using namespace std;

#include "fila-dinamica.hpp"

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    // **************************
    // ORDENANDO LISTA DE NÚMEROS

    NoF<int> *F = nullptr;

    F = adicionaF(F, 20);
    F = adicionaF(F, 10);
    F = adicionaF(F, 40);
    F = adicionaF(F, 30);
    F = adicionaF(F, 5);
    F = adicionaF(F, 25);
    F = adicionaF(F, 35);
    mostraF(F, "de números (desde INÍCIO)");

    F = ordenaF(F, true);
    mostraF(F, "de números CRESCENTE (desde INÍCIO)");

    F = ordenaF(F, false);
    mostraF(F, "de números DECRESCENTE (desde INÍCIO)");


    // **************************
    // ORDENANDO LISTA DE STRINGS

    NoF<string> *Fs = nullptr;

    string S = "Ricardo";
    Fs = adicionaF(Fs, S);

    S = "Augusto";
    Fs = adicionaF(Fs, S);

    S = "Karmine";
    Fs = adicionaF(Fs, S);

    S = "Geremia";
    Fs = adicionaF(Fs, S);

    cout << "\n=====================================\n";
    mostraF(Fs, "de nomes (desde INÍCIO)");

    Fs = ordenaF(Fs, false);
    mostraF(Fs, "de nomes DECRESCENTE (desde INÍCIO)");
}
