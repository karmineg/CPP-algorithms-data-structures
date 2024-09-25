#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iostream>
#include<iomanip>
#include<string>
#include<typeinfo>
using namespace std;

// FUNÇÃO GENÉRICA para exibição dos itens
template<typename T> void mostrarItem(T L, int qtd, int Q) {
    cout << setfill(' ') << setw(13) << L << " |";
    cout << setfill(' ') << setw(qtd - Q) << L->dado << endl;
}

// Lista SIMPLESMENTE encadeada
template<typename T> class No {
public:
    T dado;
    No *prox = nullptr;
};

// Lista DUPLAMENTE encadeada
template<typename T> class NoD {
public:
    T dado;
    NoD *prox = nullptr, *ant = nullptr;
};

// LISTAS
template<typename T, typename U, typename V> class Lista { // Classe pai
protected:
    U* adIni(T dado) { // Aqui criei uma função a ser utilizada para todas as listas (para inserir no início)
        U *N = new U(); // Cria um nó
        N->dado = dado; // Adiciona o dado
        N->prox = inicio; // Passa o que tava no início como o "próximo do novo início"
        inicio = N; // Adiciona o novo no início
        tam += 1;
        if(fim == NULL) fim = N;
        return N;
    }

    U* adFi(T dado) { // Aqui criei uma função a ser utilizada para todas as listas (para inserir no final)
        U *N = new U(); // Cria um nó
        N->dado = dado; // Adiciona o dado
        if(tam > 0) fim->prox = N;
        else inicio = N;
        fim = N;
        tam += 1;
        return N;
    }

public:
    U *inicio = nullptr,
    *fim = nullptr;
    int tam = 0;

    int mostrarColunas(string nome, string col, bool showEnd) {
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
        if(showEnd) {
            cout << "\n ** Endereço do início: " << inicio << endl;
            cout << " ** Endereço do fim: " << fim << endl;
            cout << " ** Quantidade de elementos: " << tam << endl << endl;
        } cout << "     Endereço |" << col << "\n";
        cout << "--------------|" << setfill('-') << setw(qtd + 1) << barra << "\n";
        return qtd;
    }

    void destruir() {
        if(tam > 0) {
            U *N = inicio;
            while(N != NULL) {
                U *atual = N;
                delete atual;
                N = N->prox;
            } inicio = nullptr;
            fim = nullptr;
            tam = 0;
        }
    }

    void mostrar(string nome, string col, int Q, char C) { // Aqui tá o método genérico (tem esse atributo 'C' com uma letra que identifica o que queremos mostrar
        if(tam == 0) {
            string message = "!!! ";
            if(C == 'T') message += nome + " está VAZIA";
            else if(C == 'I' || C == 'F') message += "NÃO HÁ " + nome;
            message += " !!!\n\n";
            cout << message;
        } else {
            int qtd = this->mostrarColunas(nome, col, (C == 'T'));
            if(C == 'T') { // Todos os itens
                U *L = inicio;
                while(L != NULL) {
                    mostrarItem(L, qtd, Q);
                    L = L->prox;
                }
            } else if(C == 'I') mostrarItem(inicio, qtd, Q); // Mostrar início
            else if(C == 'F') mostrarItem(fim, qtd, Q); // Mostrar fim
        }
    }

    void ordenar(bool(*isMinor)(T, T)) {
        int qtd = 0;

        if(this->tam != NULL) { // Tem, pelo menos, dois itens (algoritmo de ordenação)
            U* m = nullptr;
            T M, N;
            while(true) { // Dentro deste laço, verificamos a lista do início ao fim!
                qtd++;
                m = this->inicio;
                M = m->dado;
                bool cond = true;
                while(m->prox != NULL) {
                    N = (m->prox)->dado;
                    if(isMinor(N, M)) {// N < M { // Se o nome do próximo é MENOR que o atual, EFETUAR TROCA!!
                        (m->prox)->dado = M;
                        m->dado = N;
                        N = M;
                        cond = false;
                    } M = N;
                    m = m->prox;
                } if(cond) break; // Se a lista já está ordenada, encerrar laço principal
            }
        } cout << ">> Lista ordenada com sucesso... após " << qtd << " verificações(ão)!!!\n";
    }

    int qtdD(T dado) {
        U *N = inicio;
        int cont = 0;
        while(N != NULL) {
            if(dado == N->dado) cont++;
            N = N->prox;
        } return cont;
    }

    T removeFim() { // Usar APENAS quando o tamanho for, pelo menos, um
        U *pen = inicio, // Endereço do penúltimo (TEM que percorrer desde início)
          *F = fim;
        T dado = F->dado;
        if(tam == 1) { // Se tem UM elemento na lista, fim e início serão nulos
            inicio = nullptr;
            fim = nullptr;
        } else {
            while(pen->prox != fim) pen = pen->prox; // Enquanto o próximo NÃO for o fim, percorrer!
            fim = pen; // Fim passa a ser o penúltimo (se penúltimo for início, início e fim SÃO IGUAIS, logo um elemento na lista)
            pen->prox = nullptr;
        }
        tam -= 1;
        delete F;
        return dado;
    };

    T removeIni() { // Usar APENAS quando o tamanho for, pelo menos, um
        U *I = inicio;
        if(tam == 1) fim = nullptr; // Se a lista tem um elemento, início e fim serão NULOS
        else if(tam == 2) fim = I->prox; // Se a lista tem DOIS elementos, início e fim serão IGUAIS
        T dado = I->dado;
        tam -= 1;
        inicio = I->prox;
        delete I;
        return dado;
    }

    template<typename K> bool removeUmVal(K dado) {
        if(tam == 0) return false;

        U *N = inicio;
        // Verificar dado do primeiro nó
        if(N->dado == dado) {
            inicio = N->prox;
            if(inicio == NULL) fim = nullptr;
            else if(inicio->prox == NULL) fim = N->prox;
            tam -= 1;
            delete N;
            return true;
        }

        // Verificar dado dos nós seguintes (se houver)
        while(N->prox != NULL) {
            U *prox = N->prox;
            if(prox->dado == dado) {
                N->prox = prox->prox;
                tam -= 1;
                delete prox;
                return true;
            } N = N->prox;
        } return false;
    }

    template<typename K> int removeVariosVal(K dado) {//ListaD<int>* L, int num) {
        if(tam == 0) return 0;

        U *N = inicio;
        int cont = 0;

        // Início
        while(N != NULL) {
            cout << N << endl;
            if(N->dado == dado) {
                U *atual = N;
                inicio = N->prox;
                cont++;
                N = N->prox;
                delete atual;
            } else break;
        }
        if(N != NULL) {
            // Após o início
            while(N->prox != NULL) {
                U *prox = N->prox;
                if(prox->dado == dado) {
                    N->prox = prox->prox;
                    cont++;
                    delete prox;
                } else N = N->prox;
            }
        } fim = N;
        tam -= cont;
        return cont;
    }

    V unirLista(V L2) {
        V novoL;
        U *N = inicio;
        while(N != NULL) {
            novoL.adFim(N->dado);
            N = N->prox;
        }
        N = L2.inicio;
        while(N != NULL) {
            novoL.adFim(N->dado);
            N = N->prox;
        }
        return novoL;
    }

    V intersectLista(V L2) {
        V novoL;
        U *N = inicio;
        while(N != NULL) {
            T D = N->dado;
            int q = L2.qtdD(D);
            if(q > 0 && q > novoL.qtdD(D)) novoL.adFim(D);
            N = N->prox;
        }
        return novoL;
    }
};

