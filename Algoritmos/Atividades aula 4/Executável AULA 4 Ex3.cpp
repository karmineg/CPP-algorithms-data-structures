/* 3 - Escrever um algoritmo para uma empresa que decide dar um reajuste a seus funcion�rios de acordo
com os seguintes crit�rios:
a) 50% para aqueles que ganham menos do que tr�s sal�rios m�nimos;
b) 20% para aqueles que ganham entre tr�s at� dez sal�rios m�nimos;
c) 15% para aqueles que ganham acima de dez at� vinte sal�rios m�nimos;
d) 10% para os demais funcion�rios.
Leia o nome do funcion�rio, seu sal�rio e o valor do sal�rio m�nimo. Calcule o seu novo sal�rio reajustado.
Escrever o nome do funcion�rio, o valor do reajuste e o seu novo sal�rio. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float salario, minimo, reajuste, novo;
    string nome;

    cout << "Informe o nome do(a) funcion�rio(a): ";
    cin >> (nome);

    cout << "Informe seu sal�rio: ";
    cin >> (salario);

    cout << "Informe o sal�rio m�nimo: ";
    cin >> (minimo);

    if (salario < minimo * 3)
    {
        reajuste = salario * 0.5;
        novo = salario + reajuste;
        cout << "O(a) funcion�rio(a) " << nome << " obeteve reajuste no sal�rio de " << reajuste << "R$, seu sal�rio atual � " << novo << "R$." << endl;
    }
    else if ((salario >= minimo * 3) and (salario <= minimo * 10))
    {
        reajuste = salario * 0.2;
        novo = salario + reajuste;
        cout << "O(a) funcion�rio(a) " << nome << " obeteve reajuste no sal�rio de " << reajuste << "R$, seu sal�rio atual � " << novo << "R$." << endl;
    }
    else if ((salario > minimo * 10) and (salario <= minimo * 20))
    {
        reajuste = salario * 0.15;
        novo = salario + reajuste;
        cout << "O(a) funcion�rio(a) " << nome << " obeteve reajuste no sal�rio de " << reajuste << "R$, seu sal�rio atual � " << novo << "R$." << endl;
    }
    else{
        reajuste = salario * 0.1;
        novo = salario + reajuste;
        cout << "O(a) funcion�rio(a) " << nome << " obeteve reajuste no sal�rio de " << reajuste << "R$, seu sal�rio atual � " << novo << "R$." << endl;
    };



}
