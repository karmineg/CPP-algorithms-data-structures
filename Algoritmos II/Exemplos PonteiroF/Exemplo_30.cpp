#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    int l, c, cont;
    cout << "Informe o numero de linhas: ";
    cin >> l;
    fflush(stdin);

    cout << "Informe o numero de colunas: ";
    cin >> c;
    fflush(stdin);

    int *mat = new int[l * c];

    srand(time(NULL));

    for(int i = 0; i < (l * c); i++)
    {
       mat[i] = rand() % 100;
    }

    cont = 1;
    for(int i = 0; i < (l * c); i++)
    {
        cout << mat[i] << "\t";
        if(cont == c)
        {
            cout << "\n";
            cont = 0;
        }
        cont++;
    }
}

