#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;
void gerar(int *v, int **t);
void mostra(int *v, int *t);

main()
{
    int *tam = new int;

    cout << "Informe a quantidade de numeros: ";
    cin >> *tam;
    fflush(stdin);

    int *pvet = new int[*tam];

    gerar(pvet, &tam);
    mostra(pvet, tam);
    delete tam;
    delete []pvet;
}


void gerar(int *v, int **t)
{
    srand(time(NULL));
    int *i = new int;
    for (*i = 0; *i < **t; (*i)++)
    {
        *(v + *i) = rand() % 100;
    }
    delete i;
}

void mostra(int *v, int *t)
{
    int *i = new int;
    int *psoma = new int(0);
    for (*i = 0; *i < *t; (*i)++)
    {
        cout << *v << ", ";
        if(*v % 2 == 0)
            *psoma += *v;
        v++;
    }
    cout << "\n\nSoma dos pares: " << *psoma << endl;
    delete psoma;
    delete i;
}
