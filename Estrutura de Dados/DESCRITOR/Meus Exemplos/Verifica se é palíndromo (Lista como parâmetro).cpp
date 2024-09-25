#include<iostream>
using namespace std;
#include "descritor-template.hpp"

void VerificaPalindromo(ListaS<char> *L) {
    if(L->tam == 0) {
        cout << "\n> A lista est� vazia!" ;
        return;
    }

    if(L->tam == 1) {
        cout << "\n> A lista � um pal�ndromo!" ;
        return;
    }

    ListaS<char> aux;
    No<char> *N = L->inicio;
    while(N != NULL) {
        aux.adInicio(N->dado);
        N = N->prox;
    }

    N = L->inicio;
    No<char> *M = aux.inicio;
    while(N != NULL && M != NULL) {
        if(N->dado != M->dado) {
            cout << "\n> A lista n�o � um pal�ndromo!";
            return;
        }
        N = N->prox;
        M = M->prox;
    }
    cout << "\n> A lista � um pal�ndromo!";
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    ListaS<char> L;
    for(int i = 0; i < palavra.size(); i++) {
        L.adFim(palavra[i]);
    }

    VerificaPalindromo(&L);

}
