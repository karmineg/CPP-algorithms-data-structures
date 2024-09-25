/*8 – Escreva um programa que receba um texto qualquer do teclado, em seguida
apresente:
- Total de caracteres do texto
- Total de espaços em branco
- Total de vogais
- Total de consoantes
- Total de números
- Total de caracteres especiais*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    string text;
    int esp = 0, v = 0, c = 0, num = 0, ce = 0;

    cout << "Digite um texto qualquer: ";
    getline(cin, text);

    cout << "\nTamanho do texto: " << text.size() << " caracteres";

    for (int i = 0; i < text.size(); i++){
         if (isspace(text[i]))
            esp++;

        else if (((text[i])=='a') or ((text[i])=='e') or ((text[i])=='i') or ((text[i])=='o') or ((text[i])=='u') or ((text[i])=='A') or ((text[i])=='E') or ((text[i])=='I') or ((text[i])=='O') or ((text[i])=='U'))
            v++;

        else if ((isalpha(text[i]) && ((text[i])!='a') or ((text[i])!='e') or ((text[i])!='i') or ((text[i])!='o') or ((text[i])!='u') or ((text[i])!='A') or ((text[i])!='E') or ((text[i])!='I') or ((text[i])!='O') or ((text[i])!='U')))
            c++;

        else if (isalnum(text[i]))
            num++;

        else
            ce++;

    }

    cout << "\nEspaços em branco: " << esp;
    cout << "\nVogais: "<< v;
    cout << "\nConsoantes: " << c;
    cout << "\nNúmeros: " << num;
    cout << "\nCaracteres especiais: " << esp + ce;


}
