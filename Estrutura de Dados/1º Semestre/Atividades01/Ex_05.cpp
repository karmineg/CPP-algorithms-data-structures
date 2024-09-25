/*5) Faça um programa que crie dinamicamente um vetor de n elementos e passe esse vetor
para uma função que vai ler os elementos desse vetor. Depois, no programa principal
(main), o vetor preenchido deve ser impresso. Além disso, antes de finalizar o programa,
deve-se liberar a área de memória alocada.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;


int criandoNum(int *pv, int *el) {
    for(int i = 0; i < *el; i++) {
        *pv = (rand() % (*el + 1));
        pv++;
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int *el = new int(0);

    cout << "Informe a quantidade de elementos do vetor: ";
    cin >> *el;
    int *pv = new int[*el];

    criandoNum(pv, el);

    cout << "> Vetor: ";
    for(int i = 0; i < *el - 1; i++) { // i < 10
        cout << *pv << ", ";
        pv++;
    } cout << *pv << ";";
    pv -= *el - 1;

    delete[] pv;
}
