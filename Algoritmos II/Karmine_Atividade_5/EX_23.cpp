/*23 - Crie um programa que receba um n�mero inteiro qualquer menor que 999, implemente uma fun��o
recursiva para realizar a soma dos algarismos que comp�em o n�mero. Exemplo:
Entrada 528
Resultado: 15 (5 + 2 + 8)
Considere que o algarismo 0 (zero) n�o far� parte do n�mero informado.*/

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

        cout << "Insira um n�mero menor que 999: ";
        cin >> num;

        if(num < 999) {
            num = abs(num);
            string n = std::to_string(num);
            cout << endl << soma(n, 0);
            break;
        }
        else {
            cout << "Valor inv�lido\n";
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
