#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"

main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha<string>* P = new Pilha<string>();
    inicializaP(P, 10); // Inicia pilha com vetor de 10 elementos


    // Adicionando strings na pilha
    string S = "Ricardo";
    empilhaP(P, S);

    S = "Augusto";
    empilhaP(P, S);

    S = "Müller";
    empilhaP(P, S);

    S = "Germani";
    empilhaP(P, S);

    S = "Karmine";
    empilhaP(P, S);

    S = "Geremia";
    empilhaP(P, S);
    mostraP(P, "de nomes");

    ordenaP(P, true); // Organiza nomes em ordem CRESCENTE
    cout << endl;
    mostraP(P, "de nomes em ordem CRESCENTE (desde a base)");

    ordenaP(P, false); // Organiza nomes em ordem DESCRESCENTE
    cout << endl;
    mostraP(P, "de nomes em ordem DECRESCENTE (desde a base)");

    return 0;
}
