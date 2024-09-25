#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[10];
    srand(time(NULL)); //INICIALIZA A SEMENTE DO RANDÔMICO
    for(i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 21 - 10; //GERA UMA VALOR RANDÔMICO
    }
    cout << "\n\nELEMENTOS NO VETOR: " << endl;
    for(i = 0; i < 10; i++)
    {
        cout <<  vetor[i] << ", ";
    }
}
