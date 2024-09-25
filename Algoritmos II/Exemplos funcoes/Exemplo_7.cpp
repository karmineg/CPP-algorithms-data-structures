#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

void leitura(int &n); // protótipo da função
int fatorial(int x);

main()
{
   setlocale(LC_ALL,"portuguese");
   int n;
   leitura(n);
   cout << "Valor lido: " << n << endl;
   cout << "Fatorial de " << n << ": " << fatorial(n);
}

void leitura(int &n)
{
    cout << "Informe o valor de N: ";
    cin >> n;
    fflush(stdin); //limpa o buffer do teclado.
    n += 2;
}

int fatorial(int x)
{
    int fat = 1;
    for(int i = x; i > 1; i--)
    {
        fat *= i;
    }
    return fat;
}
