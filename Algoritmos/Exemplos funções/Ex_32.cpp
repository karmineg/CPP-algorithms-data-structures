
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int leitura(char texto[100]);
int calcula(int n1, int n2);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;
    n1 = leitura("Informe o valor 1: ");
    n2 = leitura("Informe o valor 2: ");
    cout << "Soma de " << n1 << " + " << n2 << " = " << calcula(n1, n2);
}

int leitura(char texto[100])
{
    int v;
    cout << texto;
    cin >> v;
    return v;
}

int calcula(int n1, int n2)
{
    int soma = 0;
    soma = n1 + n2;
    return soma;
}



