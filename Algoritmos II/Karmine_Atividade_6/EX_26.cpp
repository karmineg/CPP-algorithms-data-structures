/* 26 � Crie um programa que manipule uma estrutura capaz de descrever um m�s do ano. A
estrutura deve conter os seguintes membros: n�mero do m�s, nome por extenso do m�s,
abreviatura com as tr�s iniciais do m�s e o n�mero de dias do m�s (validar o m�s de fevereiro
em caso de ano bissexto).
Ap�s alimentar os dados para esta estrutura o programa deve solicitar um dia e um m�s
qualquer e dever� mostrar o total de dias j� transcorrido no corrente ano, o dia e m�s
informado e os dados (nome, abreviatura, total de dias) referente ao m�s informado, caso seja
informado dia ou m�s inv�lido dever� apresentar uma mensagem com tal informa��o. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

struct mes {
    string nome, abrev;
    int num, dias;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    mes M[12];
    int i,soma = 0, n, d;

    for (i = 1; i <= 12; i++) { // Determinar as informa��es dos meses.
        M[i - 1].num = i;
        cout << "Informe nome do " << i << "� m�s: ";
        cin >> M[i - 1].nome;

        do {
            cout << "\nInforme os tr�s primeiros caracteres do " << i << "� m�s: ";
            cin >> M[i - 1].abrev;
        } while(M[i - 1].abrev.length() != 3);

        cout << "\nInforme quantidade de dias do " << i << "� m�s: ";
        cin >> M[i - 1].dias;

        cout << "\n-----------------------\n";
    }

    cout << "\nInforme o n�mero do m�s: ";
    cin >> n;
    if (n <= 0 || n > 12) {
        cout << "M�s inv�lido!";
        return 0;
    }

    cout << "Informe o dia do m�s: ";
    cin >> d;

    if (d > M[n - 1].dias || d <= 0) {
        cout << "Dia inv�lido em rela��o ao m�s!";
        return 0;
    }

    for (i = 0; i < n - 1; i++) soma += M[i].dias;
    soma += d;

    cout << "\nPassou, at� a data informada, um total de " << soma << " dias";
    cout << "\nA data inserida � " << d << " de " << M[n - 1].nome;
    cout << "\nO m�s informado � " << M[n - 1].nome << " (Abreviado como " << M[n - 1].abrev << ") e possui " << M[n - 1].dias << " dias.";
}
