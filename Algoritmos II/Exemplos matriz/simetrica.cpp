#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void matriz(int M[][3]);
void simetrica(int M[][3]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int matrix[3][3];

    matriz(matrix);
    simetrica(matrix);

}

void matriz(int M[][3]) {
    srand(time(NULL));
    int l, c;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            M[l][c] = rand() % 2;
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
}

void simetrica(int M[][3]) {
    int yex = 1, l, c;

    for (l = 0; ( l < 3 ) && (yex == 1); l++) {
        for (c = 0; (c < l) && (yex == 1); c++) {
            if (M[l][c] != M[c][l])
                yex = 0;
            }
    }
  if (yex == 1)
     cout << "A matriz é simétrica!";

  else
    cout << "A matriz não é simétrica!";
}
