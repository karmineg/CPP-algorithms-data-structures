/*23 - Crie um programa que receba um número inteiro qualquer menor que 999, implemente uma função
recursiva para realizar a soma dos algarismos que compõem o número. Exemplo:
Entrada 528
Resultado: 15 (5 + 2 + 8)
Considere que o algarismo 0 (zero) não fará parte do número informado.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int soma(string N, int i);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    do {
        int num;

        cout << "Insira um número menor que 999: ";
        cin >> num;

        if(num < 999) {
            num = abs(num);
            string n = std::to_string(num);
            cout << endl << soma(n, 0);
            break;
        }
        else {
            cout << "Valor inválido\n";
        }
    } while(true);
}

int soma(string N, int i) {
    int digito = N.length(), caractere = N[i] - '0';;

    cout << caractere;
    if(i != digito - 1) {
        cout << " + ";
        caractere += soma(N, i + 1);
    }
    else
        cout << " = ";
        return caractere;
}
