/* 5 - Os funcion�rios de uma empresa receberam um aumento de sal�rio:
1) T�cnicos: 50% 2) Gerentes: 30% 3) Demais: 20%
Escreva um algoritmo que receba como entrada o sal�rio atual e o cargo do funcion�rio, e apresente o
novo sal�rio ap�s o aumento. Imprima tamb�m o cargo, de acordo com a entrada digitada */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float satual, saument;
    int cargo;

    cout << "Digite o sal�rio atual: ";
    cin >> (satual);

    cout << "Digite seu cargo (T�cnico (1), Gerente (2), Outro (3) ): ";
    cin >> (cargo);

    switch (cargo)
    {

    case 1:
        saument = satual + (satual * 0.5);
        cout << "Seu novo sal�rio ap�s o aumento � " << saument << " R$." << endl;
        break;
    case 2:
        saument = satual + (satual * 0.3);
        cout << "Seu novo sal�rio ap�s o aumento � " << saument << " R$." << endl;
        break;
    case 3:
        saument = satual + (satual * 0.2);
        cout << "Seu novo sal�rio ap�s o aumento � " << saument << " R$." << endl;
        break;
    default:
        cout << "Cargo inv�lido.";
             break;

    };

}
