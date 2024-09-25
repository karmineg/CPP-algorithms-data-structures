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

void mostra_pre(arvore *t, int profundidade = 0) {
    if(!testa_vazia(t)) {
        cout << string(profundidade, '.') << t->info << endl;
        mostra_pre(t->sae, profundidade + 1);
        mostra_pre(t->sad, profundidade + 1);
    }
}

void mostra_sim(arvore *t, int profundidade = 0) {
    if(!testa_vazia(t)) {
        mostra_sim(t->sae, profundidade + 1);
        cout << string(profundidade, '.') << t->info << endl;
        mostra_sim(t->sad, profundidade + 1);
    }
}

void mostra_pos(arvore *t, int profundidade = 0) {
    if(!testa_vazia(t)) {
        mostra_pos(t->sae, profundidade + 1);
        mostra_pos(t->sad, profundidade + 1);
        cout << string(profundidade, '.') << t->info << endl;
    }
}

arvore* minValorNo(arvore* no) {
    arvore* c = no;
    while (c && c->sae != NULL)
        c = c->sae;
    return c;
}

arvore* remover(arvore* t, int num, bool &encontrado) {
    encontrado = true;
    if (t == NULL) {
        encontrado = false;
        return NULL;
    }
    if (num < t->info) t->sae = remover(t->sae, num, encontrado);
    else if (num > t->info) t->sad = remover(t->sad, num, encontrado);
    else {
        if (t->sae == NULL) {
            arvore* temp = t->sad;
            delete t;
            return temp;
        }
        else if (t->sad == NULL) {
            arvore* temp = t->sae;
            delete t;
            return temp;
        }

        arvore* temp = minValorNo(t->sad);
        t->info = temp->info;
        t->sad = remover(t->sad, temp->info, encontrado);
    }
    return t;
}

int nivel(arvore *t) {
    if(t == NULL) return -1;
    else {
        int nivelEsq = nivel(t->sae);
        int nivelDir = nivel(t->sad);
        if(nivelEsq > nivelDir) return nivelEsq + 1;
        else return nivelDir + 1;
    }
}

int totalNos(arvore *t) {
    if(t == NULL) return 0;
    else return totalNos(t->sae) + totalNos(t->sad) + 1;
}

int qtdfolhas(arvore *t) {
    if(t == NULL) return 0;
    if(t->sae == NULL && t->sad == NULL) return 1;
    else return qtdfolhas(t->sae) + qtdfolhas(t->sad);
}

int qtd2filhos(arvore *t) {
    if(t == NULL) return 0;
    if(t->sae != NULL && t->sad != NULL) return 1 + qtd2filhos(t->sae) + qtd2filhos(t->sad);
    else return qtd2filhos(t->sae) + qtd2filhos(t->sad);
}

void estatisticasArv(arvore *t) {
    cout << "> Altura da árvore: " << nivel(t) + 1 << endl;
    cout << "> Altura da sub-árvore esquerda: " << nivel(t->sae) + 1 << endl;
    cout << "> Altura da sub-árvore direita: " << nivel(t->sad) + 1 << endl;
    cout << "> Total de níveis da árvore: " << nivel(t) << endl;
    cout << "> Total de nós: " << totalNos(t) << endl;
    cout << "> Quantidade de nós folha: " << qtdfolhas(t) << endl;
    cout << "> Nós com dois filhos: " << qtd2filhos(t) << endl;
    if(t != NULL) cout << "> Raiz da árvore: " << t->info << endl;
    else cout << "> A árvore está vazia." << endl;
}

int qtdDescendentes(arvore *t) {
    if(t == NULL) return 0;
    return 1 + qtdDescendentes(t->sae) + qtdDescendentes(t->sad);
}

void mostraDesc(arvore *t) {
    if(t != NULL) {
        cout << t->info << ", ";
        mostraDesc(t->sae);
        mostraDesc(t->sad);
    }
}

arvore* retornaPai(arvore *t, int num) {

    arvore *pai = NULL;
    while(t != NULL) {
        if(num != t->info) {
            pai = t;
            if(num < t->info) t = t->sae;
            else t = t->sad;
        } else return pai;
    }
}

arvore* mostraAncesERetornaPai(arvore *t, int num) {

    arvore *pai = NULL;
    while(t != NULL) {
        if(num != t->info) {
            pai = t;
            cout << t->info << ", ";
            if(num < t->info) t = t->sae;
            else t = t->sad;
        } else return pai;
    }
}

void estatisticasNo(arvore *t, int num, bool &encontrado, arvore *raiz, int niv = 0) {
    if(t == NULL) {
        encontrado = false;
        return;
    }

    if(t->info == num) {
        encontrado = true;
        cout << "> Nível do nó: " << niv << endl;

        int qtdFilhos = (t->sae != NULL) + (t->sad != NULL);
        cout << "> Grau do nó: " << qtdFilhos << endl;

        cout << "> Filho(s) do nó: ";
        if(t->sae) cout << t->sae->info << ", ";
        if(t->sad) cout << t->sad->info << ", ";
        cout << endl;

        cout << "> Quantidade de descendente(s) do nó: " << qtdDescendentes(t) - 1 << endl;

        cout << "> Descendente(s) do nó: ";
        mostraDesc(t->sae);
        mostraDesc(t->sad);
        cout << endl;

        cout << "> Quantidade de ancestrais do nó: " << niv << endl;

        cout << "> Ancestrais do nó: ";
        arvore *pai = mostraAncesERetornaPai(raiz, num);
        cout << endl;

        if(pai != NULL) cout << "> Pai do nó: " << pai->info << endl;
        else cout << "> O nó é a raiz e não tem pai!" << endl;

        arvore *avo = retornaPai(raiz, retornaPai(raiz, num)->info);
        if(avo != NULL) cout << "> Avô do nó: " << avo->info << endl;
        else cout << "> O nó não tem avô!" << endl;

    }
    else {
        if(num < t->info) estatisticasNo(t->sae, num, encontrado, raiz, niv + 1);
        else estatisticasNo(t->sad, num, encontrado, raiz, niv + 1);
    }
}

void excluirArvore(arvore **t) {
    if(*t != NULL) {
        excluirArvore(&(*t)->sae);
        excluirArvore(&(*t)->sad);
        delete *t;
        *t = NULL;
    }
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
        cout << "# 5 - Remover nó              #" << endl;
        cout << "# 6 - Estatísticas da árvore  #" << endl;
        cout << "# 7 - Estatísticas do nó      #" << endl;
        cout << "# 8 - Excluir árvore          #" << endl;
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

            case 5:
                cout << "> Digite um número para remover da árvore: ";
                cin >> num;
                bool encontrado;
                t = remover(t, num, encontrado);
                if (encontrado) cout << "> Número " << num << " removido com sucesso!";
                else cout << "> Valor " << num << " não encontrado na árvore!";
                fflush(stdin);
                break;

            case 6:
                cout << "> Estatísticas da árvore: \n";
                estatisticasArv(t);
                break;

            case 7:
                cout << "> Digite o nó que deseja ver as estatísticas: ";
                cin >> num;
                cout << endl;
                bool achado;
                estatisticasNo(t, num, achado, t);
                if(!achado) cout << "> O nó " << num << " não existe na árvore!" << endl;
                fflush(stdin);
                break;

            case 8:
                excluirArvore(&t);
                cout << "> Árvore excluída com sucesso!" << endl;
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    } while(menu != 0);
}
