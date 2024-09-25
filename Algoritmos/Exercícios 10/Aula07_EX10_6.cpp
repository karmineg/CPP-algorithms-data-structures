/* 6 - Crie um algoritmo que leia um número inteiro N. Em seguida, gere uma matriz quadrada N x N com
valores aleatórios, intervalo de 0 a 9. Ao final, o calcule e mostre a soma:
a) Dos elementos da linha 4;
b) Dos elementos da coluna 2;
c) Dos elementos da diagonal principal;
d) Dos elementos da diagonal secundária
e) De todos os elementos da matriz.
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
    int N, l, c, soma = 0, somap = 0, somas = 0, somal4 = 0, somac2 = 0;

    cout << "Quantas linhas e colunas deseja na matriz?: " << endl;
    cin >> N;

    int matrix[N][N];

    cout << "Matriz: \n";
    for (l = 0; l < N; l++) {
        for (c = 0; c < N; c++) {
            matrix[l][c] = rand() % 9 + 1;
            soma += matrix[l][c];
            cout << matrix[l][c] << "\t";
            if (l == c)
                somap += matrix[l][c];

            if (l + c == N - 1)
                somas += matrix[l][c];
        }
        cout << "\n";
    }
    for (c = 0; c < N; c++) {
      l = 3;
      somal4 += matrix[l][c];
      }
    for (l = 0; l < N; l++) {
        c = 1;
        somac2 += matrix[l][c];
        }

    cout << "Soma de todos elementos da matriz: " << soma << endl;
    cout << "Soma da diagonal principal da matriz: " << somap << endl;
    cout << "Soma da diagonal secundária da matriz: " << somas << endl;
    cout << "Soma linha 4: "<< somal4 << endl;
    cout << "Soma coluna 2: "<< somac2 << endl;
}
