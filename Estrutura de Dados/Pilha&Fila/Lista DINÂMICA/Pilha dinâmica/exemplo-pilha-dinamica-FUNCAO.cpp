#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"

// *******************************************
// CONSTRUINDO FUNÇÕES ONDE PILHA É MANIPULADA
//
// >> Observe que a pilha é passada nos parâmetros como um ponteiro DUPLO (ponteiro de ponteiro), para que o ponteiro DO MAIN seja MODIFICADO
// (Se o parâmetro das funções fosse ponteiro SIMPLES, apenas o ponteiro DENTRO DA FUNÇÃO seria mudado, e NÃO o que está no MAIN!!!

void adicionarValores(No<int>** P) { // Ponteiro duplo: **P

    *P = adicionaP(*P, 10); // Use *P!!!
    *P = adicionaP(*P, 20); // Use *P!!!
    *P = adicionaP(*P, 30); // Use *P!!!
    *P = adicionaP(*P, 40); // Use *P!!!
    *P = adicionaP(*P, 50); // Use *P!!!
    *P = adicionaP(*P, 60); // Use *P!!!
    *P = adicionaP(*P, 70); // Use *P!!!
    cout << ">> Adicionado VÁRIOS valores à pilha... Confira!!\n\n";
}

void adicionarMaisEMostrar(No<int>** P, int N1, int N2, int N3) { // Ponteiro duplo: **P

    *P = adicionaP(*P, N1); // Use *P!!!
    *P = adicionaP(*P, N2); // Use *P!!!
    *P = adicionaP(*P, N3); // Use *P!!!
    mostraP(*P, "de 10 a 100, exceto 60 e 70 (do FIM ao INÍCIO)"); // Use *P!!!
}

void removerValores(No<int>** P) { // Ponteiro duplo: **P

    cout << "> Removido " << (*P)->dado << "\n"; // Use *P (ENTRE PARÊNTESES PARA MOSTRAR ÚLTIMO VALOR)!!!
    *P = removeP(*P); // Use *P!!!

    cout << "> Removido " << (*P)->dado << "\n\n"; // Use *P (ENTRE PARÊNTESES PARA MOSTRAR ÚLTIMO VALOR)!!!
    *P = removeP(*P); // Use *P!!!
}

void buscandoEDeletando(No<int>** P, int N1, int N2, int N3) { // Ponteiro duplo: **P

    // Buscando números...
    cout << "\n> Existe 10 na lista? " << buscaP(*P, N1); // Use *P!!!
    cout << "\n> Existe 100 na lista? " << buscaP(*P, N2); // Use *P!!!
    cout << "\n> Existe 45 na lista? " << buscaP(*P, N3); // Use *P!!!

    // DELETANDO DADOS!!
    cout << endl;
    if(*P == NULL) cout << "\n> Pilha está completamente VAZIA!!"; // Use *P!!!
    else cout << "\n> Pilha tem, pelo menos, um elemento!";

    *P = destroiP(*P); // Destrói elementos da pilha (Use *P)

    if(*P == NULL) cout << "\n> Pilha FOI DESTRUIDA!!\n"; // Use *P!!!
    else cout << "\n> Pilha tem, pelo menos, um elemento!\n";
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    No<int>* P = nullptr; // Inicia a pilha como PONTEIRO NULO

    // Adicionando números na pilha (empilhando...)
    adicionarValores(&P); // Passe no parâmetro como &P!!!
    mostraP(P, "de 10 a 70 (do FIM ao INÍCIO)");

    // Retirando os primeiros números da pilha (LIFO)
    removerValores(&P); // Passe no parâmetro como &P!!!
    mostraP(P, "de 10 a 50 (do FIM ao INÍCIO)");


    // Adicionando MAIS números ("dando a volta" na pilha CIRCULAR)
    adicionarMaisEMostrar(&P, 80, 90, 100);


    // Buscando números (função CRIADA aqui) e DELETANDO DADOS!!
    buscandoEDeletando(&P, 10, 100, 45);
    mostraP(P, "de números");
}
