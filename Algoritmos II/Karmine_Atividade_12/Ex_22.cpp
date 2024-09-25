/*22 � Fa�a um programa para ler um arquivo texto chamado cidade.txt, o qual cont�m uma lista de cidades
cadastradas, sendo cada cidade em uma linha diferente do arquivo. O sistema deve permitir que o usu�rio
informe o nome de uma cidade, se a cidade existir no arquivo o sistema deve informar o n�mero da linha que a
cidade est� no arquivo, caso n�o exista a cidade cadastrada dever� incluir a cidade no final do arquivo. O nome
das cidades podem conter letras mai�sculas e min�sculas.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>

using namespace std;

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    ifstream ler;
    string nome;

    cout << "> Informe o nome da cidade: ";
    getline(cin, nome);
    ler.open("cidade.txt", ios::in);

    string cidades[100] = {};
    int qtd = 0;
    int achou = 0;

    while(!ler.eof()) {
        char cidade[100];
        ler.getline(cidade, 100);
        cidades[qtd] = cidade;
        qtd++;
        if(cidade == nome) {
            achou = 1;
            cout << "A cidade referida foi encontrada em 'cidade.txt'!";
            break;
        }
    } ler.close();

    if(!achou) {
        cout << "Cidade n�o encontrada!\nNome da cidade referida foi adicionada em 'cidade.txt'!\n";
        ofstream escrever;
        escrever.open("cidade.txt", ios::app);

        for(int i = 0; i < qtd; i++) {
            cout << "\n" << cidades[i];
        } cout << "\n" << nome << "\n";
        escrever << "\n" << nome;
        escrever.close();
    }
}
