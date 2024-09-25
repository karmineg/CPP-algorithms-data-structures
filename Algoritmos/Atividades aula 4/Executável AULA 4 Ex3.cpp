/* 3 - Escrever um algoritmo para uma empresa que decide dar um reajuste a seus funcionários de acordo
com os seguintes critérios:
a) 50% para aqueles que ganham menos do que três salários mínimos;
b) 20% para aqueles que ganham entre três até dez salários mínimos;
c) 15% para aqueles que ganham acima de dez até vinte salários mínimos;
d) 10% para os demais funcionários.
Leia o nome do funcionário, seu salário e o valor do salário mínimo. Calcule o seu novo salário reajustado.
Escrever o nome do funcionário, o valor do reajuste e o seu novo salário. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float salario, minimo, reajuste, novo;
    string nome;

    cout << "Informe o nome do(a) funcionário(a): ";
    cin >> (nome);

    cout << "Informe seu salário: ";
    cin >> (salario);

    cout << "Informe o salário mínimo: ";
    cin >> (minimo);

    if (salario < minimo * 3)
    {
        reajuste = salario * 0.5;
        novo = salario + reajuste;
        cout << "O(a) funcionário(a) " << nome << " obeteve reajuste no salário de " << reajuste << "R$, seu salário atual é " << novo << "R$." << endl;
    }
    else if ((salario >= minimo * 3) and (salario <= minimo * 10))
    {
        reajuste = salario * 0.2;
        novo = salario + reajuste;
        cout << "O(a) funcionário(a) " << nome << " obeteve reajuste no salário de " << reajuste << "R$, seu salário atual é " << novo << "R$." << endl;
    }
    else if ((salario > minimo * 10) and (salario <= minimo * 20))
    {
        reajuste = salario * 0.15;
        novo = salario + reajuste;
        cout << "O(a) funcionário(a) " << nome << " obeteve reajuste no salário de " << reajuste << "R$, seu salário atual é " << novo << "R$." << endl;
    }
    else{
        reajuste = salario * 0.1;
        novo = salario + reajuste;
        cout << "O(a) funcionário(a) " << nome << " obeteve reajuste no salário de " << reajuste << "R$, seu salário atual é " << novo << "R$." << endl;
    };



}
