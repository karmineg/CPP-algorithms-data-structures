#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"
//q1-entrada1.txt
void verificaInverso(ListaS<int> *L1, ListaS<int> *L2) {
    ListaS<int> Lcop = L1->copiaLista();
    ListaS<int>* Laux = nullptr;
    Lcop.mostrarSimples("Lista copiada");
    cout << endl;

    No<int>* N1 = Lcop.inicio;
    No<int>* N2 = L2->inicio;

    while(Lcop.tam > 0 && N2 != NULL) {
        int num = Lcop.removeFim();
        if(num != N2->dado) {
            cout << "> As listas NÃO SÃO inversas uma da outra... :_(";
            return;
        } N2 = N2->prox;
    }

    if(Lcop.tam == 0 && N2 == NULL) {
        cout << "> As listas SÃO INVERSAS!!! :D";
    } else {
        cout << "> As listas NÃO SÃO inversas uma da outra... :_(";
    }
}

void lerArquivo(ListaS<int> *L1, ListaS<int> *L2) {
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
        if(acao == "L1") {
            string num;
            getline(ss, num);

            int N = stoi(num);
            L1->adFim(N);
            cout << "O número " << N << " foi adicionado na lista 1";
        }

        else if(acao == "L2") {
            string num;
            getline(ss, num);

            int N = stoi(num);
            L2->adFim(N);
            cout << "O número " << N << " foi adicionado na lista 2";
        }

        else {
            cout << "> Função inválida";
        }

        cout << endl << "--------------------------------------" << endl;
    }

    getchar();
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    //ListaS --> Lista simplesmente encadeada
    ListaS<int> L1, L2;

    lerArquivo(&L1, &L2);
    L1.mostrarSimples("Lista 1");
    cout << endl;
    cout << endl;
    L2.mostrarSimples("Lista 2");

    cout << endl << "\n-------------- FUNÇÃO :( --------------" << endl;
    verificaInverso(&L1, &L2);
    cout << endl << "--------------------------------------\n" << endl;

    L1.mostrarSimples("Lista 1 depois da função");
    cout << endl;
    cout << endl;
    L2.mostrarSimples("Lista 2 depois da função");
}
