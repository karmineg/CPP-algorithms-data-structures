/*
5 - Escrever um algoritmo que leia um vetor A[20] de caracteres. Mostrar
o vetor lido. Trocar a seguir
o 1� elemento com o 11�, o 2� com o 12� e, assim, sucessivamente at� o 10�
com o 20�. Mostrar o
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
    srand(time(NULL)); //inicializando o rand�mico
    int i;
    char vet[20], aux;

    for(i = 0; i < 20; i++)
    {
        cout << "Informe o elemento da posi��o [" << i << "]: ";
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

    cout << "\n\nVETOR AP�S AS TROCAS: " << endl;

    for(i = 0; i < 20; i++)
    {
        cout << vet[i] << ", ";
    }
}
