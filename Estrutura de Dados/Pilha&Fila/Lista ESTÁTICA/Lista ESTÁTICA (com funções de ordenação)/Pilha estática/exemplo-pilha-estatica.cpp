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

    S = "Müller";
    empilhaP(P, S);

    S = "Germani";
    empilhaP(P, S);

    S = "Karmine";
    empilhaP(P, S);

    S = "Geremia";
    empilhaP(P, S);
    mostraP(P, "de nomes");


    // Conferindo último elemento da pilha
    cout << "\n> Último item da lista: " << espiaP(P);



    // Removendo os últimos nomes da pilha
    cout << "\n\n> Removido: " << desempilhaP(P);
    cout << "\n> Removido: " << desempilhaP(P);
    cout << "\n> Removido: " << desempilhaP(P) << "\n\n";
    mostraP(P, "de nomes ATUALIZADO");



    // Buscando nomes na pilha!!!
    S = "Karmine";
    if(buscaP(P, S)) cout << "\n> Existe '" << S << "' na pilha!! :D";
    else cout << "\n> '" << S << "' NÃO está na pilha... :(";

    S = "Augusto";
    if(buscaP(P, S)) cout << "\n> Existe '" << S << "' na pilha!! :D";
    else cout << "\n> '" << S << "' NÃO está na pilha... :(";



    // DELETANDO DADOS!!
    if(vaziaP(P)) cout << "\n\n> Pilha SEM ELEMENTOS!!";
    else cout << "\n\n> Pilha NÃO está vazia!";

    destroiP(P); // Destrói elementos da pilha

    if(vaziaP(P)) cout << "\n> Pilha FOI DESTRUIDA!!\n\n";
    else cout << "\n> Pilha NÃO está vazia!\n";
    mostraP(P, "de números");
}
