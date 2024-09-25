/* 7 - Escreva um algoritmo que receba 3 notas escolares de um aluno ap�s ler as notas o algoritmo dever�
fazer o c�lculo da m�dia de forma ponderada, sabendo que a nota 1 tem peso 2.5 a nota 2 tem peso 5.0
e a nota 3 tem peso 2.5, ap�s classifique o conceito deste aluno segundo a tabela abaixo:
D = media < 3
C = media entre 3 e 4.9
B = media entre 5 e 7.4
A = media maior que 7.4
Mostrar a m�dia do aluno e seu conceito. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float n1, n2, n3, media;

    cout << "Informe a nota 1: ";
    cin >> (n1);

    cout << "Informe a nota 2: ";
    cin >> (n2);

    cout << "Informe a nota 3: ";
    cin >> (n3);

    media = ((0.25 * n1) + (0.5 * n2) + (0.25 * n3));

    if (media < 3){
        cout << "Voc� recebeu um D.";
    }
    else if ((media >= 3) and (media <= 4.9)){
        cout << "Voc� recebeu um C." << endl;
    }
    else if ((media >= 5) and (media <= 7.4)){
        cout << "Voc� recebeu um B." << endl;
    }
    else{
        cout << "Voc� recebeu um A." << endl;
    };


}
