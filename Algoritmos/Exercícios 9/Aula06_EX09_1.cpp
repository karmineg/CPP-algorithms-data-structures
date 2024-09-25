/* 1 – Escrever um algoritmo que leia um vetor A[10] de números inteiros. Mostrar o vetor lido. Ler um
número inteiro e multiplicar todo o vetor pelo número lido. Mostrar o vetor modificado. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[10], multi, num;

    for (i = 0; i < 10; i++){
        cout << "Digite o valor " << i << ": ";
        cin >> vetor[i];
        fflush(stdin);
    }
    cout << "Digite o multiplicador: ";
    cin >> (multi);

     for (i = 0; i < 10; i++)
     {
        cout << vetor[i] * multi << ", ";
     }
}
