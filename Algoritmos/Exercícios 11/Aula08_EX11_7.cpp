/* 7 - Escrever um algoritmo que leia uma matriz M[3][3]. A seguir, o algoritmo deverá:
a) Mostrar a matriz lida;
b) Encontrar o menor elemento da matriz e mostrá-lo juntamente com sua posição (linha, coluna).
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
    int l, c, matrix[3][3], menor = matrix[l][c], posicaol, posicaoc;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            cout << "Informe o elemento [" << l << "][" << c << "]: ";
            cin >> matrix[l][c];
            fflush(stdin);

            if (matrix[l][c] < menor){
                menor = matrix[l][c];
                posicaol = l;
                posicaoc = c;
            }
        }
    }

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            cout << matrix[l][c] << "\t";
        }
        cout << "\n";
    }
    cout << "\n\nMenor valor da Matriz: " << menor << " - Posição: " << posicaol << ", " << posicaoc;

}
