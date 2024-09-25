#include<iostream>
#include<fstream>
using namespace std;
#include"fila-circular.hpp"

struct Documento {
    string nome;
    int pag;
};

bool buscaPDF(Fila<Documento>* F, string nome) {
    int idx = F->inicio;
    for(int i = 0; i < F->total; i++) {
        Documento d = F->dados[idx];
        if(d.nome == nome) return true;
        idx++;
        if(idx >= F->tam) idx=0;
    } return false;
}

void mostrarDoc(Fila<Documento>* F, string tipo, int qtd) {
    if(!verificaInicializacaoF(F)) cout << "ERRO: inicializar " << tipo;
    else if(vaziaF(F)) cout << "ERRO: " << tipo << " vazia";
    else {
        cout << tipo << ": ";
        int idx = F->inicio;
        for(int i = 0; i < qtd; i++)
        {
            Documento d = F->dados[idx];
            cout << d.nome << ", ";
            idx++;
            if(idx >= F->tam) idx=0;
        }
    }
}

void lerArquivo(Fila<Documento>* N, Fila<Documento>* P) {
    cout << "#####################################################\n";
    cout << "##                    DOCUMENTOS                   ##\n";
    cout << "#####################################################\n\n";

    string arch = "entrada.txt";
    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) {
        string linha;
        getline(leitor, linha);

        string acao;
        stringstream ss(linha);
        getline(ss, acao, ' ');

        if(acao == "MOSTRAR") {
            string C;
            getline(ss, C);

            if(C == "P") {
                if(!verificaInicializacaoF(P)) cout << "ERRO: Inicializar fila P";
                else mostrarDoc(P, "Fila prioritária", P->total);
            }
            else {
                if(!verificaInicializacaoF(N)) cout << "ERRO: Inicializar fila N";
                else mostrarDoc(N, "Fila não prioritária", N->total);
            }
        }
        else if(acao == "IMPRIMIRDOC") {
            if(!verificaInicializacaoF(P)) cout << "ERRO: inicializar filas P e N";
            else {
                if(!vaziaF(P)){
                    Documento C = desenfileiraF(P);
                    cout << "O documento " << C.nome << " foi impresso.";
                }
                else if(!vaziaF(N)){
                    Documento C = desenfileiraF(N);
                    cout << "O documento " << C.nome << " foi impresso.";
                }
                else cout << "Não há documentos para imprimir";
            }
        }
        else if(acao == "INICIALIZAR") {
            string num;
            getline(ss, num);
            int n = stoi(num);

            destroiF(P);
            destroiF(N);
            inicializaF(P, n);
            inicializaF(N, n);
            cout << "A fila P e N foram inicializadas com o tamanho " << n;
        }
        else if(acao == "TOTALPAG") {
            int soma = 0;

            int idx = P->inicio;
            for(int i = 0; i < P->total; i++)
            {
                Documento d = P->dados[idx];
                soma += d.pag;
                idx++;
                if(idx >= P->tam) idx=0;
            }

            int idz = N->inicio;
            for(int i = 0; i < N->total; i++)
            {
                Documento d = N->dados[idz];
                soma += d.pag;
                idz++;
                if(idz >= N->tam) idz=0;
            }
            cout << soma << " página(s)";
        }
        else if(acao == "ENFILEIRARDOC") {
            string n;
            getline(ss, n, ' ');

            string num;
            getline(ss, num, ' ');
            int qtd = stoi(num);

            string T;
            getline(ss, T);

            if(T == "P") {
                if(!verificaInicializacaoF(P)) cout << "ERRO: inicializar fila P";
                else if(cheiaF(P)) cout << "ERRO: a Fila P está cheia";
                else {
                    Documento D = { n, qtd };
                    enfileiraF(P, D);
                    cout << "O documento " << n << "(" << qtd << " pag) foi adicionado na fila P";
                }
            }
            else {
                if(!verificaInicializacaoF(N)) cout << "ERRO: inicializar fila N";
                else if(cheiaF(N)) cout << "ERRO: a Fila N está cheia";
                else {
                    Documento D = { n, qtd };
                    enfileiraF(N, D);
                    cout << "O documento " << n << " (" << qtd << " pag) foi adicionado na fila N";
                }
            }
        }
        else if(acao == "CONSULTAR") {
            string n;
            getline(ss, n, ' ');

            string T;
            getline(ss, T);

            if(T == "P") {
                if(!verificaInicializacaoF(P)) cout << "ERRO: inicializar fila P";
                else if(vaziaF(P)) cout << "ERRO: a Fila P está vazia";
                else if(buscaPDF(P, n)) cout << "O documento " << n <<" encontra-se na fila P";
                else cout << "O documento "<< n <<" não está na fila P";
            }
            else {
                if(!verificaInicializacaoF(N)) cout << "ERRO: inicializar fila N";
                else if(vaziaF(N)) cout << "ERRO: a Fila N está vazia";
                else if(buscaPDF(N, n)) cout << "O documento " << n <<" encontra-se na fila N";
                else cout << "O documento "<< n <<" não está na fila N";
            }
        }
        else {
               cout << "Função inválida";
        }
        cout << endl << "=====================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    Fila<Documento>* P = new Fila<Documento>;
    Fila<Documento>* N = new Fila<Documento>;

    lerArquivo(N, P);
}
