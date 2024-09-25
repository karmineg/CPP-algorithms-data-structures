#include<iostream>
using namespace std;
#include "descritor-template.hpp"

string minusculo(string C) {
    string res = "";
    for(int i = 0; i < C.length(); i++) res += tolower(C[i]);
    return res;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    ListaD<string> L;

    do {
        string C;
        cout << "> Digite um direção para avançar no labirinto (para finalizar digite 'fim'): ";
        cin >> C;

        C = minusculo(C);
        if(C == "fim") {
            cout << "> Você chegou ao fim do labirinto!";
            break;
        }

        else {
            if((C == "cima") or (C == "baixo") or (C == "direita") or (C == "esquerda")) L.adFim(C);
            else cout << "> Direção inserida inválida!\n";
        }
    }while(true);

    // MOSTRAR IDA
    NoD<string> *N = L.inicio;
    cout << "\n\nIDA: ";
    while(N != NULL) {
        string dir = N->dado;
        cout << dir << ", ";
        N = N->prox;
    }

    // MOSTRAR VOLTA
    N = L.fim;
    cout << "\n\nVOLTA: ";
    while(N != NULL) {
        string dir = N->dado;
        if(dir == "cima") cout << "baixo, ";
        if(dir == "baixo") cout << "cima, ";
        if(dir == "esquerda") cout << "direita, ";
        if(dir == "direita") cout << "esquerda, ";
        N = N->ant;
    }

}

