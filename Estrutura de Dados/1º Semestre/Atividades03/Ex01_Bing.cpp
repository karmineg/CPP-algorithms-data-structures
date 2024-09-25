/*1. Empregando pilha, implemente um programa para inverter a ordem das letras nas palavras em uma frase. Por
exemplo, na frase “teste de pilha”, o programa deverá exibir “etset ed ahlip”.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamicaCHAR.hpp"

void Invert(string c) {
    Pilha P;
    for (int i = 0; i < c.length(); i++) {
        if (c[i] != ' ') { // se o caractere não for um espaço em branco, empilha ele na pilha
            empilhaP(&P, c[i]);
        }
        else { // se o caractere for um espaço em branco, desempilha os elementos da pilha e imprime eles na tela até a pilha ficar vazia ou encontrar outro espaço em branco na frase original
            while (!vaziaP(&P)) {
                cout << desempilhaP(&P);
            }
            cout << " "; // imprime um espaço em branco após cada palavra invertida
        }
    }
    while (!vaziaP(&P)) { // desempilha os elementos restantes da pilha e imprime eles na tela (última palavra invertida)
        cout << desempilhaP(&P);
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");

    string text;

    cout << "Digite um texto: ";
    getline(cin, text);
    Invert(text);

}
