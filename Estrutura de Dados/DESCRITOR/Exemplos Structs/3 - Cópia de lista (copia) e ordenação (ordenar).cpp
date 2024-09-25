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

// *********************************************************************
// !!! IMPORTANTÍSSIMO: Exemplos de funções booleanas para ORDENAÇÃO !!!

// NOME EM ORDEM ALFABÉTICA
bool nomeCrescente(Pessoa P1, Pessoa P2) {
    return (P1.nome < P2.nome);
}

// CÓDIGO EM ORDEM DECRESCENTE
bool codigoDecrescente(Pessoa P1, Pessoa P2) {
    return (P1.codigo > P2.codigo);
}

// O QUE O CÓDIGO FAZ??
// Armazena pessoas em uma lista, cria uma cópia da mesma e, com ela, fazemos operações de ORDENAÇÃO!!
main() {
    setlocale(LC_ALL, "Portuguese");

    ListaD<Pessoa> L;
    string col = " Código |            Nome |     Idade";

    // ADICIONAR PESSOAS
    Pessoa P = { 1, 19, "Ricardo" };
    L.adFim(P);

    P = { 2, 19, "Karmine" };
    L.adFim(P);

    P = { 3, 50, "Manoel Gomes" };
    L.adFim(P);

    // FAZER CÓPIA DE PESSOAS E MOSTRAR
    ListaD<Pessoa> Lcop;
    Lcop = L.copiaLista();

    Lcop.mostrar("Cópia de pessoas", col, 2, 'T');


    // ORDENAR CÓPIA PELO NOME
    cout << endl << endl << endl;
    Lcop.ordenar(nomeCrescente);
    Lcop.mostrar("Pessoas em ORDEM ALFABÉTICA", col, 2, 'T');

    // ORDENAR CÓPIA PELO CÓDIGO
    cout << endl << endl << endl;
    Lcop.ordenar(codigoDecrescente);
    Lcop.mostrar("Pessoas com código DECRESCENTE", col, 2, 'T');

    cout << endl;
}
