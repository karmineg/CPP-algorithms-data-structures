#include <iostream>
#include <fstream>
using namespace std;

#include "lista-template.hpp"
struct Point {
    int x;
    int y;
};

struct Point2 {
    int x;
    int y;
};

ostream& operator << (ostream &o, Point &p) { return o << p.x << " |" << p.y; }

template<typename T> void mostrar(No<T>* L, string nome, string col) {
// ** OBSERVAÇÃO: Importante ressaltar que as funções padrão para mostrar os itens contidas aqui funcionam adequadamente para tipos de dados simples (como string, int, float, char, etc...).
// Para structs ou ponteiros, funções mais robustas criadas para casos particulares podem ser necessárias!!!
    if(L == NULL) cout << "!!! " << nome << " está VAZIA !!!\n\n";
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
        cout << "     Endereço |" << col << "\n";
        cout << "--------------|" << setfill('-') << setw(qtd + 1) << barra << "\n";
        while(L != NULL) {
            cout << setfill(' ') << setw(13) << L << " |";
            cout << setfill(' ') << setw(qtd) << L->dado << endl;
            L = L->prox;
        } cout << endl;
    }
}

main() {
    setlocale(LC_ALL, "Portuguese");

    No<int>** I = new No<int>*();
    adicionarFim(I, 10);
    adicionarFim(I, 20);
    adicionarFim(I, 30);
    mostrar(*I, "Lista de inteiros", " Teste de valor");

    No<Point>** P = new No<Point>*();
    Point p1 = { 1, 2 };
    Point p2 = { -2, 0 };
    adicionarFim(P, p1);
    adicionarFim(P, p2);
    mostrar(*P, "Lista de points", "  x");
}
