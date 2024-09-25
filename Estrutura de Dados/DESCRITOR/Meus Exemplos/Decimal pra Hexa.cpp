#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaD<char>* decToHexD(int dec) {
    ListaD<char>* L = new ListaD<char>();;
    char c;
    dec = abs(dec);

    while(dec > 0) {
        int rest = dec % 16;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        L->adInicio(c);
        dec /= 16;
    } return L;
}

ListaS<char>* decToHexS(int dec) {
    ListaS<char>* L = new ListaS<char>();
    char c;
    dec = abs(dec);

    while(dec > 0) {
        int rest = dec % 16;
        if(rest < 10) c = rest + '0';
        else c = rest - 10 + 'A';
        L->adInicio(c);
        dec /= 16;
    } return L;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int numD, numS;

    cout << "Digite um número decimal: ";
    cin >> numD;
    numS = numD;
    cout << endl;

    //Exemplo DUPLAMENTE
    ListaD<char> LD;
    if(numD != 0)LD = *decToHexD(numD);
    else LD.adFim('0');
    LD.mostrarSimples("Duplamente");

    cout << endl;

    //Exemplo SIMPLESMENTE
    ListaS<char> LS;
    if(numS != 0)LS = *decToHexS(numS);
    else LS.adFim('0');
    LS.mostrarSimples("Simplesmente");

}
