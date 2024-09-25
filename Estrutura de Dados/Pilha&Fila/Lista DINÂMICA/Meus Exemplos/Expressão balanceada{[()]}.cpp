#include<iostream>
#include<string>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

string message1(string tipo) {
    return "> Um" + tipo + " está em posição indevida!";
}

void message2(string tipo) {
    cout << "> Pelo menos, um" + tipo + " não foi fechado!";
}

void AnalisaExprF(Fila<char>* F, string expr) {
    int cmp = expr.length();
    string b = "";
    Fila<char>* Faux = new Fila<char>;
    char aux;

    for(int i = 0; i < cmp; i++) {
        char C = expr[i];

        if(C == '(' || C == '[' || C == '{') {
            enfileiraF(Faux, C);
        }
        else if(C == ')' || C == ']' || C == '}') {
            while(!vaziaF(Faux)) {
                aux = desenfileiraF(Faux);
                if((aux == '(' && C != ')') || (aux == '[' && C != ']') || (aux == '{' && C != '}')) {
                    b = message1(" símbolo");
                    break;
                }
                else {
                    enfileiraF(F, aux);
                    break;
                }
            }
            if(b != "") break;
        }
    }

    if(b == "" && vaziaF(Faux)) {
        cout << "> Equação balanceada!";
    }
    else {
        cout << "> Equação não balanceada!\n";
        if(b == "") {
            while(!vaziaF(F)) {
                aux = desenfileiraF(F);
                if(aux == '(') message2(" parêntese");
                else if(aux == '[') message2(" colchete");
                else message2("a chave");
            }
        } else cout << b;
    }
}

void AnalisaExprP(Pilha<char>* P, string expr) {
    int cmp = expr.length();
    string b = "";

    for(int i = 0; i < cmp; i++) {
        char C = expr[i];

        if(C == '(' || C == '[' || C == '{') {
            empilhaP(P, C);
        }
        else if(C == ')') {
            if(P->topo == -1 || espiaP(P)!= '(') {
                b = message1(" parêntese");
                break;
            } desempilhaP(P);
        }
        else if(C == ']') {
            if(P->topo == -1 || espiaP(P)!= '[') {
                b = message1(" colchete");
                break;
            } desempilhaP(P);
        }
        else if(C == '}') {
            if(P->topo == -1 || espiaP(P)!= '{') {
                b = message1("a chave");
                break;
            } desempilhaP(P);
        }
    }

    if(b == "" && P->topo == -1) {
        cout << "> Equação balanceada!";
    }
    else {
        cout << "> Equação não balanceada!\n";
        if(b == "") {
            if(espiaP(P) == '(') message2(" parêntese");
            else if(espiaP(P) == '[') message2(" colchete");
            else message2("a chave");
        } else cout << b;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;
    string expr;
    Pilha<char>* P = new Pilha<char>();
    inicializaP(P, 15);
    Fila<char>* F = new Fila<char>();
    inicializaF(F, 15);

    cout << "> Insira uma expressão(PILHA): ";
    cin >> expr;
    AnalisaExprP(P, expr);

    cout << endl;
    cout << endl;
    cout << "> Insira uma expressão(FILA): ";
    cin >> expr;
    AnalisaExprF(F, expr);

}
