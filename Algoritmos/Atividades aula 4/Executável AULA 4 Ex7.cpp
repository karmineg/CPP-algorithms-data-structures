/* 7 - Faça um algoritmo que leia o sexo, a altura e a idade de uma pessoa. Calcule e mostre o seu peso
ideal de acordo com as seguintes características */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float altura, ideal;
    int idade, sexo;


    cout << "Informe sua altura (metros): ";
    cin >> (altura);

    cout << "Informe sua idade: ";
    cin >> (idade);

    cout << "Informe seu sexo (Para Masculino digite 1, para Feminino digite 2: ";
    cin >> (sexo);

    switch (sexo)
    {
    case 1:
        if ((altura > 1.70) and (idade <= 20))
        {
            ideal = (72.7 * altura) - 58;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else if ((altura > 1.70) and ( 21 >= idade <= 39))
        {
            ideal = (72.7 * altura) - 53;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else if ((altura > 1.70) and (idade >= 40))
        {
            ideal = (72.7 * altura) - 45;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else if ((altura <= 1.70) and (idade <= 40))
        {
            ideal = (72.7 * altura) - 50;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else
        {
            ideal = (72.7 * altura) - 58;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
    break;

    case 2:
        if (altura > 1.50)
        {
            ideal = (62.1 * altura) - 44.7;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else if ((altura <= 1.70) and (idade >= 38))
        {
            ideal = (62.1 * altura) - 45;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
        else
        {
            ideal = (62.1 * altura) - 49;
                    cout << "Seu peso ideal é " << ideal << endl;
        }
    break;

    default:
        cout << "Sexo inválido." << endl;
        break;


    }
}
