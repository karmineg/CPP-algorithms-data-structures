/*
1 - Escreva um programa que lê um número inteiro. Mostrar se o número é
ou não primo. Número primo é aquele que é divisível por 1 e por ele mesmo.
Construa o diagrama de blocos deste exercício.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, num, cont = 0;

    cout << "Informe um número qualquer: ";
    cin >> num;
    fflush(stdin);

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            cont++;
    }

    if(cont == 0)
        cout << "O número " << num << " é primo.";
    else
        cout << "O número " << num << " não é primo.";
}
