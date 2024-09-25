#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include<iostream>
#include<iomanip>
#include<string>
#include<typeinfo>
using namespace std;

// FUN��O GEN�RICA para exibi��o dos itens
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
    U* adIni(T dado) { // Aqui criei uma fun��o a ser utilizada para todas as listas (para inserir no in�cio)
        U *N = new U(); // Cria um n�
        N->dado = dado; // Adiciona o dado
        N->prox = inicio; // Passa o que tava no in�cio como o "pr�ximo do novo in�cio"
        inicio = N; // Adiciona o novo no in�cio
        tam += 1;
        if(fim == NULL) fim = N;
        return N;
    }

    U* adFi(T dado) { // Aqui criei uma fun��o a ser utilizada para todas as listas (para inserir no final)
        U *N = new U(); // Cria um n�
        N->dado = dado; // Adiciona o dado
        if(tam > 0) fim->prox = N;
        else inicio = N;
        fim = N;
        tam += 1;
        return N;
    }

    U* adOrdenadoGeral(T dado, auto updAnt) {
        U* no = inicio;
        if(tam == 0 || (tam > 0 && dado < no->dado)) { // Sem itens na lista
            U* iniNo = inicio;
            U* novo = this->adIni(dado);
            updAnt(nullptr, novo, iniNo);
            return novo;
        } else {
            while(no->prox != NULL) {
                if((no->prox)->dado < dado) no = no->prox;
                else break;
            }

            U *prox = no->prox;
            U *N = new U();
            N->dado = dado;
            no->prox = N;
            if(prox != NULL) N->prox = prox;
            else fim = N;

            updAnt(no, N, prox);
            tam += 1;

            return N;
        }
    }

    template<typename K> T* removeUmValGeral(K dado, auto updAnt) {
        if(tam == 0) return nullptr;

        U *N = inicio;
        // Verificar dado do primeiro n�
        if(N->dado == dado) {
            T *no = new T(N->dado);
            inicio = N->prox;
            updAnt(inicio, nullptr);
            if(inicio == NULL) fim = nullptr;
            else if(inicio->prox == NULL) fim = N->prox;
            tam -= 1;
            //cout << "tamanho agora � " << tam << endl;
            delete N;
            return no;
        }

        // Verificar dado dos n�s seguintes (se houver)
        while(N->prox != NULL) {
            U *prox = N->prox;
            if(prox->dado == dado) {
                T *no = new T(prox->dado);
                N->prox = prox->prox;
                updAnt(prox->prox, N);
                if(N->prox == NULL) fim = N;
                tam -= 1;
                //cout << "tamanho agora � " << tam << endl;
                delete prox;
                return no;
            } N = N->prox;
        } return nullptr;
    }

    template<typename K> int removeVariosValGeral(K dado, auto updAnt) {
        if(tam == 0) return 0;

        U *N = inicio;
        int cont = 0;

        // In�cio
        while(N != NULL) {
            if(N->dado == dado) {
                U *atual = N;
                inicio = N->prox;
                updAnt(inicio, nullptr);
                cont++;
                N = N->prox;
                delete atual;
            } else break;
        }
        if(N != NULL) {
            // Ap�s o in�cio
            while(N->prox != NULL) {
                U *prox = N->prox;
                if(prox->dado == dado) {
                    N->prox = prox->prox;
                    updAnt(prox->prox, N);
                    if(N->prox == NULL) fim = N;
                    cont++;
                    delete prox;
                } else N = N->prox;
            }
        }
        tam -= cont;
        return cont;
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
            cout << "\n ** Endere�o do in�cio: " << inicio << endl;
            cout << " ** Endere�o do fim: " << fim << endl;
            cout << " ** Quantidade de elementos: " << tam << endl << endl;
        } cout << "     Endere�o |" << col << "\n";
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

    void mostrarSimples(string nome) {
        cout << nome << ": ";
        if(tam == 0) cout << "VAZIA";
        else {
            U *L = inicio;
            for(int i = 0; i < tam - 1; i++) {
                cout << L->dado << ", ";
                L = L->prox;
            } cout << L->dado;
        }
    }

    void mostrar(string nome, string col, int Q, char C) { // Aqui t� o m�todo gen�rico (tem esse atributo 'C' com uma letra que identifica o que queremos mostrar
        if(tam == 0) {
            string message = "!!! ";
            if(C == 'T') message += nome + " est� VAZIA";
            else if(C == 'I' || C == 'F') message += "N�O H� " + nome;
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
            } else if(C == 'I') mostrarItem(inicio, qtd, Q); // Mostrar in�cio
            else if(C == 'F') mostrarItem(fim, qtd, Q); // Mostrar fim*/
        }
    }

    void ordenar(bool(*isMinor)(T, T)) {
        int qtd = 0;

        if(this->tam != NULL) { // Tem, pelo menos, dois itens (algoritmo de ordena��o)
            U* m = nullptr;
            T M, N;
            while(true) { // Dentro deste la�o, verificamos a lista do in�cio ao fim!
                qtd++;
                m = this->inicio;
                M = m->dado;
                bool cond = true;
                while(m->prox != NULL) {
                    N = (m->prox)->dado;
                    if(isMinor(N, M)) {// N < M { // Se o nome do pr�ximo � MENOR que o atual, EFETUAR TROCA!!
                        (m->prox)->dado = M;
                        m->dado = N;
                        N = M;
                        cond = false;
                    } M = N;
                    m = m->prox;
                } if(cond) break; // Se a lista j� est� ordenada, encerrar la�o principal
            }
        } //cout << ">> Lista ordenada com sucesso... ap�s " << qtd << " verifica��es(�o)!!!\n";
    }

    template<typename K> int qtdD(K dado) {
        U *N = inicio;
        int cont = 0;
        while(N != NULL) {
            if(N->dado == dado) cont++;
            N = N->prox;
        } return cont;
    }

    // Verificar se j� existe (retorna booleano)
    template<typename K> bool existeVal(K dado) {
        U *N = inicio;
        while(N != NULL) {
            if(N->dado == dado) return true;
            N = N->prox;
        } return false;
    }

    // Verificar se j� existe (retorna n�)
    template<typename K> U* existeNo(K dado) {
        U *N = inicio;
        while(N != NULL) {
            if(N->dado == dado) return N;
            N = N->prox;
        } return nullptr;
    }

    T removeFim() { // Usar APENAS quando o tamanho for, pelo menos, um
        U *pen = inicio, // Endere�o do pen�ltimo (TEM que percorrer desde in�cio)
          *F = fim;
        T dado = F->dado;
        if(tam == 1) { // Se tem UM elemento na lista, fim e in�cio ser�o nulos
            inicio = nullptr;
            fim = nullptr;
        } else {
            while(pen->prox != fim) pen = pen->prox; // Enquanto o pr�ximo N�O for o fim, percorrer!
            fim = pen; // Fim passa a ser o pen�ltimo (se pen�ltimo for in�cio, in�cio e fim S�O IGUAIS, logo um elemento na lista)
            pen->prox = nullptr;
        }
        tam -= 1;
        delete F;
        return dado;
    };

    T removeIni() { // Usar APENAS quando o tamanho for, pelo menos, um
        U *I = inicio;
        if(tam == 1) fim = nullptr; // Se a lista tem um elemento, in�cio e fim ser�o NULOS
        else if(tam == 2) fim = I->prox; // Se a lista tem DOIS elementos, in�cio e fim ser�o IGUAIS
        T dado = I->dado;
        tam -= 1;
        inicio = I->prox;
        delete I;
        return dado;
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

    V copiaLista() {
        V novoL;
        U *N = inicio;
        while(N != NULL) {
            novoL.adFim(N->dado);
            N = N->prox;
        } return novoL;
    }
};

