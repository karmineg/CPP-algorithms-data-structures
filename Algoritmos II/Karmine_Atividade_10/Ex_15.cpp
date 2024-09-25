/*15 – Escreva um programa que leia um valor inteiro N, sendo 3 ≤ N ≤ 9. Em seguida, imprima um
padrão triangular de números, conforme os exemplos abaixo.
Observação: Caso o valor de N seja inválido (fora do intervalo), o programa deve mostrar uma
mensagem de erro e um novo valor deve ser lido, até que um valor válido seja digitado pelo usuário.
Utilize ponteiro e alocação dinâmica de memória e aritmética de ponteiro para resolver este exercício.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main() {
    setlocale(LC_ALL, "Portuguese");
    int *N = new int;

    do {
        cout << "> Informe um valor: ";
        cin >> *N;

        if(*N < 3)
            cout <<"> Valor inválido! (menor que 3)\n";
        else if(*N > 9)
            cout << "> Valor inválido! (maior que 9)\n";
        else
            break;
    } while(true);

    char *M = new char[*N + 1];
    M = " 123456789";

    cout << endl;
    for(int i = 0; i < *N; i++) {
        for(int x = 0; x < *N; x++) {
            int *add = new int(i + x - *N + 2);
            *add = (*add > 0)*(*add);
            cout << *(M + *add) << " ";
        } cout << endl;
    }
}
