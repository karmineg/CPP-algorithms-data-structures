/* Faça um algoritmo para “calcular o estoque médio de uma peça”, sendo que:
ESTOQUEMÉDIO = (QUANTIDADE MÍNIMA + QUANTIDADE MÁXIMA) /2
Observação: as quantidades mínima e máxima devem ser informadas pelo usuário. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int estoque_medio, quant_min, quant_max;

    cout << "Digite a quantidade mínima: ";
    cin >> (quant_min);

    cout << "Digite a quantidade máxima: ";
    cin >> (quant_max);

    estoque_medio = (quant_min + quant_max) /2;

    cout << "O estoque médio é: " << estoque_medio << endl;

}
