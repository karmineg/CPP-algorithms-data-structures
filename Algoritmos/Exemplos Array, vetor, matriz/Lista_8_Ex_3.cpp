/*
3 – Escreva um programa que receba o valor inicial de uma aplicação
financeira, a quantidade de meses
da aplicação e o percentual da correção. O programa deverá mostrar o
extrato como o exemplo abaixo:
Valor inicial: 100,00
Total de meses: 3
Percentual da correção: 1.2

Mês    Valor inicial    Rendimento    Valor Final
1    100.00     1.20      101.20
2    101.20     1.21      102.41
3    102.41     1.23      103.64
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int meses, i;
    float valor, perc, rendimento;

    cout << fixed; //define a notação
    cout.precision(2); //define o número de casas decimais

    cout << "Informe o valor inicial da aplicação: ";
    cin >> valor;
    fflush(stdin);

    cout << "Informe o percentual da correção: ";
    cin >> perc;
    fflush(stdin);

    cout << "Informe o número de meses: ";
    cin >> meses;
    fflush(stdin);

    cout << "Mês            ";
    cout << "Valor inicial       ";
    cout << "Rendimento     ";
    cout << "Valor Final    " << endl;

    for(i = 1; i <= meses; i++)
    {
        cout << i << "              ";
        cout << valor << "              ";
        rendimento = (perc / 100.0) * valor;
        cout << rendimento << "           ";
        valor += rendimento;
        cout << valor << "          " << endl;
    }

}
