/* 8 - Construa um algoritmo que:
a) Leia um n�mero �mpar (5<= N <= 13)
- Caso o valor de N informado pelo usu�rio seja inv�lido, ou seja, fora do intervalo especificado, o programa deve
mostrar uma mensagem de erro e um novo valor deve ser lido, at� que um valor v�lido seja digitado pelo usu�rio!
b) Em seguida, declare a matriz MAT de tamanho NxN.
c) Por fim, gere a matriz MAT com o seguinte padr�o:
*/

#include <iostream>
using namespace std;

main()
{
    setlocale(LC_ALL, "portuguese");
    int N, centro; //ler um inteiro N maior 4 e menor ou igual a 10
    do
    {
        cout << "Informe um inteiro N, sendo N um n�mero �mpar (5<= N <= 13): ";
        cin >> N;
    }
    while(N<5 || N>13 || N%2==0);

    int M[N][N]; // DECLARAR A MATRIZ DEPOIS DE LER N !!
    centro = N / 2; //2 � um n�mero inteiro!
    for(int lin=0; lin<N; lin++)
    {
        for(int col=0; col<N; col++)

        {
            if(lin == centro || col == centro)
                M[lin][col] = 1;
            else
                M[lin][col] = 0;
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
