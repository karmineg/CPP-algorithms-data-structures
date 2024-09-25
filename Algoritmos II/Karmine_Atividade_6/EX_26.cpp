/* 26 – Crie um programa que manipule uma estrutura capaz de descrever um mês do ano. A
estrutura deve conter os seguintes membros: número do mês, nome por extenso do mês,
abreviatura com as três iniciais do mês e o número de dias do mês (validar o mês de fevereiro
em caso de ano bissexto).
Após alimentar os dados para esta estrutura o programa deve solicitar um dia e um mês
qualquer e deverá mostrar o total de dias já transcorrido no corrente ano, o dia e mês
informado e os dados (nome, abreviatura, total de dias) referente ao mês informado, caso seja
informado dia ou mês inválido deverá apresentar uma mensagem com tal informação. */

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

    for (i = 1; i <= 12; i++) { // Determinar as informações dos meses.
        M[i - 1].num = i;
        cout << "Informe nome do " << i << "º mês: ";
        cin >> M[i - 1].nome;

        do {
            cout << "\nInforme os três primeiros caracteres do " << i << "º mês: ";
            cin >> M[i - 1].abrev;
        } while(M[i - 1].abrev.length() != 3);

        cout << "\nInforme quantidade de dias do " << i << "º mês: ";
        cin >> M[i - 1].dias;

        cout << "\n-----------------------\n";
    }

    cout << "\nInforme o número do mês: ";
    cin >> n;
    if (n <= 0 || n > 12) {
        cout << "Mês inválido!";
        return 0;
    }

    cout << "Informe o dia do mês: ";
    cin >> d;

    if (d > M[n - 1].dias || d <= 0) {
        cout << "Dia inválido em relação ao mês!";
        return 0;
    }

    for (i = 0; i < n - 1; i++) soma += M[i].dias;
    soma += d;

    cout << "\nPassou, até a data informada, um total de " << soma << " dias";
    cout << "\nA data inserida é " << d << " de " << M[n - 1].nome;
    cout << "\nO mês informado é " << M[n - 1].nome << " (Abreviado como " << M[n - 1].abrev << ") e possui " << M[n - 1].dias << " dias.";
}
