#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char nome[50], aux[50];
   cout << "Informe o nome: ";
   gets(nome);
   fflush(stdin);

   cout << nome << endl;

   strcpy(aux, nome);

   cout << aux << endl;

}
