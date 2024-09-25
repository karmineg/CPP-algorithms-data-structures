#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void dividePilhaValor(Pilha<int>* P, int valor) {
    Pilha<int>* P1 = new Pilha<int>();
    Pilha<int>* P2 = new Pilha<int>();
    Pilha<int>* Paux = new Pilha<int>();
    inicializaP(P1, 10);
    inicializaP(Paux, 10);
    inicializaP(P2, 10);
    bool encontrado = false;

    while (!vaziaP(P)) {
        int x = desempilhaP(P);
        if (encontrado) empilhaP(P2, x);
        else {
            if (x == valor) {
                encontrado = true;
                empilhaP(P1, x);
            }
            else empilhaP(P1, x);
        }
    }

    if (encontrado) {
        while (!vaziaP(P1)) {
            int x = desempilhaP(P1);
            empilhaP(P, x);
        }
        while (!vaziaP(P2)) {
            int x = desempilhaP(P2);
            empilhaP(Paux, x);
        }
        cout << endl;
        mostrarSimplesP(P, "Pilha dividida parte 1");
        cout << endl;
        mostrarSimplesP(Paux, "Pilha dividida parte 2");
    }
    else cout << "> Valor não encontrado na pilha, portanto não foi possível a divisão da mesma\n";
}

void divideFilaValor(Fila<int>* F, int valor) {
    Fila<int>* F1 = new Fila<int>();
    Fila<int>* F2 = new Fila<int>();
    inicializaF(F1, 10);
    inicializaF(F2, 10);
    bool encontrado = false;

    while (!vaziaF(F)) {
        int x = desenfileiraF(F);
        if (encontrado)enfileiraF(F2, x);
        else {
            if (x == valor){
                encontrado = true;
                enfileiraF(F1, x);
            }
            else enfileiraF(F1, x);
        }
    }

    if (encontrado) {
        while (!vaziaF(F1)) {
            int x = desenfileiraF(F1);
            enfileiraF(F, x);
        }
        cout << endl;
        mostrarSimplesF(F, "Fila dividida parte 1");
        cout << endl;
        mostrarSimplesF(F2, "Fila dividida parte 2");
    }
    else cout << "> Valor não encontrado na fila, portanto não foi possível a divisão da mesma\n";
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int num;
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 10);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);

    enfileiraF(F, 1);
    enfileiraF(F, 2);
    enfileiraF(F, 3);
    enfileiraF(F, 4);
    enfileiraF(F, 5);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 5);

    cout << "Fila e pilha originais:" << endl;
    mostrarSimplesF(F, "de números");
    cout << endl;
    mostrarSimplesP(P, "de números");

    cout << "\n> Digite um número: ";
    cin >> num;
    cout << endl;
    divideFilaValor(F, num);
    cout << endl;
    dividePilhaValor(P, num);

}
