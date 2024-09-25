#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void convertePilha(int num, Pilha<char> *P) {
    char c;
    num = abs(num);

    while(num > 0) {
        int rest = num % 16;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        empilhaP(P, c);
        num /= 16;
    }
}

void converteFila(int num, Fila<char> *F) {
    char c;
    num = abs(num);
    while(num > 0) {
        int rest = num % 16;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        enfileiraF(F, c);
        num /= 16;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 10);
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 10);

    int num = 1050;

    cout << "> O número decimal é: " << num;
    cout << endl;
    convertePilha(num, P);

    mostraP(P, "hexadecimal");
    cout << endl;

    converteFila(num, F);
    mostrarSimplesF(F, "hexadecimal");

    destroiP(P);
    destroiF(F);

}
