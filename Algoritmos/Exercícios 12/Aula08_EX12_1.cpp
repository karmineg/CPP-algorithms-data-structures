/* 1 - Crie uma fun��o que recebe como par�metros o sal�rio de um funcion�rio e o percentual de reajuste e retorna o sal�rio
reajustado. No programa principal, leia o sal�rio do funcion�rio e o percentual de reajuste, em seguida, chame a fun��o para
calcular o reajuste do sal�rio e imprima o valor do sal�rio reajustado.
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

    cout << "Informe o sal�rio do funcion�rio: ";
    cin >> (salario);

    cout << "\nInforme o pocentual do reajuste: ";
    cin >> (porcent);

    cout << "\nSal�rio reajustado: " << funcao(salario, porcent);

}

float funcao(float salario, float porcent)
{
    float reajuste = 0;
    reajuste = salario + (salario * (porcent / 100.0));
    return reajuste;
}
