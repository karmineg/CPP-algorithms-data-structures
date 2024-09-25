#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

template<typename T> struct No {
    T dado;
    No *prox;
};
template<typename T> No<T> *adicionar(No<T> *atual, T dado) {
    No<T> *novo = new No<T>();
    novo->dado = dado;
    novo->prox = atual;
    return novo;
}
template<typename T> No<T> *remover(No<T> *atual) {
    if(atual != NULL) {
        No<T> *Prox = atual->prox;
        delete atual;
        return Prox;
    } return nullptr;
}
template<typename T> No<T> *destruir(No<T> *P) {
    No<T> *Prox;
    while(P != NULL) {
        Prox = P->prox;
        delete P;
        P = Prox;
    } return Prox;
}
template<typename T> int quantosItens(No<T> *P) {
    //No<T> *Prox;
    int cont = 0;
    while(P != NULL) {
        P = P->prox;
        cont++;
    } return cont;
}
template<typename T> void mostrar(No<T> *P) {
    if(P == NULL) cout << "!!! Pilha está VAZIA !!!\n\n";
    else {
        cout << "*** PILHA ***\n";
        No<T> *atual = P;
        while(atual != NULL) {
            cout << " " << atual << " | " << atual->dado << endl;
            atual = atual->prox;
        } cout << endl;
    }
}

#endif // _HPP_PILHA_DINAMICA
