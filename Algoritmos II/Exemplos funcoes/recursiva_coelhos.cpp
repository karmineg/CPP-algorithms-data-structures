#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void coelho(int cont, int t1, int t2);
main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << "Os primeiros 20 termos da série de coelhos são: ";
    coelho(2, 0, 1);
}
void coelho(int cont, int t1, int t2)
{

    if(cont > 20)
        return;

    else
        if (cont == 2) {
            cout << t1 << ", " << t2 << ", ";
            cont++;
            coelho(cont, t1, t2);
        }

        else {
            cout << t1 + t2 << ", ";
            cont++;
            coelho(cont, t2, t1 + t2);
        }
}
