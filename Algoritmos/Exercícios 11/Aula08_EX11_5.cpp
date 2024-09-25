/* 5 - Escrever um algoritmo que gere uma matriz M[4][4], intervalo de 0 a 50. A seguir, o algoritmo
deverá:
a) Mostrar a matriz gerada.
b) Criar um vetor V[16] e copiar os elementos da matriz M para o vetor V.
c) Mostrar o vetor V em ordem crescente.
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
    int l, c, matrix[4][4], vetor[16], i;

    for (l = 0; l < 4; l++) {
        for (c = 0; c < 4; c++) {
            matrix[l][c] = rand() % 51;
            cout << matrix[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;

    int indice = 0;
    for (l = 0; l < 4; l++) {
        for (c = 0; c < 4; c++) {
            vetor[indice] = matrix[l][c];
            indice++;
        }
    }

    cout << "Vetor matriz: ";
    for (i = 0; i < indice; i++) {
        cout << vetor[i] << ", ";
    }

}
