#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);

    enfileiraF(F, 0);
    enfileiraF(F, 2);
    enfileiraF(F, 9);
    enfileiraF(F, 3);
    enfileiraF(F, 8);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 2);
    empilhaP(P, 0);

    mostrarSimplesP(P, "Pilha");
    cout << endl;
    mostrarSimplesF(F, "Filha");

    ordenaF(F, false);
    ordenaP(P, false);
    cout << endl;
    mostrarSimplesF(F,"após a função");
    cout << endl;
    mostrarSimplesP(P,"após a função");

}
