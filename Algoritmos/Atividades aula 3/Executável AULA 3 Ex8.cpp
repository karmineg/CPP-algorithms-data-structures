/* 8. Escreva um programa que receba um n�mero inteiro entre 1 e 12 referente ao n�mero do m�s, o
programa dever� exibir o m�s por extenso, caso informado um n�mero fora do intervalo, dever�
apresentar uma mensagem com esta informa��o. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int mes;

    cout << "Escreva um n�mero do m�s: ";
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
    cout << "Mar�o" << endl;
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
    cout << "Valor n�o corresponde a nenhum m�s" << endl;
    break;
};

}
