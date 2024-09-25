/* Todo restaurante, embora por lei não possa obrigar o cliente a pagar, cobra 15% para o garçom.
Elabore um algoritmo que após ler o valor total do consumo, calcule a gorjeta e o total a pagar com
a gorjeta. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float valor_total, gorjeta, total_pagar;

    cout << "Digite o valor total do consumo: ";
    cin >> (valor_total);

    gorjeta = valor_total * 0.15;
    total_pagar = valor_total + gorjeta;

    cout << "O total a pagar com gorjeta é: " << total_pagar << endl;

}
