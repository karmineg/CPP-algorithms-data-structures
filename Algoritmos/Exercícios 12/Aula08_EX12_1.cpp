/* 1 - Crie uma função que recebe como parâmetros o salário de um funcionário e o percentual de reajuste e retorna o salário
reajustado. No programa principal, leia o salário do funcionário e o percentual de reajuste, em seguida, chame a função para
calcular o reajuste do salário e imprima o valor do salário reajustado.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

float funcao(float salario, float porcent);

main()
{
    setlocale(LC_ALL, "Portuguese");
    float porcent, salario;

    cout << "Informe o salário do funcionário: ";
    cin >> (salario);

    cout << "\nInforme o pocentual do reajuste: ";
    cin >> (porcent);

    cout << "\nSalário reajustado: " << funcao(salario, porcent);

}

float funcao(float salario, float porcent)
{
    float reajuste = 0;
    reajuste = salario + (salario * (porcent / 100.0));
    return reajuste;
}
