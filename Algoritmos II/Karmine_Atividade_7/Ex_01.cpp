/*1– Crie um programa para ler o tempo registrado por um atleta durante uma corrida
com N voltas, a leitura deve ocorrer em uma função e o registro do melhor tempo deve
ser atualizado através de um ponteiro. Encerrar o programa quando o número zero for
informado para o tempo, apresentar o melhor tempo.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void tempo(int *Pmt);

main(){
    int bestT = 0;
    tempo(&bestT);
}

void tempo(int *Pmt) {
    setlocale(LC_ALL, "Portuguese");
    int T;

    cout << "> Adicione um valor de tempo(s): ";
    cin >> T;

    if(T > 0) {
        if(*Pmt == 0) {
            *Pmt = T;
        }
        else {
            if(*Pmt > T) {
                *Pmt = T;
            }
        }
        tempo(Pmt);
    }

    else if(T == 0) {
        cout << "> Melhor tempo: " << *Pmt << "s";
    }

    else {
        cout << "Valor inválido! Insira um novo valor!\n";
        tempo(Pmt);
    }
}
