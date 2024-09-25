/*Ponteiro para Ponteiro
> Gerar vetor e mostarr > Ordenar vetor > Somar elementos do vetor*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void GerarVetor(int *P);
void MostrarVetor(int **P1);
void SomarVetor(int ***P2);
void OrdenarVetorC(int ****P3);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *Pv = new int[10];
    GerarVetor(Pv);
}

void GerarVetor(int *P){
    for(int i = 0; i < 10; i++) {
        *P = 1 + (rand() % 50);
        P++;
    }
    P -= 10;
    MostrarVetor(&P);
}

void MostrarVetor(int **P1){
    cout << "Vetor gerado: ";
    for(int i = 0; i < 10; i++) {
        cout << **P1;
        (*P1)++;
        if(i < 9)
            cout << ", ";
    }
    (*P1) -= 10;
    SomarVetor(&P1);
}

void SomarVetor(int ***P2){
    int *soma = new int(0);

    for(int i = 0; i < 10; i++) {
        *soma += ***P2;
        (**P2)++;
    }
    cout << "\n\nSoma dos elementos do vetor: " << *soma;
    (**P2) -= 10;
    OrdenarVetorC(&P2);
}

void OrdenarVetorC(int ****P3){
    cout << "\n\nVetor Ordenado Crescente: ";
    for(int x = 0; x < 9; x++) {
        int *PvX = new int(****P3);
        for(int i = 1; i <= 9 - x; i++) {
            (***P3)++;
            int *PvI = new int(****P3);
            if(*PvI > *PvX) {
                ****P3 = *PvX;
                *PvX = *PvI;
            }
        }
        (***P3) -= 9 - x;
        ****P3 = *PvX;
        cout << ****P3 << ", ";
        (***P3)++;
    }
    cout << ****P3;

    (***P3) -= 10;
}

