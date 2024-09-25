/*
6 - Crie um algoritmo para simular um jogo de apostas onde o usu�rio dever�
informar 6 n�meros
do
tipo inteiro n�o aceitando valores repetidos, o sistema dever� gerar
dinamicamente 6 valores sorteados
que  tamb�m  n�o  podem  ser  repetidos  e  devem  ser  entre  1  e  60
(inclusive),  ap�s  o  algoritmo deve
apresentar os valores sorteados, os valores apostados pelo usu�rio e
quantos acertos ele teve, caso ele
tenha acertado menos de 4 valores deve exibir a mensagem: �Voc� n�o ganhou
nada�, 4 acertos �Voc�
acertou a quadra�, 5 acertos �Voc� acertou a quina�, 6 acertos �Parab�ns
voc� est� milion�rio�.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o rand�mico
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
                cout << "VALOR INV�LIDO PARA APOSTA.";
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
                cout << "VALOR J� REGISTRADO NESTA APOSTA.";
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

    cout << "\n\nN�MEROS SORTEADOS: " << endl;

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
        cout << "\n\nVoc� n�o ganhou nada";
    else if(conta == 4)
        cout << "\n\nVoc� acertou a quadra";
    else if(conta == 5)
        cout << "\n\nVoc� acertou a quina";
    else
        cout << "\n\nParab�ns voc� est� milion�rio";

}
