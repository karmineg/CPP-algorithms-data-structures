/*6 � Fa�a um programa que l� um texto qualquer do teclado, remova os espa�os em
branco do texto e apresente o texto conforme lido, sem os espa�os, e o texto de forma
invertida, sem os espa�os.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    string text;

    cout << "Digite um texto qualquer: ";
    getline(cin, text);

    cout << text;

    cout << endl;
    for (int i = text.size() - 1; i >= 0; i--) {
        if(isspace(text[i]) == 0)
            cout << text[i];

    }

}
