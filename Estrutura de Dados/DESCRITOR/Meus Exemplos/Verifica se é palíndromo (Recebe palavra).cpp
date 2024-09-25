#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void VerificaPalindromo(string palavra) {
    ListaS<char> L;
    for(int i = 0; i < palavra.size(); i++) {
        L.adFim(palavra[i]);
    }

    ListaS<char> aux;
    for(int i = 0; i < palavra.size(); i++) {
        aux.adInicio(palavra[i]);
    }

    No<char> *N1 = L.inicio;
    No<char> *N2 = aux.inicio;
    while(N1 != NULL && N2 != NULL) {
        if(N1->dado != N2->dado) {
            cout << "\n> A palavra " << palavra << " não é um palíndromo!";
            return;
        }
        N1 = N1->prox;
        N2 = N2->prox;
    }
    cout << "\n> A palavra " << palavra << " é um palíndromo!";
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    VerificaPalindromo(palavra);

}
