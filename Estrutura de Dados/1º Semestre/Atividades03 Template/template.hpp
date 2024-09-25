#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iomanip>
#include<string>

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
    int cont = 0;
    while(P != NULL) {
        P = P->prox;
        cont++;
    } return cont;
}
template<typename T> void mostrar(No<T> *P, string nome) {
    if(P == NULL) cout << "!!! Pilha " << nome << " está VAZIA !!!\n\n";
    else {
        cout << ">> Pilha " << nome << "\n\n";
        cout << "       Código |        Valor \n";
        cout << "--------------|--------------\n";
        while(P != NULL) {
            cout << setfill(' ') << std::setw(13) << P << " |";
            cout << setfill(' ') << std::setw(13) << P->dado << endl;
            P = P->prox;
        } cout << endl;
    }
}

#endif // _HPP_PILHA_DINAMICA
