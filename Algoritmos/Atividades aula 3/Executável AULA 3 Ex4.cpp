/* 4 - Elabore um algoritmo que receba um ano (numérico inteiro) e informe se o ano é bissexto ou não.
Lembrete:
São bissextos todos os anos múltiplos de 400, ex.: 1600, 2000, 2400, 2800...
São bissextos todos os múltiplos de 4 e não múltiplos de 100, ex.: 1996, 2004, 2008, 2012, 2016...
Não são bissextos todos os demais anos. */

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
        cout << "Esse ano é bissexto.";
    }
    else if ((ano % 4 == 0) and (ano != 100)){
        cout << "Esse ano é bissexto." << endl;
    }
    else{
        cout << "Esse ano não é bissexto." << endl;
    };

}
