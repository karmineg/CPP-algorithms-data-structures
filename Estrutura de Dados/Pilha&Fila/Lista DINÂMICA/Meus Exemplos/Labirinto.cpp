#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<string>* P = new Pilha<string>;
    inicializaP(P, 10);
    Fila<string>* F = new Fila<string>;
    inicializaF(F, 10);

    string C;
    cout << "> Digite um direção para avançar no labirinto (para finalizar digite 'fim'): ";
    cin >> C;

    for (int i = 0; i < C.length(); i++) {
        C[i] = tolower(C[i]);
    }

    while (C != "fim") {
        if((C == "cima") or (C == "baixo") or (C == "direita") or (C == "esquerda")){
            empilhaP(P, C);
            enfileiraF(F, C);
        }
        else cout << "> Direção inserida inválida!\n";

        cout << "> Digite um direção para avançar no labirinto (para finalizar digite 'fim'): ";
        cin >> C;

        for (int i = 0; i < C.length(); i++) {
            C[i] = tolower(C[i]);
        }
    }

    cout << "\n> Você chegou ao fim do labirinto!";

    cout << "\n\nIDA USANDO A PILHA: ";
    mostrarSimplesP(P, "");

    cout << "\n\nVOLTA USANDO A PILHA: ";
    Pilha<string>* PAux = new Pilha<string>;
    inicializaP(PAux, P->tam);

    while (!vaziaP(P)) {
        string dir = desempilhaP(P);
        if(dir == "cima") {
            string conv = "baixo";
            empilhaP(PAux, conv);
        }
        if(dir == "baixo") {
            string conv = "cima";
            empilhaP(PAux, conv);
        }
        if(dir == "esquerda") {
            string conv = "direita";
            empilhaP(PAux, conv);
        }
        if(dir == "direita") {
            string conv = "esquerda";
            empilhaP(PAux, conv);
        }
    }

    mostrarSimplesP(PAux, "");

    cout << endl;
    cout << "\n\nIDA USANDO A FILA: ";
    mostrarSimplesF(F, "");

    cout << "\n\nVOLTA USANDO A FILA: ";
    Fila<string>* FAux = new Fila<string>;
    inicializaF(FAux, F->tam);

    while (!vaziaF(F)) {
        string dir = desenfileiraF(F);
        if(dir == "cima") {
            string conv = "baixo";
            enfileiraF(FAux, conv);
        }
        if(dir == "baixo") {
            string conv = "cima";
            enfileiraF(FAux, conv);
        }
        if(dir == "esquerda") {
            string conv = "direita";
            enfileiraF(FAux, conv);
        }
        if(dir == "direita") {
            string conv = "esquerda";
            enfileiraF(FAux, conv);
        }
    }

    mostrarSimplesF(FAux, "");

}
