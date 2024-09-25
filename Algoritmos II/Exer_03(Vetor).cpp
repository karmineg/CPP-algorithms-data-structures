#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void vetor(int V[]);
void mostra(int V[]);
void recursiva(int V[], int a, int b, int maxi);

main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[10];

    vetor(vet);
    mostra(vet);
    recursiva(vet, 0, 1, 0);

}

void vetor(int V[]) {
    int i, aux, y, x;

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        for (i = 0; i < 10; i++) {
        aux = rand() % 100; // de 0 a 99

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
    }
}

void mostra(int V[]) {
    int i;

    cout << "Vetor: ";
    for (i = 0; i < 10; i++){
        cout << V[i] << ", ";
    }
}

void recursiva(int V[], int a, int b, int maxi) {
    if((maxi > V[b]) and (maxi > V[a]) and (maxi > V[b + 1]) and (maxi > V[a + 1]) and (maxi > V[b + 2]) and (maxi > V[a + 2]) and (maxi > V[a + 3]) and (maxi > V[b + 3]) and (maxi > V[a + 4]) and (maxi > V[b + 4]) and (maxi > V[a + 5]) and (maxi > V[b + 5]))
        cout << "\nMaior valor do vetor: " << maxi;

    else {
        if(V[a] > V[b]) {
            maxi = V[a];
            a++;
            b++;
            recursiva(V, a, b, maxi);
        }

        else {
            maxi = V[b];
            a++;
            b++;
            recursiva(V, a, b, maxi);
        }
    }

}
