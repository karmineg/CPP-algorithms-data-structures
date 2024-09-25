/*4 - Diz-se que um n�mero inteiro N � um quadrado perfeito se existirem M n�meros
�mpares consecutivos a partir do valor 1 cuja soma � igual a N. Neste caso N = M2
.
Exemplo: 16=1+3+5+7 (16 � igual � soma dos quatro primeiros �mpares a partir de 1)
e 16=4
2
. Logo 16 representa um quadrado perfeito. Escreva um algoritmo que
utilizando ponteiros e fun��es, verifique se um valor inteiro positivo fornecido pelo
usu�rio � um quadrado perfeito ou n�o*/

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
        cout << "> Informe um n�mero: ";
        cin >> N;

        if(N < 0) {
            cout << "Valor inv�lido!\n";
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
        cout << "> O n�mero � um quadrado perfeito!\n" << *PN << " = " << cont << "�";
    }

    else {
        cout << "> O n�mero inserido n�o � um quadrado perfeito!";
    }
}
