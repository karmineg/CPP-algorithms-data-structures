/*4 - Escreva um algoritmo que leia valores para preencher um vetor de 5 posi��es de n�meros inteiros,
ap�s o sistema dever� gerar um segundo vetor, tamb�m de 5 posi��es, sendo formado pelo fatorial do
elemento no primeiro vetor.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetorx[5],vetory[5];
    srand(time(NULL));

    cout << "Elementos do Vetor: ";
    for(i = 0; i < 5; i++)
    {
        vetorx[i] = rand() % 10;
        cout << vetorx[i] << ", ";
    }

    cout << endl;

    cout << "Vetor Fatorial: ";
    for(i = 0; i < 5; i++)
    {
        for(vetory[i] = 1; vetorx[i] > 1; vetorx[i]--)
        {
            vetory[i] *= vetorx[i];
        }
        cout << vetory[i] << ", ";
    }

}
