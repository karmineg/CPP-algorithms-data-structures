/* 5 - Escreva um algoritmo que leia a quantidade de alunos de uma turma, ap�s solicite a m�dia final de
cada aluno da turma e apresente os seguintes dados:
- M�dia da turma com uma casa decimal;
- Maior m�dia entre os alunos;
- Menor m�dia entre os alunos;
- Percentual de alunos aprovados (m�dia >= 6);
- Percentual de alunos reprovados (m�dia < 6); */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int quantidade_alunos, x;
    float media, soma = 0, maior, menor, porcentual_aprovados = 0, porcentual_reprovados = 0;

    cout << fixed;
    cout.precision(1);

    cout << "Informe a quantidade de alunos da turma: ";
    cin >> quantidade_alunos;

    x = 1;
    while(x <= quantidade_alunos)
    {
        cout << "Informe a m�dia do aluno " << x << ": ";
        cin >> media;
        soma += media;
        if(x == 1)
        {
            maior = media;
            menor = media;
        }
        else
        {
            if(media > maior)
               maior = media;
            if(media < menor)
               menor = media;
        }

        if (media >= 6)
            porcentual_aprovados++;
        else
            porcentual_reprovados++;
        x++;
    }

    cout << "M�dia da turma: " << (soma / quantidade_alunos) << endl;
    cout << "Maior m�dia: " << maior << endl;
    cout << "Menor m�dia: " << menor << endl;
    cout << "Percentual de alunos aprovados: " << (porcentual_aprovados / quantidade_alunos) * 100 << endl;
    cout << "Percentual de alunos reprovados: " << (porcentual_reprovados / quantidade_alunos) * 100;
}
