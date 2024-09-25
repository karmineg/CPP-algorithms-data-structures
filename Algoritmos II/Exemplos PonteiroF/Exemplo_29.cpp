#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    int (*mat)[4];
    int l;
    cout << "Informe o numero de linhas: ";
    cin >> l;
    fflush(stdin);

    mat = new int[l][4];

    srand(time(NULL));

    for(int i = 0; i < l; i++)
    {
        for(int x = 0; x < 4; x++)
        {
            mat[i][x] = rand() % 100;
        }
    }

    for(int i = 0; i < l; i++)
    {
        for(int x = 0; x < 4; x++)
        {
            cout << mat[i][x] << "\t";
        }
        cout << "\n";
    }
}

