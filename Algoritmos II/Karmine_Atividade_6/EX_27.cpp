/* 27 – Faça um programa que realize o cadastro de contas bancárias com as seguintes
informações: número da conta, nome do cliente e saldo. O banco permite o cadastramento de
10 contas e não poderá haver mais que uma conta com o mesmo número. O sistema deverá
apresentar um menu com as seguintes opções:
1 – Cadastrar contas;
2 – Visualizar dados da conta; (deve ser informado o número da conta)
3 – Depositar; (deve ser informado o número da conta e o valor a ser depositado)
4 – Sacar; (deve ser informado o número da conta e o valor a ser sacado, validar se o saque
pode ser realizado ou não)
5 – Pix; (deve ser informado o número da conta de origem, o número da conta de destino e o
valor, existindo saldo na conta de origem o programa deve realizar a transferência, atualizando
o saldo nas duas contas)
5 – Sair; */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

struct banco {
    int num;
    float saldo;
    string nome;
};

main() {
    setlocale(LC_ALL, "Portuguese");
    banco V[10];
    int menu = -1, i, x, cont = 0, n, numC, numC1, numC2, iC1, iC2;
    float deposito, saque;
    bool jaInserido, foiEncontrado = false, naoFoiEncontrado;

    do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES#########" << endl;
        cout << "# 1 - Cadastrar contas         #" << endl;
        cout << "# 2 - Visualizar dados da conta#" << endl;
        cout << "# 3 - Depositar                #" << endl;
        cout << "# 4 - Sacar                    #" << endl;
        cout << "# 5 - Pix                      #" << endl;
        cout << "# 6 - Sair                     #" << endl;
        cout << "################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch(menu)
        {
        case 1:
            for(i = 0; i < 10; i++) {
                do {
                    jaInserido = false;
                    cout << "Informe o número do cliente: ";
                    cin >> V[i].num;
                    for(x = 0; x < i; x++) {

                        if (V[i].num == V[x].num) {
                            cout << "Número do cliente já inserido!";
                            jaInserido = true;
                            break;
                        }
                    }
                }while (jaInserido);

                cout << "\nInforme o saldo do cliente: ";
                cin >> V[i].saldo;

                cout << "\nInforme o nome do cliente: ";
                cin >> V[i].nome;

                cout << "\n-------------------\n";
            }
            cont++;
            break;

        case 2:
            if (cont == 0)
                cout << "Nenhuma conta cadastrada no momento!";

            else {
                cout << "Informe o número da conta: ";
                cin >> n;

                for (i = 0; i < 10; i++) {
                    if(V[i].num == n) {
                        foiEncontrado = true;

                        cout << "\n > Nome: " << V[i].nome << "\n > Saldo: R$ " << V[i].saldo << "\n > Número: " << V[i].num << "\n";
                        break;
                    }
                }
                if(!foiEncontrado)
                    cout << "\n > Não foi encontrado uma conta com o número informado!";
                    getchar();
            }
            break;

        case 3:
            if (cont == 0)
                cout << "Nenhuma conta cadastrada no momento!";

            else {
                do {
                    naoFoiEncontrado = true;
                    cout << "Informe o número da conta: ";
                    cin >> numC;

                    for(i = 0; i < 10; i++) {
                        if(V[i].num == numC) { //se for encontrado, então informar o valor a ser depositado
                            do {
                                cout << "Informe o valor a ser depositado: ";
                                cin >> deposito;
                            } while (deposito <= 0);

                            V[i].saldo += deposito;
                            cout << "\nValor depositado!\nAgora o saldo é de R$ " << V[i].saldo;
                            naoFoiEncontrado = false;
                            break;
                        }
                    }
                    if(naoFoiEncontrado)
                        cout << "> Número não encontrado!\n";
                } while (naoFoiEncontrado);
            }
            break;

        case 4: // TIRAR DIM DIM DA CONTA
            if (cont == 0) {
                cout << "Nenhuma conta cadastrada no momento!";
            } else {
                do {
                    naoFoiEncontrado = true;
                    cout << "Informe o número da conta: ";
                    cin >> numC;

                    for(i = 0; i < 10; i++) {
                        if (V[i].num == numC) { //se for encontrado, então informar o valor a ser sacado
                            do {
                                cout << "Informe o valor a ser sacado: ";
                                cin >> saque;
                            } while(saque > V[i].saldo || saque < 0);

                            V[i].saldo -= saque;
                            cout << "\nValor sacado!\nAgora o saldo é de R$ " << V[i].saldo;
                            naoFoiEncontrado = false;
                            break;
                        }
                    }
                    if(naoFoiEncontrado)
                        cout << "> Número não encontrado!\n";
                } while(naoFoiEncontrado);
            }

            break;

        case 5:
            if (cont == 0)
                cout << "Nenhuma conta cadastrada no momento!";

            else {
                do {  // número da 1º conta
                    naoFoiEncontrado = true;
                    cout << "Informe o número da primeira conta (saque): ";
                    cin >> numC1;
                    for(i = 0; i < 10; i++) {
                        if(V[i].num == numC1) { //se for encontrado, então informar o número da segunda conta
                            iC1 = i;
                            naoFoiEncontrado = false;
                        }
                    }
                    if(naoFoiEncontrado)
                        cout << "> Número não encontrado!\n";
                } while (naoFoiEncontrado);

                do { // número da 2º conta
                    naoFoiEncontrado = true;
                    cout << "Informe o número da segunda conta (transferência): ";
                    cin >> numC2;
                    for(i = 0; i < 10; i++) {
                        if(V[i].num == numC2) { //se for encontrado, então informar o número da segunda conta
                            iC2 = i;
                            naoFoiEncontrado = false;
                        }
                    }
                    if(naoFoiEncontrado)
                        cout << "> Número não encontrado!\n";
                } while(naoFoiEncontrado);

                do { // Informar o número de saque e realizar a tranferência
                    cout << "Informe o valor a ser sacado: ";
                    cin >> saque;
                } while(saque > V[iC1].saldo || saque < 0);

                V[iC1].saldo -= saque; //Tira saldo do C1
                V[iC2].saldo += saque; //E passa pro C2

                cout << "\nPIX realizado com sucesso!\nAgora o saldo das contas é: ";
                cout << "\n- Conta nº " << numC1 << ": R$ " << V[iC1].saldo;
                cout << "\n- Conta nº " << numC2 << ": R$ " << V[iC2].saldo;
                break;
            }
            break;

        case 6:
            cout << "Programa finalizado!";
            break;

        default :
            cout << "Opção inválida!";
        }
        fflush(stdin);
        getchar();

    }
    while (menu != 6);

}
