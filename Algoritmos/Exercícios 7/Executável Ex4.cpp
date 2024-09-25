/* 4 - Faça um algoritmo que leia o código do produto, a quantidade em estoque, o preço de custo e o tipo (S – serviço,
P - produto). Com base na quantidade de produtos em estoque (Qt. Estoque) e preço de custo (Preço Custo), o
programa deve calcular e mostrar o valor do total de produtos em estoque (Valor Estoque), e também o preço de venda
com base nas seguintes informações:
● Se o tipo for P de Produto, o preço de venda é calculado com 90% sobre o preço de custo.
● Se o tipo S de Serviço, o preço de venda é calculado com 65% sobre o preço de custo. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int codigo, estoque;
    float valor, custo, porcent, venda;
    char tipo;

    cout << "Informe o código do produto: ";
    cin >> (codigo);

    cout << "Informe o tipo de produto (S- serviço; P- produto): ";
    cin >> (tipo);

    cout << "Informe a quantidade em estoque: ";
    cin >> (estoque);

    cout << "Informe o preço de custo: ";
    cin >> (custo);

    valor = estoque * custo;

    switch (tipo){

    case 'p':
        venda = (custo * 0.9) + custo;
        cout << "O valor total de produtos em estoque é: " << valor << "R$, e o preço da venda é: " << venda << "R$." << endl;
        break;

    case 's':
        venda = (custo * 0.65) + custo;
        cout << "O valor total de produtos em estoque é: " << valor << "R$, e o preço da venda é: " << venda << "R$." << endl;
        break;

    default:
        cout << "Tipo de produto inválido.";
        break;

    };

}
