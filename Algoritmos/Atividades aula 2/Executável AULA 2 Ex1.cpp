/* Fa�a um algoritmo para �calcular o estoque m�dio de uma pe�a�, sendo que:
ESTOQUEM�DIO = (QUANTIDADE M�NIMA + QUANTIDADE M�XIMA) /2
Observa��o: as quantidades m�nima e m�xima devem ser informadas pelo usu�rio. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int estoque_medio, quant_min, quant_max;

    cout << "Digite a quantidade m�nima: ";
    cin >> (quant_min);

    cout << "Digite a quantidade m�xima: ";
    cin >> (quant_max);

    estoque_medio = (quant_min + quant_max) /2;

    cout << "O estoque m�dio �: " << estoque_medio << endl;

}
