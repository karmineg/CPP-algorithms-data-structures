/*9. Dados duas listas L1 e L2, crie uma função para computar a lista L3 que é a intersecção de L1 e L2.
Exemplo:*/

#include<iostream>
#include<time.h>
using namespace std;

#include "lista-template.hpp"

void Ordenacao1(No<int>* l) {
    int qtd = 0;
    if(l != NULL) { // Tem, pelo menos, dois itens (algoritmo de ordenação)
        No<int>* m = nullptr;
        int M;
        int N;
        while(true) { // Dentro deste laço, verificamos a lista do início ao fim!
            qtd++;
            m = l;
            M = m->dado;
            bool cond = true;
            while(m->prox != NULL) {
                N = (m->prox)->dado;
                if(N < M) { // Se o próximo dado é MENOR que o atual
                    (m->prox)->dado = M;
                    m->dado = N;
                    N = M;
                    cond = false;
                } M = N;
                m = m->prox;
            } if(cond) break; // Se a lista já está ordenada, encerrar laço principal
        }
    } cout << ">> Lista ordenada com sucesso... após " << qtd << " verificações(ão)!!!\n";
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
        cout << "##########MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                        #" << endl;
        cout << "# 1 - Inserir número              #" << endl;
        cout << "# 2 - Remover último número       #" << endl;
        cout << "# 3 - Ordenar números (função #1) #" << endl;
        cout << "# 4 - Ordenar números (função #2) #" << endl;
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
                cout << ">> Digite um valor numérico: ";
                cin >> num;
                adicionarFim(L, num);
                cout << "!!! Adicionado com sucesso na lista !!!";
                getchar();
                break;
            }

            case 2:
                if(*L != NULL) cout << "> Valor " << removeFim(L) << " retirado com sucesso da lista!";
                else cout << "> Lista JÁ está vazia!!!";
                break;

            case 3:
                Ordenacao1(*L);
                break;

            case 4:
                *L = Ordenacao2(*L);
                break;

            case 5:
                mostrar(*L, "Lista de números", "    Número", 0);
                break;

        }; getchar();
    }
    while(menu != 0);
}