// Lista SIMPLESMENTE encadeada
template<typename T> class ListaS : public Lista<T, No<T>, ListaS<No<T>>> {
public:
    adInicio(T dado) { this->adIni(dado); }

    adFim(T dado) { this->adFi(dado); }

    T removeInicio() { return this->removeIni(); }
};

// Lista DUPLAMENTE encadeada
template<typename T> class ListaD : public Lista<T, NoD<T>, ListaD<T>> {
public:
    adInicio(T dado) {
        NoD<T> *ini = this->inicio;
        if(ini != NULL) ini->ant = this->adIni(dado);
        else this->adIni(dado);
    }

    adFim(T dado) {
        NoD<T> *fim = this->fim;
        (this->adFi(dado))->ant = fim;
    }

    T removeInicio() {
        T dado = this->removeIni();
        if(this->inicio != NULL) (this->inicio)->ant = nullptr;
        return dado;
    }

    mostrarDesdeFim(string nome, string col, int Q) {
        if(this->tam == 0) cout << "!!! " << nome << " está VAZIA !!!\n\n"; // Vai fazer a análise pelo tamanho
        else {
            int qtd = this->mostrarColunas(nome, col, true);
            NoD<T> *L = this->fim;
            while(L != NULL) {
                mostrarItem(L, qtd, Q);
                L = L->ant;
            }
        }
    }
};

#endif
