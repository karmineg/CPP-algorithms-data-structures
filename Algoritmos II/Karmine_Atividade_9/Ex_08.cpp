/*8 - Crie um programa que receba um valor qualquer representando o tamanho dos lados de um
quadrado, implemente uma função que receba esse valor e utilizando ponteiros escreva com o caracter
“*” asterisco na tela, um quadrado com as respectivas diagonais, conforme exemplo apresentado abaixo:

OBS: Neste exercício não poderá ser utilizado nenhuma variável, somente ponteiros e alocação dinâmica
de memória.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void validN(int *n);
void lineComplete(int *n);
void lineIntermed(int *n, int *i, char *C);
void printSquare(int *n, char *C);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *n = new int;
    validN(n);

    char *C;
    C = " *";
    printSquare(n, C);
}

void validN(int *n) {
    do {
        cout << "Informe um valor: ";
        cin >> *n;
        if(*n < 1) cout << "Valor inválido! Insira um valor maior que 1!" << endl << endl;
        else break;
    } while(true);
}

void lineComplete(int *n) {
    cout << "*";
    for(int i = 1; i < *n; i++) cout << " *";
    cout << endl;
}

void lineIntermed(int *n, int *i, char *C) {
    int *Q = new int(*n - 1 - *i);
    int *j = new int;
    cout << "*";
    for(*j = 1; *j < *n - 1; *j += 1) {
        cout << " " << *(C + (*j == *i || *j == *Q));
    } cout << " *" << endl;
}

void printSquare(int *n, char *C) {
    lineComplete(n);
    int *i = new int;
    for(*i = 1; *i < *n/2; *i += 1) lineIntermed(n, i, C);
    for(*i = (*n - 1)/2; *i >= 1; *i -= 1) lineIntermed(n, i, C);
    if(*n > 1) lineComplete(n);
    cout << endl;
}

