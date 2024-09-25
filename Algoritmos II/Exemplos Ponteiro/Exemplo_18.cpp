#include<iostream>
#include<cstdio>
#include<cstdlib>

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
    for(x = 0; x < 5; x++)
    {
        cout << "Informe o valor da posicao [" << x + 1 << "]: ";
        cin >> valores[x];
        fflush(stdin);
    }
}

void mostra(int *valores)
{
    int x;
    for(x = 0; x < 5; x++)
    {
        cout << valores[x] << ", ";
    }
}
