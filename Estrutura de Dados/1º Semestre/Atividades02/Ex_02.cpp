/*2. Implemente um programa que manipule uma pilha. O programa deve ser desenvolvido com as seguintes regras:
• Criar um menu com as opções:
o Criar pilhar – O usuário deve informar o tamanho da pilha; caso a pilha já tenha sido criada
anteriormente, antes de criar uma pilha nova, a pilha antiga deve ser removida e a memória deve
ser desalocada.
o Inserir – O usuário deve informar um valor a ser inserido; caso a pilha esteja cheia, uma mensagem
deve ser exibida.
o Remover – Remover um elemento da pilha e mostrar o elemento removido; caso a pilha esteja
vazia, uma mensagem deve ser exibida.
o Consultar – Verificar se a pilha contém um determinado valor informado pelo usuário.
o Mostrar – Mostar a pilha.
o Sair – Sair do programa.
• Não permitir a inclusão de valores duplicados;
• Imprimir uma mensagem de erro caso a pilha não tenha sido criada e o usuário tente executar uma das
seguintes operações: inserir, remover, consultar ou mostrar.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int menu = -1;
    int *pilha = NULL;
    int *tam = new int;
    int *top = new int(-1);

    do
    {
        system("cls");
        cout << "####MENU DE OPÇÕES###" << endl;
        cout << "# 0 - Sair          #" << endl;
        cout << "# 1 - Criar pilha   #" << endl;
        cout << "# 2 - Inserir       #" << endl;
        cout << "# 3 - Remover       #" << endl;
        cout << "# 4 - Consultar     #" << endl;
        cout << "# 5 - Mostrar pilha #" << endl;
        cout << "#####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: // CRIAÇÃO DE PILHAA

                do {
                    cout << ">> Insira o tamanho da nova pilha: ";
                    cin >> *tam; // Usuário informa o tamanho, que não pode ser nulo ou negativo!!
                    if(*tam <= 0) cout << "!!! VALOR INSERIDO INVÁLIDO !!!\n";
                    else break;
                } while(true);
                if(pilha != NULL) { // Se já houver uma pilha, fazer a exclusão dela na memória para inserir a nova
                    delete[] pilha;
                    *top = -1;
                }
                pilha = new int[*tam]; // Nova pilha criada!!! B)
                cout << "Nova pilha criada!!!";
                getchar();

            break;

            case 2: // INSERIR ELEMENTO NA PILHA

                if(pilha != NULL) {
                    if(*top == *tam - 1) {
                        cout << "!!! PILHA JÁ ESTÁ CHEIA (Retire elementos para poder colocar mais) !!!";
                    } else {
                        do {
                            int elem;
                            cout << ">> Insira um elemento para a pilha: ";
                            cin >> elem;
                            int jaExiste = 0;
                            int *i = new int;
                            for(*i = 0; *i <= *top; *i += 1) {
                                if(pilha[*i] == elem) {
                                    cout << "!!! ESTE ELEMENTO JÁ FOI INSERIDO... INSIRA OUTRO !!!\n";
                                    jaExiste = 1;
                                    break;
                                }
                            } if(!jaExiste) { // Se usuário inseriu elemento que NÃO existe na pilha, laço "do.. while" é ENCERRADO!!!
                                *top += 1;
                                pilha[*top] = elem;
                                cout << "!!! Elemento inserido com MUITO SUCESSO B-) !!!";
                                getchar();
                                break;
                            }
                        } while(true);
                    }
                } else {
                    cout << "!!! VOCÊ NÃO CRIOU UMA PILHA (Faça isso na opção 1!) >:( !!!";
                }

            break;

            case 3: // REMOVER ELEMENTO
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha VAZIA... Preencha com elementos !!!";
                    } else {
                        cout << "!!! Elemento de índice " << *top << " removido: " << pilha[*top] << " !!!";
                        *top -= 1;
                    }
                } else {
                    cout << "!!! VOCÊ NÃO CRIOU UMA PILHA (Faça isso na opção 1!) >:( !!!";
                }
            break;

            case 4: // CONSULTAR
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha VAZIA... Preencha com elementos !!!";
                    } else {
                        int num;
                        cout << ">> Insira um elemento: ";
                        cin >> num;
                        int encontrado = 0;
                        int *i = new int(0);
                        for(*i = 0; *i <= *top; *i += 1) {
                            if(pilha[*i] == num) {
                                cout << "!!! ELEMENTO ENCONTRADO no índice " << *i << " !!!";
                                encontrado = 1;
                                break;
                            }
                        } if(!encontrado) {
                            cout << "!!! OI, MEU AMOR, O SISTEMA NÃO ENCONTROU O NÚMERO QUE TU INSERIU, MAS NÃO DESISTA DE SEUS SONHOS !!!";
                        } getchar();
                    }
                } else {
                    cout << "!!! VOCÊ NÃO CRIOU UMA PILHA (Faça isso na opção 1!) >:( !!!";
                }

            break;

            case 5: // MOSTRAR PILHA
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha está VAZIA... Insira elementos!!!";
                    } else {
                        cout << "!!! Pilha (com " << (*top + 1) << " elemento";
                        if(*top > 0) {
                            cout << "s): ";
                            int *i = new int(0);
                            for(*i = 0; *i <= *top; *i += 1) {
                                cout << "| " << pilha[*i] << " ";
                            } cout << "|";
                        } else {
                            cout << "): | " << pilha[0] << " |";
                        }
                    }
                } else {
                    cout << "!!! VOCÊ NÃO CRIOU UMA PILHA (Faça isso na opção 1!) >:( !!!";
                }

            break;

            default:
                cout << "Opção inválida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
