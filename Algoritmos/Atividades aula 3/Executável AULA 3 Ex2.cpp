/* 2. Escreva um programa que receba um n�mero qualquer e verifique se o n�mero lido � par, caso seja
execute a divis�o deste n�mero por 2, caso n�o seja par execute a soma deste n�mero com 5 mostrando
em qualquer condi��o o resultado na tela. Crie tamb�m o diagrama de blocos deste exerc�cio. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num;

    cout << "Informe um n�mero: ";
    cin >> (num);

    if (num % 2 == 0){
        cout << " \n divis�o do n�mero por 2: " << num / 2;
    } else {
        cout << " \n soma do n�mero com 5: " << num + 5;
    };


}
