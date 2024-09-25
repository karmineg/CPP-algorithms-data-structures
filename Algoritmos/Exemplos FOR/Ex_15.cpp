#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    int i;
    for(i = 1; i <= 10; i++)
    {
        cout << "i: " << i << endl;
    }
    cout << "\n\n";
    for(i = 1; i <= 10; i += 2)
    {
        cout << "i: " << i << endl;
    }

    cout << "\n\n";
    for(i = 10; i > 0; i--)
    {
        cout << "i: " << i << endl;
    }
}
