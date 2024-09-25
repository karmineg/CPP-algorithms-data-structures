/*24 – Escreva um programa que receba um texto qualquer e utilizando uma função recursiva, apresente o
texto de forma invertida.
Exemplo:
Texto digitado: Minha Prova
Resultado exibido: avorP ahniM
OBS: Validar o texto para não aceitar números e caracteres especiais, exibindo mensagem de “Entrada
inválida” e solicitando a leitura de um novo texto.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

string A = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

string inverte(string text, int i);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    do {
        string txt("");

        cout << "Insira um texto: ";
        getline(cin, txt);

        string txtAoC = inverte(txt, txt.length() - 1);
        if (txtAoC.length() != txt.length()) {
            cout << "Entrada inválida\n";
        }
        else {
            cout << txtAoC;
            break;
        }
    } while(true);
}

string inverte(string text, int i) {
    char caractere = text[i];
    int indice = A.find(caractere);

    if (indice != std::string::npos) {
        return caractere + inverte(text, i - 1);
    }
    return "";
}
