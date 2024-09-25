#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iomanip>
#include<string>

// Estrutura dinâmica genérica tanto para PILHAS quanto para FILAS
template<typename T> struct No {
    T dado;
    No *prox;
};
// Funções de remoção de itens (específicas para cada tipo)
template<typename T> T removeP(No<T>** P) { // Remove último item de pilha (LIFO: Last-in, first-out)
    No<T>* p = *P;
    if(p->prox == NULL) {
        T dado = p->dado;
        delete p;
        *P = nullptr;
        return dado;
    } while((p->prox)->prox != NULL) {
        p = p->prox; // A mudança de valor do ponteiro "p" NÃO modificará o ponteiro de ponteiro "P"
    } No<T>* last = p->prox;
    T dado = last->dado;
    delete last;
    p->prox = nullptr; // Com a remoção do último elemento, penúltimo elemento passa para o posto de "último"
    return dado;
}
template<typename T> T removeF(No<T>** F) { // Remove primeiro item de fila (FIFO: First-in, first-out)
    No<T>* prim = *F;
    T dado = prim->dado;
    delete prim;
    *F = (*F)->prox;
    return dado;
}
// Funções COMUNS para ambos os tipos (adição, destruição, contagem e exibição de itens)
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
// ** OBSERVAÇÃO: Importante ressaltar que as funções padrão para mostrar os itens contidas aqui funcionam adequadamente para tipos de dados simples (como string, int, float, char, etc...).
// Para structs ou ponteiros, funções mais robustas criadas para casos particulares podem ser necessárias!!!
    if(N == NULL) cout << "!!! " << nome << " está VAZIA !!!\n\n";
    else {

        cout << ">> " << nome << "\n";
        cout << "     Endereço |        Valor \n";
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
