/*7. Crie um programa para converter número decimais em hexadecimais empregando uma pilha.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamicaCHAR.hpp"

void decimalToHexadecimal(int decimal, Pilha *P) {

    // 0 1 2 3 4 5 6 7 8 9 A B C D E F

    while (decimal > 0) { // Enquanto houver dígitos decimais a serem convertidos...
        int rest = decimal % 16; // Obter o resto da divisão por 16 (um dígito hexadecimal)
        char c; // Variável para armazenar o dígito hexadecimal correspondente ao resto
        if (rest < 10) { // Se o resto for menor que 10...
            c = rest + '0'; // Converter o resto em um caractere numérico de '0' a '9'
        }
        else { // Se não...
            c = rest - 10 + 'A'; // Converter o resto em um caractere alfabético de 'A' a 'F'
        }
        empilhaP(P, c); // Empilhar o dígito hexadecimal na pilha
        decimal /= 16; // Dividir o número decimal por 16 e repetir até que ele se torne zero
    }
    mostraP(P, "hexadecimal");
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    Pilha P;
    int num;

    cout << "Digite um valor: ";
    cin >> num;
    decimalToHexadecimal(num, &P);
}
