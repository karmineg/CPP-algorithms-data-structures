/* 8. Escreva um programa que receba um número inteiro entre 1 e 12 referente ao número do mês, o
programa deverá exibir o mês por extenso, caso informado um número fora do intervalo, deverá
apresentar uma mensagem com esta informação. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int mes;

    cout << "Escreva um número do mês: ";
    cin >> (mes);

switch (mes)
{

case 1:
    cout << "Janeiro" << endl;
    break;
case 2:
    cout << "Fevereiro" << endl;
    break;
case 3:
    cout << "Março" << endl;
    break;
case 4:
    cout << "Abril" << endl;
    break;
case 5:
    cout << "Maio" << endl;
    break;
case 6:
    cout << "Junho" << endl;
    break;
case 7:
    cout << "Julho" << endl;
    break;
case 8:
    cout << "Agosto" << endl;
    break;
case 9:
    cout << "Setembro" << endl;
    break;
case 10:
    cout << "Outubro" << endl;
    break;
case 11:
    cout << "Novembro" << endl;
    break;
case 12:
    cout << "Dezembro" << endl;
    break;
default:
    cout << "Valor não corresponde a nenhum mês" << endl;
    break;
};

}
