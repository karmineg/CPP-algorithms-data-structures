/*
4 - Escreva um algoritmo que leia valores para preencher um vetor de 5
posi��es de n�meros inteiros,
ap�s o sistema dever� gerar um segundo vetor, tamb�m de 5 posi��es,
sendo formado pelo fatorial do
elemento no primeiro vetor.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o rand�mico
    int i, x, v[5], fatorial[5], fat;

    cout << "VETOR GERADO: " << endl;
    for(i = 0; i < 5; i++)
    {
        v[i] = rand() % 6;
        cout << v[i] << ", ";
    }

    cout << "\n\nFATORIAL DO VETOR GERADO: " << endl;

    for(i = 0; i < 5; i++)
    {
        if(v[i] < 2)
            fatorial[i] = 1;
        else
        {
            fat = 1;
            for(x = v[i]; x > 1; x--)
            {
                fat *= x;
            }

            fatorial[i] = fat;
        }
        cout << fatorial[i] << ", ";
    }
}
