/*25 - Escreva um programa que implemente as seguintes funções:
- Função para ler um número inteiro qualquer, maior que 10, considere que o dígito 0 “zero” não será
informado na composição do valor lido.
- Função para ler um número verificador inteiro entre 1 e 9 (inclusive 1 e 9), valores fora deste intervalo
não serão aceitos, validar a entrada.
- Função RECURSIVA que conta quantas vezes o número verificador aparece no número inteiro lido e
apresenta o resultado. Caso o número verificador não aparecer deve apresentar 0 como resposta.
Exemplo:
Informe um número inteiro qualquer: 12345
Informe o número verificador: 3
Resposta: 1
Informe um número inteiro qualquer: 5347412
Informe o número verificador: 4
Resposta: 2
Informe um número inteiro qualquer: 4176
Informe o número verificador: 2
Resposta: 0
OBS: Todas as funções devem ser acionadas na respectiva ordem no programa principal.*/

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
        cout << "Não é permitido valor com dígito zero!";
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
        cout << "Informe um número: ";
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
        cout << "Informe outro número: ";
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
