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
// !!! IMPORTANT�SSIMO: Exemplos de fun��es booleanas para ORDENA��O !!!

// NOME EM ORDEM ALFAB�TICA
bool nomeCrescente(Pessoa P1, Pessoa P2) {
    return (P1.nome < P2.nome);
}

// C�DIGO EM ORDEM DECRESCENTE
bool codigoDecrescente(Pessoa P1, Pessoa P2) {
    return (P1.codigo > P2.codigo);
}

// O QUE O C�DIGO FAZ??
// Armazena pessoas em uma lista, cria uma c�pia da mesma e, com ela, fazemos opera��es de ORDENA��O!!
main() {
    setlocale(LC_ALL, "Portuguese");

    ListaD<Pessoa> L;
    string col = " C�digo |            Nome |     Idade";

    // ADICIONAR PESSOAS
    Pessoa P = { 1, 19, "Ricardo" };
    L.adFim(P);

    P = { 2, 19, "Karmine" };
    L.adFim(P);

    P = { 3, 50, "Manoel Gomes" };
    L.adFim(P);

    // FAZER C�PIA DE PESSOAS E MOSTRAR
    ListaD<Pessoa> Lcop;
    Lcop = L.copiaLista();

    Lcop.mostrar("C�pia de pessoas", col, 2, 'T');


    // ORDENAR C�PIA PELO NOME
    cout << endl << endl << endl;
    Lcop.ordenar(nomeCrescente);
    Lcop.mostrar("Pessoas em ORDEM ALFAB�TICA", col, 2, 'T');

    // ORDENAR C�PIA PELO C�DIGO
    cout << endl << endl << endl;
    Lcop.ordenar(codigoDecrescente);
    Lcop.mostrar("Pessoas com c�digo DECRESCENTE", col, 2, 'T');

    cout << endl;
}
