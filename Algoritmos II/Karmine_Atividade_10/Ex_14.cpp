/*14 - Escreva um programa que utilizando ponteiro e aloca��o din�mica de mem�ria, manipule um vetor
de inteiros de 10 posi��es, o vetor dever� ser preenchido de forma pseudo-aleat�ria com valores entre 30
e 55, mostrar o vetor gerado na tela, realizar a troca dos valores no vetor de tal forma que o primeiro
passa a ser o �ltimo, o segundo o pen�ltimo e assim sucessivamente. Mostre o vetor na tela ap�s as
trocas, utilize aritm�tica de ponteiro para percorrer o vetor.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

void mostrarVetor(int *pv, string txtV);
void inverterVetor(int *pv);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *pv= new int[10];

    /*cout << "Vetor gerado: ";
    for(int i = 0; i < 10; i++) {
        *pv = 30 + (rand() % 26);
        cout << *pv;
        if(i < 9) {
            pv++;
            cout << ", ";
        }
    } cout << ";";

    cout << "\n\nVetor ao contr�rio: ";
    for(int i = 9; i >= 0; i--) {
        cout << *pv;
        pv--;
        if(i > 0)
            cout << ", ";
    } cout << ";";*/

    for(int i = 0; i < 10; i++) {
        *pv = 30 + (rand() % 26);
        pv++;
    }

    pv -= 10;
    mostrarVetor(pv, "Vetor gerado");
    inverterVetor(pv);
    mostrarVetor(pv, "Vetor ao contr�rio");

}

void mostrarVetor(int *pv, string txtV) {
    cout << txtV << ": ";
    for(int i = 0; i < 9; i++) {
        cout << *pv << ", ";
        pv++;
    } cout << *pv << ";\n";
}

void inverterVetor(int *pv) {
    for(int i = 0; i < 5; i++) {
        int *aux = new int(*(pv + i));
        *(pv + i) = *(pv + 9 - i);
        *(pv + 9 - i) = *aux;
    }
}

