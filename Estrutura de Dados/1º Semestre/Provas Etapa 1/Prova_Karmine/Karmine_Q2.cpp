#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-template.hpp"
#include "filadinamica-template.hpp"

No<int>* InverteItem(No<int>* P, int K) {
    No<int> *Paux = nullptr;
    NoF<int> *Faux = nullptr; // Isso é pilha (por enquanto)

    // Adiciona tudo da pilha original na fila auxiliar
    while(P != NULL){
        Faux = adicionaF(Faux, P->dado);
        P = removeP(P);
    }

    // Adicionar (total - K) elementos da fila pra pilha auxiliar
    int cont = 0;
    int total = quantosItensFila(Faux);
    if(K != total) {
        while(Faux != NULL) {
            Paux = adicionaP(Paux, Faux->dado);
            Faux = removeF(Faux);
            cont++;
            if(cont == total - K) break;
        }
    }
    // Adicionar K elementos (excedente) da fila pra pilha original
    while(Faux != NULL) {
        P = adicionaP(P, Faux->dado);
        Faux = removeF(Faux);
    }

    // Adicionar elementos da pilha auxiliar pra pilha
    while(Paux != NULL) {
        P = adicionaP(P, Paux->dado);
        Paux = removeP(Paux);
    }

    cout << "> Pilha invertida!";
    getchar();
    return P;

}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int> *P = nullptr;

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                        #" << endl;
        cout << "# 1 - Inserir valores na pilha    #" << endl;
        cout << "# 2 - Inverter elementos da pilha #" << endl;
        cout << "# 3 - Mostrar pilha               #" << endl;
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

            case 1:
                int elem;
                cout << "> Insira um valor: ";
                cin >> elem;
                cout << "> Elemento adicionado!";
                P = adicionaP(P, elem);
                getchar();
                break;

            case 2: {
                int K;
                int qtd = quantosItens(P);
                do {
                    cout << "> Digite o número de elementos da pilha a serem invertidos: ";
                    cin >> K;
                    if(K > qtd) cout << "> Esse valor é maior do que a quantidade de elementos armazenados na pilha!\n";
                    else break;
                } while(true);
                P = InverteItem(P, K);
                break;}

            case 3:
                mostraP(P, "dos valores");
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
