#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i;
    float vetor[10];
    cout << fixed;
    cout.precision(2);

    srand(time(NULL)); //INICIALIZA A SEMENTE DO RANDÔMICO
    for(i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 20 * 1.156; //GERA UMA VALOR RANDÔMICO FLOAT
    }
    cout << "\n\nELEMENTOS NO VETOR: " << endl;
    for(i = 0; i < 10; i++)
    {
        cout <<  vetor[i] << ", ";
    }
}
