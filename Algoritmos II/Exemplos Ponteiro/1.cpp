#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int soma()
{
	int j = 3, *pj, s = 0;
	pj = &j;
	s += *pj;
	return s;
}

main()
{
     cout<< soma();
}
