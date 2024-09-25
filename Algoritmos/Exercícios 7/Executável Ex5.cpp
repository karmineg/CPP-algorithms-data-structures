/* 5 - Um posto está vendendo combustíveis com base na tabela de descontos abaixo. Escreva um
algoritmo que leia o número de litros vendidos, o tipo de combustível (codificado da seguinte forma: A-
álcool G-Gasolina), calcule e imprima o valor a ser pago pelo cliente, sabendo-se que o preço da gasolina
é de R$ 2.590 o litro e o álcool R$ 1.650. */

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

    cout << "Escreva o tipo de combustível desejado (A- álcool; G- gasolina): ";
    cin >> (tipo);

    cout << "Indique o número de litros desejados: ";
    cin >> (litros);

    gasolina = 2590;
    alcool = 1650;

    switch(tipo){

    case 'a':
        if (litros <= 20){
            valor = litros * alcool;
            desconto = valor - (valor / 3);
            cout << "O valor a ser pago é: " << desconto << endl;
            break;
        }
        else if (litros > 20){
            valor = litros * alcool;
            desconto = valor - (valor / 5);
            cout << "O valor a ser pago é: " << desconto << endl;
            break;
        }
        else{
            cout << "Número de litros inválido" << endl;
            break;
        }
    case 'g':
        if (litros <= 15){
            valor = litros * gasolina;
            desconto = valor - (valor / 3);
            cout << "O valor a ser pago é: " << desconto << endl;
            break;
        }
        else if (litros > 15){
            valor = litros * gasolina;
            desconto = valor - (valor / 5);
            cout << "O valor a ser pago é: " << desconto << endl;
            break;
        }
        else{
            cout << "Número de litros inválido" << endl;
            break;
        }
    default:
        cout << "Tipo de combustível inválido.";

    };
}
