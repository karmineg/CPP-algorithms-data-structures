#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void coelho(int cont, int t1, int t2, int t3);
main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;

    cout << "Escolha o número da cria de coelho: ";
    cin >> n;
    coelho(2, 1, 1, n);
}
void coelho(int cont, int t1, int t2, int t3)
{

    if(t2 >= t3)
        return;

    else
        if (cont == 2) {
            cout << t1 << ", " << t2 << ", ";
            cont++;
            coelho(cont, t1, t2, t3);
        }

        else {
            cout << t1 + t2 << ", ";
            cont++;
            coelho(cont, t2, t1 + t2, t3);
        }
}
