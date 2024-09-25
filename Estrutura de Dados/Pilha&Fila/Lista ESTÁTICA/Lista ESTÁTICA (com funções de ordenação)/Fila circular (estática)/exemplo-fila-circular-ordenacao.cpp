#include<iostream>
using namespace std;
#include"fila-circular.hpp"

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila<int>* F = new Fila<int>();
    inicializaF(F, 5); // Inicia fila com vetor de 5 dados!!

    // Adicionando números na fila (enfileirando...)
    enfileiraF(F, -30);
    enfileiraF(F, -20);
    enfileiraF(F, -10);
    enfileiraF(F, 0);
    enfileiraF(F, 30);
    enfileiraF(F, 10); // Não foi adicionado, lista JÁ lotada
    enfileiraF(F, 20); // Não foi adicionado, lista JÁ lotada
    desenfileiraF(F);
    desenfileiraF(F);
    desenfileiraF(F);
    desenfileiraF(F);
    enfileiraF(F, 10);
    enfileiraF(F, 20);
    enfileiraF(F, 0);
    mostraF(F, "de números");

    ordenaF(F, true); // Organiza dados em ORDEM CRESCENTE
    mostraF(F, "de números em ordem CRESCENTE");


    ordenaF(F, false); // Organiza dados em ORDEM DECRESCENTE
    mostraF(F, "de números em ordem DECRESCENTE");

    return 0;
}
