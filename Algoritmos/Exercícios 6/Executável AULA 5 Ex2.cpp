/* 2 - Escrever um programa que leia dois números inteiros “A” e “B”, calcular e mostrar:
• a soma dos inteiros entre eles;
• a quantidade de números ímpares entre eles;
• o percentual de números pares entre eles. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int a, b, quantidade_impar = 0, quantidade_par = 0, x, soma = 0;
    float porcentual;

    cout << "Informe o valor de A: ";
    cin >> (a);

    cout << "Informe o valor de B: ";
    cin >> (b);

    if (a < b){
            x = a + 1;
            while (x < b){
        soma += x;
        if (x % 2 != 0)
            quantidade_impar++;
        else
            quantidade_par++;
            x++;
            };

        porcentual = ((float)quantidade_par / ((float)quantidade_impar + (float)quantidade_par)) * 100.0;
        cout << "Soma entre inteiros de: " << a << " e " << b << " é: " << soma << endl;
        cout << "Quantidade de ímpares: " << quantidade_impar << endl;
        cout << "Porcentual de pares: " << porcentual;
    }
    else if (a > b){
        x = b + 1;
        while (x < a){
            soma += x;
        if (x % 2 != 0)
            quantidade_impar++;
        else
            quantidade_par++;
            x++;
            };

        porcentual = ((float)quantidade_par / ((float)quantidade_impar + (float)quantidade_par)) * 100.0;
        cout << "Soma entre inteiros de: " << b << " e " << a << " é: " << soma << endl;
        cout << "Quantidade de ímpares: " << quantidade_impar << endl;
        cout << "Porcentual de pares: " << porcentual;
        }

    else{
        cout << "Valores iguais!";
    }


}
