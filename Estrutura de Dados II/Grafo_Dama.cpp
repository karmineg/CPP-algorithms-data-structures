#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

void inicializar_grafo(int grafo[64][64]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grafo[i][j] = 0;
        }
    }
}

int posicao_indice(int linha, int coluna, int t) {
    return linha * t + coluna;
}

void inserir(int grafo[64][64], int linha, int coluna, int t) {
    int pos = posicao_indice(linha, coluna, t);

    for (int i = 0; i < t; i++) {
        if (i != linha) {
            grafo[pos][posicao_indice(i, coluna, t)] = 1;
        }
        if (i != coluna) {
            grafo[pos][posicao_indice(linha, i, t)] = 1;
        }
    }

    for (int i = 1; i < t; i++) {
        if (linha + i < t && coluna + i < t) grafo[pos][posicao_indice(linha + i, coluna + i, t)] = 1;
        if (linha - i >= 0 && coluna - i >= 0) grafo[pos][posicao_indice(linha - i, coluna - i, t)] = 1;
        if (linha + i < t && coluna - i >= 0) grafo[pos][posicao_indice(linha + i, coluna - i, t)] = 1;
        if (linha - i >= 0 && coluna + i < t) grafo[pos][posicao_indice(linha - i, coluna + i, t)] = 1;
    }
}

void mostrar_grafo(int grafo[64][64], int t) {
    cout << "Grafo:" << endl;
    for (int i = 0; i < t * t; i++) {
        cout << "Vértice " << i << " conectado a: ";
        for (int j = 0; j < t * t; j++) {
            if (grafo[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void mostrar_tabuleiro(int grafo[64][64], int linha, int coluna, int t) {
    char tabuleiro[8][8];
    int pos = posicao_indice(linha, coluna, t);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    tabuleiro[linha][coluna] = 'D';
    for (int i = 0; i < t * t; i++) {
        if (grafo[pos][i] == 1) {
            int l = i / t;
            int c = i % t;
            tabuleiro[l][c] = 'X';
        }
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    system ("color 05");
    setlocale(LC_ALL, "Portuguese");
    int t = 8;
    int grafo[64][64];
    inicializar_grafo(grafo);

    int linha, coluna;
    cout << "> Informe a posicao atual da dama (linha): ";
    cin >> linha;

    cout << "> Informe a posicao atual da dama (coluna): ";
    cin >> coluna;

    if (linha >= 0 && linha < t && coluna >= 0 && coluna < t) {
        inserir(grafo, linha, coluna, t);
        mostrar_tabuleiro(grafo, linha, coluna, t);
    } else cout << "> Posição inválida!" << endl;
}
