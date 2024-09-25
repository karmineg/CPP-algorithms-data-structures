#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

bool eh_primo(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

void DivideF(Fila<int>* F) {
    Fila<int>* Fpar = new Fila<int>;
    inicializaF(Fpar, 10);
    Fila<int>* Fimpar = new Fila<int>;
    inicializaF(Fimpar, 10);
    Fila<int>* Fprimo = new Fila<int>;
    inicializaF(Fprimo, 10);

    while(!vaziaF(F)) {
        int x = desenfileiraF(F);

        if(x % 2 == 0) enfileiraF(Fpar, x);
        else enfileiraF(Fimpar, x);
        if(eh_primo(x)) enfileiraF(Fprimo, x);
    }

    cout << endl;
    mostrarSimplesF(Fpar, "Pares");
    cout << endl;
    mostrarSimplesF(Fimpar, "Ímpares");
    cout << endl;
    mostrarSimplesF(Fprimo, "Primos");
}

void DivideP(Pilha<int>* P) {
    Pilha<int>* Par = new Pilha<int>;
    inicializaP(Par, 10);
    Pilha<int>* Pimpar = new Pilha<int>;
    inicializaP(Pimpar, 10);
    Pilha<int>* Primo = new Pilha<int>;
    inicializaP(Primo, 10);

    while(!vaziaP(P)) {
        int x = desempilhaP(P);

        if(x % 2 == 0) empilhaP(Par, x);
        else empilhaP(Pimpar, x);
        if(eh_primo(x)) empilhaP(Primo, x);
    }

    cout << endl;
    mostrarSimplesP(Par, "Pares");
    cout << endl;
    mostrarSimplesP(Pimpar, "Ímpares");
    cout << endl;
    mostrarSimplesP(Primo, "Primos");
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>;
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>;
    inicializaF(F, 10);

    enfileiraF(F, 0);
    enfileiraF(F, 2);
    enfileiraF(F, 9);
    enfileiraF(F, 3);
    enfileiraF(F, 8);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;

    DivideF(F);
    cout << endl;
    cout << endl;
    DivideP(P);

}
