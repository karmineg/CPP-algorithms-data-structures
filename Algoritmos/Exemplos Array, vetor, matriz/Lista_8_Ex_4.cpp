/*
4 - Faça um algoritmo para desenhar um triângulo retângulo na tela.
Onde deve ser informado a altura
(indicando o número de caracteres nos lados do triângulo) e exibir o
triângulo na tela, usando o
caractere '*'. A altura mínima é 3 e a máxima é de 20.
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
        cout << "Informe a altura do triângulo: ";
        cin >> altura;
        fflush(stdin);
        if(altura < 3 or altura > 20)
        {
            cout << "\nAltura inválida.";
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
