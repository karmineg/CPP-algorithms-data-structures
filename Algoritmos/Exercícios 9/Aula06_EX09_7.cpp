/*7 - Crie um algoritmo que gere dinamicamente valores para preencher um vetor de 10 elementos do
tipo float, em seguida apresente os elementos do vetor e realize as seguintes operações:
- Mostra a média dos elementos do vetor;
- Mostrar o maior e o menor elemento do vetor;*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i;
    float media, maior = 0, menor = 10, vetor[10], soma = 0;
    srand(time(NULL));

    cout << "Elementos do Vetor: ";
    for(i = 0; i < 10.0; i++)
    {
        vetor[i] = ((rand() % 100) / 100.0) * 10.0;
        soma += vetor[i];
        cout << vetor[i] << ", ";

        if (vetor[i] > maior){
            maior = vetor[i];
        }
        else if(vetor[i] < menor){
            menor = vetor[i];
        }
    }
    media = soma / 10;

    cout << "\n\nMédia do Vetor: " << media;
    cout << "\n\nMaior valor do Vetor: " << maior;
    cout << "\n\nMenor valor do Vetor: " << menor;
}
