#include<iostream>
#include<fstream>
using namespace std;
#include"pilha-dinamica.hpp"

void lerArquivo(No<int> *P) {
    string arch;
    cout << ">> Insira o nome do arquivo: ";
    cin >> arch;
    cout << endl;

    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) {
        string linha;
        getline(leitor, linha);

        string acao;
        stringstream ss(linha);
        getline(ss, acao, ' ');

        if(acao == "MOSTRAR") {
            if(P == NULL) cout << "PILHA VAZIA";
            else mostrarSimplesP(P, "");
        }
        else if(acao == "CONSULTAR") {
            string num;
            getline(ss, num);
            int N = stoi(num);

            if(buscaP(P, N)) cout << "O valor " << N << " est� armazenado na pilha";
            else cout << "O valor " << N << " n�o est� armazenado na pilha";
        }
        else if(acao == "INSERIR") {
            string num;
            getline(ss, num);
            int N = stoi(num);

            P = adicionaP(P, N);
            cout << "O valor " << N << " foi inserido na pilha";
        }
        else if(acao == "REMOVER") {
            if(P == NULL) cout << "PILHA VAZIA";
            else {
                cout << "O elemento " << P->dado << " foi removido da pilha";
                P = removeP(P);
            }
        }
        else if(acao == "REMOVERTODOS") {
            if(P == NULL) cout << "PILHA VAZIA";
            else {
                cout << "Todos os elementos removidos";
                P = destroiP(P);
            }
        }
        else {
               cout << "Fun��o inv�lida";
        }
        cout << endl << "===============================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    No<int>* P = nullptr;

    lerArquivo(P);
    cout << endl;
    P = destroiP(P);
}
