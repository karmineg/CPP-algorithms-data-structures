/*13 - Escreva uma fun��o que receba como par�metro um array de inteiros com N valores, e determina o
maior elemento do array e o n�mero de vezes que este elemento ocorreu no array. Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a fun��o deve fornecer para o programa
que a chamou o valor 15 e o n�mero 3 (indicando que o n�mero 15 ocorreu 3 vezes). A fun��o deve ser
do tipo void, utilize ponteiros para fornecer as informa��es solicitadas*/

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
    cout << "> Informe a semente dos rand�micos (inteiro): ";
    cin >> *S;

    int *N = new int;
    do {
        cout << "> Informe quantidade de n�meros: ";
        cin >> *N;
        if(*N < 1) cout << "Valor negativo ou nulo inv�lido!\n";
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
    cout << "> Ocorr�ncias: " << *Q;
}
