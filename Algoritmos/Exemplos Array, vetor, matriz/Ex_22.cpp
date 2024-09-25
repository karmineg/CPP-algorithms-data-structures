#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, vetor[10], soma = 0;
    for(i = 0; i < 10; i++)
    {
        cout << "Informe o valor " << i << ": ";
        cin >> vetor[i];
        fflush(stdin);
        soma += vetor[i];
    }
    cout << "\n\nELEMENTOS NO VETOR: ";
    for(i = 0; i < 10; i++)
    {
        cout <<  vetor[i] << ", ";
    }

    cout << "\n\nSOMA DOS ELEMENTOS NO VETOR: " << soma << endl;
}
