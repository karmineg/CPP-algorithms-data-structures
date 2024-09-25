/*3. Empregando pilha, crie uma fun��o para verificar se uma express�o composta apenas por chaves, colchetes e
par�nteses est� ou n�o balanceada.
a) Exemplo de express�es balanceadas: �[ { () () } {} ]�, �{ [ ( [ { } ] ) ] }�
b) Exemplo de express�es n�o balanceadas: �{ [ ( } ] )�, �{ [ ) () ( ] }�*/

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
                b = " par�ntese fechado";
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
        cout << "Equa��o devidamente BALANCEADA!!";
    } else {
        cout << "Equa��o N�O balanceada... ";
        if(b == "") cout << "H� itens que n�o foram fechados!!";
        else cout << "Um" << b << " est� em posi��o indevida!!";
    }
}

main() {
    setlocale(LC_ALL, "Portuguese");
    system ("color F5");
    Pilha P;
    string expr = "";
    cout << ">> Insira uma express�o: ";
    getline(cin, expr);

    AnalisaExp(&P, expr);
}
