#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void inicializar_grafo(int grafo[64][64]) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            grafo[i][j] = 0;
        }
    }
}

int posicao_indice(int linha, int coluna, int t) {
    return linha * t + coluna;
}

void inserir_dama(int grafo[64][64], int linha, int coluna, int t) {
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

void inserir_cavalo(int grafo[64][64], int linha, int coluna, int t) {
    int pos = posicao_indice(linha, coluna, t);
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos[i][0];
        int nova_coluna = coluna + movimentos[i][1];
        if (nova_linha >= 0 && nova_linha < t && nova_coluna >= 0 && nova_coluna < t) {
            grafo[pos][posicao_indice(nova_linha, nova_coluna, t)] = 1;
        }
    }
}

void inserir_bispo(int grafo[64][64], int linha, int coluna, int t) {
    int pos = posicao_indice(linha, coluna, t);

    for (int i = 1; i < t; i++) {
        if (linha + i < t && coluna + i < t)
            grafo[pos][posicao_indice(linha + i, coluna + i, t)] = 1;
        if (linha - i >= 0 && coluna - i >= 0)
            grafo[pos][posicao_indice(linha - i, coluna - i, t)] = 1;
        if (linha + i < t && coluna - i >= 0)
            grafo[pos][posicao_indice(linha + i, coluna - i, t)] = 1;
        if (linha - i >= 0 && coluna + i < t)
            grafo[pos][posicao_indice(linha - i, coluna + i, t)] = 1;
    }
}

void inserir_torre(int grafo[64][64], int linha, int coluna, int t) {
    int pos = posicao_indice(linha, coluna, t);

    for (int i = 0; i < t; i++) {
        if (i != linha) {
            grafo[pos][posicao_indice(i, coluna, t)] = 1;
        }
        if (i != coluna) {
            grafo[pos][posicao_indice(linha, i, t)] = 1;
        }
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

void mostrar_tabuleiro(int grafo[64][64], int linha, int coluna, int t, char peca) {
    char tabuleiro[8][8];
    int pos = posicao_indice(linha, coluna, t);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    tabuleiro[linha][coluna] = peca;
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
    system("color 05");
    setlocale(LC_ALL, "Portuguese");
    int t = 8;
    int grafo[64][64];
    inicializar_grafo(grafo);

    int linha, coluna;
    char peca;
    cout << "> Escolha a peca (D para Dama, C para Cavalo, T para Torre, B para Bispo): ";
    cin >> peca;

    cout << "> Informe a posicao atual da peca (linha): ";
    cin >> linha;

    cout << "> Informe a posicao atual da peca (coluna): ";
    cin >> coluna;

    if (linha >= 0 && linha < t && coluna >= 0 && coluna < t) {
        switch (peca) {
            case 'D':
            case 'd':
                inserir_dama(grafo, linha, coluna, t);
                mostrar_tabuleiro(grafo, linha, coluna, t, 'D');
                break;
            case 'C':
            case 'c':
                inserir_cavalo(grafo, linha, coluna, t);
                mostrar_tabuleiro(grafo, linha, coluna, t, 'C');
                break;
            case 'T':
            case 't':
                inserir_torre(grafo, linha, coluna, t);
                mostrar_tabuleiro(grafo, linha, coluna, t, 'T');
                break;
            case 'B':
            case 'b':
                inserir_bispo(grafo, linha, coluna, t);
                mostrar_tabuleiro(grafo, linha, coluna, t, 'B');
                break;
            default:
                cout << "> Peca invalida!" << endl;
                break;
        }
    } else {
        cout << "> Posicao invalida!" << endl;
    }
}
