/*6. Faça um programa que implemente uma fila circular com no máximo 8 elementos, nesta fila é possível inserir
números reais, seguindo as regras descritas abaixo:
Regras:
− Não pode ser permitido inserir números maiores que 50;
− Todo elemento excluído da fila deve ser adicionado em um arquivo texto chamado revisa.txt, inserindo
cada elemento em uma linha;
− Deve existir no menu uma opção para mostrar os dados existentes no arquivo na tela, juntamente com a
soma dos elementos.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filacircular-template.hpp"

void adicionaF(Fila<float> *F) {
    if(cheiaF(F)) {
        cout << "!!! A fila está cheia... Remova um elemento antes !!!";
    } else {
        float num;
        do {
            cout << "> Digite um valor: ";
            cin >> num;
            if(num >= 50) cout << "!!! O valor NÃO pode ser maior ou igual a 50!!!\n";
            else break;
        } while(true);
        enfileiraF(F, num);
        cout << "Elemento adicionado na fila!!!";
    }
}

void removeF(Fila<float> *F) {
    if(vaziaF(F)) cout << "!!! A fila está vazia... Insira um elemento antes !!!";
    else {
        float num = desenfileiraF(F);
        cout << "Elemento " << num << " foi removido !!!" ;
        ofstream objeto;
        objeto.open("revisa.txt", ios::app);
        objeto << num << endl;
    }
}

void mostraSomaANDados(Fila<float> *f) {
    ifstream objeto("revisa.txt");
    float u;
    float soma = 0;
    int lido = 0;
    string res = "";
    while(objeto >> u) {
        if(!lido) lido = 1;
        else res += ", ";
        res += std::to_string(u);
        soma += u;
    } if(!lido) cout << ">> NENHUM elemento foi encontrado no arquivo... :(";
    else {
        cout << ">> Elementos removidos: " << res << ";" << endl;
        cout << ">> Soma: " << soma;
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, qtd;
    ofstream objeto("revisa.txt");
    objeto << "";

    Fila<float> F;
    inicializaF(&F, 8);

    do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Sair                            #" << endl;
        cout << "# 1 - Incluir na fila                 #" << endl;
        cout << "# 2 - Remover na fila                 #" << endl;
        cout << "# 3 - Mostrar fila                    #" << endl;
        cout << "# 4 - Mostrar dados e soma do arquivo #" << endl;
        cout << "#######################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                adicionaF(&F);
                getchar();
                break;

            case 2:
                removeF(&F);
                break;

            case 3:
                mostraF(&F, "de números");
                break;

            case 4:
                mostraSomaANDados(&F);
                break;

        }; getchar();
    }
    while(menu != 0);
}
