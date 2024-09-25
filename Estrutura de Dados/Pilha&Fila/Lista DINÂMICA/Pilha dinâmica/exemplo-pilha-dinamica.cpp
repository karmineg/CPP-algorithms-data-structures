#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"

int main() {
    setlocale(LC_ALL, "Portuguese");

    setlocale(LC_ALL, "Portuguese");

    No<int>* P = nullptr; // Inicia a pilha como PONTEIRO NULO

    // Adicionando números na pilha (enfileirando...)
    P = adicionaP(P, 10);
    P = adicionaP(P, 20);
    P = adicionaP(P, 30);
    P = adicionaP(P, 40);
    P = adicionaP(P, 50);
    P = adicionaP(P, 60);
    P = adicionaP(P, 70);
    mostraP(P, "de 10 a 70 (do FIM ao INÍCIO)");

    // Retirando os primeiros números da pilha (FIFO)
    cout << "> Removido " << P->dado << "\n";
    P = removeP(P);

    cout << "> Removido " << P->dado << "\n\n";
    P = removeP(P);
    mostraP(P, "de 10 a 50 (do FIM ao INÍCIO)");


    // Adicionando MAIS números ("dando a volta" na pilha CIRCULAR)
    P = adicionaP(P, 80);
    P = adicionaP(P, 90);
    P = adicionaP(P, 100); // NÃO foi adicionado, pilha JÁ lotada
    mostraP(P, "de 10 a 100, exceto 60 e 70 (do FIM ao INÍCIO)");


    // Buscando números (função CRIADA aqui)
    cout << "\n> Existe 10 na lista? " << buscaP(P, 10);
    cout << "\n> Existe 100 na lista? " << buscaP(P, 100);
    cout << "\n> Existe 45 na lista? " << buscaP(P, 45);



    // DELETANDO DADOS!!
    cout << endl;
    if(P == NULL) cout << "\n> Pilha está completamente VAZIA!!";
    else cout << "\n> Pilha tem, pelo menos, um elemento!";

    P = destroiP(P); // Destrói elementos da pilha

    if(P == NULL) cout << "\n> Pilha FOI DESTRUIDA!!\n";
    else cout << "\n> Pilha tem, pelo menos, um elemento!\n";
    mostraP(P, "de números");
}
