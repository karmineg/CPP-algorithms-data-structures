#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> //biblioteca usada para formatar a impressão da fila

template<typename T> struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posição do vetor onde será armazenado o próximo elemento)
    T *dados;//ponteiro para o vetor que será alocado para armazenar os dados

    Fila() {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

template<typename T> void inicializaF(Fila<T> *f, int tam) /// inicialização da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new T[tam];/// aloca memória para vetor
}

template<typename T> bool verificaInicializacaoF(Fila<T> *f) { return (f->dados != NULL); }

template<typename T> void destroiF(Fila<T> *f) {
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(verificaInicializacaoF(f)) {
        delete[] (f->dados); // Se fila JÁ foi inicializada, destruir os dados que há (se houver)
        f->dados = nullptr;
    }
}

template<typename T> bool vaziaF(Fila<T> *f) { return (f->total == 0); }

template<typename T> bool cheiaF(Fila<T> *f) { return (f->total == f->tam); } // fila cheia

template<typename T> void enfileiraF(Fila<T> *f, T valor) {/// incluir valor na fila
    if(f->total == f->tam) return;
    f->dados[f->fim] = valor;
    f->total++;
    f->fim++;
    if(f->fim>=f->tam) f->fim = 0;
}

//Dequeue
template<typename T> T desenfileiraF(Fila<T> *f)  //retirar da fila
{
    T valor = f->dados[f->inicio];
    f->total--;
    f->inicio++;
    if(f->inicio>=f->tam) f->inicio = 0;
    return valor;
}

template<typename T> void mostraF(Fila<T> *f, string nome)
{
    if(vaziaF(f)) cout << "!!! Fila " << nome << " está VAZIA !!!\n\n";
    else {
        cout << ">> Fila " << nome << "\n";
        cout << "       Índice |        Valor \n";
        cout << "--------------|--------------\n";
        int idx = f->inicio;
        for(int i = 0; i < f->total; i++) {
            cout << setfill(' ') << std::setw(13) << idx << " |";
            cout << setfill(' ') << std::setw(13) << f->dados[idx] << endl;
            idx++;
            if(idx >= f->tam) idx = 0;
        } cout << endl;
    }
}

template<typename T> void mostrarSimplesF(Fila<T> *f, string nome) {
    cout << "Fila " << nome << ": ";
    if(vaziaF(f)) cout << "VAZIA";
    else {
        int idx = f->inicio;
        for(int i = 0; i <  f->total; i++) {
            cout << f->dados[idx] << ", ";
            idx++;
            if(idx >= f->tam) idx = 0;
        }
    }
}

template<typename T> bool buscaF(Fila<T> *f, T valor) {

    for(int i = f->inicio; i < (f->inicio + f->total); i++) {
        if(valor == f->dados[(i % f->tam)]) return true;
    }
    return false;

}

template<typename T> T espiaF(Fila<T> *F) {
    if(vaziaF(F)) { // Se a fila estiver vazia
        cout << "ERRO: Fila vazia!" << endl;
        return 0; // Retorna zero
    }
    else { // Se a fila não estiver vazia
        return F->dados[F->inicio]; // Retorna o dado do início da fila
    }
}

template<typename T> void ordenaF(Fila<T> *f, bool cresc) {

    T* D = f->dados;
    while(true) {
        bool ord = true;

        int iB = f->inicio - 1,
            iA = f->inicio;

        for(int i = 0; i < f->total - 1; i++) {
            iB = (iB + 1) % (f->tam);
            iA = (iA + 1) % (f->tam);
            if((D[iB] > D[iA] && cresc) || (D[iB] < D[iA] && !cresc)) {
                T aux = D[iB];
                D[iB] = D[iA];
                D[iA] = aux;
                ord = false;
            }
        }

        if(ord) break;
    }
}

#endif // _HPP_FILA

