#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct dados
{
    int numero;
    char nome[50];
};

void leitura(dados *x);

main()
{
    dados cadastro;
    leitura(&cadastro);
    cout << "Numero informado: " << cadastro.numero << endl;
    cout << "Nome informado: " << cadastro.nome;
    getchar();
}

void leitura(dados *x)
{
    cout << "informe o numero: ";
    //cin >> x->numero;
    cin >> (*x).numero;
    fflush(stdin);

    cout << "informe o nome: ";
    gets(x->nome);
    fflush(stdin);
}
