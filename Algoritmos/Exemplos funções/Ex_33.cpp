
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int leitura(char texto[100]);
int calcula(int n1, int n2);
bool verifica(int v);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;

    n1 = leitura("Informe o valor 1: ");
    n2 = leitura("Informe o valor 2: ");
    cout << "Soma de " << n1 << " + " << n2 << " = " << calcula(n1, n2);
}

int leitura(char texto[100])
{
    int v;
    do
    {
        cout << texto;
        cin >> v;
        fflush(stdin);
        if(v < 1 or v > 100)
        {
            cout << "Valor fora do intervalo!";
            getchar();
            system("cls");
        }
    }while(verifica(v));
    return v;
}

int calcula(int n1, int n2)
{
    int soma = 0;
    soma = n1 + n2;
    return soma;
}

bool verifica(int v)
{
    if(v < 1 or v > 100)
        return true;
    else
        return false;
}



