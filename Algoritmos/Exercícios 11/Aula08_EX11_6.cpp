/* 6 - Escrever um algoritmo que gere uma matriz M[10][10] com valores aleatórios, intervalo de 0 a 1000.
A seguir, o algoritmo deverá:
a) Mostrar a matriz gerada;
b) Determinar o elemento minimax desta matriz;
c) Mostrar a posição e o valor do elemento minimax.
- Define-se o valor denominado minimax de uma matriz como: o menor elemento da linha onde se
encontra o maior elemento da matriz.
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
    int l, c, matrix[10][10], maior = 0, posicao, menor = 1000;

    for (l = 0; l < 10; l++) {
        for (c = 0; c < 10; c++) {
            matrix[l][c] = rand() % 1001;
            cout << matrix[l][c] << "\t";

            if (matrix[l][c] > maior){
                maior = matrix[l][c];
                posicao = l;
            }
        }
        cout << "\n";
    }
    for (c = 0; c < 10; c++) {
            if (matrix[posicao][c] < menor)
                menor = matrix[posicao][c];

    }
    cout << "Maior: " << maior << endl;
    cout << "Minimax: " << menor << endl;
    cout << "Posição: " << posicao + 1 << endl;
}
