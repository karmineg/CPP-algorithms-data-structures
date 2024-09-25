/* 2 - Escrever um programa que leia um número inteiro e verifique se o número lido é um número perfeito.
Um número perfeito é aquele em que a soma dos seus divisores, exceto ele, seja igual a ele próprio.
Ex.: 6 = 1+2+3; 28=1+2+4+7+14. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, soma = 0;

    cout << "Escreva um número: ";
    cin >> (num);

    for (int i = 1; i < num; i++ ){
        if(num % i == 0){
           soma = soma + i;
        }
    }
    if(num == soma){
        cout << "O número " << num << " é perfeito!" << endl;
    } else {
        cout << "O número " << num << " não é perfeito!" << endl;
    }

}
