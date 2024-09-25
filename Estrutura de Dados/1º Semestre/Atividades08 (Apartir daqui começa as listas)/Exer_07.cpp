/*9. Dados duas listas L1 e L2, crie uma fun��o para computar a lista L3 que � a intersec��o de L1 e L2.
Exemplo:*/

#include<iostream>
#include<time.h>
using namespace std;

#include "lista-template.hpp"

void Ordenacao1(No<int>* l) {
    int qtd = 0;
    if(l != NULL) { // Tem, pelo menos, dois itens (algoritmo de ordena��o)
        No<int>* m = nullptr;
        int M;
        int N;
        while(true) { // Dentro deste la�o, verificamos a lista do in�cio ao fim!
            qtd++;
            m = l;
            M = m->dado;
            bool cond = true;
            while(m->prox != NULL) {
                N = (m->prox)->dado;
                if(N < M) { // Se o pr�ximo dado � MENOR que o atual
                    (m->prox)->dado = M;
                    m->dado = N;
                    N = M;
                    cond = false;
                } M = N;
                m = m->prox;
            } if(cond) break; // Se a lista j� est� ordenada, encerrar la�o principal
        }
    } cout << ">> Lista ordenada com sucesso... ap�s " << qtd << " verifica��es(�o)!!!\n";
}

No<int>* removeEnd(No<int>* men, No<int>* l) {
    if(l == men) {
        delete men;
        return l->prox;
    }
    No<int>* prim = l,
    *prox = nullptr;
    while(l->prox != NULL) {
        prox = l->prox;
        if(prox == men) {
            l->prox = prox->prox;
            delete prox;
            break;
        } l = l->prox;
    } return prim;
}

No<int>* Ordenacao2(No<int>* l) {
    if(l != NULL) {
        No<int>** aux = new No<int>*(),
        *m = nullptr;
        while(l != NULL) {
            m = l;
            int men = m->dado;
            No<int>* Men = m;
            while(m != NULL) {
                int D = m->dado;
                if(D < men) {
                    men = D;
                    Men = m;
                } m = m->prox;
            } l = removeEnd(Men, l);
            adicionarFim(aux, men);
        } l = *aux;
    } cout << ">> Lista ordenada com sucesso!!!\n";
    return l;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int>** L = new No<int>*();

    do
    {
        system("cls");
        cout << "##########MENU DE OP��ES###########" << endl;
        cout << "# 0 - Sair                        #" << endl;
        cout << "# 1 - Inserir n�mero              #" << endl;
        cout << "# 2 - Remover �ltimo n�mero       #" << endl;
        cout << "# 3 - Ordenar n�meros (fun��o #1) #" << endl;
        cout << "# 4 - Ordenar n�meros (fun��o #2) #" << endl;
        cout << "# 5 - Mostrar lista               #" << endl;
        cout << "###################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: {
                int num;
                cout << ">> Digite um valor num�rico: ";
                cin >> num;
                adicionarFim(L, num);
                cout << "!!! Adicionado com sucesso na lista !!!";
                getchar();
                break;
            }

            case 2:
                if(*L != NULL) cout << "> Valor " << removeFim(L) << " retirado com sucesso da lista!";
                else cout << "> Lista J� est� vazia!!!";
                break;

            case 3:
                Ordenacao1(*L);
                break;

            case 4:
                *L = Ordenacao2(*L);
                break;

            case 5:
                mostrar(*L, "Lista de n�meros", "    N�mero", 0);
                break;

        }; getchar();
    }
    while(menu != 0);
}
