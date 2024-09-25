#include<iostream>
#include<string>
using namespace std;
#include "descritor-template.hpp"

string message1(string tipo) {
    return "> Um" + tipo + " está em posição indevida!";
}

void message2(string tipo) {
    cout << "> Pelo menos, um" + tipo + " não foi fechado!";
}

void AnalisaExprD(ListaD<char>* L, string expr) {
    int cmp = expr.length();
    string b = "";

    for(int i = 0; i < cmp; i++) {
        char C = expr[i];

        if(C == '(' || C == '[' || C == '{') {
            L->adFim(C);
        }
        else if(C == ')') {
            if(L->tam == 0 || !L->existeVal('(')) {
                b = message1(" parêntese");
                break;
            } L->removeUmVal('(');
        }
        else if(C == ']') {
            if(L->tam == 0 || !L->existeVal('[')) {
                b = message1(" colchete");
                break;
            } L->removeUmVal('[');
        }
        else if(C == '}') {
            if(L->tam == 0 || !L->existeVal('{')) {
                b = message1("a chave");
                break;
            } L->removeUmVal('{');
        }
    }

    if(b == "" && L->tam == 0) {
        cout << "> Equação balanceada!";
    }
    else {
        cout << "> Equação não balanceada!\n";
        if(b == "") {
            if(L->existeVal('(')) message2(" parêntese");
            else if(L->existeVal('[')) message2(" colchete");
            else message2("a chave");
        } else cout << b;
    }
}

void AnalisaExprS(ListaS<char>* L, string expr) {
    int cmp = expr.length();
    string b = "";

    for(int i = 0; i < cmp; i++) {
        char C = expr[i];

        if(C == '(' || C == '[' || C == '{') {
            L->adFim(C);
        }
        else if(C == ')') {
            if(L->tam == 0 || !L->existeVal('(')) {
                b = message1(" parêntese");
                break;
            } L->removeUmVal('(');
        }
        else if(C == ']') {
            if(L->tam == 0 || !L->existeVal('[')) {
                b = message1(" colchete");
                break;
            } L->removeUmVal('[');
        }
        else if(C == '}') {
            if(L->tam == 0 || !L->existeVal('{')) {
                b = message1("a chave");
                break;
            } L->removeUmVal('{');
        }
    }

    if(b == "" && L->tam == 0) {
        cout << "> Equação balanceada!";
    }
    else {
        cout << "> Equação não balanceada!\n";
        if(b == "") {
            if(L->existeVal('(')) message2(" parêntese");
            else if(L->existeVal('[')) message2(" colchete");
            else message2("a chave");
        } else cout << b;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;
    string expr;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<char> L;
            cout << "> Insira uma expressão: ";
            cin >> expr;

            AnalisaExprD(&L, expr);

            break;
        }

        case 1: {
            ListaS<char> L;
            cout << "> Insira uma expressão: ";
            cin >> expr;

            AnalisaExprS(&L, expr);

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
