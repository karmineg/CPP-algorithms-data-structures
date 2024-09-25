#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    int soma = 0, ini, fim;
    cout << "Informe o valor inicial: ";
    cin >> ini;
    fflush(stdin);

    cout << "Informe o valor final: ";
    cin >> fim;
    fflush(stdin);

    if(ini >= fim)
        cout << "Valores invalidos";
    else
    {
        for(int i = ini; i <= fim; i++)
        {
            if(i % 2 == 0)
            {
                soma += i;
                cout << i << ", ";
            }
        }
        cout << "\nSoma dos valores pares: " << soma;
    }
}
