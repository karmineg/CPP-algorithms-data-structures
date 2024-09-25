#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int *valores);
void mostra(int *valores);

main()
{
    int vet[5];
    leitura(vet);
    mostra(vet);
    getchar();
}

void leitura(int *valores)
{
    int x;
    srand(time(NULL));
    cout << "Posicao inicial do ponteiro: " << valores << endl;

    for(x = 0; x < 5; x++)
    {
        valores[x] = rand() % 50;
    }

    cout << "Posicao final do ponteiro: " << valores << endl;
}

void mostra(int *valores)
{
    int x, soma = 0;
    cout << "\n\nVALORES NO VETOR: " << endl;
    for(x = 0; x < 5; x++)
    {
        cout << valores[x] << ", ";
        soma += valores[x];
    }
    cout << "\n\nSoma dos valores: " << soma << endl;
}
