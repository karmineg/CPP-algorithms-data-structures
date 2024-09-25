/* 6. Faça um programa que leia o ano de nascimento de uma pessoa e o ano atual, calcule e mostre:
− A idade desta pessoa
− Quantos anos ela terá em 2063. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int nas, atual, idade, anos;

    cout << "Informe o ano de nascimento: ";
    cin >> (nas);

    cout << "Informe o ano atual: ";
    cin >> (atual);

    idade = atual - nas;
    anos = 2063 - nas;

    cout << "Sua idade é " << idade << endl;

    cout << "Você terá em 2063 " << anos << " anos." << endl;

}
