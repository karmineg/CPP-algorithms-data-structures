/* 5 - Escrever um algoritmo que leia tr�s valores inteiros e verifique se eles podem ser os lados
de um tri�ngulo. Se forem, informar qual o tipo de tri�ngulo que eles formam: equil�tero, is�scele ou
escaleno.
Propriedade: o comprimento de cada lado de um tri�ngulo � menor do que a soma dos comprimentos
dos outros dois lados.
Tri�ngulo Equil�tero: aquele que tem os comprimentos dos tr�s lados iguais;
Tri�ngulo Is�scele: aquele que tem os comprimentos de dois lados iguais. Portanto, todo tri�ngulo
equil�tero � tamb�m is�scele;
Tri�ngulo Escaleno: aquele que tem os comprimentos de seus tr�s lados diferentes. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int a, b, c;

    cout << "Informe um n�mero inteiro qualquer (A): ";
    cin >> (a);

    cout << "Informe um n�mero inteiro qualquer (B): ";
    cin >> (b);

    cout << "Informe um n�mero inteiro qualquer (C): ";
    cin >> (c);


    if((a + b > c) and (a + c > b) and (b + c > a)){
        cout << "Os 3 lados formam um tri�ngulo!\n";
        if(a == b and a == c)
            cout << "Equil�tero\n";
        else
            if((a == b) or (a == c) or (b == c))
                cout << "Is�sceles\n";
            else
                cout << "Escaleno\n";
    }
    else
        cout << "Os 3 lados n�o formam um tri�ngulo!\n";
}
