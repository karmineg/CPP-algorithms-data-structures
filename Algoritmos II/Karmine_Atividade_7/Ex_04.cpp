/*4 - Diz-se que um número inteiro N é um quadrado perfeito se existirem M números
ímpares consecutivos a partir do valor 1 cuja soma é igual a N. Neste caso N = M2
.
Exemplo: 16=1+3+5+7 (16 é igual à soma dos quatro primeiros ímpares a partir de 1)
e 16=4
2
. Logo 16 representa um quadrado perfeito. Escreva um algoritmo que
utilizando ponteiros e funções, verifique se um valor inteiro positivo fornecido pelo
usuário é um quadrado perfeito ou não*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

void PerfectQuadrado(int *PN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int N;

    do {
        cout << "> Informe um número: ";
        cin >> N;

        if(N < 0) {
            cout << "Valor inválido!\n";
        }

        else {
            PerfectQuadrado(&N);
            break;
        }
    } while(true);
}

void PerfectQuadrado(int *PN) {
    int num = 0, cont = 0;

    while(*PN > num) {
        num += (2*cont + 1);
        cont++;
    }

    if(*PN == num) {
        cout << "> O número é um quadrado perfeito!\n" << *PN << " = " << cont << "²";
    }

    else {
        cout << "> O número inserido não é um quadrado perfeito!";
    }
}
