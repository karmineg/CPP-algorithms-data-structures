/* 4. Escreva um algoritmo que calcule o valor de uma presta��o em atraso, utilizando a f�rmula: total =
valor + (valor * ((taxa / 100) * dias)). Mostre o valor inicial e o valor corrigido. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float valor, taxa, total;
    int dias;

    cout << "Informe o valor: ";
    cin >> (valor);

    cout << "Informe os dias: ";
    cin >> (dias);

    cout << "Informe a taxa: ";
    cin >> (taxa);

    total = valor + (valor * ((taxa / 100) * dias));

    cout << "O valor incial da presta��o era " << valor << "$, o valor corrigidido da presta��o � " << total << "$." << endl;

}
