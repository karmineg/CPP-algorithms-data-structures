/* 1 - Escreva um programa que receba um valor referente a uma hora, caso o valor não esteja no intervalo
00 até as 24 informar que não é uma hora válida, caso esteja no intervalo calcular e informar quantas
horas faltam ou já passaram das 12 horas. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int horas, intervalo;

    cout << "Informe a hora: ";
    cin >> (horas);

    if ((horas <= 0) or (horas >= 25)){
        cout << "Hora inválida." << endl;
    }
    else
    {
        cout << "Hora válida." << endl;

        intervalo = (horas - 12);

        if (intervalo >= 0){
            cout << "Passaram-se " << intervalo << " horas das 12 horas." << endl;
        }
        else{
            cout << "Faltam " << (intervalo * -1) << " horas para ser as 12 horas." << endl;
        }
    };


}
