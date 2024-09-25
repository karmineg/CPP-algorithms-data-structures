#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filacircular-template.hpp"
#include "pilha-template.hpp"

main() {
    Fila<char> F;
    No<char> *P = nullptr;

    setlocale(LC_ALL, "Portuguese");
    system ("color F2");
    string texto = "";
    cout << ">> Escreva um texto aqui: ";
    getline(cin, texto);

    int cmp = texto.length();

    inicializaF(&F, cmp);
    for(int i = 0; i < cmp; i++) {
        char c = texto[i];
        if(isalnum(c)) {
            c = tolower(c);
            P = adicionaP(P, c);
            enfileiraF(&F, c);
        }
    }
    cout << endl;
    mostraP(P, "do texto");
    mostraF(&F, "do texto");

    int isPalindr = 1;
    for(int i = cmp; i > 0; i--) {
        if(P->dado == desenfileiraF(&F)) {
            P = removeP(P);
        } else {
            cout << "\n>> Texto inserido NÃO é um palíndromo..." << endl;
            isPalindr = 0;
            break;
        }
    } if(isPalindr) cout << endl << ">> Texto inserido É um palíndromo!!!" << endl;
}

