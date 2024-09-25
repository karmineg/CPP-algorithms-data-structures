#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    int soma = 0;
    for(int i = 1; i <= 10; i++)
    {
        if(i % 2 == 0)
        {
            soma += i;
            cout << i << ", ";
        }
    }
    cout << "\nSoma dos valores pares: " << soma;
}
