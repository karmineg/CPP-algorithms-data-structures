#include<iostream>
using namespace std;
#include"fila-dinamica.hpp"

// ******************************************
// CONSTRUINDO FUN��ES ONDE FILA � MANIPULADA
//
// >> Observe que a fila � passada nos par�metros como um ponteiro DUPLO (ponteiro de ponteiro), para que o ponteiro DO MAIN seja MODIFICADO
// (Se o par�metro das fun��es fosse ponteiro SIMPLES, apenas o ponteiro DENTRO DA FUN��O seria mudado, e N�O o que est� no MAIN!!!

void adicionarValores(NoF<string>** F) { // Ponteiro duplo: **F

    string S = "Ricardo";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Augusto";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "M�ller";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Germani";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Karmine";
    *F = adicionaF(*F, S); // Use *F!!!

    S = "Geremia";
    *F = adicionaF(*F, S); // Use *F!!!
}

void removerValores(NoF<string>** F) { // Ponteiro duplo: **F

    cout << "> Removido: " << (*F)->dado; // Use *F (ENTRE PAR�NTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!

    cout << "\n> Removido: " << (*F)->dado; // Use *F (ENTRE PAR�NTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!

    cout << "\n> Removido: " << (*F)->dado << "\n\n"; // Use *F (ENTRE PAR�NTESES PARA MOSTRAR PRIMEIRO VALOR)!!!
    *F = removeF(*F); // Use *F!!!
}

void buscarValores(NoF<string>** F) { // Ponteiro duplo: **F

    string S = "Karmine";
    if(buscaF(*F, S)) cout << "\n> Existe '" << S << "' na fila!! :D"; // Use *F!!!
    else cout << "\n> '" << S << "' N�O est� na fila... :(";

    S = "Augusto";
    if(buscaF(*F, S)) cout << "\n> Existe '" << S << "' na fila!! :D"; // Use *F!!!
    else cout << "\n> '" << S << "' N�O est� na fila... :(";
}

void destruirFila(NoF<string>** F) { // Ponteiro duplo: **F

    if(*F == NULL) cout << "\n\n> Fila SEM ELEMENTOS!!"; // Use *F!!!
    else cout << "\n\n> Fila N�O est� vazia!";

    *F = destroiF(*F); // Destr�i elementos da fila (Use *F)

    if(*F == NULL) cout << "\n> Fila FOI DESTRUIDA!!\n\n"; // Use *F!!!
    else cout << "\n> Fila N�O est� vazia!\n";
}


main() {
    setlocale(LC_ALL, "Portuguese");

    NoF<string>* F = nullptr; // Inicia a fila como PONTEIRO NULO

    // Adicionando strings na fila
    adicionarValores(&F); // Passe no par�metro como &F!!!
    mostraF(F, "de nomes (do IN�CIO ao FIM)");


    // Removendo os primeiros nomes da fila
    removerValores(&F); // Passe no par�metro como &F!!!
    mostraF(F, "de nomes ATUALIZADO (do IN�CIO ao FIM)");


    // Buscando nomes na fila!!!
    buscarValores(&F); // Passe no par�metro como &F!!!


    // DELETANDO DADOS!!
    destruirFila(&F); // Passe no par�metro como &F!!!
    mostraF(F, "de n�meros");
}
