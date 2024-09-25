#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

bool intMenor(int N, int M) { return N < M; }
bool intMaior(int N, int M) { return N > M; }


ListaS<int>* copia(ListaS<int>* L) {
    ListaS<int>* nova = new ListaS<int>();

    No<int>* N = L->inicio;
    while(N != NULL) {
        nova->adFim(N->dado);
        N = N->prox;
    }

    return nova;
}

ListaS<int>* crescente(ListaS<int>* L) {

    ListaS<int>* cop = copia(L);
    cop->ordenar(intMenor);
    return cop;
}

ListaS<int>* decrescente(ListaS<int>* L) {

    ListaS<int>* cop = copia(L);
    cop->ordenar(intMaior);
    return cop;
}

float mediana(ListaS<int>* L) {
    ListaS<int>* cresc = crescente(L);

    No<int>* N = cresc->inicio;
    int tam = cresc->tam;
    for(int i = 0; i < tam/2 - 1 + (tam % 2); i++) N = N->prox;


    if(tam % 2 == 0) { // Se tamanho par, média aritmética dos dois valores centrais
        return (float)(N->dado + (N->prox)->dado)/(float)(2);
    } else { // Se tamanho ímpar, valor exatamente no centro
        return N->dado;
    }
}

void moda(ListaS<int>* L) {
    if(L->tam == 0) {
        cout << ": VAZIA (lista vazia)";
        return;
    }

    ListaS<int>* Lc = copia(L);
    ListaS<int>* Lint = new ListaS<int>();

    int qtd = -1;
    while(Lc->tam != 0) {
        int newNum = (Lc->inicio)->dado;
        int newQ = Lc->removeVariosVal(newNum);

        if(newQ > qtd) {
            Lint->destruir();
            Lint->adFim(newNum);
            qtd = newQ;
        }
        else if(newQ == qtd) {
            Lint->adFim(newNum);
        }
    }

    if(qtd > 1) {
        Lint->mostrarSimples("");
    } else {
        cout << ": VAZIA (todos os elementos se repetem)";
    }
}

void precis(float N) {
    cout << (int)(N) << "." << ((int)(10*N) % 10) << ((int)(100*N) % 10);
}

void mostraDif(ListaS<int>* M1, ListaS<int>* M2, string m1, string m2) {
    // Lógica: #1 realizar a intersecção das listas
    //         #2 eliminar os elementos da intersecção na primeira lista, gerando nova lista
    //         #3 ordenar lista resultante

    ListaS<int> Lint = M1->intersectLista(*M2);
    ListaS<int>* M1cop = copia(M1);

    No<int>* N = Lint.inicio;
    while(N != NULL) {
        M1cop->removeVariosVal(N->dado); // #2
        N = N->prox;
    }

    M1cop->ordenar(intMenor); // #3
    M1cop->mostrarSimples(m1 + " - " + m2);
}

void lerArquivo(ListaS<int> *L1, ListaS<int> *L2) {
    cout << "########################################\n";
    cout << "##   TRABALHO DE ESTRUTURA DE DADOS   ##\n";
    cout << "## Por Ricardo Augusto Müller Germani ##\n";
    cout << "########################################\n\n";

    string arch = "entrada.txt";
    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) { // Se leitor NÃO chegou até o final do arquivo
        string acao, lista;
        getline(leitor, acao, ' ');

        if(acao == "adiciona") {
            string num;
            getline(leitor, lista, ' ');
            getline(leitor, num);

            int N = stoi(num);
            if(lista == "L1") L1->adFim(N);
            else if(lista == "L2") L2->adFim(N);
            cout << "O número " << N << " foi adicionado na lista " << lista;
        }

        else if(acao == "mostra") {
            string ordem;
            getline(leitor, lista, ' ');
            getline(leitor, ordem);

            ListaS<int> *L = new ListaS<int>();
            if(lista == "L1") L = L1;
            else if(lista == "L2") L = L2;

            if(ordem == "C") crescente(L)->mostrarSimples(lista + " (C)");
            else if(ordem == "D") decrescente(L)->mostrarSimples(lista + " (D)");
            else if(ordem == "I") L->mostrarSimples(lista + " (I)");
        }

        else if(acao == "mostraDif") {
            string lista2;
            getline(leitor, lista, ' ');
            getline(leitor, lista2);

            if(lista == "L1") {

                if(lista2 == "L1") {
                    cout << "!!! Listas inseridas IGUAIS !!!";
                } else if(lista2 == "L2") {
                    mostraDif(L1, L2, "L1", "L2"); // Elementos de L1 que NÃO tem em L2
                }
            } else if(lista == "L2") {

                if(lista2 == "L1") {
                    mostraDif(L2, L1, "L2", "L1"); // Elementos de L2 que NÃO tem em L2
                } else if(lista2 == "L2") {
                    cout << "!!! Listas inseridas IGUAIS !!!";
                }
            }
        }

        else if(acao == "mediana") {
            getline(leitor, lista);

            ListaS<int>* L = new ListaS<int>();
            if(lista == "L1") L = L1;
            else if(lista == "L2") L = L2;
            if(L->tam == 0) cout << "Erro ao calcular a mediana de " << lista << ": lista vazia!";
            else {
                cout << "Mediana " << lista << ": ";
                precis(mediana(L));
            }
        }

        else if(acao == "moda") {
            getline(leitor, lista);

            ListaS<int>* L = new ListaS<int>();
            if(lista == "L1") L = L1;
            else if(lista == "L2") L = L2;
            cout << "Moda(s) " << lista;
            moda(L);
        }

        else if(acao == "removeTodos") {
            getline(leitor, lista);

            if(lista == "L1") L1->destruir();
            else if(lista == "L2") L2->destruir();
            cout << "Todos os valores de " << lista << " foram REMOVIDOS";
        }

        cout << endl << "----------------------------" << endl;
    }

    getchar();
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    ListaS<int> L1, L2;

    lerArquivo(&L1, &L2);
}
