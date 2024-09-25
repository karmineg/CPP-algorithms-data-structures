/*2. Crie as seguintes funções:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

int condNum(No<int>* L) {
    int A = ((L->prox)->dado > L->dado);
    int B = ((L->prox)->dado == L->dado);
    return A - B; // 0: Decrescente; 1: Crescente; -1: Igual
}

void VerificaOrdenacao(No<int>* L) {
    if(L == NULL) cout << "> A lista está vazia!\nÉ impossível classificá-lo em crescente ou decrescente!";
    else {
        if(L->prox == NULL) cout << "> Há apenas um valor dentro da lista!\nÉ impossível classificá-lo em crescente ou decrescente!";
        else {
            // Analisar do primeiro pro segundo
            int C = condNum(L);
            L = L->prox;
            // Em seguida, analisar o resto
            while(L->prox != NULL) {
                int D = condNum(L);
                if(D >= 0) {
                    if(C == -1) C = D; // Se até então os valores estavam iguais, substituir aqui
                    else if(C != D) { // Se a relação é quebrada (Ex.: antes estava decrescente, agora ficou crescente)
                        cout << "> Esta lista NÃO está ordenada!!";
                        return;
                    }
                } L = L->prox;
            }
            if(C == 0) cout << "> Esta lista é DECRESCENTE!!";
            else if(C == 1) cout << "> Esta lista é CRESCENTE!!";
            else cout << "> Esta lista é CONSTANTE (todos os valores são iguais)!!";
        }
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declaração padrão para criar uma lista
    No<int>** L = new No<int>*();

    do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Inserir valor na lista        #" << endl;
        cout << "# 2 - Remover último valor da lista #" << endl;
        cout << "# 3 - Mostrar lista                 #" << endl;
        cout << "# 4 - Verificar se está ordenada    #" << endl;
        cout << "#####################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu) {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: {
                int num;
                cout << ">> Digite um valor numérico: ";
                cin >> num;
                adicionarFim(L, num);
                cout << "!!! Adicionado com sucesso !!!";
                getchar();
                break;
            }

            case 2:
                if(*L != NULL) cout << "> Valor " << removeFim(L) << " retirado com sucesso!";
                else cout << "> Lista JÁ está vazia!!!";
                break;

            case 3:
                mostrar(*L, "Lista de números");
                break;

            case 4:
                VerificaOrdenacao(*L);
                break;

            default:
                cout << "!!! Opção inválida !!!";
        } getchar();
    } while(menu != 0);
}
