/*6 - Crie um algoritmo para simular um jogo de apostas onde o usu�rio dever� informar 6 n�meros do
tipo inteiro n�o aceitando valores repetidos, o sistema dever� gerar dinamicamente 6 valores sorteados
que tamb�m n�o podem ser repetidos e devem ser entre 1 e 60 (inclusive), ap�s o algoritmo deve
apresentar os valores sorteados, os valores apostados pelo usu�rio e quantos acertos ele teve, caso ele
tenha acertado menos de 4 valores deve exibir a mensagem: �Voc� n�o ganhou nada�, 4 acertos �Voc�
acertou a quadra�, 5 acertos �Voc� acertou a quina�, 6 acertos �Parab�ns voc� est� milion�rio�.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int acertos = 0, vetorx[6], vetory[6], i, x, y, aux;
    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        do {
            system("cls");
            cout << "Digite seus n�meros de aposta[" << i + 1 << "]: ";
            cin >> aux;
            fflush(stdin);

            if (aux < 1 or aux > 60){
                cout << "Valor inv�lido!" << endl;
                getchar();
            }
        }
    while (aux < 1 or aux > 60);

    if (i == 0) {
        vetorx[i] = aux;
    }

    else {
        y = 0;
        for (x = 0; x < i; x++){
            if (vetorx[x] == aux){
                y++;
                break;
            }
        }

        if (y == 0)
            vetorx[i] = aux;

        else {
            cout << "Valor j� registrado na aposta!";
            getchar();
            i--;
            }
        }
    }

    cout << "Aposta realizada: " << endl;
    for (i = 0; i < 6; i++) {
        cout << vetorx[i] << ", ";
    }

    for (i = 0; i < 6; i++) {
        aux = rand() % 60 + 1;

        if (i == 0)
            vetory[i] = aux;

        else {
            y = 0;
            for (x = 0; x < i; x++) {
                if(vetory[x] == aux) {
                    y++;
                    break;
                }
            }

            if(y == 0)
                vetory[i] = aux;

            else
                i--;
        }
    }

    cout << "\n\nN�meros sorteados: " << endl;
    for(i = 0; i < 6; i++) {
        cout << vetory[i] << ", ";
    }

    for(i = 0; i < 6; i++) {
        for(x = 0; x < 6; x++) {
            if(vetorx[i] == vetory[x])
               acertos++;
        }
    }

    if (acertos <= 3)
        cout << "\n\nVoc� n�o ganhou nada!";

    else if (acertos == 4)
        cout << "\n\nVoc� acertou a quadra!";

    else if (acertos == 5)
        cout << "\n\nVoc� acertou a quina!";

    else
        cout << "\n\nParab�ns! Voc� est� milion�rio!";
}
