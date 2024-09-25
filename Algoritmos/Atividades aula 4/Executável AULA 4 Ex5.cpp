/* 5 - Escrever um algoritmo que leia três valores inteiros e verifique se eles podem ser os lados
de um triângulo. Se forem, informar qual o tipo de triângulo que eles formam: equilátero, isóscele ou
escaleno.
Propriedade: o comprimento de cada lado de um triângulo é menor do que a soma dos comprimentos
dos outros dois lados.
Triângulo Equilátero: aquele que tem os comprimentos dos três lados iguais;
Triângulo Isóscele: aquele que tem os comprimentos de dois lados iguais. Portanto, todo triângulo
equilátero é também isóscele;
Triângulo Escaleno: aquele que tem os comprimentos de seus três lados diferentes. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int a, b, c;

    cout << "Informe um número inteiro qualquer (A): ";
    cin >> (a);

    cout << "Informe um número inteiro qualquer (B): ";
    cin >> (b);

    cout << "Informe um número inteiro qualquer (C): ";
    cin >> (c);


    if((a + b > c) and (a + c > b) and (b + c > a)){
        cout << "Os 3 lados formam um triângulo!\n";
        if(a == b and a == c)
            cout << "Equilátero\n";
        else
            if((a == b) or (a == c) or (b == c))
                cout << "Isósceles\n";
            else
                cout << "Escaleno\n";
    }
    else
        cout << "Os 3 lados não formam um triângulo!\n";
}
