/*17 – Escreva um programa que leia um arquivo texto contendo vários números float, separados por ponto e vírgula, o
programa deverá mostrar a soma, média, maior e menor valor existente no arquivo.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    ifstream objeto("text_float.txt");
    float V[10] = {};
    int cont = 0;
    float soma = 0, media = 0, maior, menor;

    objeto >> V[0];
    maior = V[0];
    menor = V[0];
    soma = V[0];
    cout << V[0];

    for(int i = 1; i < 5; i++) {
        objeto >> V[i];
        cout << "; " << V[i];
        soma += V[i];
        if(V[i] > maior){
            maior = V[i];
        }
         if(V[i] < menor){
            menor = V[i];
        }

    } cout << ";";

    media = soma / 5;
    cout << "\nSoma: " << soma;
    cout << "\nMédia: " << media;
    cout << "\nMaior valor: " << maior;
    cout << "\nMenor valor: " << menor;
    objeto.close();
}
