/*22 - Crie um programa que calcula o n-�simo n�mero harm�nico que � calculado pela seguinte f�rmula:
H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma fun��o recursiva que calcula
H(n).*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

float calcula(float cont, int n);

main() {
    setlocale(LC_ALL, "Portuguese");
    int num;

    cout << "Digite um n�mero: ";
    cin >> num;

    cout << calcula(1, num);

}

float calcula(float cont, int n) {
    if (cont == n) {
        return 1 / cont;
    }
    else {
        return (1 / cont + calcula(cont + 1, n));
    }
};
