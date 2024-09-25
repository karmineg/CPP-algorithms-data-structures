#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[10];
    for(i = 0; i < 10; i++)
    {
        cout << "Informe o valor " << i << ": ";
        cin >> vetor[i];
        fflush(stdin);
    }
    cout << "\n\nELEMENTOS NO VETOR: ";
    for(i = 0; i < 10; i++)
    {
        cout <<  vetor[i] << ", ";
    }
}
