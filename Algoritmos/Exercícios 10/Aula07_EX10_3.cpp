/*3 - Elabore um algoritmo que gere uma matriz 3x6 com valores aleatórios, intervalo de 0 a 50. Ao final,
o algoritmo deverá:
a) Mostrar os valores da matriz;
b) Pedir um valor ao usuário;
c) Multiplicar todos os valores pelo valor fornecido pelo usuário;
d) Mostrar novamente os valores da matriz.
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
    int l, c, matrix[3][6], num;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 6; c++) {
            matrix[l][c] = rand() % 51;
            cout << matrix[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << "\nInforme um valor: " << endl;
    cin >> num;
    cout << "\n";
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 6; c++) {
            matrix[l][c] = matrix[l][c] * num;
            cout << matrix[l][c] << "\t";
        }
        cout << "\n";
    }

}
