/* 3 � Escreva um programa que receba a altura (h), o sexo de uma pessoa (M � Masculino, F �
Feminino) e o seu peso atual, ap�s o sistema dever� calcular o peso ideal, utilizando as
seguintes f�rmulas:
- Homens: (72.7 * h) - 58
- Mulheres: (62.1 * h) - 44.7
Considera-se que a pessoa est� no peso ideal se o seu peso atual encontra-se em uma margem
de -3kg do peso ideal ou +3kg do peso ideal.
Ao Final o sistema dever� exibir se o usu�rio est� abaixo, dentro do peso ideal, ou acima do
peso ideal. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    char sexo;
    float h, peso, ideal;

    cout << "Informe sua altura (m): ";
    cin >> h;
    fflush(stdin);

    cout << "\nInforme seu peso atual (kg): ";
    cin >> peso;
    fflush(stdin);

    cout << "\nInforme seu sexo (Para Masculino digite M, para Feminino digite F: ";
    cin >> sexo;
    fflush(stdin);

    switch (sexo)
    {
    case 'M':
        ideal = (72.7 * h) - 58;

        if ((ideal-3) <= peso && (ideal+3) >= peso)
            cout << "\nVoc� est� dentro do seu peso ideal!";

        else if ((ideal+3) < peso)
            cout << "\nVoc� est� acima do seu peso ideal!";

        else if ((ideal-3) > peso)
            cout << "\nVoc� est� abaixo do seu peso ideal!";
    break;

    case 'F':
        ideal = (62.1 * h) - 44.7;

        if ((ideal-3) <= peso && (ideal+3) >= peso)
            cout << "\nVoc� est� dentro do seu peso ideal!";

        else if ((ideal+3) < peso)
            cout << "\nVoc� est� acima do seu peso ideal!";

        else if ((ideal-3) > peso)
            cout << "\nVoc� est� abaixo do seu peso ideal!";

    break;

    default:
        cout << "\nSexo inv�lido." << endl;
        break;

    }
}
