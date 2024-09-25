/*18 - Crie um programa que manipule um vetor V[10] que deve ser preenchido com valores
inteiros entre 15 e 50, sem números repetidos.
Após gerar o vetor o programa deverá:
- Exibir o vetor na tela
- Exibir o vetor em ordem crescente e decrescente
- Exibir o percentual de valores pares e ímpares constantes no vetor
- Exibir os elementos que se encontram em posições (índices) ímpares*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void vetor(int V[]);
void ordem(int V[]);
float porcent(int V[]);
void posicao(int V[]);

main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[10];

    vetor(vet);
    posicao(vet);
    ordem(vet);
    porcent(vet);

}

void vetor(int V[]) {
    int i, aux, y, x;

    srand(time(NULL));
    cout << "Vetor: ";
    for (i = 0; i < 10; i++) {
        for (i = 0; i < 10; i++) {
        aux = rand() % 36 + 15;

        if (i == 0) {
            V[i] = aux;
                cout << V[i] << ", ";
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
                cout << V[i] << ", ";
            }

            else
                i--;
            }
        }
    }
}

void posicao(int V[]) {
    cout << "\nÍndices ímpares: ";
    for (int i = 1 ; i < 10 ; i+=2) {
        cout << V[i] << ", ";
    }
}

void ordem(int V[]) {
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

    for (int x = 0; x < 10; x++) {
        for (int i = x + 1; i < 10; i++) {
            if (V[i] < V[x]) {
                aux = V[x];
                V[x] = V[i];
                V[i] = aux;
            }
        }
    }

    cout << "\nVetor crescente: ";
    for (int i = 0 ; i < 10 ; i++) {
        cout << V[i] << ", ";
    }
}

float porcent(int V[]) {
    setlocale(LC_ALL, "Portuguese");
    float par = 0, imp = 0, porcpar, porcimp;

    for (int i = 0; i < 10; i++){
        if (V[i] % 2 == 0)
            par++;

        else
            imp++;
    }

    porcpar = (par / 10) * 100.0;
    porcimp = (imp / 10) * 100.0;

    cout <<"\nPorcentual de Pares: " << porcpar << "%";
    cout <<"\nPorcentual de Ímpares: " << porcimp << "%";
}
