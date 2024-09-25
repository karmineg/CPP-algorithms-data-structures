/*7 - Escrever um programa que recebe um texto qualquer e um caracter qualquer, em
seguida mostre o texto conforme lido, em seguida remova todas as ocorrências do
caracter lido do texto e apresente o texto resultante.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    string text;
    char c;

    cout << "Digite um texto qualquer: ";
    getline(cin, text);

    for (int i = 0; i < text.size(); i++){
        cout << text[i];
    }

    cout << "\n\nDigite um caractere qualquer: ";
    cin >> c;

    cout << endl;
    for (int i = 0; i < text.size(); i++){
        if (text[i] != c)
            cout << text[i];
    }

}
