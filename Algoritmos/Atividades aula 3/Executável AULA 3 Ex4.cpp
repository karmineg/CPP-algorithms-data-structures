/* 4 - Elabore um algoritmo que receba um ano (num�rico inteiro) e informe se o ano � bissexto ou n�o.
Lembrete:
S�o bissextos todos os anos m�ltiplos de 400, ex.: 1600, 2000, 2400, 2800...
S�o bissextos todos os m�ltiplos de 4 e n�o m�ltiplos de 100, ex.: 1996, 2004, 2008, 2012, 2016...
N�o s�o bissextos todos os demais anos. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int ano;

    cout << "Informe um ano: ";
    cin >> (ano);

    if (ano % 400 == 0){
        cout << "Esse ano � bissexto.";
    }
    else if ((ano % 4 == 0) and (ano != 100)){
        cout << "Esse ano � bissexto." << endl;
    }
    else{
        cout << "Esse ano n�o � bissexto." << endl;
    };

}
