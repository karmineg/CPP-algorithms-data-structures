/* 6. Escreva um algoritmo que leia tr�s n�meros: A, B e C. Encontrar e mostrar o maior, o menor e o do
meio entre os tr�s n�meros. Mostre os n�meros em ordem crescente. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float a, b, c;

    cout << "Escreva o n�mero A: ";
    cin >> (a);

    cout << "Escreva 0 n�mero B: ";
    cin >> (b);

    cout << "Escreva 0 n�mero C: ";
    cin >> (c);

    if ((a >= b) and (a >= c) and (b >= c))
    cout << "A ordem crescente � C ,B e A";

    if ((a >= b) and (a >=c) and (c >= b))
    cout << "A ordem crescente � B ,C e A";

    if ((b >= a) and (b >= c) and (a >= c))
    cout << "A ordem crescente � C ,A e B";

    if ((b >= a) and (b >= c) and (c >= a))
    cout << "A ordem crescente � A ,C e B";

    if ((c >= a) and (c >= b) and (a >=b))
    cout << "A ordem crescente � B ,A e C";

    if ((c >= a) and (c >= b) and (b >= a))
    cout << "A ordem crescente � A ,B e C" << endl;


}
