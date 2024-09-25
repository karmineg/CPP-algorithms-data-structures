/*
6 - Crie um algoritmo para simular um jogo de apostas onde o usuário deverá
informar 6 números
do
tipo inteiro não aceitando valores repetidos, o sistema deverá gerar
dinamicamente 6 valores sorteados
que  também  não  podem  ser  repetidos  e  devem  ser  entre  1  e  60
(inclusive),  após  o  algoritmo deve
apresentar os valores sorteados, os valores apostados pelo usuário e
quantos acertos ele teve, caso ele
tenha acertado menos de 4 valores deve exibir a mensagem: “Você não ganhou
nada”, 4 acertos “Você
acertou a quadra”, 5 acertos “Você acertou a quina”, 6 acertos “Parabéns
você está milionário”.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o randômico
    int i, aux, x, achou, conta = 0;
    int aposta[6], sorteados[6];

    for(i = 0; i < 6; i++)
    {
        do
        {
            system("cls");
            cout << "Digite a sua aposta [" << i + 1 << "]: ";
            cin >> aux;
            fflush(stdin);
            if(aux < 1 or aux > 60)
            {
                cout << "VALOR INVÁLIDO PARA APOSTA.";
                getchar();
            }
        }
        while(aux < 1 or aux > 60);

        if(i == 0)
        {
            aposta[i] = aux;
        }
        else
        {
            achou = 0;
            for(x = 0; x < i; x++)
            {
                if(aposta[x] == aux)
                {
                    achou++;
                    break;
                }
            }
            if(achou == 0)
                aposta[i] = aux;
            else
            {
                cout << "VALOR JÁ REGISTRADO NESTA APOSTA.";
                getchar();
                i--;
            }
        }
    }

    cout << "\n\nAPOSTA REALIZADA: " << endl;

    for(i = 0; i < 6; i++)
    {
        cout << aposta[i] << ", ";
    }

    for(i = 0; i < 6; i++)
    {
        aux = rand() % 60 + 1;

        if(i == 0)
            sorteados[i] = aux;
        else
        {
            achou = 0;
            for(x = 0; x < i; x++)
            {
                if(sorteados[x] == aux)
                {
                    achou++;
                    break;
                }
            }
            if(achou == 0)
                sorteados[i] = aux;
            else
                i--;
        }
    }

    cout << "\n\nNÚMEROS SORTEADOS: " << endl;

    for(i = 0; i < 6; i++)
    {
        cout << sorteados[i] << ", ";
    }

    for(i = 0; i < 6; i++)
    {
        for(x = 0; x < 6; x++)
        {
            if(aposta[i] == sorteados[x])
               conta++;
        }
    }

    if(conta <= 3)
        cout << "\n\nVocê não ganhou nada";
    else if(conta == 4)
        cout << "\n\nVocê acertou a quadra";
    else if(conta == 5)
        cout << "\n\nVocê acertou a quina";
    else
        cout << "\n\nParabéns você está milionário";

}
