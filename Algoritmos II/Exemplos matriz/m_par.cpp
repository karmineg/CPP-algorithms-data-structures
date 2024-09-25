void matriz(int M[][5]);
void mostra(int M[][5]);
void calcula(int M[][5]);
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void matriz(int M[][5]);
void mostra(int M[][5]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int matrix[3][5];

    matriz(matrix);
    mostra(matrix);

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
}
