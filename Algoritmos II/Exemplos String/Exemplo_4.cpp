#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   char texto[10], senha[10] = {"Adilso"};
   cout << "Informe a senha: ";
   gets(texto);
   fflush(stdin);


   cout << senha << endl;
   cout << texto << endl;

   if(strcmp(texto, senha) == 0)
      cout << "Senha correta";
   else
      cout << "Acesso inválido";


}
