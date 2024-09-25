/*Escreva um programa que receba o preço de custo de um produto e o código da sua categoria
(conforme tabela apresentada), caso for informado uma categoria diferente das apresentadas, deve
apresentar mensagem de “Categoria inválida” e finalizar o programa, caso a categoria seja válida o
programa deverá calcular o preço de venda, conforme margem de lucro da categoria.
Código da categoria Margem de lucro %
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

    cout << "Escreva o código da categoria: ";
    cin >> (codigo);

    if ((codigo < 1) or (codigo > 4))
    {
        cout << "Categoria inválida.";
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
        cout << "Preço da venda" << venda << endl;
    }

}
