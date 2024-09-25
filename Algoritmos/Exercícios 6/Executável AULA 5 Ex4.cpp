/* 4 - Escrever um programa que leia uma quantidade não determinada de vezes um número inteiro. Para
cada número lido apresentar a soma dos números lidos. Parar de informar quando a soma ultrapassar
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
        cout << "Informe um número inteiro: ";
        cin >> (num);
        fflush (stdin);
        soma += num;
    }
        cout << "\n\n Resultado da soma dos valores: " << soma;

    }
