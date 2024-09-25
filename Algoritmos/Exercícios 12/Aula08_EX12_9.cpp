/* 9 - Construa um algoritmo que leia para determinado ve�culo o ano de fabrica��o e o pre�o do ve�culo (o valor que o propriet�rio
deseja receber do ve�culo):
a) Construa uma fun��o que recebe por par�metro o ano de fabrica��o e retorne sua classifica��o de acordo com a tabela:
Mostre a classifica��o no programa principal (main).
b) Construa uma fun��o que receba por par�metro a classifica��o ve�culo e o pre�o do ve�culo e retorne o valor de venda de
acordo:
Mostre o pre�o de venda no programa principal (main).
*/

#include <iostream>
using namespace std;
char classificarVeiculo(int anoFabricacao);
float calcValorVenda(float preco, char classificacao);
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int anoFab;
    float preco, valorVenda;
    char classificacaoVel;
    cout << "Informe o ano de fabrica��o do ve�culo: ";
    cin >> anoFab;
    cout << "Informe o pre�o do ve�culo: ";

    cin >> preco;
    classificacaoVel = classificarVeiculo(anoFab);
    valorVenda = calcValorVenda(preco, classificacaoVel);
    cout << "O ve�culo foi classificado como [" << classificacaoVel << "] e seu valor de revenda �: " << valorVenda << endl;
}
char classificarVeiculo(int anoFabricacao)
{
    int anoAtual = 2022;
    char classificacao = ' ';
    if(anoFabricacao == anoAtual)
        classificacao = 'N';
    else if(anoFabricacao >= anoAtual-3)
        classificacao = 'S';
    else if(anoFabricacao < anoAtual-3)
        classificacao = 'U';
    return classificacao;
}
float calcValorVenda(float preco, char classificacao)
{
    float precoVenda = 0;
    if(classificacao == 'N')
        precoVenda = preco + ((5/100.0) * preco );
    else if(classificacao == 'S')
        precoVenda = preco + ((15/100.0) * preco );
    else if(classificacao == 'U')
        precoVenda = preco + ((25/100.0) * preco );
    return precoVenda;
}
