#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int QP, PP;
    float VALOR, PAGAS = 0, SALDO = 0;
    cout << "INFORME A QUANTIDADE DE PRESTA��ES: ";
    cin >> QP;
    cout << "INFORME A QUANTIDADE DE PRESTA��ES PAGAS: ";
    cin >> PP;
    cout << "INFORME O VALOR DE CADA PRESTA��O: ";
    cin >> VALOR;

    PAGAS = VALOR * PP;
    SALDO = (QP * VALOR) - PAGAS;

    cout << "VALOR J� PAGO: " << PAGAS << endl;
    cout << "SALDO DEVEDOR: " << SALDO << "\n";

}
