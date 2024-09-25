/*22 – Faça um programa para ler um arquivo texto chamado cidade.txt, o qual contém uma lista de cidades
cadastradas, sendo cada cidade em uma linha diferente do arquivo. O sistema deve permitir que o usuário
informe o nome de uma cidade, se a cidade existir no arquivo o sistema deve informar o número da linha que a
cidade está no arquivo, caso não exista a cidade cadastrada deverá incluir a cidade no final do arquivo. O nome
das cidades podem conter letras maiúsculas e minúsculas.*/

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
        cout << "Cidade não encontrada!\nNome da cidade referida foi adicionada em 'cidade.txt'!\n";
        ofstream escrever;
        escrever.open("cidade.txt", ios::app);

        for(int i = 0; i < qtd; i++) {
            cout << "\n" << cidades[i];
        } cout << "\n" << nome << "\n";
        escrever << "\n" << nome;
        escrever.close();
    }
}
