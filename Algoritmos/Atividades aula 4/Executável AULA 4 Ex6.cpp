/* 6 – Uma empresa irá dar um aumento de salário aos seus funcionários de acordo com a categoria de
cada empregado. O aumento seguirá as seguintes regras:
➢ A, C, F, e H ganharão 10 % de aumento sobre o salário
➢ B, D , E , I , J e T ganharão 15 % de aumento sobre o salário
➢ K e R ganharão 25 % de aumento sobre o salário
➢ L, M , N , O, P e S ganharão 35 % de aumento sobre o salário
➢ U, V , X , Z e W ganharão 50 % de aumento sobre o salário
Faça o algoritmo que leia a categoria (variável do tipo char) e o salário do empregado. O
programa deve mostrar a categoria do funcionário e o valor do salário reajustado. */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float salario;
    char categoria;
    string nome;

    cout << "Informe o nome do(a) funcionário(a): ";
    cin >> (nome);

    cout << "Informe a categoria do(a) funcionário(a): ";
    cin >> (categoria);

    cout << "Informe o salário do(a) funcionário(a): ";
    cin >> (salario);

    switch (categoria)
    {
    case 'A':

        salario = (salario * 0.1) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'C':

        salario = (salario * 0.1) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'F':

        salario = (salario * 0.1) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'H':

        salario = (salario * 0.1) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'B':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'D':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'E':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'I':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'J':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'T':

        salario = (salario * 0.15) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'K':

        salario = (salario * 0.25) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'R':

        salario = (salario * 0.25) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'L':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'M':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'N':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'O':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'P':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'S':

        salario = (salario * 0.35) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'U':

        salario = (salario * 0.5) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'V':

        salario = (salario * 0.5) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'X':

        salario = (salario * 0.5) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'Z':

        salario = (salario * 0.5) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    case 'W':

        salario = (salario * 0.5) + salario;
        cout << "Valor do salário reajustado é " << salario;

        break;
    default:
        cout << "Categoria inválida.";
        break;

    }

}
