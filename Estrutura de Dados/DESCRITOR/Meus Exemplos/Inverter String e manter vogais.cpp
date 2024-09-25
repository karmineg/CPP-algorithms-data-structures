#include<iostream>
using namespace std;
#include "descritor-template.hpp"

bool vogal(char c) {
    char mc = tolower(c);
    return (mc == 'a' || mc == 'e' || mc == 'i' || mc == 'o' || mc == 'u');
}

ListaD<char>* InverteLD(ListaD<char>* L){
    ListaD<char> LD, Laux1, Laux2;
    NoD<char>* N = L->inicio;
    int tam = L->tam;

    while(N != NULL) {
        if(vogal(N->dado)) {
            Laux1.adFim(N->dado);
        } else Laux2.adInicio(N->dado);
        N = N->prox;
    }

    N = L->inicio;
    while(N != NULL) {
        if(vogal(N->dado)) {
            LD.adFim(Laux1.inicio->dado);
            Laux1.removeInicio();
        } else {
            LD.adFim(Laux2.inicio->dado);
            Laux2.removeInicio();
        }
        N = N->prox;
    }

    L->destruir();
    *L = LD.copiaLista();

    return L;
}

ListaS<char>* InverteLS(ListaS<char>* L){
    ListaS<char> LS, Laux1, Laux2;
    No<char>* N = L->inicio;
    int tam = L->tam;

    while(N != NULL) {
        if(vogal(N->dado)) {
            Laux1.adFim(N->dado);
        } else Laux2.adInicio(N->dado);
        N = N->prox;
    }

    N = L->inicio;
    while(N != NULL) {
        if(vogal(N->dado)) {
            LS.adFim(Laux1.inicio->dado);
            Laux1.removeInicio();
        } else {
            LS.adFim(Laux2.inicio->dado);
            Laux2.removeInicio();
        }
        N = N->prox;
    }

    L->destruir();
    *L = LS.copiaLista();

    return L;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<char> L;
            string C;
            cout << "> Insira um string: ";
            cin >> C;
            for (int i = 0; i < C.length(); i++) {
                L.adFim(C[i]);
            }
            L.mostrarSimples("Lista Duplamente");

            L = *InverteLD(&L);
            cout << endl;
            L.mostrarSimples("Lista Duplamente após inversão");

            break;
        }

        case 1: {
            ListaS<char> L;
            string C;
            cout << "> Insira um string: ";
            cin >> C;
            for (int i = 0; i < C.length(); i++) {
                L.adFim(C[i]);
            }
            L.mostrarSimples("Lista Simplesmente");

            L = *InverteLS(&L);
            cout << endl;
            L.mostrarSimples("Lista Simplesmente após inversão");

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}


