#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> //biblioteca usada para formatar a impressão da fila

template<typename T> struct NoF
{
    T dado;
    NoF<T>* prox;
};



template<typename T> NoF<T>* adicionaF(NoF<T> *F, T item) /// inicialização da fila
{
    NoF<T>* novo = new NoF<T>();
    novo->dado = item;
    if(F == NULL) {
        return novo;
    } else {
        NoF<T>* orig = F;
        while(F->prox != NULL) {
            F = F->prox;
        } F->prox = novo;
        return orig;
    }
}

template<typename T> NoF<T>* removeF(NoF<T> *F)  //retirar da fila
{
    NoF<T>* prox = F->prox;
    delete F;
    return prox;
}

template<typename T> NoF<T>* destroiF(NoF<T> *F) {
    while(F != NULL) {
        NoF<T>* act = F;
        delete act;
        F = F->prox;
    } return nullptr;
}

template<typename T> int quantosItensFila(NoF<T> *F) {
    int cont = 0;
    while(F != NULL) {
        F = F->prox;
        cont++;
    } return cont;
}

template<typename T> void mostraF(NoF<T> *F, string nome)
{
    if(F == NULL) cout << "!!! Fila " << nome << " está VAZIA !!!\n\n";
    else {
        cout << ">> Fila " << nome << "\n";
        cout << "       Índice |        Valor \n";
        cout << "--------------|--------------\n";
        while(F != NULL) {
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(13) << F->dado << endl;
            F = F->prox;
        }
    } cout << endl;
}

#endif // _HPP_FILA
