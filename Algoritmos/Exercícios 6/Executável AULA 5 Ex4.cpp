/* 4 - Escrever um programa que leia uma quantidade n�o determinada de vezes um n�mero inteiro. Para
cada n�mero lido apresentar a soma dos n�meros lidos. Parar de informar quando a soma ultrapassar
250. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, soma = 0;

    while (soma < 250){
        cout << "Informe um n�mero inteiro: ";
        cin >> (num);
        fflush (stdin);
        soma += num;
    }
        cout << "\n\n Resultado da soma dos valores: " << soma;

    }
