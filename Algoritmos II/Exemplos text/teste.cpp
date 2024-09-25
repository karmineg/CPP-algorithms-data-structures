#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

main(){
    int *p;
    int i =10;
    p = &i;
    (*p)++;

    cout << *p;

}
