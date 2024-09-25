#include<iostream>
using namespace std;
#include"fila-dinamica.hpp"

main() {
    setlocale(LC_ALL, "Portuguese");

    NoF<string>* F = nullptr; // Inicia a fila como PONTEIRO NULO

    // Adicionando strings na fila
    string S = "Ricardo";
    F = adicionaF(F, S);

    S = "Augusto";
    F = adicionaF(F, S);

    S = "M�ller";
    F = adicionaF(F, S);

    S = "Germani";
    F = adicionaF(F, S);

    S = "Karmine";
    F = adicionaF(F, S);

    S = "Geremia";
    F = adicionaF(F, S);
    mostraF(F, "de nomes (do IN�CIO ao FIM)");


    // Removendo os primeiros nomes da fila
    cout << "> Removido: " << F->dado;
    F = removeF(F);

    cout << "\n> Removido: " << F->dado;
    F = removeF(F);

    cout << "\n> Removido: " << F->dado << "\n\n";
    F = removeF(F);
    mostraF(F, "de nomes ATUALIZADO (do IN�CIO ao FIM)");



    // Buscando nomes na fila!!!
    S = "Karmine";
    if(buscaF(F, S)) cout << "\n> Existe '" << S << "' na fila!! :D";
    else cout << "\n> '" << S << "' N�O est� na fila... :(";

    S = "Augusto";
    if(buscaF(F, S)) cout << "\n> Existe '" << S << "' na fila!! :D";
    else cout << "\n> '" << S << "' N�O est� na fila... :(";



    // DELETANDO DADOS!!
    if(F == NULL) cout << "\n\n> Fila SEM ELEMENTOS!!";
    else cout << "\n\n> Fila N�O est� vazia!";

    F = destroiF(F); // Destr�i elementos da fila

    if(F == NULL) cout << "\n> Fila FOI DESTRUIDA!!\n\n";
    else cout << "\n> Fila N�O est� vazia!\n";
    mostraF(F, "de n�meros");
}
