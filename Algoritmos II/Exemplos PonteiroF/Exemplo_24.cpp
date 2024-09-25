#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int *px);
void calcula(int **px1);

main()
{
   int x;
   leitura(&x);

   cout << "Valor final de X: " << x;
}

void leitura(int *px)
{
   cout << "Informe um valor para o X: ";
   cin >> *px;
   fflush(stdin);

   cout << "\nEndereco de px: " << px << endl;
   calcula(&px);
}

void calcula(int **px1)
{
    **px1 = **px1 + 5;
    cout << "\nEndereco de *px: " << *px1 << endl;
}