// Lista SIMPLESMENTE encadeada
template<typename T> class ListaS : public Lista<T, No<T>, ListaS<T>> {
public:
    adInicio(T dado) { this->adIni(dado); }

    adFim(T dado) { this->adFi(dado); }

    T removeInicio() { return this->removeIni(); }

    template<typename K> T* removeUmVal(K dado) {
        auto updAnt = [](No<T>* no, No<T>* novoAnt) { };
        return this->removeUmValGeral(dado, updAnt);
    }

    template<typename K> int removeVariosVal(K dado) {
        auto updAnt = [](No<T>* no, No<T>* novoAnt) { };
        return this->removeVariosValGeral(dado, updAnt);
    }

    adOrdenado(T dado) {
        auto updAnt = [](No<T>* no, No<T>* novo, No<T>* noProx) {};
        this->adOrdenadoGeral(dado, updAnt);
    }
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

    template<typename K> T* removeUmVal(K dado) {
        auto updAnt = [](NoD<T>* no, NoD<T>* novoAnt) {
            if(no != NULL) no->ant = novoAnt;
        };
        return this->removeUmValGeral(dado, updAnt);
    }

    template<typename K> int removeVariosVal(K dado) {
        auto updAnt = [](NoD<T>* no, NoD<T>* novoAnt) {
            if(no != NULL) no->ant = novoAnt;
        };
        return this->removeVariosValGeral(dado, updAnt);
    }

    adOrdenado(T dado) {
        auto updAnt = [](NoD<T>* no, NoD<T>* novo, NoD<T>* noProx) {
            if(noProx != NULL) noProx->ant = novo;
            novo->ant = no;
        };
        this->adOrdenadoGeral(dado, updAnt);
    }

    mostrarDesdeFim(string nome, string col, int Q) {
        if(this->tam == 0) cout << "!!! " << nome << " est� VAZIA !!!\n\n"; // Vai fazer a an�lise pelo tamanho
        else {
            int qtd = this->mostrarColunas(nome, col, true);
            NoD<T> *L = this->fim;
            while(L != NULL) {
                mostrarItem(L, qtd, Q);
                L = L->ant;
            }
        }
    }

    mostrarTresUlt(string nome, string col, int Q) {
        if(this->tam == 0) cout << "!!! " << nome << " est� VAZIA !!!\n\n"; // Vai fazer a an�lise pelo tamanho
        else {
            int qtd = this->mostrarColunas(nome, col, true);
            NoD<T> *L = this->fim;
            mostrarItem(L, qtd, Q); // Mostrar �ltimo
            L = L->ant;
            if(L != NULL) {
                mostrarItem(L, qtd, Q); // Mostrar pen�ltimo (se tiver)
                L = L->ant;
                if(L != NULL) mostrarItem(L, qtd, Q); // Mostrar antepen�ltimo (se tiver)
            }
        }
    }
};

#endif
