/*5. Faça um programa para ler uma string e após empilhar os caracteres que são letras em uma pilha P1 e empilhar
os que são dígitos em outra pilha P2. Ao final, desempilhe os dados de P2 e em seguida, os de P1, imprimindo-os
na tela.
Dicas:
− Use as funções isdigit e isalpha da biblioteca “#include <cctype>”
− A pilha P1 deve armazenar letras. Dessa forma, altere o arquivo “pilha.hpp” para atender esta
necessidade.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

#include "pilhaString.hpp"

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    Pilha P1, P2;

    string C;
    cout << "Digite uma frase: ";
    getline(cin, C);
    int tam = C.length();

    inicializaP(&P1, tam);
    inicializaP(&P2, tam);

    for(int i = 0; i < tam; i++) {
        char elemC = C[i];
        string elem = "";
        elem += elemC;
        if(isalpha(elemC)) {
            empilhaP(&P1, elem);
        }
        if(isdigit(elemC)) {
            empilhaP(&P2, elem);
        }
    }


    mostraP(&P1, "Letras");
    cout << endl;
    mostraP(&P2, "Digitos");
}
