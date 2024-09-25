
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int n1, soma; //variável global existe em todo o programa
void leitura();
void mostra();

main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << "Informe um valor: ";
    cin >> n1;
    leitura();
    mostra();
    cout << "\nValor de n1 no programa principal: " << n1;
}

void leitura()
{
    int n1; //variável local só existe na função leitura
    cout << "Informe um valor: ";
    cin >> n1;
}

void mostra()
{
    cout << "Valor de n1 na função mostra: " << n1;
}

