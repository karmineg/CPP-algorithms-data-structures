/* 1 - Escreva um programa que l� um n�mero inteiro. Mostrar se o n�mero � ou n�o primo. N�mero primo
� aquele que � divis�vel por 1 e por ele mesmo. Construa o diagrama de blocos deste exerc�cio. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num, cont=0, i;

    cout << "Informe um n�mero: ";
    cin >> num;
    for (i=1; i<=num; i++)
    {
        if(num%i == 0)
            cont++;
    }
    if(cont==2)
        cout << "O n�mero " << num << " � primo!\n";
    else
        cout << "O n�mero " << num << " n�o � primo!\n";
}
