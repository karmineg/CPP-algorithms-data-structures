#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void VerificaPalindromoF(Fila<char>* F) {
    Fila<char>* Aux = new Fila<char>();
    inicializaF(Aux, F->tam);

    string palavra = "";
    string inversa = "";

    while (!vaziaF(F)) {
        char c = desenfileiraF(F);
        palavra += c;
        inversa = c + inversa;
        enfileiraF(Aux, c);
    }

    while (!vaziaF(Aux)) {
        enfileiraF(F, desenfileiraF(Aux));
    }

    if (palavra == inversa) {
        cout << "\n> A palavra " << palavra << " é um palíndromo!" << endl;
    }
    else {
        cout << "\n> A palavra " << palavra << " não é um palíndromo!" << endl;
    }
}

void VerificaPalindromoP(Pilha<char>* P) {
    Pilha<char>* Aux = new Pilha<char>();
    inicializaP(Aux, P->tam);

    string palavra = "";
    string inversa = "";

    while (!vaziaP(P)) {
        char c = desempilhaP(P);
        palavra = c + palavra;
        inversa += c;
        empilhaP(Aux, c);
    }

    while (!vaziaP(Aux)) {
        empilhaP(P, desempilhaP(Aux));
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
    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 10);
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 10);
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    for(int i = 0; i < palavra.size(); i++) {
        enfileiraF(F, palavra[i]);
        empilhaP(P, palavra[i]);
    }

    VerificaPalindromoF(F);
    VerificaPalindromoP(P);

}
