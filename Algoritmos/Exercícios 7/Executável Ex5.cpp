/* 5 - Um posto est� vendendo combust�veis com base na tabela de descontos abaixo. Escreva um
algoritmo que leia o n�mero de litros vendidos, o tipo de combust�vel (codificado da seguinte forma: A-
�lcool G-Gasolina), calcule e imprima o valor a ser pago pelo cliente, sabendo-se que o pre�o da gasolina
� de R$ 2.590 o litro e o �lcool R$ 1.650. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char tipo;
    int litros;
    float desconto, valor, gasolina, alcool;

    cout << "Escreva o tipo de combust�vel desejado (A- �lcool; G- gasolina): ";
    cin >> (tipo);

    cout << "Indique o n�mero de litros desejados: ";
    cin >> (litros);

    gasolina = 2590;
    alcool = 1650;

    switch(tipo){

    case 'a':
        if (litros <= 20){
            valor = litros * alcool;
            desconto = valor - (valor / 3);
            cout << "O valor a ser pago �: " << desconto << endl;
            break;
        }
        else if (litros > 20){
            valor = litros * alcool;
            desconto = valor - (valor / 5);
            cout << "O valor a ser pago �: " << desconto << endl;
            break;
        }
        else{
            cout << "N�mero de litros inv�lido" << endl;
            break;
        }
    case 'g':
        if (litros <= 15){
            valor = litros * gasolina;
            desconto = valor - (valor / 3);
            cout << "O valor a ser pago �: " << desconto << endl;
            break;
        }
        else if (litros > 15){
            valor = litros * gasolina;
            desconto = valor - (valor / 5);
            cout << "O valor a ser pago �: " << desconto << endl;
            break;
        }
        else{
            cout << "N�mero de litros inv�lido" << endl;
            break;
        }
    default:
        cout << "Tipo de combust�vel inv�lido.";

    };
}
