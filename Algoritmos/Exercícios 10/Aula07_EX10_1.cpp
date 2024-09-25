/* 1 – Escrever um programa que gere dois vetores X[10] e Y[10] com valores no intervalo de 0 a 50. A
seguir:
a) Ordenar o vetor X em ordem crescente. Mostre o vetor X.
b) Ordenar o vetor Y em ordem decrescente. Mostre o vetor Y.
c) Criar um vetor Z que contenha os valores ímpares de X. Mostre o vetor Z.
d) Criar um vetor W que contenha os valores pares de X. Mostre o vetor W.
e) Criar um vetor S que contenha os valores de X e Y que são maiores que 30. Mostre o vetor S.
f) Criar um vetor U que seja a união dos vetores X e Y.
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
    int i, x, y, aux, X[10], Y[10], Z[10] = {0}, W[10] = {0}, S[20] = {0}, U[20];

    for (x = 0; x < 10; x++) { //Crescente X
        X[x] = rand() % 51;
    }

    for (x = 0; x < 9; x++) {
        for (i = x + 1; i < 10; i++) {
            if (X[i] > X[x]) {
                aux = X[x];
                X[x] = X[i];
                X[i] = aux;
            }
        }
    }
    cout << "Elementos X (Crescente): ";
    for (x = 0; x < 10; x++) {
        cout << X[x] << ", ";
    }

    cout << endl; //Decrescente Y
    for (y = 0; y < 10; y++) {
        Y[y] = rand() % 51;
    }

    for (y = 0; y < 9; y++) {
        for (i = y + 1; i < 10; i++) {
            if (Y[y] < Y[i]) {
                aux = Y[y];
                Y[y] = Y[i];
                Y[i] = aux;
            }
        }
    }
    cout << "Elementos Y (Decrescente): ";
    for (y = 0; y < 10; y++) {
        cout << Y[y] << ", ";
    }

    cout << endl; // União
    for(x = 0; x < 10; x++){
        U[x] = X[x];
    }
    for(y = 0; y < 10; y++){
        U[y + 10] = Y[y];
    }
    cout << "Vetor U (União X e Y): ";
    for(i = 0; i < 20; i++){
        cout << U[i] << ", ";
    }

    cout << endl; //Ímpares X
    for (x = 0; x < 10; x++) {
        if (X[x]%2!=0){
         Z[x] = X[x];
        }
        else
         W[x]=X[x];
    }
    cout << "Vetor Z (Ímpares de X): ";
    for (i = 0; i < 10; i++) {
        if (Z[i] != 0)
        cout << Z[i] << ", ";
        }

    cout << endl; //Pares X
    cout << "Vetor W (Pares de X): ";
    for (i = 0; i < 10; i++) {
        if (W[i] != 0)
        cout << W[i] << ", ";
    }

    cout << endl; //Maiores que 30 do vetor U
    cout << "Vetor S (Maiores que 30): ";
    for (x = 0; x < 20; x++) {
       if (U[x] > 30)
       S[x] = U[x];
    }
    for(i = 0; i < 20; i++){
        if (S[i] != 0)
        cout << S[i] << ", ";
    }
}
