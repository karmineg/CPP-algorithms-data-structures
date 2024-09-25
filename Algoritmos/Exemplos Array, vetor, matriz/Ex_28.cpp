
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o randômico
    int lin, col;
    int mat[5][5];

    for(lin = 0; lin < 5; lin++)
    {
        for(col = 0; col < 5; col++)
        {
            cout << "Informe o elemento [" << lin << "][" << col << "]: ";
            cin >> mat[lin][col];
            fflush(stdin);
        }
    }


    for(lin = 0; lin < 5; lin++)
    {
        for(col = 0; col < 5; col++)
        {
            cout << mat[lin][col] << "\t";
        }
        cout << "\n";
    }

}
