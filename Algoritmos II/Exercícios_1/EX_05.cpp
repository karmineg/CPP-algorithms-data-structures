/* 5 – Crie um programa que manipule um vetor V[10] que deve ser preenchido com valores
inteiros entre 15 e 50, sem números repetidos.
Após gerar o vetor o programa deverá:
- Exibir o vetor na tela
- Exibir o vetor em ordem decrescente
- Exibir o percentual de valores pares e ímpares constantes no vetor
- Exibir a soma e a média dos elementos do vetor. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int V[10], i, x, y, aux;
    float porcpar, porcimp, par = 0, imp = 0, media, soma = 0;;

    cout << "Vetor: ";
    for (i = 0; i < 10; i++) {
        for (i = 0; i < 10; i++) {
        aux = rand() % 36 + 15;

        if (i == 0) {
            V[i] = aux;
            soma += V[i];
                cout << V[i] << ", ";

                if (V[i] % 2 == 0)
                    par++;

                else
                    imp++;
        }

        else {
            y = 0;
            for (x = 0; x < i; x++) {
                if(V[x] == aux) {
                    y++;
                    break;
                }
            }

            if (y == 0) {
                V[i] = aux;
                soma += V[i];
                cout << V[i] << ", ";

                if (V[i] % 2 == 0)
                    par++;

                else
                    imp++;
            }

            else
                i--;
            }
        }
    }

    for (int x = 0; x < 10; x++) {
        for (int i = x + 1; i < 10; i++) {
            if (V[i] > V[x]) {
                aux = V[x];
                V[x] = V[i];
                V[i] = aux;
            }
        }
    }

    cout<<"\nVetor decrescente: ";
    for (int i = 0 ; i < 10 ; i++) {
        cout << V[i] << ", ";
    }

    porcpar = (par / 10) * 100.0;
    porcimp = (imp / 10) * 100.0;
    media = soma / 10;

    cout <<"\nPorcentual de Pares: " << porcpar << "%";
    cout <<"\nPorcentual de Ímpares: " << porcimp << "%";
    cout << "\nSoma do Vetor: " << soma;
    cout << "\nMédia do Vetor: " << media;
}
