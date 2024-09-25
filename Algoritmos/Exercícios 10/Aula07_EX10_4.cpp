/*4 - Escrever um algoritmo que leia uma matriz M[3][3]. A seguir, o algoritmo deverá:
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
    int l, c, matrix[3][3], maior = matrix[0][0], posicao;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            matrix[l][c] = rand() % 50;
            cout << matrix[l][c] << "\t";

            if (matrix[l][c] > maior){
                maior = matrix[l][c];
                posicao = (l, c);
            }
        }
        cout << "\n";
    }
     cout << "\n\nMaior valor da Matriz: " << maior << " - Posição: " << posicao;
}
