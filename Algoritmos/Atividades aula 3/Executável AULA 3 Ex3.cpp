/* 3. Na lanchonete de Bianca s�o servidos tr�s tipos de lanches, que s�o apresentados na tabela abaixo:
C�digo Descri��o       Valor
10     Hamb�rguer      5.00
11     Cachorro Quente 3.20
12     Torrada Simples 4.50
Crie um algoritmo que receba o c�digo do produto e mostre na tela a descri��o do mesmo e o seu
referido valor. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int codigo, descricao, valor;

    cout << "Escreva o c�digo do lanche: ";
    cin >> (codigo);

switch (codigo)
{
case 10:
    cout << "Descri��o: Hamb�rguer; Valor: 5.00$" << endl;
    break;
case 11:
    cout << "Descri��o: Cachorro Quente; Valor: 3.20$" << endl;
    break;
case 12:
    cout << "Descri��o: Torrada Simples; Valor: 4.50$" << endl;
    break;
default:
    cout << "C�digo inv�lido" << endl;
    break;

};

}
