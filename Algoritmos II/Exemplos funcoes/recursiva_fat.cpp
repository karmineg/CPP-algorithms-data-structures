#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include <math.h>

using namespace std;

int fat(int n);
main()
{
int v;
cout << "Informe um valor qualquer: ";
cin >> v;
cout << fat(v);
}
int fat(int n)
{
if(n == 1)
return 1;
else
return (n * fat(n-1));
}
