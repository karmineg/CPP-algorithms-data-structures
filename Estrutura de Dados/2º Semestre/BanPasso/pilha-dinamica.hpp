#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iomanip>
#include<string>

template<typename T> struct No {
    T dado;
    No *prox;
};

template<typename T> No<T> *adicionaP(No<T> *atual, T dado) {
    No<T> *novo = new No<T>();
    novo->dado = dado;
    novo->prox = atual;
    return novo;
}

template<typename T> No<T> *removeP(No<T> *atual) {
    if(atual != NULL) {
        No<T> *Prox = atual->prox;
        delete atual;
        return Prox;
    } return nullptr;
}

template<typename T> No<T> *destroiP(No<T> *P) {
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

template<typename T, typename V> bool buscaP(No<T> *P, V dado) {
    while(P != NULL) {
        if(P->dado == dado) return true;
        P = P->prox;
    } return false;
}
template<typename T, typename V> No<T>* buscaERetornaNo(No<T> *P, V dado) {
    while(P != NULL) {
        if(P->dado == dado) return P;
        P = P->prox;
    } return nullptr;
}

template<typename T> No<T>* adicionaOrdenado(No<T>* P, T elem, bool cresc) {
    No<T> *Paux = nullptr;
    while(P != NULL) {
        T itemT = P->dado;
        if((elem < itemT) == cresc) {
            Paux = adicionaP(Paux, itemT);
            P = removeP(P);
        } else {
            P = adicionaP(P, elem);
            break;
        }
    } if(P == NULL) {
        P = adicionaP(P, elem);
    } while(Paux != NULL) {
        P = adicionaP(P, Paux->dado);
        Paux = removeP(Paux);
    } return P;
}

template<typename T> No<T>* ordenaP(No<T> *P, bool cresc) {
    No<T> *newP = nullptr;
    while(P != NULL) {
        newP = adicionaOrdenado(newP, P->dado, cresc);
        P = P->prox;
    } return newP;
}

template<typename T> void mostraP(No<T> *P, string nome) {
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

template<typename T> void mostrarSimplesP(No<T> *P, string nome)
{
    cout << "Pilha (topo -> base) " << nome << ": ";
    if(P == NULL) cout << "VAZIA";
    else {
        while(P != NULL) {
            cout << P->dado << ", ";
            P = P->prox;
        }
    }
}

#endif // _HPP_PILHA_DINAMICA
