#include<iostream>
using namespace std;
#include"pilha-estatica.hpp"

main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha<string>* P = new Pilha<string>();
    inicializaP(P, 10); // Inicia pilha com vetor de 10 elementos


    // Adicionando strings na pilha
    string S = "Ricardo";
    empilhaP(P, S);

    S = "Augusto";
    empilhaP(P, S);

    S = "M�ller";
    empilhaP(P, S);

    S = "Germani";
    empilhaP(P, S);

    S = "Karmine";
    empilhaP(P, S);

    S = "Geremia";
    empilhaP(P, S);
    mostraP(P, "de nomes");


    // Conferindo �ltimo elemento da pilha
    cout << "\n> �ltimo item da lista: " << espiaP(P);



    // Removendo os �ltimos nomes da pilha
    cout << "\n\n> Removido: " << desempilhaP(P);
    cout << "\n> Removido: " << desempilhaP(P);
    cout << "\n> Removido: " << desempilhaP(P) << "\n\n";
    mostraP(P, "de nomes ATUALIZADO");



    // Buscando nomes na pilha!!!
    S = "Karmine";
    if(buscaP(P, S)) cout << "\n> Existe '" << S << "' na pilha!! :D";
    else cout << "\n> '" << S << "' N�O est� na pilha... :(";

    S = "Augusto";
    if(buscaP(P, S)) cout << "\n> Existe '" << S << "' na pilha!! :D";
    else cout << "\n> '" << S << "' N�O est� na pilha... :(";



    // DELETANDO DADOS!!
    if(vaziaP(P)) cout << "\n\n> Pilha SEM ELEMENTOS!!";
    else cout << "\n\n> Pilha N�O est� vazia!";

    destroiP(P); // Destr�i elementos da pilha

    if(vaziaP(P)) cout << "\n> Pilha FOI DESTRUIDA!!\n\n";
    else cout << "\n> Pilha N�O est� vazia!\n";
    mostraP(P, "de n�meros");
}
