/*
5 - Escrever um algoritmo que leia um vetor A[20] de caracteres. Mostrar
o vetor lido. Trocar a seguir
o 1º elemento com o 11º, o 2º com o 12º e, assim, sucessivamente até o 10º
com o 20º. Mostrar o
vetor modificado.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o randômico
    int i;
    char vet[20], aux;

    for(i = 0; i < 20; i++)
    {
        cout << "Informe o elemento da posição [" << i << "]: ";
        cin >> vet[i];
        fflush(stdin);
    }

    cout << "ELEMENTOS INSERIDOS NO VETOR: " << endl;

    for(i = 0; i < 20; i++)
    {
        cout << vet[i] << ", ";
    }

    for(i = 0; i < 10; i++)
    {
        aux = vet[i];
        vet[i] = vet[i + 10];
        vet[i + 10] = aux;
    }

    cout << "\n\nVETOR APÓS AS TROCAS: " << endl;

    for(i = 0; i < 20; i++)
    {
        cout << vet[i] << ", ";
    }
}
