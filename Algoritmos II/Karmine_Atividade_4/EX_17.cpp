/*17 – Crie um programa que manipule uma matriz 3 x 5 de números inteiros, o sistema deverá
utilizar funções para realizar as ações apresentadas abaixo:
- Gerar valores para preencher toda a matriz, não sendo permitido números maiores que 50 e
somente números pares serão aceitos na matriz
- Mostrar a matriz gerada e sua respectiva matriz transposta.
- Calcular e mostrar o maior, o menor e a média dos elementos existentes na matriz.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void matriz(int M[][5]);
void mostra(int M[][5]);
void calcula(int M[][5]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int matrix[3][5];

    matriz(matrix);
    mostra(matrix);
    calcula(matrix);

}

void matriz(int M[][5]) {
    srand(time(NULL));
    int l, c;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            M[l][c] = rand() % 25 * 2;
        }
    }
}

void mostra(int M[][5]) {
    int l, c, trans[5][3];

    cout << "Matriz gerada: \n";
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            trans[c][l] = M[l][c];
        }
    }

    cout << "Matriz transposta: \n";
    for (l = 0; l < 5; l++) {
        for (c = 0; c < 3; c++) {
            cout << trans[l][c] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}

void calcula(int M[][5]) {
    setlocale(LC_ALL, "Portuguese");

    int l, c, maior = M[0][0], menor = M[l][c];
    float soma = 0, media;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 5; c++) {
            soma += M[l][c];

            if (M[l][c] > maior) {
                maior = M[l][c];
            }
            else if (M[l][c] < menor){
                menor = M[l][c];
            }
        }
    }
    media  = soma / 15;

     cout << "\nMaior valor da Matriz: " << maior;
     cout << "\nMenor valor da Matriz: " << menor;
     cout << "\nMédia dos elementos da matriz: " << media << endl;
}
