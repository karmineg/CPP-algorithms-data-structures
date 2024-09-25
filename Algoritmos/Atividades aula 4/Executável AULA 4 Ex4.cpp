/* 4 - Dados tr�s valores A, B e C, em que A e B s�o n�meros inteiros e C � um caractere, pede-se para
imprimir o resultado da opera��o de A por B se C for um s�mbolo de operador aritm�tico v�lido;
caso contr�rio deve ser impressa uma mensagem de operador n�o definido. Tratar erro de divis�o
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

    cout << "Informe um n�mero inteiro qualquer: ";
    cin >> (a);

    cout << "Informe um n�mero inteiro qualquer: ";
    cin >> (b);

    cout << "Informe um s�mbolo de operador aritm�tico v�lido: ";
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
        cout << "Operador n�o definido!" << endl;
        break;

    };


}
