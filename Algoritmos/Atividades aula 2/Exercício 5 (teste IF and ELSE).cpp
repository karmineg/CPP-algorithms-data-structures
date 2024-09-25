/* Crie um algoritmo que receba o n�mero da matr�cula de um aluno e o valor de 3 notas escolares,
ap�s calcule a m�dia ponderada deste aluno, sabendo que a nota 1 tem peso 3,2 a nota 2 tem peso
5,5 e a nota 3 tem peso 1,3, apresente no final a mensagem com o n�mero da matr�cula do aluno e
a sua m�dia; */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
  setlocale(LC_ALL,"Portuguese");
  int mat;
  float n1, n2, n3, freq, media;

  cout << "Informe a matr�cula: ";
 cin >> mat;

 cout << "Digite a nota 1: ";
 cin >> n1;

cout << "Digite a nota 2: ";
cin >> n2;

 cout << "Digite a nota 3: ";
 cin >> n3;

  cout << "Informe a frequ�ncia: ";
 cin >> freq;

 media = ((3.2 / 10.0) * n1 + (5.5 / 10.0) * n2 + (1.3 / 10.0) * n3);

 cout << "M�dia ponderada do aluno " << mat << ": " << media << endl;

 if ((media >= 60) and (freq >= 75))
    cout << "Aluno aprovado";
 else
    cout << "Aluno reprovado" << endl;
 if (freq < 75)
    cout << "Aluno reprovado pela frequ�ncia" << endl;
}

