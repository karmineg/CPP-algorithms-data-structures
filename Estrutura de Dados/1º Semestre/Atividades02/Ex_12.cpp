/*. 12. A conversão de um número decimal N (base 10) para binário (base 2) é realizada por sucessivas divisões de N por
2, em que o número binário é obtido pelos restos das divisões realizadas. Crie um programa para converter
número decimais em binários empregando uma pilha.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int num;
    Pilha P;
    //inicializaP(&P, ));

    cout << "Digite um número decimal: ";
    cin >> num;
    if(num == 0) {
        cout << "Binário: 0";
    } else {
        num = abs(num);
        int tam = floor(log2(num) + 1);
        inicializaP(&P, tam);
        // Processo de obtenção dos dígitos em binário
        while(num > 1) {
            empilhaP(&P, num % 2);
            num = floor(num/2);
        } empilhaP(&P, 1);
        cout << endl;
        mostraP(&P, "binária");
    }
}
