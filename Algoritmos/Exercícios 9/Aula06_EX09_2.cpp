/*2 - Escrever um algoritmo que gere dinamicamente valores inteiros para um vetor de 8 posições, sendo
esses valores entre 20 e 80. Encontrar o maior valor do vetor e sua posição; mostrar ao final o maior
valor e sua posição.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[8], maior = 20, posicao;
    srand(time(NULL));

    for(i = 0; i < 8; i++)
    {
        vetor[i] = rand() % 60 + 20;

        if (vetor[i] > maior){
        maior = vetor[i];
        posicao = i;
        }
    }
    for(i = 0; i < 8; i++)
    {
        if (i < 7) // pra tirar a vírgula no final...
            cout <<  vetor[i] << ", ";
        else
            cout <<  vetor[i] << "!";
    }
    cout << "\n\nMaior valor do Vetor: " << maior << " - Posição: " << posicao;

}
