/*2 - Escrever um algoritmo que gere dinamicamente valores inteiros para um vetor de 8 posi��es, sendo
esses valores entre 20 e 80. Encontrar o maior valor do vetor e sua posi��o; mostrar ao final o maior
valor e sua posi��o.*/

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
        if (i < 7) // pra tirar a v�rgula no final...
            cout <<  vetor[i] << ", ";
        else
            cout <<  vetor[i] << "!";
    }
    cout << "\n\nMaior valor do Vetor: " << maior << " - Posi��o: " << posicao;

}
