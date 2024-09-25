/* 4 - Elabore um programa que possibilite a realização dos seguintes cálculos:
1 – Potenciação (entrada dois valores inteiros e positivos)
2 – Raiz quadrada (entrada um valor inteiro e positivo)
3 - Arredondar o valor seguindo o critério da primeira casa decimal e mostrar na tela
(entrada um valor float)
4 – Verificar se um valor é primo ou não (entrada um valor inteiro positivo)
5 – Verificar se um valor é um número perfeito ou não (entrada um valor inteiro positivo).
O sistema deverá apresentar um menu com as opções e conforme a opção desejada será
solicitado os dados de entrada. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num1, num2, menu = -1, i, resto = 0, soma = 0, flag = 1;
    float num;

    do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES##############" << endl;
        cout << "# 0 - Sair                             #" << endl;
        cout << "# 1 - Potenciação                      #" << endl;
        cout << "# 2 - Raiz quadrada                    #" << endl;
        cout << "# 3 - Arredondar o valor               #" << endl;
        cout << "# 4 - Verificar se é primo             #" << endl;
        cout << "# 5 - Verificar se é um número perfeito#" << endl;
        cout << "########################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

            case 1 :
            system("cls");
            cout << "Digite um valor: ";
            cin >> num1;

            cout << "\nDigite o expoente: ";
            cin >> num2;

            cout << "\nResultado: " << pow(num1, num2);
            fflush(stdin);
            getchar();
            break;

            case 2 :
            system("cls");
            cout << "Digite um valor: ";
            cin >> num1;

            cout << "\nResultado: " << sqrt(num1);
            fflush(stdin);
            getchar();
            break;

            case 3 :
            system("cls");
            cout << "Digite um valor: ";
            cin >> num;

            cout << "\nResultado: " << round(num);
            fflush(stdin);
            getchar();
            break;

            case 4 :
            system("cls");
            cout << "Digite um valor: ";
            cin >> num1;

           for (i = 2; i <= sqrt(num1); i++) {
                if (num1 % i == 0) {
                flag = 0;
                break;
                }
            }
                if(num1 <= 1)
                    flag = 0;

                if(flag == 1)
                    cout << "É primo" << endl;

                else
                    cout << "Não é primo" << endl;
            fflush(stdin);
            getchar();
            break;

            case 5 :
            system("cls");
            cout << "Digite um valor: ";
            cin >> num1;

            soma = 0;
            for(i = 1; i <= (num1 - 1); i++){
                resto = num1 % i;

                if(resto == 0)
                    soma += i;
            }
            if(soma == num1)
                cout << "É perfeito" << endl;
            else
                cout << "Não é perfeito" << endl;
            fflush(stdin);
            getchar();
            break;

            default :
                system("cls");

                cout << "Opção inválida.";
                getchar();
                break;
        };

    }
    while(menu != 0);
}

