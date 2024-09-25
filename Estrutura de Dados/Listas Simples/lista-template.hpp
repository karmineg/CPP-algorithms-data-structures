#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iomanip>
#include<string>

// Estrutura din�mica gen�rica para listas (pode ser usado para pilhas e filas tamb�m)
template<typename T> struct No {
    T dado;
    No *prox;
};

template<typename T> T removeInicio(No<T>** L) { // Remove primeiro item de lista (como fila)
    No<T>* prim = *L;
    T dado = prim->dado;
    delete prim;
    *L = (*L)->prox;
    return dado;
}

template<typename T> T removeFim(No<T>** L) { // Remove �ltimo item de lista (como pilha)
    No<T>* l = *L;
    if(l->prox == NULL) {
        T dado = l->dado;
        delete l;
        *L = nullptr;
        return dado;
    } while((l->prox)->prox != NULL) {
        l = l->prox; // A mudan�a de valor do ponteiro "l" N�O modificar� o ponteiro de ponteiro "L"
    } No<T>* last = l->prox;
    T dado = last->dado;
    delete last;
    l->prox = nullptr; // Com a remo��o do �ltimo elemento, pen�ltimo elemento passa para o posto de "�ltimo"
    return dado;
}

template<typename T> T removeValor(No<T>** L, T dado) { // Remove valor na lista (que � retornado pela fun��o)
    No<T>* elem = *L;
    // Analisar o primeiro dado da lista (caso especial)
    T dadoElem = elem->dado;
    if(dadoElem == dado) {
        *L = (*L)->prox; // Substitui o endere�o da lista pelo do n� seguinte
        delete elem;
        return dadoElem;
    } // Se o primeiro dado N�O for igual ao informado, analisar os demais
    while(elem->prox != NULL) {
        No<T>* prox = elem->prox;
        T proxDado = prox->dado;
        if(proxDado == dado) { // Encontrado elemento na lista
            elem->prox = prox->prox;
            delete prox;
            return proxDado;
        } elem = elem->prox;
    } return NULL;
}

template<typename T> bool existeValor(No<T>* L, T dado) { // Fun��o que retorna os endere�os dos n�s que possuem o valor
    while(L != NULL) {
        if(L->dado == dado) return true; // Encontrado uma ocorr�ncia do elemento na lista
        L = L->prox;
    } return false;
}

template<typename T> No<No<T>*>** buscarValor(No<T>* L, T dado) { // Fun��o que retorna os endere�os dos n�s que possuem o valor
    No<No<T>*>** lista = new No<No<T>*>*();
    while(L != NULL) {
        T dadoElem = L->dado;
        if(dadoElem == dado) adicionarFim(lista, L); // Encontrado elemento na lista
        L = L->prox;
    } return lista;
}

template<typename T> T buscarPosicao(No<T>* L, int ind) { // Fun��o que retorna o valor pelo �ndice (posi��o) informado
    if(ind < 0) {
        cout << "!!! ERRO: valor informado para �ndice � inv�lido (negativo) !!!\n";
        return NULL;
    } int cont = 0;
    while(L != NULL) {
        if(cont == ind) return L->dado;
        cont++;
        L = L->prox;
    } cout << "!!! ERRO: �ndice informado � superior ao �ndice do �ltimo elemento !!!";
    return NULL;
}

template<typename T> void buscarEMostrar(No<T>* L, T dado, T (*newD)(T)) {
    if(L == NULL) cout << "!!! A lista N�O tem valores a serem analisados !!!\n\n";
    else {
        int encontrado = 0;
        T dadoNovo = newD(dado);
        while(L != NULL) {
            if(newD(L->dado) == dadoNovo) {
                if(!encontrado) {
                    encontrado = 1;
                    cout << ">> Lista dos endere�os do valor buscado\n";
                    cout << "     Endere�o |\n";
                    cout << "--------------|\n";
                } cout << setfill(' ') << std::setw(13) << L << " |\n";
            } L = L->prox;
        } if(!encontrado) cout << "!!! N�O foi encontrado na lista o dado informado !!!\n\n";
        cout << endl;
    }
}

