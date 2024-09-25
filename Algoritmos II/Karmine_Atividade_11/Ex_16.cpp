/*16 - Faça um programa para ler um arquivo texto (o usuário deve fornecer o nome do arquivo) e o programa
deverá imprimir seu conteúdo na tela. E em seguida mostrar quantos caracteres existem no arquivo.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

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
            int cont = 0;
            string text = "";

            cout << "Arquivo lido com sucesso!\n\n";
            while(objeto.get(c)){
                text += c;
                if(c != ' ')
                    cont++;
            }

            cout << text << endl << endl;
            cout << "Quantidade de caracteres: " << cont;
            break;
        }
        else
            cout << "Arquivo inexistente!\n\n";
    }while(true);
}
