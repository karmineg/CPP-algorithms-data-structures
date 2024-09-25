/* 1 – Escrever um programa que lê 12 valores reais para a variável “B”, um de cada vez. Mostrar a soma
dos valores lidos menores que 50; */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float num, soma = 0;

    while (soma < 50.0){
        cout << "Digite 12 números menores que 50: " << endl;
        cin >> (num);
        fflush (stdin);
        soma += num;
    }
        cout << "\n\n Resultado da soma dos valores: " << soma;

    }
