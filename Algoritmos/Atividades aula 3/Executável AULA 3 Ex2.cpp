/* 2. Escreva um programa que receba um número qualquer e verifique se o número lido é par, caso seja
execute a divisão deste número por 2, caso não seja par execute a soma deste número com 5 mostrando
em qualquer condição o resultado na tela. Crie também o diagrama de blocos deste exercício. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num;

    cout << "Informe um número: ";
    cin >> (num);

    if (num % 2 == 0){
        cout << " \n divisão do número por 2: " << num / 2;
    } else {
        cout << " \n soma do número com 5: " << num + 5;
    };


}
