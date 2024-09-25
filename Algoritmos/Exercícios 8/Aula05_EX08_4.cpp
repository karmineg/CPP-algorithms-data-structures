/* 4 - Faça um algoritmo para desenhar um triângulo retângulo na tela. Onde deve ser informado a altura
(indicando o número de caracteres nos lados do triângulo) e exibir o triângulo na tela, usando o
caractere '*'. A altura mínima é 3 e a máxima é de 20. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, i = 1, x = 1;

    cout << "Digite o tamanho do triângulo (entre 3 e 20): ";
    cin >> (num);

    if (num < 3 or num > 20){
        cout << "Número inválido!" << endl;
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
