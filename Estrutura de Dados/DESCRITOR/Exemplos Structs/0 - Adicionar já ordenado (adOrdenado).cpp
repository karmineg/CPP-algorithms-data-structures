#include<iostream>
using namespace std;
#include "descritor-template.hpp"

struct Pessoa {
    int codigo, idade;
    string nome;
};

// !!! IMPORTANTE: Overloading para MOSTRAR pessoas !!!
ostream& operator << (ostream &o, Pessoa &P) {
    return o << P.codigo << " |" << setfill(' ') << setw(16) << P.nome << " |"
             << setfill(' ') << setw(10) << P.idade;
}

// !!! IMPORTANTE: Overloading para ordenar código em ordem CRESCENTE (OBRIGATÓRIO USAR OPERADOR "<", E APENAS ESTE)
bool operator<(const Pessoa &P1, const Pessoa &P2) {
    return (P1.codigo < P2.codigo);
}

// O QUE O CÓDIGO FAZ???
// Armazena pessoas em uma lista, de forma que o código seja ordenado de forma CRESCENTE!!!
main() {
    setlocale(LC_ALL, "Portuguese");

    ListaD<Pessoa> L; // Uso de lista dinâmica
    string col = " Código |            Nome |     Idade";

    // ADICIONANDO PESSOAS
    Pessoa P = { 5, 16, "Ricardo" };
    L.adOrdenado(P);

    P = { 3, 17, "Augusto" };
    L.adOrdenado(P);

    P = { 1, 18, "Karmine" };
    L.adOrdenado(P);

    P = { 7, 19, "Geremia" };
    L.adOrdenado(P);

    P = { 2, 20, "Müller" };
    L.adOrdenado(P);

    P = { 0, 21, "Germani" };
    L.adOrdenado(P);

    // MOSTRANDO PESSOAS COM CÓDIGO ORDENADO
    L.mostrar("Lista de pessoas (ordem CRESCENTE)", col, 2, 'T');

    cout << endl << endl << endl;
    L.mostrarDesdeFim("Lista INVERTIDA (ordem DECRESCENTE)", col, 2);

    cout << endl;
}
