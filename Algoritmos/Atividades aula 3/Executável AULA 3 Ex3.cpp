/* 3. Na lanchonete de Bianca são servidos três tipos de lanches, que são apresentados na tabela abaixo:
Código Descrição       Valor
10     Hambúrguer      5.00
11     Cachorro Quente 3.20
12     Torrada Simples 4.50
Crie um algoritmo que receba o código do produto e mostre na tela a descrição do mesmo e o seu
referido valor. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int codigo, descricao, valor;

    cout << "Escreva o código do lanche: ";
    cin >> (codigo);

switch (codigo)
{
case 10:
    cout << "Descrição: Hambúrguer; Valor: 5.00$" << endl;
    break;
case 11:
    cout << "Descrição: Cachorro Quente; Valor: 3.20$" << endl;
    break;
case 12:
    cout << "Descrição: Torrada Simples; Valor: 4.50$" << endl;
    break;
default:
    cout << "Código inválido" << endl;
    break;

};

}
