#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaPalindromoF(string palavra) {
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 10);

    for (int i = 0; i < palavra.size(); i++) {
        enfileiraF(F, palavra[i]);
    }

    string inversa = "";
    while (!vaziaF(F)) {
        inversa += desenfileiraF(F);
    }

    if (palavra == inversa) {
        cout << "\n> A palavra " << palavra << " é um palíndromo!" << endl;
    }
    else {
        cout << "\n> A palavra " << palavra << " não é um palíndromo!" << endl;
    }
}

void VerificaPalindromoP(string palavra) {
    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 10);

    for (int i = 0; i < palavra.size(); i++) {
        empilhaP(P, palavra[i]);
    }

    string inversa = "";
    while (!vaziaP(P)) {
        inversa += desempilhaP(P);
    }

    if (palavra == inversa) {
        cout << "\n> A palavra " << palavra << " é um palíndromo!" << endl;
    }
    else {
        cout << "\n> A palavra " << palavra << " não é um palíndromo!" << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    VerificaPalindromoF(palavra);
    VerificaPalindromoP(palavra);

}
