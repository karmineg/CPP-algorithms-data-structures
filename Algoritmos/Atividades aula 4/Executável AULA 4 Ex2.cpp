/* 2 � Escreva um programa que receba um n�mero inteiro N qualquer, de tal forma que
N > 0 e N < 9999, validar para aceitar n�mero no intervalo definido.
Se o valor informado for v�lido, apresentar uma mensagem indicando se o n�mero � uma dezena, uma
centena ou um milhar */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num;

    cout << "Informe um n�mero inteiro: ";
    cin >> (num);

    if((num > 0) and (num < 99))
        cout << "O n�mero � uma dezena.";

    if ((num > 100) and (num < 999))
        cout << "O n�mero � uma centena.";

    if ((num > 1000) and (num <9999))
        cout << "O n�mero � um milhar.";

    else
    {
        cout << "N�mero inv�lido.";
    };

}
