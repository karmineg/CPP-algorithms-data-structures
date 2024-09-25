#include<iostream>
using namespace std;
#include"fila-dinamica.hpp"

// ******************************************
// CONSTRUINDO FUNÇÕES ONDE FILA É MANIPULADA
//
// >> Observe que a fila é passada nos parâmetros como um ponteiro DUPLO (ponteiro de ponteiro), para que o ponteiro DO MAIN seja MODIFICADO
// (Se o parâmetro das funções fosse ponteiro SIMPLES, apenas o ponteiro DENTRO DA FUNÇÃO seria mudado, e NÃO o que está no MAIN!!!

void adicionarValores(NoF<string>** F) { // Ponteiro duplo: **F

    string S = "Ricardo";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Augusto";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Müller";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Germani";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Karmine";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Geremia";
    *F = adicionaF(*F, S); // Use *F!!!
}

void removerValores(NoF<string>** F) { // Ponteiro duplo: **F

    cout << "> Removido: " << (*F)->dado; // Use *F (ENTRE PARÊNTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!

    cout << "\n> Removido: " << (*F)->dado; // Use *F (ENTRE PARÊNTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!

    cout << "\n> Removido: " << (*F)->dado << "\n\n"; // Use *F (ENTRE PARÊNTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!
}

void buscarValores(NoF<string>** F) { // Ponteiro duplo: **F

    string S = "Karmine";
    if(buscaF(*F, S)) cout << "\n> Existe '" << S << "' na fila!! :D"; // Use *F!!!
    else cout << "\n> '" << S << "' NÃO está na fila... :(";

    S = "Augusto";
    if(buscaF(*F, S)) cout << "\n> Existe '" << S << "' na fila!! :D"; // Use *F!!!
    else cout << "\n> '" << S << "' NÃO está na fila... :(";
}

void destruirFila(NoF<string>** F) { // Ponteiro duplo: **F

    if(*F == NULL) cout << "\n\n> Fila SEM ELEMENTOS!!"; // Use *F!!!
    else cout << "\n\n> Fila NÃO está vazia!";

    *F = destroiF(*F); // Destrói elementos da fila (Use *F)

    if(*F == NULL) cout << "\n> Fila FOI DESTRUIDA!!\n\n"; // Use *F!!!
    else cout << "\n> Fila NÃO está vazia!\n";
}


main() {
    setlocale(LC_ALL, "Portuguese");

    NoF<string>* F = nullptr; // Inicia a fila como PONTEIRO NULO

    // Adicionando strings na fila
    adicionarValores(&F); // Passe no parâmetro como &F!!!
    mostraF(F, "de nomes (do INÍCIO ao FIM)");


    // Removendo os primeiros nomes da fila
    removerValores(&F); // Passe no parâmetro como &F!!!
    mostraF(F, "de nomes ATUALIZADO (do INÍCIO ao FIM)");


    // Buscando nomes na fila!!!
    buscarValores(&F); // Passe no parâmetro como &F!!!


    // DELETANDO DADOS!!
    destruirFila(&F); // Passe no parâmetro como &F!!!
    mostraF(F, "de números");
}
