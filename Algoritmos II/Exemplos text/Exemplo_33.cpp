#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

main()
{
    ifstream ler;
    char texto[100];
    ler.open("exemplo_41.txt", ios::in);

    if(ler.is_open())
    {
        cout << "\nDados no arquivo: " << endl;
        while(!ler.eof())
        {
            ler.getline(texto, 100, ';');
            cout << texto << endl;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    ler.close();
}

