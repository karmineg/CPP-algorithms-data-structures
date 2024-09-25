/*. 12. A convers�o de um n�mero decimal N (base 10) para bin�rio (base 2) � realizada por sucessivas divis�es de N por
2, em que o n�mero bin�rio � obtido pelos restos das divis�es realizadas. Crie um programa para converter
n�mero decimais em bin�rios empregando uma pilha.*/

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

    cout << "Digite um n�mero decimal: ";
    cin >> num;
    if(num == 0) {
        cout << "Bin�rio: 0";
    } else {
        num = abs(num);
        int tam = floor(log2(num) + 1);
        inicializaP(&P, tam);
        // Processo de obten��o dos d�gitos em bin�rio
        while(num > 1) {
            empilhaP(&P, num % 2);
            num = floor(num/2);
        } empilhaP(&P, 1);
        cout << endl;
        mostraP(&P, "bin�ria");
    }
}
