/*2 - Crie um programa para controlar o estoque de uma empresa, sabendo que ser�o no
m�ximo 50 produtos (mas o sistema deve funcionar para qualquer quantidade inferior
ao m�ximo permitido), o sistema dever� manipular o c�digo do produto, nome, unidade
(kg, dz, m, un, cx, tn, etc...), valor de venda e quantidade em estoque. O sistema
dever� utilizar ponteiro para manipular a struct e apresentar um menu com as seguintes
op��es:
0 � Sair
1 � Cadastrar produto
2 � Listar produtos cadastrados
3 � Consultar produto pelo c�digo
4 � Vender produto (fornece o c�digo e a quantidade de venda, o sistema verifica se
existe estoque suficiente e executa a venda atualizando a quantidade em estoque).*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

struct produto {
    int codigo, quantidade;
    string nome, unidade;
    float venda;
};

void mostrarProduto(produto *C);
bool encontrarP(int *codigo, int *cont, int *ind, produto *C);

main() {
    setlocale(LC_ALL, "Portuguese");
    produto C[50];
    int menu = -1, cont = 0, qtd = 2, codigo, ind;
    do
    {
        system("cls");
        cout << "########### MENU DE OP��ES ##########" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Cadastrar produto             #" << endl;
        cout << "# 2 - Listar produtos cadastrados   #" << endl;
        cout << "# 3 - Consultar produto pelo c�digo #" << endl;
        cout << "# 4 - Vender produto                #" << endl;
        cout << "#####################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch(menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            if(cont < 50) {
                bool jaInserido;
                do {
                    jaInserido = false;
                    cout << "\n> Informe o c�digo do produto: ";
                    cin >> C[cont].codigo;

                    for(int x = 0; x < cont; x++) {
                        if(C[cont].codigo == C[x].codigo) {
                            cout << "> C�digo do produto j� inserido!";
                            jaInserido = true;
                            break;
                        }
                    }
                } while(jaInserido);

                cout << "\n> Informe o nome do produto: ";
                cin.ignore();
                getline(cin, C[cont].nome);
                cout << "\n> Informe a unidade do produto: ";
                cin >> C[cont].unidade;
                cout << "\n> Informe valor da venda do produto: ";
                cin >> C[cont].venda;
                cout << "\n> Informe a quantidade do produto: ";
                cin >> C[cont].quantidade;
                cont++;
            }
            else {
                cout << "Limite m�ximo de produtos alcan�ado!";
            }
            break;

        case 2:
            if (cont == 0) {
                cout << "Nenhum produto cadastrado!";
            }
            else {
                cout << "> Produtos <\n\n";
                for(int i = 0; i < cont; i++) {
                    mostrarProduto(&C[i]);

                    if(i < cont - 1)
                        cout << "-----------------------------\n";
                }
            }
            break;

        case 3:
            if (cont == 0) {
                cout << "Nenhum produto cadastrado!";
            }
            else {
                if(encontrarP(&codigo, &cont, &ind, C)) {
                    mostrarProduto(&C[ind]);
                }
            } break;

        case 4:
            if (cont == 0) {
                cout << "Nenhuma conta cadastrada!";
            }
            else {
                if(encontrarP(&codigo, &cont, &ind, C)) {
                    do {
                        int quantidade;
                        cout << "> Informe a quantidade para vender: ";
                        cin >> quantidade;

                        if(quantidade > C[ind].quantidade) {
                            cout << "\n> Valor excedeu o estoque!\n";
                        }
                        else {
                            C[ind].quantidade -= quantidade;
                            cout << "\n> Venda efetuada com sucesso! A quantidade atual � " << C[ind].quantidade << "!";
                            break;
                        }
                    } while(true);
                }
            }
            break;

        default :
            cout << "Op��o inv�lida!";
        }
        fflush(stdin);
        getchar();

    }
    while (menu != 6);
}

void mostrarProduto(produto *C) {
    cout << "> C�digo n� " << (*C).codigo << endl;
    cout << "> Nome: " << (*C).nome << endl;
    cout << "> Unidade: " << (*C).unidade << endl;
    cout << "> Valor da venda: " << (*C).venda << endl;
    cout << "> Quantidade: " << (*C).quantidade << endl;
}

bool encontrarP(int *codigo, int *cont, int *ind, produto *C) {
    cout << "> Informe um n�mero p/ c�digo: ";
    cin >> *codigo;
    bool encontrado = false;

    for(int i = 0; i < (*cont); i++) {
        if(C[i].codigo == (*codigo)) {
            *ind = i;
            encontrado = true;
            break;
        }
    }
    if(!encontrado) {
        cout << "> Produto n�o encontrado!";
    }
    return encontrado;
}
