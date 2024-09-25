/*7. Crie um programa para converter n�mero decimais em hexadecimais empregando uma pilha.*/

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

    while (decimal > 0) { // Enquanto houver d�gitos decimais a serem convertidos...
        int rest = decimal % 16; // Obter o resto da divis�o por 16 (um d�gito hexadecimal)
        char c; // Vari�vel para armazenar o d�gito hexadecimal correspondente ao resto
        if (rest < 10) { // Se o resto for menor que 10...
            c = rest + '0'; // Converter o resto em um caractere num�rico de '0' a '9'
        }
        else { // Se n�o...
            c = rest - 10 + 'A'; // Converter o resto em um caractere alfab�tico de 'A' a 'F'
        }
        empilhaP(P, c); // Empilhar o d�gito hexadecimal na pilha
        decimal /= 16; // Dividir o n�mero decimal por 16 e repetir at� que ele se torne zero
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
