/*4) Crie um programa que declare uma estrutura (registro) para o cadastro de clientes.
a. Deverão ser armazenados, para cada cliente: CPF, nome completo e ano
de nascimento.
b. Ao início do programa, o usuário deverá informar o número de clientes que serão
armazenados
c. O programa devera alocar dinamicamente a quantidade necessária de memória
para armazenar os registros dos clientes.
d. O programa deverá pedir ao usuário que entre com as informações clientes.
e. Ao final, mostrar os dados armazenados e liberar a memória alocada.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

struct registro {
    int cpf, ano;
    string nome;
};

main() {
    registro *R;
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, *pv = NULL, jaAdicionado = false, *qtd;

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Mostrar todas as contas e sair #" << endl;
        cout << "# 1 - Cadastrar contas               #" << endl;
        cout << "# 2 - Visualizar dados da pessoa     #" << endl;
        cout << "######################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                for (int i = 0; i < *qtd; i++) {
                    cout << "------------------------------------------" << endl;
                    cout << " > Nome: " << R[i].nome << endl;
                    cout << " > CPF: " << R[i].cpf << endl;
                    cout << " > Ano de nascimento: " << R[i].ano << endl;
                    cout << "------------------------------------------" << endl;
                }
                delete[] R;
                cout << "Programa finalizado.";
            break;

            case 1 :
                do {
                    qtd = new int();
                    cout << "> Informe a quantidade de clientes: ";
                    cin >> *qtd;
                    if(*qtd > 0) {
                        R = new registro[*qtd];
                        break;
                    } else {
                        cout << "Valor inválido!";
                    }
                } while(true);

                for (int i = 1; i <= *qtd; i++) {
                    cout << "> Informe o nome da pessoa [" << i << "] : ";
                    cin.ignore();
                    getline(cin, R[i - 1].nome);

                    cout << "> Informe o CPF da pessoa [" << i << "] : ";
                    cin >> R[i - 1].cpf;

                    cout << "> Informe o ano de nascimento da pessoa [" << i << "] : ";
                    cin >> R[i - 1].ano;

                    cout << "------------------------------------------" << endl;
                }
                if(!jaAdicionado) jaAdicionado = true;
                break;

            case 2 :
                if(jaAdicionado) {
                    string nomeInform;
                    cout << "> Informe o nome de um cliente: ";
                    getline(cin, nomeInform);

                    int achado = false;
                    for (int i = 0; i < *qtd; i++) {
                        if(R[i].nome == nomeInform) {
                            achado = true;
                            cout << "Pessoa encontrada!" << endl;
                            cout << "------------------------------------------" << endl;
                            cout << " > Nome: " << nomeInform << endl;
                            cout << " > CPF: " << R[i].cpf << endl;
                            cout << " > Ano de nascimento: " << R[i].ano << endl;
                            cout << "------------------------------------------";
                            break;
                        }
                    } if(!achado) {
                        cout << "Não existe um cliente com o nome informado!";
                    }

                } else {
                    cout << "Primeiramente registre os clientes antes de acessar esse recurso!";
                }
            break;

            default :
                cout << "Opção inválida.";
                break;
        }; getchar();
    }
    while(menu != 0);

}
