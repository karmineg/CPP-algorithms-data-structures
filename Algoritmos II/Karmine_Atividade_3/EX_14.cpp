/*14 - Escreva um programa que simule um caixa eletrônico, sabendo que o caixa dispõe das
seguintes notas: 2, 5, 10, 20, 50 e 100. O caixa deve priorizar (sempre que possível) a entrega
das notas de maior valor, por exemplo:
Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
Saque 11,00: uma nota de 5, 3 notas de 2
Caso seja solicitado um valor inválido para saque deverá informar uma mensagem com tal
informação e solicitar a leitura de outro valor.
Utilize funções para resolver este exercício.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int &n);
void calcula (int n);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int saque;

    leitura(saque);
    calcula(saque);

}

void leitura(int &n) {
    setlocale(LC_ALL,"Portuguese");

    cout << "Digite um valor para sacar: ";
    cin >> n;

    while ((n == 1) or (n == 3) or (n < 0)) {
        cout << "Valor inválido! ";

        cout << "Digite outro valor para sacar: ";
        cin >> n;
    }
}

void calcula (int n) {
    int cem, cinc, vin, dez , ciq , doi, res;

        while (n-100!=1&&n-100!=3&&n-100>=0)
        {
        n -= 100;
        cout << "\nNota de: 100";
        }
        while (n-50!=1&&n-50!=3&&n-50>=0)
        {
        n -= 50;
        cout << "\nNota de: 50";
        }
        while (n-20!=1&&n-20!=3&&n-20>=0)
        {
        n -= 20;
        cout << "\nNota de: 20";
        }
        while (n-10!=1&&n-10!=3&&n-10>=0)
        {
        n -= 10;
        cout << "\nNota de: 10";
        }
        while (n-5!=1&&n-5!=3&&n-5>=0) {
        n -= 5;
        cout << "\nNota de: 5";
        }
        while (n-2!=1&&n-2!=3&&n-2>=0) {
        n -= 2;
        cout << "\nNota de: 2";
        }
}
