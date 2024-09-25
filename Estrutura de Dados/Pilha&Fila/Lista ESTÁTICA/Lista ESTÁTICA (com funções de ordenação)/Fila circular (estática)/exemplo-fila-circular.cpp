#include<iostream>
using namespace std;
#include"fila-circular.hpp"

void existeNumero(Fila<int> *F, int num) {
    bool existe = buscaF(F, num);

    cout << "> Existe número " << num << " na lista? ";
    if(existe) cout << "Sim!!! :D\n";
    else cout << "Não... :.(\n";
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila<int>* F = new Fila<int>();
    inicializaF(F, 5); // Inicia fila com vetor de 5 dados!!

    // Adicionando números na fila (enfileirando...)
    enfileiraF(F, 10);
    enfileiraF(F, 20);
    enfileiraF(F, 30);
    enfileiraF(F, 40);
    enfileiraF(F, 50);
    enfileiraF(F, 60); // Não foi adicionado, lista JÁ lotada
    enfileiraF(F, 70); // Não foi adicionado, lista JÁ lotada
    mostraF(F, "de 10 a 50");


    // Retirando os primeiros números da fila (FIFO)
    desenfileiraF(F);
    desenfileiraF(F);
    mostraF(F, "de 30 a 50");


    // Adicionando MAIS números ("dando a volta" na fila CIRCULAR)
    enfileiraF(F, 60);
    enfileiraF(F, 70);
    enfileiraF(F, 80); // NÃO foi adicionado, fila JÁ lotada
    mostraF(F, "de 30 a 70 (fila 'deu a volta')");


    // Buscando números (função CRIADA aqui)
    existeNumero(F, 10);
    existeNumero(F, 40);
    existeNumero(F, 70);



    // DELETANDO DADOS!!
    cout << endl;
    if(vaziaF(F)) cout << "\n> Fila está completamente VAZIA!!";
    else cout << "\n> Fila tem, pelo menos, um elemento!";

    destroiF(F); // Destrói elementos da fila

    if(vaziaF(F)) cout << "\n> Fila FOI DESTRUIDA!!\n";
    else cout << "\n> Fila tem, pelo menos, um elemento!\n";
    mostraF(F, "de números");
}
