/* 5 - Os funcionários de uma empresa receberam um aumento de salário:
1) Técnicos: 50% 2) Gerentes: 30% 3) Demais: 20%
Escreva um algoritmo que receba como entrada o salário atual e o cargo do funcionário, e apresente o
novo salário após o aumento. Imprima também o cargo, de acordo com a entrada digitada */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float satual, saument;
    int cargo;

    cout << "Digite o salário atual: ";
    cin >> (satual);

    cout << "Digite seu cargo (Técnico (1), Gerente (2), Outro (3) ): ";
    cin >> (cargo);

    switch (cargo)
    {

    case 1:
        saument = satual + (satual * 0.5);
        cout << "Seu novo salário após o aumento é " << saument << " R$." << endl;
        break;
    case 2:
        saument = satual + (satual * 0.3);
        cout << "Seu novo salário após o aumento é " << saument << " R$." << endl;
        break;
    case 3:
        saument = satual + (satual * 0.2);
        cout << "Seu novo salário após o aumento é " << saument << " R$." << endl;
        break;
    default:
        cout << "Cargo inválido.";
             break;

    };

}
