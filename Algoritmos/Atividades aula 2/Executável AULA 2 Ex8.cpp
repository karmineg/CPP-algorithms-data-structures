/* 8. Faça um algoritmo que leia dois números inteiros (Int1 e Int2) e imprima o quociente e o resto da
divisão inteira de Int1 por Int2. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int int1, int2, quo, resto;

    cout << "Digite 0 1º número inteiro: ";
    cin >> (int1);

    cout << "Digite o 2º número inteiro: ";
    cin >> (int2);

    quo = int1 / int2;
    resto = int1%int2;

    if (int2 == 0){
        cout << "Impossível de dividir.";
    }
    else {
          cout << "O quoficiente é " << quo << " e o resto é " << resto << endl;
          };

}
