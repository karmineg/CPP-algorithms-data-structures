#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[100], menor;
    srand(time(NULL)); //INICIALIZA A SEMENTE DO RAND�MICO
    for(i = 0; i < 100; i++)
    {
        vetor[i] = rand(); //GERA UMA VALOR RAND�MICO
        if(i == 0)
            menor = vetor[i];
        else if(vetor[i] < menor)
            menor = vetor[i];
    }
    cout << "\n\nELEMENTOS NO VETOR: " << endl;
    for(i = 0; i < 100; i++)
    {
        cout <<  vetor[i] << ", ";
        if((i + 1) % 10 == 0)
            cout << "\n";
    }

    cout << "\n\nMENOR VALOR NO VETOR: " << menor;
}
