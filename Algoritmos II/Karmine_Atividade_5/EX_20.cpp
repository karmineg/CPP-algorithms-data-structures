/*20 � Fa�a um programa que receba dois valores inteiros e positivos, referentes a uma base e um
expoente, ap�s crie uma fun��o recursiva para realizar o c�lculo e retornar o valor resultante.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void calcula(int n1, int n2, int cont, int multi);

main() {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2;

    cout << "Digite um n�mero para ser a base: ";
    cin >> n1;

    cout << "Digite outro n�mero para ser o expoente: ";
    cin >> n2;

    calcula(n1, n2, 1, n1);

}

void calcula(int n1, int n2, int cont, int multi) {

    if (n2 == 1)
        cout << n1;

    else if (n2 == 0)
        cout << "1";

    else if (cont == n2)
        cout << n1;

    else {
        cont++;
        calcula(n1 * multi, n2, cont, multi);
    }

}
