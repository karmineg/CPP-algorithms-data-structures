/* 1 � Escrever um programa que l� 12 valores reais para a vari�vel �B�, um de cada vez. Mostrar a soma
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
        cout << "Digite 12 n�meros menores que 50: " << endl;
        cin >> (num);
        fflush (stdin);
        soma += num;
    }
        cout << "\n\n Resultado da soma dos valores: " << soma;

    }
