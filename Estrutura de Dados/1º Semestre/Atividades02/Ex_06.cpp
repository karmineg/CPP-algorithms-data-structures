/*6. Faça um programa que leia uma string e verifica se o texto é um palíndromo, ou seja, se a string é escrita da
mesma maneira de frente para trás e de trás para frente. Ignore espaços e pontos. Exemplos: Osso, Radar, Ovo,
Arara
Observação: Use uma pilha para realizar a verificação do palíndromo*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

#include "pilhaString.hpp"

main() {
    Pilha P1, P2;

    setlocale(LC_ALL, "Portuguese");
    system ("color F5");
    string texto = "";
    cout << ">> Escreva um texto aqui: ";
    getline(cin, texto);

    int cmp = texto.length();
    // Inicializa duas pilhas com metade do comprimento do texto
    inicializaP(&P1, cmp);
    inicializaP(&P2, cmp);
    int cmp2 = 0;

    for(int i = 0; i < cmp; i++) {//<= cmp/2; i++) {
        // Empilha a primeira metade de caracteres em P1, do início ao meio
        char c1 = texto[i];
        if(isalnum(c1)) {
            cmp2++;
            string C1 = "";
            C1 += c1;
            empilhaP(&P1, C1);
        }

        // Empilha a segunda metade de caracteres em P2, do fim ao meio
        char c2 = texto[cmp - 1 - i];
        if(isalnum(c2)) {
            string C2 = "";
            C2 += c2;
            empilhaP(&P2, C2);
        }
    }

    // R a d a r

    // P1: R a d
    // P2: r a d

    mostraP(&P1, "1");
    cout << endl;
    mostraP(&P2, "2");

    for(int i = cmp2; i > cmp2/2; i--) {
        desempilhaP(&P1);
        desempilhaP(&P2);
    }

    int isPalindr = 1;
    for(int i = cmp2/2; i >= 0; i--) {
        string last1 = desempilhaP(&P1); // Tira o último elemento da pilha 1
        string last2 = desempilhaP(&P2); // ... da pilha 2
        if(tolower(last1[0]) != tolower(last2[0])) {
            isPalindr = 0;
            cout << endl << "Texto inserido NÃO é um palíndromo... :(" << endl;
            break;
        }
        // Se ambos forem iguais, continua o processo
        // Caso contrário, automaticamente se define que o texto NÃO é palíndromo
    }
    if(isPalindr) {
        cout << endl << "Texto inserido É um palíndromo!!!" << endl;
    }
}
