/*3 - Escrever um algoritmo que gere dinamicamente valores para dois vetores de 10 posições, A e B.
Mostrar os vetores gerados. Gerar um novo vetor Y, que será formado pela soma dos elementos das
posições iguais nos vetores A e B. Mostrar o vetor Y.
Exemplo
A[0] <- 5
B[0] <- 4
Y[0] <- 9 (soma de 5 + 4)*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int a, b, vetora[10],vetorb[10],vetory[10], soma;
    srand(time(NULL));

    cout << "Elementos A: ";
    for(a = 0; a < 10; a++)
    {
        vetora[a] = rand() % 10;
        cout << vetora[a] << ", ";
    }

    cout << endl;

    cout << "Elementos B: ";
    for(b = 0; b < 10; b++)
    {
        vetorb[b] = rand() % 10;
        cout << vetorb[b] << ", ";
    }

    cout << endl;
    b = 0;

    cout << "Vetor Y: ";
    for(a = b; b < 10; b++)
    {
        vetory[b] = vetora[a] + vetorb[b];
        cout << vetory[b] << ", ";
        a++;
    }

}
