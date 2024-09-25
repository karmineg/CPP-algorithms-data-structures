/*
3 � Escreva um programa que receba o valor inicial de uma aplica��o financeira, a quantidade de meses
da aplica��o e o percentual da corre��o. O programa dever� mostrar o extrato como o exemplo abaixo:
Valor inicial: 100,00
Total de meses: 3
Percentual da corre��o: 1.2

M�s Valor inicial Corre��o Valor Final
1     100.00        1.20       101.20
2     101.20        1.21       102.41
3     102.41        1.23       103.64
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <iomanip> //para usar setprecision()

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float valorIncial, perc, valorFinal, rendMesal;
    int meses, i;

    cout << fixed << setprecision(2);
    cout << "Informe o valor inicial da aplica��o: ";
    cin >> valorIncial;

    cout << "Informe a quantidade de meses: ";
    cin >> meses;

    cout << "Informe o percentual da corre��o: ";
    cin >> perc;

    cout << "\nM�s\tValor inicial\tRendimento\tValor Final\n";
    for (i=1; i<=meses; i++)
    {
        rendMesal = valorIncial * (perc / 100.0);
        valorFinal = valorIncial + rendMesal;
        cout << i << "\t" << valorIncial << "\t\t" << rendMesal << "\t\t" << valorFinal << endl;
        valorIncial = valorFinal; //atualiza o valor inicial
    }

}
