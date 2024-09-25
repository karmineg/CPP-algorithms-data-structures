/* 1 - Escreva um programa que receba um valor referente a uma hora, caso o valor n�o esteja no intervalo
00 at� as 24 informar que n�o � uma hora v�lida, caso esteja no intervalo calcular e informar quantas
horas faltam ou j� passaram das 12 horas. */

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
        cout << "Hora inv�lida." << endl;
    }
    else
    {
        cout << "Hora v�lida." << endl;

        intervalo = (horas - 12);

        if (intervalo >= 0){
            cout << "Passaram-se " << intervalo << " horas das 12 horas." << endl;
        }
        else{
            cout << "Faltam " << (intervalo * -1) << " horas para ser as 12 horas." << endl;
        }
    };


}
