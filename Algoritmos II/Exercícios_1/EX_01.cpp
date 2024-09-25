/* 1 – Escreva um programa que manipule um vetor A[10] de números float, os valores para
preencher o vetor devem ser gerados randomicamente, mostre o vetor gerado na tela, ordenar
o vetor em ordem crescente e apresentar novamente o vetor na tela, a seguir mostre o vetor
com valores arredondados para cima, para baixo e seguindo o critério da primeira casa decimal. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    cout << fixed;
    cout.precision(2);
    float A[10], aux;

    cout<<"Vetor A: ";
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100 * 0.1;

        if (i < 9) // esse if e else para tirar a vírgula do último número
            cout << A[i] << ", ";
        else
            cout << A[i] << endl;
    }

    for (int x = 0; x < 10; x++) {
        for (int i = x + 1; i < 10; i++) {
            if (A[i] < A[x]) {
                aux = A[x];
                A[x] = A[i];
                A[i] = aux;
            }
        }
    }

    cout<<"\nVetor A crescente: ";
    for (int i = 0 ; i < 10 ; i++) {
        if (i < 9)
            cout << A[i] << ", ";
        else
            cout << A[i] << endl;
    }

    cout<<"\nVetor A arredondado cima: ";
    for (int i = 0 ; i < 10 ; i++) {
        if (i < 9)
            cout << ceil(A[i]) << ", ";
        else
            cout << ceil(A[i]) << endl;
    }

    cout<<"\nVetor A arredondado baixo: ";
    for (int i = 0 ; i < 10 ; i++) {
        if(i < 9)
            cout << floor(A[i]) << ", ";
        else
            cout << floor(A[i]) << endl;
    }

    cout<<"\nVetor A arredondado primeira casa decimal: ";
    for(int i = 0 ; i<10 ; i++)
    {
        if(i < 9)
            cout << round(A[i]) << ", ";
        else
            cout << round(A[i]) << endl;
    }
}
