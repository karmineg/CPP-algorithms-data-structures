/*
1 - Escreva um programa que l� um n�mero inteiro. Mostrar se o n�mero �
ou n�o primo. N�mero primo � aquele que � divis�vel por 1 e por ele mesmo.
Construa o diagrama de blocos deste exerc�cio.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, num, cont = 0;

    cout << "Informe um n�mero qualquer: ";
    cin >> num;
    fflush(stdin);

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            cont++;
    }

    if(cont == 0)
        cout << "O n�mero " << num << " � primo.";
    else
        cout << "O n�mero " << num << " n�o � primo.";
}
