/*2) Construa um programa que:
a. Aloque dinamicamente um vetor de 10 posições;
b. Gravar as 10 posições do vetor com valores aleatório, intervalo de 20 a 50;
c. Mostre o vetor;
d. Libere a memória alocada.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;


int rand(int *pv, string c) {
    *pv = 20 + (rand() % 31);
    cout << *pv << c;
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int *pv = new int[10];

    for(int i = 0; i < 9; i++) { // i < 10
        //*pv = 20 + (rand() % 31);
        //cout << *pv;
        //if(i < 9) cout << ", ";
        //else cout << ";";
        rand(pv, ", ");
        pv++;
    } rand(pv, ";");

    pv -= 9;
    // pv -= 10;

    delete[] pv;
}
