/*7. Empregando pilha, crie uma fun��o para verificar se uma express�o matem�tica composta apenas por par�nteses
est� ou n�o balanceada.
� Exemplo de express�es balanceadas: �(A+B)�, �((A+B)+(C+D))�
� Exemplo de express�es n�o balanceadas: �((A+B)�, �)A+B(�, �(A+B)) � (C + D�*/

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
    cout << ">> Insira uma express�o matem�tica (com par�nteses): ";
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
            if(PA.topo == PF.topo) { // Quando o topo da pilha A for igual ao da pilha F, a entrada de um par�ntese fechado automaticamente DESEQUILIBRA a equa��o
                cout << "Equa��o N�O est� equilibrada... :( (par�ntese fechado entra ap�s equil�brio de par�nteses)";
                b = 0;
                break;
            } else {
                empilhaP(&PF, ")");
            }
        }
    }
    if(b) { // Se n�o for detectado erro no processo anterior
        if(PA.topo == PF.topo) {
            cout << "Equa��o est� EQUILIBRADA!!!";
        } else {
            cout << "Equa��o N�O est� equilibrada... :( (todos os par�nteses abertos N�O foram fechados)";
        }
    }

    cout << endl << endl;
    mostraP(&PA, "dos p. ABERTOS");
    cout << endl;
    mostraP(&PF, "dos p. FECHADOS");
}
