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
    ler.open("exemplo_32.txt", ios::in);

    if(ler.is_open())
    {
        cout << "\nDados no arquivo: " << endl;
        ler >> texto;
        while(!ler.fail())
        {
            cout << texto << endl;
            ler >> texto;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    ler.close();
}

