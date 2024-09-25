/*Escreva um programa que receba o pre�o de custo de um produto e o c�digo da sua categoria
(conforme tabela apresentada), caso for informado uma categoria diferente das apresentadas, deve
apresentar mensagem de �Categoria inv�lida� e finalizar o programa, caso a categoria seja v�lida o
programa dever� calcular o pre�o de venda, conforme margem de lucro da categoria.
C�digo da categoria Margem de lucro %
1                       35%
2                       28%
3                       22%
4                       15% */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int codigo;
    float custo, venda;

    cout << fixed;

    cout << "Escreva o c�digo da categoria: ";
    cin >> (codigo);

    if ((codigo < 1) or (codigo > 4))
    {
        cout << "Categoria inv�lida.";
    }
    else
    {
        cout << "Informe o custo do produto: ";
        cin >> custo;
        switch (codigo);
        {
        case 1:
            venda = custo + ((35.0 / 100.0) * custo);
            break;
        case 2:
            venda = custo + ((28.0 / 100.0) * custo);
            break;
        case 3:
            venda = custo + ((22.0 / 100.0) * custo);
            break;
        case 4:
            venda = custo + ((15.0 / 100.0) * custo);
            break;
        };
        cout << "Pre�o da venda" << venda << endl;
    }

}
