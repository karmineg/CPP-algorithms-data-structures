#include <iostream>
using namespace std;

#include "template.hpp"

string message1(string tipo) {
    return "Um" + tipo + " está em posição indevida!!";
}

void message2(string tipo) {
    cout << "Pelo menos, um" + tipo + " NÃO foi fechado!!";
}

void AnalisaExp(No<char> *P, string expr) {

    int cmp = expr.length();
    string b = "";
    for(int i = 0; i < cmp; i++) {
        char C = expr[i];
        if(C == '(' || C == '[' || C == '{') {
            P = adicionar(P, C);
        } else if(C == ')') {
            if(P == NULL || P->dado != '(') {
                b = message1(" parêntese");
                break;
            } P = remover(P);
        } else if(C == ']') {
            if(P == NULL || P->dado != '[') {
                b = message1(" colchete");
                break;
            } P = remover(P);
        } else if(C == '}') {
            if(P == NULL || P->dado != '{') {
                b = message1("a chave");
                break;
            } P = remover(P);
        }
    }

    if(b == "" && P == NULL) {
        cout << "Equação devidamente BALANCEADA!!";
    } else {
        cout << "Equação NÃO balanceada... ";
        if(b == "") {
            if(P->dado == '(') message2(" parêntese");
            else if(P->dado == '[') message2(" colchete");
            else message2("a chave");
        } else cout << b;
    }
}

main() {
    setlocale(LC_ALL, "Portuguese");
    system ("color F5");
    No<char> *P = nullptr;
    string expr = "";
    cout << ">> Insira uma expressão: ";
    getline(cin, expr);
    AnalisaExp(P, expr);
}
