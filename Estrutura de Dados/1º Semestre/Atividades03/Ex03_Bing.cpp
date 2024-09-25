/*3. Empregando pilha, crie uma função para verificar se uma expressão composta apenas por chaves, colchetes e
parênteses está ou não balanceada.
a) Exemplo de expressões balanceadas: “[ { () () } {} ]”, “{ [ ( [ { } ] ) ] }”
b) Exemplo de expressões não balanceadas: “{ [ ( } ] )”, “{ [ ) () ( ] }”*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-dinamicaCHAR.hpp"

void AnalisaExp(Pilha* P, string expr) {
    int cmp = expr.length();
    string b = "";
    for(int i = 0; i < cmp; i++) {
        char C = expr[i];
        if(C == '(' || C == '[' || C == '{') {
            empilhaP(P, C);
        } else if(C == ')') {
            if(desempilhaP(P) != '(') {
                b = " parêntese fechado";
                break;
            }
        } else if(C == ']') {
            if(desempilhaP(P) != '[') {
                b = " colchete fechado";
                break;
            }
        } else if(C == '}') {
            if(desempilhaP(P) != '{') {
                b = "a chave fechada";
                break;
            }
        }
    }

    if(b == "" && vaziaP(P)) {
        cout << "Equação devidamente BALANCEADA!!";
    } else {
        cout << "Equação NÃO balanceada... ";
        if(b == "") cout << "Há itens que não foram fechados!!";
        else cout << "Um" << b << " está em posição indevida!!";
    }
}

main() {
    setlocale(LC_ALL, "Portuguese");
    system ("color F5");
    Pilha P;
    string expr = "";
    cout << ">> Insira uma expressão: ";
    getline(cin, expr);

    AnalisaExp(&P, expr);
}
