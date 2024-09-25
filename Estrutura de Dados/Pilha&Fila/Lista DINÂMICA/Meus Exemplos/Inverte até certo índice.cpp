#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void InverteFP(Fila<char>* F, int I, int J) {
    Pilha<char>* Paux = new Pilha<char>;
    inicializaP(Paux, 20);

    int cont = 0;

    while(cont < I) {
        enfileiraF(F, desenfileiraF(F));
        cont++;
    }

    while(cont <= J) {
        empilhaP(Paux, desenfileiraF(F));
        cont++;
    }

    while(!vaziaP(Paux)) {enfileiraF(F, desempilhaP(Paux));}

    while(cont < F->total) {
        enfileiraF(F, desenfileiraF(F));
        cont++;
    }

}

void InverteP(Pilha<char>* P, int I, int J) {
    Pilha<char>* PAux1 = new Pilha<char>;
    inicializaP(PAux1, 20);
    Pilha<char>* PAux2 = new Pilha<char>;
    inicializaP(PAux2, 20);
    Pilha<char>* PAux3 = new Pilha<char>;
    inicializaP(PAux3, 20);
    for (int i = 1; i < I; i++) { empilhaP(PAux1, desempilhaP(P)); }
    for (int i = I; i <= J; i++) { empilhaP(PAux2, desempilhaP(P)); }
    while (!vaziaP(PAux2)) { empilhaP(PAux3, desempilhaP(PAux2)); }
    while (!vaziaP(PAux3)) { empilhaP(P, desempilhaP(PAux3)); }
    while (!vaziaP(PAux1)) { empilhaP(P, desempilhaP(PAux1)); }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int I, J;
    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 20);
    Fila<char>* FP = new Fila<char>();
    inicializaF(FP, 20);

    string C;
    cout << "> Insira um string: ";
    cin >> C;
    for (int i = 0; i < C.length(); i++) {
        empilhaP(P, C[i]);
        enfileiraF(FP, C[i]);
    }
    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(FP, "");

    int T = 20 - 1;
    do {
        cout << "\n> Digite apartir de qual índice deseja realizar a inversão(I): ";
        cin >> I;
        cout << "> Digite qual índice deve ser o limite da inversão(J): ";
        cin >> J;
        if(J > T) cout << "> O índice insirido para J é maior do que a quantidade de elementos armazenados na pilha/fila!\n\n";
        else if(I >= T) cout << "> O índice insirido para I é maior ou igual do que a quantidade de elementos armazenados na pilha/fila!\n\n";
        else if(I < 0) cout << "> O índice insirido para I deve ser maior do que 0!\n\n";
        else if(I >= J) cout << "> O índice insirido para I deve ser menor do que J!\n\n";
        else break;
    } while(true);

    InverteP(P, I, J);
    InverteFP(FP, I, J);

    cout << endl;
    mostrarSimplesP(P, "após função");
    cout << endl;
    mostrarSimplesF(FP, "após função");

}
