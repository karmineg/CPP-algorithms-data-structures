/* 5 - Escrever um algoritmo que gere duas matrizes A[3][3] e B[3][3] com valores aleatórios, intervalo
de 0 a 50. A seguir, o algoritmo deverá calcular a soma das matrizes A e B e gravar o resultado em
C[3][3].
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int l, c, matrix[3][3], matriy[3][3], matriz[3][3];

    cout << "Matriz A: \n";
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            matrix[l][c] = rand() % 51;
            cout << matrix[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
    cout << "Matriz B: \n";
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            matriy[l][c] = rand() % 51;
            cout << matriy[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
    cout << "Matriz C: \n";
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            matriz[l][c] = matrix[l][c] + matriy[l][c];
            cout << matriz[l][c] << "\t";
        }
        cout << "\n";
    }

}
