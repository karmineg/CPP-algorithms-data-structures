#include<iostream>
using namespace std;

#include "pilha-dinamica.hpp"
#include "fila-dinamica.hpp"

bool vogal(char c) {
    char mc = tolower(c);
    return (mc == 'a' || mc == 'e' || mc == 'i' || mc == 'o' || mc == 'u');
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    string texto = "Bergamota";
    // Filas
    NoF<char> *F = nullptr,
              *G = nullptr;
    NoF<int> *J = nullptr;

    // Pilhas
    No<char>* P = nullptr;

    for(int i = 0; i < texto.length(); i++) {
        char C = texto[i];
        if(vogal(C)) {
            G = adicionaF(G, C);
            J = adicionaF(J, i);
        } else P = adicionaP(P, C);
    }

    for(int i = 0; i < texto.length(); i++) {
        if(i == J->dado) {
            cout << G->dado;
            G = removeF(G);
            J = removeF(J);
        } else {
            cout << P->dado;
            P = removeP(P);
        }
    }

    return 0;
}
