/*
4 - Fa�a um algoritmo para desenhar um tri�ngulo ret�ngulo na tela.
Onde deve ser informado a altura
(indicando o n�mero de caracteres nos lados do tri�ngulo) e exibir o
tri�ngulo na tela, usando o
caractere '*'. A altura m�nima � 3 e a m�xima � de 20.
Exemplo: altura = 6
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int altura, i, x;

    do
    {
        system("cls"); //limpa a tela
        cout << "Informe a altura do tri�ngulo: ";
        cin >> altura;
        fflush(stdin);
        if(altura < 3 or altura > 20)
        {
            cout << "\nAltura inv�lida.";
            getchar();
        }
    }
    while(altura < 3 or altura > 20);

    for(i = 1; i <= altura; i++)
    {
        for(x = 1; x <= i; x++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

}
