/*6 - Crie um algoritmo para simular um jogo de apostas onde o usuário deverá informar 6 números do
tipo inteiro não aceitando valores repetidos, o sistema deverá gerar dinamicamente 6 valores sorteados
que também não podem ser repetidos e devem ser entre 1 e 60 (inclusive), após o algoritmo deve
apresentar os valores sorteados, os valores apostados pelo usuário e quantos acertos ele teve, caso ele
tenha acertado menos de 4 valores deve exibir a mensagem: “Você não ganhou nada”, 4 acertos “Você
acertou a quadra”, 5 acertos “Você acertou a quina”, 6 acertos “Parabéns você está milionário”.*/

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
            cout << "Digite seus números de aposta[" << i + 1 << "]: ";
            cin >> aux;
            fflush(stdin);

            if (aux < 1 or aux > 60){
                cout << "Valor inválido!" << endl;
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
            cout << "Valor já registrado na aposta!";
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

    cout << "\n\nNúmeros sorteados: " << endl;
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
        cout << "\n\nVocê não ganhou nada!";

    else if (acertos == 4)
        cout << "\n\nVocê acertou a quadra!";

    else if (acertos == 5)
        cout << "\n\nVocê acertou a quina!";

    else
        cout << "\n\nParabéns! Você está milionário!";
}
