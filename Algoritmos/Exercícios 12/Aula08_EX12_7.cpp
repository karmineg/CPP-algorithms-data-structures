/* 7 - Faça um algoritmo que receba um número inteiro N, sendo 3 < N < 7, ou seja, o valor de N deve ser maior que 3 e menor que
7. A seguir, crie uma matriz NxN conforme exemplo abaixo, em que os elementos acima da diagonal principal possuem o valor ‘A’,
os elementos abaixo da diagonal principal possuem o valor ‘B’ e os elementos da diagonal principal o valor X:
*/

#include <iostream>
using namespace std;
main()
{
    setlocale(LC_ALL, "portuguese");
    int N; //ler um inteiro N maior 4 e menor ou igual a 10
    do
    {
        cout << "Informe um inteiro N, sendo 3< N <7 : ";
        cin >> N;
    }
    while(N<=3 || N>=7);

    char M[N][N]; // DECLARAR A MATRIZ DEPOIS DE LER N !!
    for(int lin=0; lin<N; lin++)
    {
        for(int col=0; col<N; col++)
        {
            if(lin == col)
                M[lin][col] = 'X';
            if(lin < col)
                M[lin][col] = 'A';
            if(lin > col)
                M[lin][col] = 'B';
        }
    }

    for(int lin=0; lin<N; lin++)
    {
        for(int col=0; col<N; col++)
        {
            cout << M[lin][col] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
