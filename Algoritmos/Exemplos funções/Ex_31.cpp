
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int leitura();


main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, soma;
    n1 = leitura();
    n2 = leitura();
    soma = n1 + n2;
    cout << "Soma de " << n1 << " + " << n2 << " = " << soma;
}

int leitura()
{
    int v;
    cout << "Informe um valor: ";
    cin >> v;
    return v;
}


