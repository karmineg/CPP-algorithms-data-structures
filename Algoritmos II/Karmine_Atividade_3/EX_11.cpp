/*11 � Escreva um programa, que utilizando fun��es e passagem de par�metro, calcule e mostre
a �rea de um trap�zio. Sabendo que: A = (base maior + base menor) * altura) / 2;
O programa dever� ter 3 fun��es: leitura, calcula, mostra.*/

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

    n1 = leitura("Informe um valor para a base do trap�zio: ");
    n2 = leitura("Informe o outro valor para a base do trap�zio: ");
    n3 = leitura("Informe a altura do trap�zio: ");

    area = calcula(n1, n2, n3);
    cout << "�rea do Trap�zio: " << mostra(area);
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
