/*25 - Escreva um programa que implemente as seguintes fun��es:
- Fun��o para ler um n�mero inteiro qualquer, maior que 10, considere que o d�gito 0 �zero� n�o ser�
informado na composi��o do valor lido.
- Fun��o para ler um n�mero verificador inteiro entre 1 e 9 (inclusive 1 e 9), valores fora deste intervalo
n�o ser�o aceitos, validar a entrada.
- Fun��o RECURSIVA que conta quantas vezes o n�mero verificador aparece no n�mero inteiro lido e
apresenta o resultado. Caso o n�mero verificador n�o aparecer deve apresentar 0 como resposta.
Exemplo:
Informe um n�mero inteiro qualquer: 12345
Informe o n�mero verificador: 3
Resposta: 1
Informe um n�mero inteiro qualquer: 5347412
Informe o n�mero verificador: 4
Resposta: 2
Informe um n�mero inteiro qualquer: 4176
Informe o n�mero verificador: 2
Resposta: 0
OBS: Todas as fun��es devem ser acionadas na respectiva ordem no programa principal.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int num1, num2, add = 0;
string num3;

void recursiva(int i);
void leitura();
void verefica();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    leitura();
    verefica();
}

void recursiva(int i) {
    setlocale(LC_ALL, "Portuguese");
    int caractere = num3[i] - '0'; //Transforma em inteiro

    if(caractere == 0) {
        cout << "N�o � permitido valor com d�gito zero!";
    }
    else {
        if(caractere == num2) {
            add++; //Adiciona mais uma unidade na soma
        }
        if(i > 0) {
            recursiva(i - 1);
        }
        else cout << "Quantidade de caractere " << num2 << ": " << add;
    }
}

void leitura() {
    setlocale(LC_ALL, "Portuguese");
    do {
        cout << "Informe um n�mero: ";
        cin >> num1;

        if(num1 > 10) {
            num3 = std::to_string(num1);
            break;
        }
        else {
            cout << "Digite um valor maior que 10!\n";
        }
    } while(true);
}

void verefica() {
    setlocale(LC_ALL, "Portuguese");
    do {
        cout << "Informe outro n�mero: ";
        cin >> num2;

        if(num2 >= 1 && num2 <= 9) {
            recursiva(num3.length() - 1);
            break;
        }
        else {
            cout << "Digite um valor maior que 1 ou menor que 9!\n";
        }
    } while(true);
}
