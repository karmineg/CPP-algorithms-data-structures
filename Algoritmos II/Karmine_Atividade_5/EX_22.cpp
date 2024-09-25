/*22 - Crie um programa que calcula o n-ésimo número harmônico que é calculado pela seguinte fórmula:
H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma função recursiva que calcula
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

    cout << "Digite um número: ";
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
