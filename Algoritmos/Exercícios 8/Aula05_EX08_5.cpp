/* 5 - Escreva um programa que leia 10 valores inteiros, só serão aceitos valores entre 1 e 50, valores
fora do intervalo devem ser desconsiderados. Após ler os valores o sistema deverá apresentar o maior
valor lido (considerar somente os dentro do intervalo) e em qual das leituras ele foi informado, deverá
apresentar quantos dos valores digitados estavam fora do intervalo. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, soma = 0, num, maxi = 1, valores = 0, posicao;
    for(i = 1; i <= 10; i++)
    {
        cout << "Informe 1 valores menores que 50: ";
        cin >> (num);
        fflush (stdin);
        if (num >= 1 and num <= 50){
            soma += num;
            if (num > maxi){
                maxi = num;
                posicao = i;
            }
        }
        else{
            valores++;
        }
    }
    cout << "A soma dos nC:meros inteiros é " << soma << endl;
    cout << "O maior valor lido é " << maxi << " na leitura de número " << posicao << "!" << endl;
    cout << "Valores fora do intervalo: " << valores << endl;
}
