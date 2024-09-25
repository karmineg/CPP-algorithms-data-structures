/*21 – Escreva um programa que apresente os primeiros 20 termos da sequência de Fibonacci: “A geração
n de Fibonacci retorna 1 quando for até a 2a geração. Se não, retorna a soma das duas últimas gerações
anteriores”. Utilize uma função recursiva para resolver este problema.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void coelho(int cont, int t1, int t2);

main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << "Os primeiros 20 termos de Fibonacci: ";
    coelho(2, 0, 1);
}

void coelho(int cont, int t1, int t2)
{

    if (cont > 20)
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
