#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
void mostra(char *pnome);
void teste(char **p2);

main()
{
    string nome;

    cout << "Informe seu nome: ";
    getline(cin, nome);
    fflush(stdin);

    mostra(&nome[0]);

}

void mostra(char *pnome)
{
    int cont = 0;
    while(*pnome)
    {
        cout << *pnome;
        pnome++;
        cont++;
    }

    pnome -= cont;
    teste(&pnome);
}

void teste(char **p2)
{
    cout << "\n\n" << **p2;
}
