#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

main()
{
    string nome;
    char c;
    cout << "Informe o seu nome: ";
    getline(cin, nome);
    fflush(stdin);

    ofstream escrita("exemplo_31.txt", ios::app);
    //escrita.open("exemplo_31.txt", ios::app);

    if(escrita.is_open())
    {
        escrita << nome << "\n";
    }
    else
        cout << "Erro ao abrir o arquivo";

    escrita.close();

    ifstream ler;
    ler.open("exemplo_31.txt", ios::in);

    if(ler.is_open())
    {
        cout << "\nDados no arquivo: " << endl;
        while(ler.get(c))
        {
            c = toupper(c);
            cout << c;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    ler.close();
}

