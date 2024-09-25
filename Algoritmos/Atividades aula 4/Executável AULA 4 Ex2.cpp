/* 2 – Escreva um programa que receba um número inteiro N qualquer, de tal forma que
N > 0 e N < 9999, validar para aceitar número no intervalo definido.
Se o valor informado for válido, apresentar uma mensagem indicando se o número é uma dezena, uma
centena ou um milhar */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num;

    cout << "Informe um número inteiro: ";
    cin >> (num);

    if((num > 0) and (num < 99))
        cout << "O número é uma dezena.";

    if ((num > 100) and (num < 999))
        cout << "O número é uma centena.";

    if ((num > 1000) and (num <9999))
        cout << "O número é um milhar.";

    else
    {
        cout << "Número inválido.";
    };

}
