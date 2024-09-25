#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char nome[50], sobrenome[50], nomecompleto[100] = {""};
   cout << "Informe o nome: ";
   gets(nome);
   fflush(stdin);

   cout << "Informe o sobrenome: ";
   gets(sobrenome);
   fflush(stdin);

   cout << nome << endl;
   cout << sobrenome << endl;

   strcat(nomecompleto, nome);
   strcat(nomecompleto, " ");
   strcat(nomecompleto, sobrenome);

   cout << nomecompleto << endl;

}
