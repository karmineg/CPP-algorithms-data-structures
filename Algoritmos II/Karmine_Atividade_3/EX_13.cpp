/*13 - Escreva um programa que exiba um menu com as opções apresentadas abaixo e quanto
acionada deve executar as ações descritas:
0 – Sair - Encerra o programa
1 – Ler um valor qualquer – Aciona uma função para ler um número via entrada padrão
2 – Verifica primo - Aciona uma função que recebe o número por parâmetro e exibe a
informação se o número é primo ou não, os números 0 e 1 por definição não são primos.
3 – Soma algarismo - Aciona uma função que soma os algarismos que compõem o número, por
exemplo:
se o número informado foi 528 a função deve retornar 15 pois 5 + 2 + 8 = 15
Obs: executar as validações apresentadas:
- Escolha de opção inválida no menu exibir mensagem de alerta.
- As opções 2 e 3 só podem ser acionadas após ter sido executado a opção 1.
- A opção 3 só pode ser acionado se o número for maior que zero e menor ou igual a 999.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int &n);
void primo(int n);
void algarismo(int n);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int menu = -1, num, cont = 0;

    do
    {
        system("cls");
        cout << "#######MENU DE OPÇÕES########" << endl;
        cout << "# 0 - Sair                  #" << endl;
        cout << "# 1 - Ler um valor qualquer #" << endl;
        cout << "# 2 - Verifica primo        #" << endl;
        cout << "# 3 - Soma algarismo        #" << endl;
        cout << "#############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

            case 1 :
            system("cls");
            leitura(num);
            cont ++;

            fflush(stdin);
            getchar();
            break;

            case 2 :
            system("cls");
            if (cont == 0){
                cout << "Leia um número primeiro!";
            }

            else {
                primo(num);
            }

            fflush(stdin);
            getchar();
            break;

            case 3 :
            system("cls");
            if (cont == 0){
                cout << "Leia um número primeiro!";
            }
            else if ((num < 0) or (num > 999)){
                cout << "Digite um número maior do que 0 ou menor ou igual a 999!";
            }

            else {
                algarismo(num);
            }

            fflush(stdin);
            getchar();
            break;

            default :
                system("cls");

                cout << "Opção inválida.";
                getchar();
                break;
        };

    }
    while(menu != 0);
}

void leitura(int &n) {
    setlocale(LC_ALL, "Portuguese");

    cout << "Digite um número qualquer: ";
    cin >> n;

}

void primo(int n) {
    setlocale(LC_ALL, "Portuguese");
    int i, div = 0;

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
        div ++;
        break;
        }
    }
    if(div == 0)
        cout << "É primo!" << endl;

    else
        cout << "Não é primo!" << endl;
}

void algarismo(int n) {
    setlocale(LC_ALL, "Portuguese");
    int soma = 0;

    while (n != 0) {
        soma   += n % 10;
        n  = n / 10;
    }

    cout << "A soma é: " << soma << endl;


}
