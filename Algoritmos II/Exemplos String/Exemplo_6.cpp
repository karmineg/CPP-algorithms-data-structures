#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

main()
{
   setlocale(LC_ALL,"portuguese");
   string nome;
   cout << "Informe o nome: ";
   getline(cin, nome);
   fflush(stdin);

   cout << nome << endl;

   for(int i = 0; i < nome.size(); i++)
   {
       nome[i] = tolower(nome[i]);
   }

   cout << "\nNome em minúsculo: ";
   cout << nome << endl;

   for(int i = 0; i < nome.size(); i++)
   {
       if(i == 0)
          nome[i] = toupper(nome[i]);
       else{
          if(isspace(nome[i]))
              nome[i + 1] = toupper(nome[i + 1]);
       }
   }

   cout << "\nNome com iniciais em maiúsculo: ";
   cout << nome << endl;

}
