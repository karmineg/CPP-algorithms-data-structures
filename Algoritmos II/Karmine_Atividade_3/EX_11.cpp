/*11 – Escreva um programa, que utilizando funções e passagem de parâmetro, calcule e mostre
a área de um trapézio. Sabendo que: A = (base maior + base menor) * altura) / 2;
O programa deverá ter 3 funções: leitura, calcula, mostra.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int leitura (char texto[100]);
int calcula (int num1, int num2, int num3);
int mostra (int A);

main() {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, n3, area;

    n1 = leitura("Informe um valor para a base do trapézio: ");
    n2 = leitura("Informe o outro valor para a base do trapézio: ");
    n3 = leitura("Informe a altura do trapézio: ");

    area = calcula(n1, n2, n3);
    cout << "Área do Trapézio: " << mostra(area);
}

int leitura (char texto[100]){
    int n;
    cout << texto;
    cin >> n;
    fflush(stdin);
    return n;
}

int calcula (int num1, int num2, int num3){
    int A;
    A = ((num1 + num2) * num3) / 2;
    return A;

}

int mostra (int A) {
    return A;

}
