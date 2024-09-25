#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

void copiaF(Fila<int>* F1, Fila<int>* F2) {
    // copia os elementos da fila F1 para a fila F2
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 10);
    int aux, aux0;
    while(!vaziaF(F1)) {
        aux = desenfileiraF(F1);
        enfileiraF(F2, aux);
        enfileiraF(Faux, aux);
    }

    while(!vaziaF(Faux)) { // Mantém fila original intacta
        aux0 = desenfileiraF(Faux);
        enfileiraF(F1, aux0);
    }
}

int pertenceF(int x, Fila<int>* F) {
    // verifica se o elemento x pertence à fila F
    int aux;
    int res = 0;
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 15);
    while(!vaziaF(F)) {
        aux = desenfileiraF(F);
        if(aux == x) {
            res = 1;
        }
        enfileiraF(Faux, aux);
    }
    while(!vaziaF(Faux)) { // Mantém fila original intacta
        int aux0 = desenfileiraF(Faux);
        enfileiraF(F, aux0);
    }
    return res;
}

void interseccaoF(Fila<int>* F1, Fila<int>* F2, Fila<int>* F3) {
    // faz a interseccao de elementos em comum entre as filas F1 e F2 e armazena na fila F3
    int aux;
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 15);

    while(!vaziaF(F1)) {
        aux = desenfileiraF(F1);
        if(pertenceF(aux, F2)) {
            enfileiraF(F3, aux);
        }
        enfileiraF(Faux, aux);
    }

    while(!vaziaF(Faux)) { // Mantém fila original intacta
        int aux0 = desenfileiraF(Faux);
        enfileiraF(F1, aux0);
    }
}

void diferencaF(Fila<int>* F1, Fila<int>* F2, Fila<int>* F3) {
    // faz a diferenca de elementos diferentes entre as filas F1 e F2 e armazena na fila F3
    int aux;
    Fila<int>* Faux = new Fila<int>();
    inicializaF(Faux, 15);

    while(!vaziaF(F1)) {
        aux = desenfileiraF(F1);
        if(!pertenceF(aux, F2)) {
            enfileiraF(F3, aux);
        }
        enfileiraF(Faux, aux);
    }

    while(!vaziaF(Faux)) { // Mantém fila original intacta
        int aux0 = desenfileiraF(Faux);
        enfileiraF(F1, aux0);
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Fila<int>* F = new Fila<int>();
    inicializaF(F, 10);
    Fila<int>* F1 = new Fila<int>();
    inicializaF(F1, 10);

    enfileiraF(F, 1);
    enfileiraF(F, 2);
    enfileiraF(F, 5);
    enfileiraF(F, 3);
    enfileiraF(F, 4);
    enfileiraF(F, 5);

    enfileiraF(F1, 0);
    enfileiraF(F1, 2);
    enfileiraF(F1, 9);
    enfileiraF(F1, 3);
    enfileiraF(F1, 8);
    enfileiraF(F1, 5);

    Fila<int>* Fa = new Fila<int>();
    inicializaF(Fa, 10);
    copiaF(F,Fa);
    Fila<int>* Fa1 = new Fila<int>();
    inicializaF(Fa1, 10);
    copiaF(F1,Fa1);

    Fila<int>* Fi = new Fila<int>();
    inicializaF(Fi,20);
    interseccaoF(Fa,Fa1,Fi);
    mostrarSimplesF(Fi, "Comum");

    Fila<int>* Fd = new Fila<int>();
    inicializaF(Fd,20);
    diferencaF(Fa,Fa1,Fd);
    cout << endl;
    mostrarSimplesF(Fd, "Diferente");
}
