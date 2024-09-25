#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char nome[50];
   cout << "Informe o nome: ";
   gets(nome);
   fflush(stdin);

   cout << nome << endl;

   for(int i = 0; i < strlen(nome); i++)
   {
       cout << nome[i] << ", ";
   }

}
