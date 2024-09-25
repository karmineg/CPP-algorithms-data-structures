#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iomanip>
#include<string>

// Estrutura din�mica gen�rica tanto para PILHAS quanto para FILAS
template<typename T> struct No {
    T dado;
    No *prox;
};
// Fun��es de remo��o de itens (espec�ficas para cada tipo)
template<typename T> T removeP(No<T>** P) { // Remove �ltimo item de pilha (LIFO: Last-in, first-out)
    No<T>* p = *P;
    if(p->prox == NULL) {
        T dado = p->dado;
        delete p;
        *P = nullptr;
        return dado;
    } while((p->prox)->prox != NULL) {
        p = p->prox; // A mudan�a de valor do ponteiro "p" N�O modificar� o ponteiro de ponteiro "P"
    } No<T>* last = p->prox;
    T dado = last->dado;
    delete last;
    p->prox = nullptr; // Com a remo��o do �ltimo elemento, pen�ltimo elemento passa para o posto de "�ltimo"
    return dado;
}
template<typename T> T removeF(No<T>** F) { // Remove primeiro item de fila (FIFO: First-in, first-out)
    No<T>* prim = *F;
    T dado = prim->dado;
    delete prim;
    *F = (*F)->prox;
    return dado;
}
// Fun��es COMUNS para ambos os tipos (adi��o, destrui��o, contagem e exibi��o de itens)
template<typename T> No<T>* adicionar(No<T>** N, T dado) {
    No<T>* novo = new No<T>();
    novo->dado = dado;
    if(*N != NULL) {
        No<T>* n = *N;
        while(n->prox != NULL) {
            n = n->prox;
        } n->prox = novo;
    } else {
        *N = novo;
    } return novo;
}
template<typename T> void mostrar(No<T>* N, string nome) {
// ** OBSERVA��O: Importante ressaltar que as fun��es padr�o para mostrar os itens contidas aqui funcionam adequadamente para tipos de dados simples (como string, int, float, char, etc...).
// Para structs ou ponteiros, fun��es mais robustas criadas para casos particulares podem ser necess�rias!!!
    if(N == NULL) cout << "!!! " << nome << " est� VAZIA !!!\n\n";
    else {

        cout << ">> " << nome << "\n";
        cout << "     Endere�o |        Valor \n";
        cout << "--------------|--------------\n";
        while(N != NULL) {
            cout << setfill(' ') << std::setw(13) << N << " |";
            cout << setfill(' ') << std::setw(13) << N->dado << endl;
            N = N->prox;
        } cout << endl;
    }
}
template<typename T> void destruir(No<T>** N) {
    while(*N != NULL) {
        No<T> *act = *N, *prox = (*N)->prox;
        delete act;
        *N = prox;
    }
}
template<typename T> int quantosItens(No<T>* N) {
    int cont = 0;
    while(N != NULL) {
        N = N->prox;
        cont++;
    } return cont;
}

#endif // _HPP_PILHA_DINAMICA
