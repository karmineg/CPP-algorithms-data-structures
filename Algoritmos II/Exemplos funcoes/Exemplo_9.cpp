#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int leitura(string texto); // protótipo da função


main()
{
   setlocale(LC_ALL,"portuguese");
   int n1, n2;
   n1 = leitura("Informe o valor 1: ");
   n2 = leitura("Informe o valor 2: ");
}


int leitura(string texto)
{
    int n;
    cout << texto;
    cin >> n;
    fflush(stdin); //limpa o buffer do teclado.
    return n;
}

