/*1. Empregando pilha, implemente um programa para inverter a ordem das letras nas palavras em uma frase. Por
exemplo, na frase �teste de pilha�, o programa dever� exibir �etset ed ahlip�.*/

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
        if (c[i] != ' ') { // se o caractere n�o for um espa�o em branco, empilha ele na pilha
            empilhaP(&P, c[i]);
        }
        else { // se o caractere for um espa�o em branco, desempilha os elementos da pilha e imprime eles na tela at� a pilha ficar vazia ou encontrar outro espa�o em branco na frase original
            while (!vaziaP(&P)) {
                cout << desempilhaP(&P);
            }
            cout << " "; // imprime um espa�o em branco ap�s cada palavra invertida
        }
    }
    while (!vaziaP(&P)) { // desempilha os elementos restantes da pilha e imprime eles na tela (�ltima palavra invertida)
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
