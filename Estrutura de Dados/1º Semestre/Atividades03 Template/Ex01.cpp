#include<iostream>
using namespace std;

#include "template.hpp"

void Invert(string c) {
    No<char> *P = nullptr;
    for (int i = 0; i < c.length(); i++) {
        if (c[i] != ' ') { // se o caractere n�o for um espa�o em branco, empilha ele na pilha
            P = adicionar(P, c[i]);
        } else { // se o caractere for um espa�o em branco, desempilha os elementos da pilha e imprime eles na tela at� a pilha ficar vazia ou encontrar outro espa�o em branco na frase original
            while(P != NULL) {//!vaziaP(&P)) {
                cout << P->dado;
                P = remover(P);
            } cout << " "; // imprime um espa�o em branco ap�s cada palavra invertida
        }
    }
    while (P != NULL) { // desempilha os elementos restantes da pilha e imprime eles na tela (�ltima palavra invertida)
        cout << P->dado;
        P = remover(P);
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
