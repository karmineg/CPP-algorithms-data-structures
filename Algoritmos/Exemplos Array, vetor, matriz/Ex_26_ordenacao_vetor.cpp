
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o randômico
    int i, x, aux;
    int vet[5];

    cout << "VETOR GERADO: " << endl;
    for(i = 0; i < 5; i++)
    {
        vet[i] = rand() % 10;
        cout << vet[i] << ", ";
    }

    for(i = 0; i < 4; i++)
    {
        for(x = i + 1; x < 5; x++)
        {
            if(vet[i] > vet[x])
            {
                aux = vet[i];
                vet[i] = vet[x];
                vet[x] = aux;
            }
        }
    }

    cout << "\n\nVETOR ORDENADO EM ORDEM CRESCENTE: " << endl;
    for(i = 0; i < 5; i++)
    {
        cout << vet[i] << ", ";
    }

    for(i = 0; i < 4; i++)
    {
        for(x = i + 1; x < 5; x++)
        {
            if(vet[i] < vet[x])
            {
                aux = vet[i];
                vet[i] = vet[x];
                vet[x] = aux;
            }
        }
    }

    cout << "\n\nVETOR ORDENADO EM ORDEM DECRESCENTE: " << endl;
    for(i = 0; i < 5; i++)
    {
        cout << vet[i] << ", ";
    }


}
