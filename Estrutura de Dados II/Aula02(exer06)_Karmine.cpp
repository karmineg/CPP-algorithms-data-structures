#include<iostream>
#include<fstream>
using namespace std;

typedef struct arv {
    int info;
    arv *sae;
    arv *sad;
} arvore;

int testa_vazia(arvore *t) {
    if(t == NULL) return 1;
    if(t->info == NULL) return 1;
    return 0;
}

void inserir(arvore **t, int num) {
    if(*t == NULL) {
        *t = new arvore;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->info = num;
    } else {
        if(num < (*t)->info) inserir(&(*t)->sae, num);
        else inserir(&(*t)->sad, num);

    }
}

void mostra_pre(arvore *t) {
    cout << "<";
    if(!testa_vazia(t)) {
        cout << t->info;
        mostra_pre(t->sae);
        mostra_pre(t->sad);
    }
    cout << ">";
}


void mostra_sim(arvore *t) {
    cout << "<";
    if(!testa_vazia(t)) {
        mostra_sim(t->sae);
        cout << t->info;
        mostra_sim(t->sad);
    }
    cout << ">";
}

void mostra_pos(arvore *t) {
    cout << "<";
    if(!testa_vazia(t)) {
        mostra_pos(t->sae);
        mostra_pos(t->sad);
        cout << t->info;
    }
    cout << ">";
}


main() {
    system ("color 05");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, num;
    arvore *t = NULL;

     do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES########" << endl;
        cout << "# 0 - Sair                    #" << endl;
        cout << "# 1 - Incluir                 #" << endl;
        cout << "# 2 - Mostrar pré-ordem       #" << endl;
        cout << "# 3 - Mostrar ordem simétrica #" << endl;
        cout << "# 4 - Mostrar pós-ordem       #" << endl;
        cout << "###############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "> Programa finalizado.";
            break;

            case 1:
                cout << "> Digite um número para inserir na árvore: ";
                cin >> num;
                inserir(&t, num);
                cout << "> Número " << num << " inserido com sucesso!";
                fflush(stdin);
                break;

            case 2:
                cout << "> Árvore em pré-ordem: \n";
                mostra_pre(t);
                break;

            case 3:
                cout << "> Árvore em ordem simétrica: \n";
                mostra_sim(t);
                break;

            case 4:
                cout << "> Árvore em pós-ordem: \n";
                mostra_pos(t);
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    } while(menu != 0);
}
