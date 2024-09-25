#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;
void gera_matriz();
void leitura();
main()
{
    gera_matriz();
    cout << "\n\nDados no arquivo: " << endl;
    leitura();
}

void gera_matriz()
{
    ofstream escreve("exemplo_45.txt");
    int l,c;
    srand(time(NULL));
    if(escreve.is_open())
    {
        for(l = 0; l < 5; l++)
        {
            for(c = 0; c < 5; c++)
            {
                if(c == 0)
                    escreve << (rand() % 40);
                else
                    escreve << " " << (rand() % 40);
            }
            escreve << "\n";
        }
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}

void leitura()
{
    ifstream ler("exemplo_45.txt");
    int l, c, mat[5][5];

    if(ler.is_open())
    {
        for(l = 0; l < 5; l++)
        {
            for(c = 0; c < 5; c++)
            {
                ler >> mat[l][c];
                cout << mat[l][c] << "\t";
            }
            cout << "\n";
        }
        ler.close();
        cout << "\nDiagonal principal: " << endl;
        for(l = 0; l < 5; l++)
        {
            for(c = 0; c < 5; c++)
            {
                if(l == c)
                    cout << mat[l][c] << ", ";
            }
        }

    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
