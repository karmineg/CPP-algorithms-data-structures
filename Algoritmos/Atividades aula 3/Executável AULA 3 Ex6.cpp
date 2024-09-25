/* 6. Escreva um algoritmo que leia três números: A, B e C. Encontrar e mostrar o maior, o menor e o do
meio entre os três números. Mostre os números em ordem crescente. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float a, b, c;

    cout << "Escreva o número A: ";
    cin >> (a);

    cout << "Escreva 0 número B: ";
    cin >> (b);

    cout << "Escreva 0 número C: ";
    cin >> (c);

    if ((a >= b) and (a >= c) and (b >= c))
    cout << "A ordem crescente é C ,B e A";

    if ((a >= b) and (a >=c) and (c >= b))
    cout << "A ordem crescente é B ,C e A";

    if ((b >= a) and (b >= c) and (a >= c))
    cout << "A ordem crescente é C ,A e B";

    if ((b >= a) and (b >= c) and (c >= a))
    cout << "A ordem crescente é A ,C e B";

    if ((c >= a) and (c >= b) and (a >=b))
    cout << "A ordem crescente é B ,A e C";

    if ((c >= a) and (c >= b) and (b >= a))
    cout << "A ordem crescente é A ,B e C" << endl;


}
