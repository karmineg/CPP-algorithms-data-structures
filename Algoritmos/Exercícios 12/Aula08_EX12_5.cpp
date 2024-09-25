/* 5 - Fa�a um programa que gere um vetor V[15] de n�meros inteiros e realize as seguintes opera��es:
a) Calcule a m�dia dos valores de V.
b) Calcule e mostre o vetor W que ser� composto pelos elementos do vetor V que s�o menores ou igual a m�dia.
c) Ordene e mostre o W em ordem crescente.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int V[15], W[15], soma = 0, media, aux;

    cout << "Vetor: ";
    for (int i = 0;i<15;i++) {
        V[i] = rand() % 101;
        soma += V[i];
        cout << V[i] << ", ";
    }

    media = soma / 15;

    for (int i = 0;i<15;i++) {
        if(V[i] <= media)
            W[i] = V[i];
        else
            W[i] = 101;
    }

    for (int x = 0; x < 15; x++) {
        for (int i = x + 1; i < 15; i++) {
            if (W[i] < W[x]) {
                aux = W[x];
                W[x] = W[i];
                W[i] = aux;
            }
        }
    }
    cout << "\n\nM�dia: " << media << endl;
    cout << "Valores a baixo da m�dia: ";

    for (int i = 0; i < 15; i++){
        if (W[i] < 101)
        cout << W[i] << ", ";
    }
}


