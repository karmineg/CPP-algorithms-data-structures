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

    ListaS<string> L;

    do {
        string C;
        cout << "> Digite um dire��o para avan�ar no labirinto (para finalizar digite 'fim'): ";
        cin >> C;

        C = minusculo(C);
        if(C == "fim") {
            cout << "> Voc� chegou ao fim do labirinto!";
            break;
        }

        else {
            if((C == "cima") or (C == "baixo") or (C == "direita") or (C == "esquerda")) L.adFim(C);
            else cout << "> Dire��o inserida inv�lida!\n";
        }
    }while(true);

    // MOSTRAR IDA
    No<string> *N = L.inicio;
    cout << "\n\nIDA: ";
    while(N != NULL) {
        string dir = N->dado;
        cout << dir << ", ";
        N = N->prox;
    }

    // MOSTRAR VOLTA
    ListaS<string> L2; // Cria uma segunda lista para armazenar as dire��es inversas
    N = L.inicio;
    while(N != NULL) {
        string dir = N->dado;
        if(dir == "cima") L2.adInicio("baixo");
        if(dir == "baixo") L2.adInicio("cima");
        if(dir == "esquerda") L2.adInicio("direita");
        if(dir == "direita") L2.adInicio("esquerda");
        N = N->prox;
    }

    cout << "\n\nVOLTA: ";
    N = L2.inicio;
    while(N != NULL) {
        string dir = N->dado;
        cout << dir << ", ";
        N = N->prox;
    }

}
