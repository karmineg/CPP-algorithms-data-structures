/* 8. Fa�a um algoritmo que leia dois n�meros inteiros (Int1 e Int2) e imprima o quociente e o resto da
divis�o inteira de Int1 por Int2. */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int int1, int2, quo, resto;

    cout << "Digite 0 1� n�mero inteiro: ";
    cin >> (int1);

    cout << "Digite o 2� n�mero inteiro: ";
    cin >> (int2);

    quo = int1 / int2;
    resto = int1%int2;

    if (int2 == 0){
        cout << "Imposs�vel de dividir.";
    }
    else {
          cout << "O quoficiente � " << quo << " e o resto � " << resto << endl;
          };

}
