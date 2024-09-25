#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

struct Elemento {
    int dado;
    int freq;
};

bool operator>(const Elemento &E1, const Elemento &E2) {
    return (E1.freq > E2.freq);
}

bool operator<(const Elemento &E1, const Elemento &E2) {
    return (E1.freq < E2.freq);
}

void ModaF(Fila<int>* F) {
    if(vaziaF(F)) {
        cout << "> Fila está VAZIA!!\n\n";
        return;
    }

    int TOT = F->total;
    Fila<Elemento>* aux = new Fila<Elemento>();
    Fila<Elemento>* aux0 = new Fila<Elemento>();
    inicializaF(aux, F->total);
    inicializaF(aux0, F->total);

    while(!vaziaF(F)) {
        bool encontrado = false;
        int dado = desenfileiraF(F);
        while(!vaziaF(aux)) {
            Elemento e = desenfileiraF(aux);
            if(e.dado == dado) {
                e.freq++;
                encontrado = true;
            } enfileiraF(aux0, e);
        }
        if(!encontrado) {
            Elemento e;
            e.dado = dado;
            e.freq = 1;
            enfileiraF(aux, e);
        }
        while(!vaziaF(aux0)) enfileiraF(aux, desenfileiraF(aux0));
    }

    ordenaF(aux, false);
    int totAux = aux->total;

    Fila<int> *I = new Fila<int>();
    inicializaF(I, TOT);
    Elemento E1 = desenfileiraF(aux);
    int iE = E1.freq;

    if(iE == 1) cout << "> Nenhum elemento se repete mais de uma vez.";
    else {

        enfileiraF(I, E1.dado);
        while(!vaziaF(aux)) {
            Elemento E2 = desenfileiraF(aux);
            if(E2.freq == iE) enfileiraF(I, E2.dado);
            else break;
        }

        if(I->total == totAux) {
            cout << "> Todos os elementos se repetem igualmente (" << iE << " vezes)." << endl;
        } else {
            if(I->total == 1) {
                cout << "> O elemento mais repetido é " << desenfileiraF(I) << "." << endl;
                cout << "> Ele se repete " << iE << " vezes!!";
            } else {
                cout << "> Os elementos que mais se repetem são os seguintes: ";
                while(!vaziaF(I)) {
                    cout << desenfileiraF(I) << ", ";
                }
                cout << ".\n> Eles se repetem " << iE << " vezes!!";
            }
        }

    } cout << endl;
}

void ModaP(Pilha<int>* P) {
    if(vaziaP(P)) {
        cout << "> Pilha está VAZIA!!\n\n";
        return;
    }

    int TOT = P->tam;
    Pilha<Elemento>* aux = new Pilha<Elemento>();
    Pilha<Elemento>* aux0 = new Pilha<Elemento>();
    inicializaP(aux, P->tam);
    inicializaP(aux0, P->tam);

    while(!vaziaP(P)) {
        bool encontrado = false;
        int dado = desempilhaP(P);
        while(!vaziaP(aux)) {
            Elemento e = desempilhaP(aux);
            if(e.dado == dado) {
                e.freq++;
                encontrado = true;
            } empilhaP(aux0, e);
        }
        if(!encontrado) {
            Elemento e;
            e.dado = dado;
            e.freq = 1;
            empilhaP(aux, e);
        }
        while(!vaziaP(aux0)) empilhaP(aux, desempilhaP(aux0));
    }

    ordenaP(aux, true);
    int totAux = aux->topo;

    Pilha<int> *I = new Pilha<int>();
    inicializaP(I, TOT);
    Elemento E1 = desempilhaP(aux);
    int iE = E1.freq;

    if(iE == 1) cout << "> Nenhum elemento se repete mais de uma vez.";
    else {

        empilhaP(I, E1.dado);
        while(!vaziaP(aux)) {
            Elemento E2 = desempilhaP(aux);
            if(E2.freq == iE) empilhaP(I, E2.dado);
            else break;
        }

        if(I->topo == totAux) {
            cout << "> Todos os elementos se repetem igualmente (" << iE << " vezes)." << endl;
        } else {
            if(I->topo == 0) {
                cout << "> O elemento mais repetido é " << desempilhaP(I) << "." << endl;
                cout << "> Ele se repete " << iE << " vezes!!";
            } else {
                cout << "> Os elementos que mais se repetem são os seguintes: ";
                cout << desempilhaP(I);
                while(!vaziaP(I)) cout << ", " << desempilhaP(I);
                cout << ".\n> Eles se repetem " << iE << " vezes!!";
            }
        }

    } cout << endl;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Pilha<int>* P = new Pilha<int>();
    inicializaP(P, 20);
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 20);

    enfileiraF(F, 1);
    enfileiraF(F, 2);
    enfileiraF(F, 2);
    enfileiraF(F, 3);
    enfileiraF(F, 4);
    enfileiraF(F, 6);
    enfileiraF(F, 6);
    enfileiraF(F, 6);

    empilhaP(P, 1);
    empilhaP(P, 2);
    empilhaP(P, 0);
    empilhaP(P, 3);
    empilhaP(P, 4);
    empilhaP(P, 6);
    empilhaP(P, 7);
    empilhaP(P, 8);

    mostrarSimplesP(P, "");
    cout << endl;
    mostrarSimplesF(F, "");
    cout << endl;
    cout << endl;

    ModaF(F);
    cout << endl;
    ModaP(P);
}
