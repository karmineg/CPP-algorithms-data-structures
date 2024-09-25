#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"

No<char>* hexaPilha(int num, No<char>* P) {
    char c;
    num = abs(num);

    while(num > 0) {
        int rest = num % 16;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        P = adicionaP(P, c);
        num /= 16;
    }
    return P;
}

No<int>* binarioPilha(int num, No<int>* P) {
    num = abs(num);

    while(num >= 2) {
        P = adicionaP(P, num%2);
        num = num/2;
    }
    P = adicionaP(P, num);
    return P;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<char>* PH = nullptr;
    No<int>* PB = nullptr;

    int num = 1050;

    cout << "> O número decimal é: " << num;
    cout << endl;
    PH = hexaPilha(num, PH);
    PB = binarioPilha(num, PB);

    mostrarSimplesP(PH, "hexadecimal");
    cout << endl;
    mostrarSimplesP(PB, "binário");

    PH = destroiP(PH);
    PB = destroiP(PB);

}
