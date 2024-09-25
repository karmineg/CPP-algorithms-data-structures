#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char nome[50];
   cout << "Informe o nome: ";
   gets(nome);
   fflush(stdin);

   cout << nome << endl;

   cout << "Informe o nome para ler somente os 10 primeiros caracteres: ";
   cin.getline(nome, 10);
   fflush(stdin);

   cout << nome << endl;
}
