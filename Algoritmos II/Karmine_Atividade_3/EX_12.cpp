/*12 - Escreva uma função que manipule no programa principal um vetor de 10 posições de
inteiros, deverá ser implementado as seguintes funções:
- Função para preencher o vetor com números aleatórios entre 25 e 75
- Função para mostrar o vetor na tela
- Função para ordenar os elementos do vetor em ordem decrescente
- Função que deverá retornar a média dos elementos do vetor*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void vetor(int V[]);
void mostra(int V[]);
void decrescente(int V[]);
float media (int V[]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[10];

    vetor(vet);
    mostra(vet);
    decrescente(vet);
    media (vet);

}

void vetor(int V[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++){
        V[i] = rand() % 51 + 25;
    }
}

void mostra(int V[]) {
    int i;

    cout << "Vetor: ";
    for (i = 0; i < 10; i++){
        cout << V[i] << ", ";
    }
}

void decrescente(int V[]) {
    int x, i, aux;

    for (int x = 0; x < 10; x++) {
        for (int i = x + 1; i < 10; i++) {
            if (V[i] > V[x]) {
                aux = V[x];
                V[x] = V[i];
                V[i] = aux;
            }
        }
    }

    cout << "\nVetor decrescente: ";
    for (int i = 0 ; i < 10 ; i++) {
        cout << V[i] << ", ";
    }
}

float media (int V[]) {
    float media, soma = 0;

    for (int i = 0 ; i < 10 ; i++) {
        soma += V[i];
    }

     media = soma / 10;
     cout << "\nMédia do Vetor: " << media;

}

