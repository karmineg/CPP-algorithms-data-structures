#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    for(int i = 1; i <= 10; i++)
    {
        cout << i << endl;
        //variável i só existe dentro do escopo do laço
    }

//  cout << i;
}
