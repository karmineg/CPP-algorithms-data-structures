#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;
void leitura();

main()
{
    ofstream escreve("exemplo_36.txt", ios::app);//método construtor
    int cod;
    string nome;
    if(escreve.is_open())
    {
        cout << "Informe o codigo e o nome, CTRL+Z para finalizar: ";
        while(cin >> cod >> nome)
        {
            escreve << cod << " " << nome << "\n";
            cout << "Proximo Registro ou CTRL+Z para finalizar? ";
        }
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
    cout << "\n\nDados no arquivo: " << endl;
    leitura();
}

void leitura()
{
    ifstream ler("exemplo_36.txt");
    int cod, soma = 0;
    string nome;
    if(ler.is_open())
    {
        while(ler >> cod >> nome)
        {
            cout << cod << " " << nome << "\n";
            soma += cod;
        }
        cout << "\nSoma dos codigos: " << soma;
        ler.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
