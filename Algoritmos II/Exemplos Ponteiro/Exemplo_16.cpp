#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void leitura();
void ajuste(int *x, int *i);

main()
{
   leitura();
}

void leitura()
{
    int n1, n2;
    cout << "Digite o valor 1:";
    cin >> n1;
    fflush(stdin);

    cout << "Digite o valor 2:";
    cin >> n2;
    fflush(stdin);

    ajuste(&n1, &n2);
    cout << "\n\nVALORES NA FUNCAO LEITURA: " << endl;
    cout << "N1: " << n1 << endl;
    cout << "N2: " << n2 << endl;
}

void ajuste(int *x, int *i)
{
    *x += 4;
    *i -= 2;
    cout << "\n\nVALORES NA FUNCAO AJUSTE: \n";
    cout << "X: " << *x << endl;
    cout << "I: " << *i << endl;
}
