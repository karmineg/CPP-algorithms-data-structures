/*2. Crie as seguintes fun��es:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

int condNum(No<int>* L) {
    int A = ((L->prox)->dado > L->dado);
    int B = ((L->prox)->dado == L->dado);
    return A - B; // 0: Decrescente; 1: Crescente; -1: Igual
}

void VerificaOrdenacao(No<int>* L) {
    if(L == NULL) cout << "> A lista est� vazia!\n� imposs�vel classific�-lo em crescente ou decrescente!";
    else {
        if(L->prox == NULL) cout << "> H� apenas um valor dentro da lista!\n� imposs�vel classific�-lo em crescente ou decrescente!";
        else {
            // Analisar do primeiro pro segundo
            int C = condNum(L);
            L = L->prox;
            // Em seguida, analisar o resto
            while(L->prox != NULL) {
                int D = condNum(L);
                if(D >= 0) {
                    if(C == -1) C = D; // Se at� ent�o os valores estavam iguais, substituir aqui
                    else if(C != D) { // Se a rela��o � quebrada (Ex.: antes estava decrescente, agora ficou crescente)
                        cout << "> Esta lista N�O est� ordenada!!";
                        return;
                    }
                } L = L->prox;
            }
            if(C == 0) cout << "> Esta lista � DECRESCENTE!!";
            else if(C == 1) cout << "> Esta lista � CRESCENTE!!";
            else cout << "> Esta lista � CONSTANTE (todos os valores s�o iguais)!!";
        }
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declara��o padr�o para criar uma lista
    No<int>** L = new No<int>*();

    do
    {
        system("cls");
        cout << "############MENU DE OP��ES###########" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Inserir valor na lista        #" << endl;
        cout << "# 2 - Remover �ltimo valor da lista #" << endl;
        cout << "# 3 - Mostrar lista                 #" << endl;
        cout << "# 4 - Verificar se est� ordenada    #" << endl;
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
                cout << ">> Digite um valor num�rico: ";
                cin >> num;
                adicionarFim(L, num);
                cout << "!!! Adicionado com sucesso !!!";
                getchar();
                break;
            }

            case 2:
                if(*L != NULL) cout << "> Valor " << removeFim(L) << " retirado com sucesso!";
                else cout << "> Lista J� est� vazia!!!";
                break;

            case 3:
                mostrar(*L, "Lista de n�meros");
                break;

            case 4:
                VerificaOrdenacao(*L);
                break;

            default:
                cout << "!!! Op��o inv�lida !!!";
        } getchar();
    } while(menu != 0);
}
