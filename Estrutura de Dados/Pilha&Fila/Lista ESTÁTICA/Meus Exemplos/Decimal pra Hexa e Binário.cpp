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

void converteBinarioP(int num, Pilha<int> *P) {
    num = abs(num);

    while(num >= 2) {
        empilhaP(P, num%2);
        num = num/2;
    }
    empilhaP(P, num);
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
    Pilha<int>* P1 = new Pilha<int>();
    inicializaP(P1, 100);
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 10);

    int num = 367;

    cout << "> O número decimal é: " << num;
    cout << endl;
    convertePilha(num, P);
    converteBinarioP(num, P1);

    mostraP(P, "hexadecimal");
    cout << endl;
    mostrarSimplesP(P1, "binário");
    cout << endl;

    converteFila(num, F);
    mostrarSimplesF(F, "hexadecimal");

    destroiP(P);
    destroiF(F);

}
