/*12 – Crie um programa que receba um texto qualquer do teclado e implemente uma função que
utilizando aritmética de ponteiro realize as seguintes ações:
- Transformar todos os caracteres do texto para maiúsculo
- Remover os caracteres especiais existentes no texto
- Remover os espaços em branco.
- Mostrar o texto resultante.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void mostrarTexto(string txt, char *C);

main() {
    setlocale(LC_ALL, "Portuguese");
    string txt("");
    cout << "Digite um texto qualquer: ";
    getline(cin, txt);
    char *C = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    mostrarTexto(txt, C);
}

void mostrarTexto(string txt, char *C) {
    int *S = new int(txt.length());
    const char *ptxt = txt.data();
    cout << "\nTexto resultante: ";

    for(int j = 0; j < *S; j++) {
        int *notFound = new int(1);

        for(int k = 0; k < 36; k++) {
            if(*C == *ptxt || *C == toupper(*ptxt)) {
                cout << *C;
                C -= k;
                *notFound = 0;
                break;
            } C++;
        } if(*notFound) {
            C -= 36;
        } ptxt++;
    }
}
