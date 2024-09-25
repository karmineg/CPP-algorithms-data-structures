#include<iostream>
using namespace std;

#include "template.hpp"

No<char> *decToHex(int dec, No<char> *P) {
    dec = abs(dec);
    while(dec > 0) {
        int rest = dec % 16;
        char c;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        P = adicionar(P, c);
        dec /= 16;
    } return P;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    No<char> *P = nullptr;
    int num;

    cout << "Digite um valor: ";
    cin >> num;
    cout << endl;
    if(num != 0) P = decToHex(num, P);
    else P = adicionar(P, '0');
    mostrar(P, "hexadecimal");
}
