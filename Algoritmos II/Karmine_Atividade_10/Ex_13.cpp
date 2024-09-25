/*13 - Escreva uma função que receba como parâmetro um array de inteiros com N valores, e determina o
maior elemento do array e o número de vezes que este elemento ocorreu no array. Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve fornecer para o programa
que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes). A função deve ser
do tipo void, utilize ponteiros para fornecer as informações solicitadas*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void mostrarTexto(string txt, char *C);
void gerarN(int *vet, int *N, string txt);
void GerarVetor(int *N);

main() {
    setlocale(LC_ALL, "Portuguese");
    int *S = new int;
    cout << "> Informe a semente dos randômicos (inteiro): ";
    cin >> *S;

    int *N = new int;
    do {
        cout << "> Informe quantidade de números: ";
        cin >> *N;
        if(*N < 1) cout << "Valor negativo ou nulo inválido!\n";
        else break;
    } while(true);

    srand(*S);
    GerarVetor(N);
}

void mostrarTexto(string txt, char *C) {
    cout << " - ";
}

void gerarN(int *vet, int *N, string txt) {
    *vet = 1 + (rand() % *N);
    cout << *vet << txt;
}

void GerarVetor(int *N) {
    int *vet = new int[*N];

    cout << "> Vetor: ";
    for(int i = 0; i < *N - 1; i++) {
        gerarN(vet, N, ", ");
        vet++;
    } gerarN(vet, N, ";");
    vet -= (*N - 1);

    int *M = new int(*vet);
    int *Q = new int(1);
    for(int i = 1; i < *N; i++) {
        vet++;
        if(*vet > *M) {
            *M = *vet;
            *Q = 1;
        } else if(*vet == *M) {
            *Q += 1;
        }
    }
    cout << endl << endl;
    cout << "> Maior elemento: " << *M << endl;
    cout << "> Ocorrências: " << *Q;
}
