/*
3 � Escreva um programa que receba o valor inicial de uma aplica��o
financeira, a quantidade de meses
da aplica��o e o percentual da corre��o. O programa dever� mostrar o
extrato como o exemplo abaixo:
Valor inicial: 100,00
Total de meses: 3
Percentual da corre��o: 1.2

M�s    Valor inicial    Rendimento    Valor Final
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

    cout << fixed; //define a nota��o
    cout.precision(2); //define o n�mero de casas decimais

    cout << "Informe o valor inicial da aplica��o: ";
    cin >> valor;
    fflush(stdin);

    cout << "Informe o percentual da corre��o: ";
    cin >> perc;
    fflush(stdin);

    cout << "Informe o n�mero de meses: ";
    cin >> meses;
    fflush(stdin);

    cout << "M�s            ";
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
