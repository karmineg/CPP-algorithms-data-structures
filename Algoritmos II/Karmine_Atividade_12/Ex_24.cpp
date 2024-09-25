/*24 - Crie um programa que leia um arquivo texto (o nome do arquivo deve ser informado pelo usuário), após
apresente os seguintes resultados:
- Número de caracteres existentes no arquivo
- Número de vogais existentes no arquivo
- Número de espaços em branco existentes no arquivo
- Número de caracteres especiais existentes no arquivo*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

int existe(char v[10], char c) {
    for(int i = 0; i < 10; i++) {
        if(v[i] == c) return 1;
    } return 0;
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    ifstream objeto;
    string nome = "";

    do {
        cout << "> Informe o nome do arquivo: ";
        getline(cin, nome);
        objeto.open(nome, ios::in);

        if(objeto.is_open()){
            char c;
            char v[] = "aeiouAEIOU";
            int contC = 0;
            int contV = 0;
            int contE = 0;
            int contCE = 0;
            string text = "";

            cout << "Arquivo lido com sucesso!\n\n";
            while(objeto.get(c)){
                text += c;
                if(isalnum(c)) {
                    contC++;
                    if(existe(v, c))
                        contV++;
                }
                else {
                    contCE++;
                if(c == ' ')
                    contE++;
                }
            }

            cout << text << endl << endl;
            cout << "Quantidade de caracteres: " << contC;
            cout << "\nQuantidade de espaços em branco: " << contE;
            cout << "\nQuantidade de vogais: " << contV;
            cout << "\nQuantidade de caracteres especiais: " << contCE;
            break;
        }
        else
            cout << "Arquivo inexistente!\n\n";
    }while(true);
}
