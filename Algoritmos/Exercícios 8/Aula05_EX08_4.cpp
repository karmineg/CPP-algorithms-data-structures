/* 4 - Fa�a um algoritmo para desenhar um tri�ngulo ret�ngulo na tela. Onde deve ser informado a altura
(indicando o n�mero de caracteres nos lados do tri�ngulo) e exibir o tri�ngulo na tela, usando o
caractere '*'. A altura m�nima � 3 e a m�xima � de 20. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, i = 1, x = 1;

    cout << "Digite o tamanho do tri�ngulo (entre 3 e 20): ";
    cin >> (num);

    if (num < 3 or num > 20){
        cout << "N�mero inv�lido!" << endl;
    }

    else {
        while (num > 0){

            for (i = x; i > 1; i--){
            cout << "* ";
            }

        cout << "*" << endl;

        num--;
        x++;
        }
        }
}
