/* 3. Escreva o algoritmo que efetue o cálculo do salário líquido de um funcionário. Para efetuar este
cálculo serão necessários os seguintes dados:
− valor da hora trabalhada;
− número de horas trabalhadas no mês;
− percentual de desconto do INSS;
Inicialmente deverá ser calculado o salário bruto e depois descontar o valor do INSS para ter o
salário líquido, mostrando o salário bruto, o valor do desconto e o salário líquido do funcionário. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float valht, sl, sb, desc;
    int ht, inss;
    string nome;

    cout << "Informe o nome do(a) funcionário(a): ";
    cin >> (nome);

    cout << "Digite o valor da hora trabalhada: ";
    cin >> (valht);

    cout << "Digite o número de horas trabalhadas no mês: ";
    cin >> (ht);

    cout << "Digite o porcentual de desconto do INSS: ";
    cin >> (inss);

    sb = valht * ht;
    desc = (sb * inss) / 100;
    sl = sb - desc;

    cout << "O salário bruto do (a) funcionário (a) " << nome << " é " << sb << "$, e o salário líquido é " << sl << "$, com " << inss << "% de desconto do INSS." << endl;

}
