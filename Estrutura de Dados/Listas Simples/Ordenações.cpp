#include<iostream>
using namespace std;
#include "descritor-template.hpp"

bool intMenor(int N, int M) { return N < M; }
bool intMaior(int N, int M) { return N > M; }

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
    L.ordenar(intMenor);
    L.mostrarSimples("Lista Crescente");

    L.ordenar(intMaior);
    cout << endl;
    L.mostrarSimples("Lista Decrescente");

}