template<typename T> No<T>* adicionarFim(No<T>** L, T dado) {
    No<T>* novo = new No<T>();
    novo->dado = dado;
    if(*L != NULL) {
        No<T>* l = *L;
        while(l->prox != NULL) {
            l = l->prox;
        } l->prox = novo;
    } else {
        *L = novo;
    } return novo;
}

// Fun��o para quest�o 8
template<typename T> No<T>* adicionarPosicao(No<T>** L, T dado, int ind) {
    if(ind < 0) {
        cout << "!!! ERRO: valor informado para �ndice � inv�lido (negativo) !!!\n";
        return NULL;
    } int cont = 0;
    No<T>* novo = new No<T>(),
    *atual = *L;
    novo->dado = dado;

    if(ind == 0) {
        novo->prox = *L;
        *L = novo;
        return novo;
    } while(atual->prox != NULL) {
        if(cont == ind - 1) {
            No<T>* antP = atual->prox;
            atual->prox = novo;
            novo->prox = antP;
            return novo;
        } cont++;
        atual = atual->prox;
    } if(cont == ind) atual->prox = novo; // Quando o �ndice inserido � o �ltimo
    else cout << "!!! ERRO: �ndice informado � superior ao �ndice do �ltimo elemento !!!"; // Caso exceder o �ndice acima, � erro
    return novo;
}

template<typename T> No<T>* adicionarInicio(No<T>** L, T dado) {
    No<T>* novo = new No<T>();
    novo->dado = dado;
    novo->prox = *L;
    *L = novo;
}

template<typename T> T lerInicio(No<T>* L) {
    if(L == NULL) return NULL;
    return L->dado;
}

template<typename T> T lerFim(No<T>* L) {
    if(L == NULL) return NULL;
    while(L->prox != NULL) L = L->prox;
    return L->dado;
}

template<typename T> void mostrar(No<T>* L, string nome, string col, int Q) {
// ** OBSERVA��O: Importante ressaltar que as fun��es padr�o para mostrar os itens contidas aqui funcionam adequadamente para tipos de dados simples (como string, int, float, char, etc...).
// Para structs ou ponteiros, fun��es mais robustas criadas para casos particulares podem ser necess�rias!!!
    if(L == NULL) cout << "!!! " << nome << " est� VAZIA !!!\n\n";
    else {
        string barra = "";
        int qtd = 0;
        int i;
        bool jaCont = false;
        for(i = 0; i < col.length(); i++) {
            char c = col[i];
            if(c == '|') {
                barra += '|';
                jaCont = true;
            } else {
                barra += '-';
                if(!jaCont) qtd++;
            }
        } barra += '-';
        if(jaCont) qtd++;

        cout << ">> " << nome << "\n";
        cout << "     Endere�o |" << col << "\n";
        cout << "--------------|" << setfill('-') << setw(qtd + 1) << barra << "\n";
        while(L != NULL) {
            cout << setfill(' ') << setw(13) << L << " |";
            cout << setfill(' ') << setw(qtd - Q) << L->dado << endl;
            L = L->prox;
        } cout << endl;
    }
}
/*template<typename T> void mostrar(No<T>* L, string nome) {
// ** OBSERVA��O: Importante ressaltar que as fun��es padr�o para mostrar os itens contidas aqui funcionam adequadamente para tipos de dados simples (como string, int, float, char, etc...).
// Para structs ou ponteiros, fun��es mais robustas criadas para casos particulares podem ser necess�rias!!!
    if(L == NULL) cout << "!!! " << nome << " est� VAZIA !!!\n\n";
    else {

        cout << ">> " << nome << "\n";
        cout << "     Endere�o |        Valor \n";
        cout << "--------------|--------------\n";
        while(L != NULL) {
            cout << setfill(' ') << std::setw(13) << L << " |";
            cout << setfill(' ') << std::setw(13) << L->dado << endl;
            L = L->prox;
        } cout << endl;
    }
}*/

template<typename T> void destruir(No<T>** L) {
    while(*L != NULL) {
        No<T> *act = *L, *prox = (*L)->prox;
        delete act;
        *L = prox;
    }
}

template<typename T> int quantosItens(No<T>* L) {
    int cont = 0;
    while(L != NULL) {
        L = L->prox;
        cont++;
    } return cont;
}

#endif
