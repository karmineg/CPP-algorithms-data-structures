#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void matriz(int M[][5]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int matrix[5][5];

    matriz(matrix);

}

void matriz(int M[][5]) {
    int i, aux, y, x, V[25], l, c;

    srand(time(NULL));
    for (i = 0; i < 25; i++) {
        for (i = 0; i < 25; i++) {
        aux = rand() % 36 + 15;

        if (i == 0) {
            V[i] = aux;
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
            }

            else
                i--;
            }
        }
        M[0][0] = V[0]; M[0][1] = V[1]; M[0][2] = V[2]; M[0][3] = V[3]; M[0][4] = V[4]; M[1][0] = V[5]; M[1][1] = V[6]; M[1][2] = V[7]; M[1][3] = V[8]; M[1][4] = V[9]; M[2][0] = V[10]; M[2][1] = V[11]; M[2][2] = V[12]; M[2][3] = V[13]; M[2][4] = V[14];
        M[3][0] = V[15]; M[3][1] = V[16]; M[3][2] = V[17]; M[3][3] = V[18]; M[3][4] = V[19]; M[4][0] = V[20]; M[4][1] = V[21]; M[4][2] = V[22]; M[4][3] = V[23]; M[4][4] = V[24];
    }

    for (l = 0; l < 5; l++) {
        for (c = 0; c < 5; c++) {
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
}
