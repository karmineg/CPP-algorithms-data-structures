/* 3 – Escrever um programa que leia um número inteiro, positivo menor ou igual a 10. Montar e mostrar
a tabuada deste número, como o exemplo abaixo.
Informe um número: _
Tabuada do 8
1 x 8 = 8
2 x 8 = 16
.
.
10 x 8 = 80 */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num;

    cout << "Informe um número inteiro: ";
    cin >> (num);

    if ((num < 0) or (num > 10)){
        cout << "Número inválido!";
    }
    else {
        cout << num << " x 1 = " <<  num * 1 << endl;
        cout << num << " x 2 = " << num * 2 << endl;
        cout << num << " x 3 = " << num * 3 << endl;
        cout << num << " x 4 = " << num * 4 << endl;
        cout << num << " x 5 = " << num * 5 << endl;
        cout << num << " x 6 = " << num * 6 << endl;
        cout << num << " x 7 = " << num * 7 << endl;
        cout << num << " x 8 = " << num * 8 << endl;
        cout << num << " x 9 = " << num * 9 << endl;
        cout << num << " x 10 = " << num * 10 << endl;
    };
}
