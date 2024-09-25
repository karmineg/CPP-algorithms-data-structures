/* 4 - Dados três valores A, B e C, em que A e B são números inteiros e C é um caractere, pede-se para
imprimir o resultado da operação de A por B se C for um símbolo de operador aritmético válido;
caso contrário deve ser impressa uma mensagem de operador não definido. Tratar erro de divisão
por zero. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int a, b;
    char c;

    cout << "Informe um número inteiro qualquer: ";
    cin >> (a);

    cout << "Informe um número inteiro qualquer: ";
    cin >> (b);

    cout << "Informe um símbolo de operador aritmético válido: ";
    cin >> (c);

    switch (c)
    {
    case '+':
        cout << a+b << endl;
        break;
    case '-':
        cout << a-b << endl;
        break;
    case '*':
        cout << a*b << endl;
        break;
    case '/':
        cout << a/b << endl;
        break;
    case '%':
        cout << a%b << endl;
        break;
    default:
        cout << "Operador não definido!" << endl;
        break;

    };


}
