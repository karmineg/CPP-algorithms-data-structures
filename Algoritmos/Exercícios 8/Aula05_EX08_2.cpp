/* 2 - Escrever um programa que leia um n�mero inteiro e verifique se o n�mero lido � um n�mero perfeito.
Um n�mero perfeito � aquele em que a soma dos seus divisores, exceto ele, seja igual a ele pr�prio.
Ex.: 6 = 1+2+3; 28=1+2+4+7+14. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, soma = 0;

    cout << "Escreva um n�mero: ";
    cin >> (num);

    for (int i = 1; i < num; i++ ){
        if(num % i == 0){
           soma = soma + i;
        }
    }
    if(num == soma){
        cout << "O n�mero " << num << " � perfeito!" << endl;
    } else {
        cout << "O n�mero " << num << " n�o � perfeito!" << endl;
    }

}
