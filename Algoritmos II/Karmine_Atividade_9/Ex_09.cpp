/*9 - Escreva um programa que receba dois valores n1 e n2 referente a quantidade de elementos dos
vetores x1 e x2, os quais devem ser alocados dinamicamente e preenchidos de forma randômica com
valores menores que a multiplicação de n1 com n2 e sem números repetidos. Após implemente uma
função que deverá gerar um vetor x3, alocado dinamicamente, contendo a intersecção de x1 e x2,
exemplo:
Sendo x1 = {1, 4, 3, 5, 6, 7} e x2 = {1, 2, 3, 9, 6, 8}, x3 irá conter {1, 3, 6}.
OBS: utilize aritmética de ponteiro para percorrer os vetores, deverá ser exibido os três vetores na tela.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void validN(int *N, int *C);
void adicionarVparaV(int *V, int *B, int *q);
int *valoresComuns(int *x1, int *n1, int *x2, int *n2, int *x3);
void mostrarV(string *Add, int *V, int *q, int *C);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *c1 = new int(1);
    int *n1 = new int;
    validN(n1, c1);

    int *c2 = new int(2);
    int *n2 = new int;
    validN(n2, c2);

    int *Max = new int((*n1)*(*n2));
    int *x1 = new int;
    int *x2 = new int;
    int *x3 = new int;

    adicionarVparaV(x1, Max, n1);
    adicionarVparaV(x2, Max, n2);
    int *tot = valoresComuns(x1, n1, x2, n2, x3);

    cout << endl;
    mostrarV(new string(""), x1, n1, c1);
    mostrarV(new string(""), x2, n2, c2);
    mostrarV(new string(" (intersecção entre x1 e x2)"), x3, tot, new int(3));
}

void validN(int *N, int *C) {
    do {
        cout << "Informe um valor n" << *C << ": ";
        cin >> *N;
        if(*N < 1) cout << "Valor inválido! Insira um valor maior que 1!" << endl << endl;
        else break;
    } while(true);
}

void adicionarVparaV(int *V, int *B, int *q) {
    for(int i = 0; i < *q; i++) {
        int *Rand = new int;
        int *qtd = new int;
        do {
            *qtd = 0;
            // A = 1
            // B = (n1.n2)
            // Fórmula: A + (rand() % (B - A + 1))
            // Fórmula: 1 + (rand() % (B - 1 + 1))
            *Rand = 1 + (rand() % *B);
            for(int j = 0; j < i; j++) {
                if(*Rand == *(V + j)) { //---> Valor aleatório já foi adicionado!!!
                    *qtd = 1;
                    break;
                }
            }
        } while((*qtd) == 1);
        *(V + i) = *Rand;
    }
}

int *valoresComuns(int *x1, int *n1, int *x2, int *n2, int *x3) {
    int *i = new int;
    int *j = new int;
    int *tot = new int(0);
    for(*i = 0; *i < *n1; *i += 1) {
        int *q = new int(0);
        for(*j = 0; *j < *n2; *j += 1) {
            if(*x1 == *x2) {
                *x3 = *x1;
                x3++;
                *tot += 1;
                break;
            } x2++;
            *q += 1;
        } x2 -= *q;
        x1++;
    } return tot;
}

void mostrarV(string *Add, int *V, int *q, int *C) {
    cout << "Vetor x" << *C << *Add << ": {";
    int *i = new int;
    if(*q > 0) {
        for(*i = 0; *i < *q - 1; *i += 1) {
            cout << *V << ", ";
            V++;
        } cout << *V;
    } cout << "};\n";
}
