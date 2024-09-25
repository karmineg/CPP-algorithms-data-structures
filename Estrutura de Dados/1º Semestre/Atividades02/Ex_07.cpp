/*7. Empregando pilha, crie uma função para verificar se uma expressão matemática composta apenas por parênteses
está ou não balanceada.
• Exemplo de expressões balanceadas: “(A+B)”, “((A+B)+(C+D))”
• Exemplo de expressões não balanceadas: “((A+B)”, “)A+B(”, “(A+B)) – (C + D”*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilhaString.hpp"

main() {
    setlocale(LC_ALL, "Portuguese");
    system ("color F5");
    Pilha PA, PF;
    string expr = "";
    cout << ">> Insira uma expressão matemática (com parênteses): ";
    getline(cin, expr);

    int cmp = expr.length();
    inicializaP(&PA, cmp);
    inicializaP(&PF, cmp);
    int b = 1;
    for(int i = 0; i < cmp; i++) {
        char C = expr[i];
        if(C == '(') {
            empilhaP(&PA, "(");
        } else if(C == ')') {
            if(PA.topo == PF.topo) { // Quando o topo da pilha A for igual ao da pilha F, a entrada de um parêntese fechado automaticamente DESEQUILIBRA a equação
                cout << "Equação NÃO está equilibrada... :( (parêntese fechado entra após equilíbrio de parênteses)";
                b = 0;
                break;
            } else {
                empilhaP(&PF, ")");
            }
        }
    }
    if(b) { // Se não for detectado erro no processo anterior
        if(PA.topo == PF.topo) {
            cout << "Equação está EQUILIBRADA!!!";
        } else {
            cout << "Equação NÃO está equilibrada... :( (todos os parênteses abertos NÃO foram fechados)";
        }
    }

    cout << endl << endl;
    mostraP(&PA, "dos p. ABERTOS");
    cout << endl;
    mostraP(&PF, "dos p. FECHADOS");
}
