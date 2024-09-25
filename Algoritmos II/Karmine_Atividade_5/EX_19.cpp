/*19 – Crie um programa que implemente uma função recursiva para calcular o MDC (Máximo Divisor
Comum) entre dois números inteiros e positivos. Para calcular o MDC deve-se utilizar o algoritmo de
Euclides, que possui como conceito: “O MDC de dois números inteiros é o maior número inteiro que divide
ambos sem deixar resto”, a figura abaixo exemplifica o algoritmo de Euclides.

O MDC de 30 e 4 é: 2*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int mdc(int num1, int num2);

main() {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;

    cout << "Digite um número que deseje fazer o MDC: ";
    cin >> n1;

    cout << "Digite outro número que deseje fazer o MDC: ";
    cin >> n2;

    int result;
    if(n1 >= n2) result = mdc(n1, n2);
    else result = mdc(n2, n1);
    cout << "MDC: " << result;

}

int mdc(int num1, int num2) { // num1 > num2

    int resto = (num1 % num2);

    if(resto == 0)
        return num2;

    else
        return mdc(num2, resto);
};
