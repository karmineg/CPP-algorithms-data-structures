#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
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

void mostra_matriz(arvore *t, int *cont) {

        cout << setfill(' ') << setw(7) << *cont << " |";
        cout << setfill(' ') << setw(8) << t->info << " |";
        cout << setfill(' ') << setw(15) << (t->sae == NULL ? -1 : (t->sae)->info) << " |";
        cout << setfill(' ') << setw(14) << (t->sad == NULL ? -1 : (t->sad)->info) << endl;
        *cont += 1;

        if(t->sae != NULL) mostra_matriz(t->sae, cont);
        if(t->sad != NULL) mostra_matriz(t->sad, cont);
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
    while (c && c->sae != NULL) c = c->sae;
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

int qtdfolhas(arvore *t) {
    if(t == NULL) return 0;
    if(t->sae == NULL && t->sad == NULL) return 1;
    else return qtdfolhas(t->sae) + qtdfolhas(t->sad);
}

int totalNos(arvore *t) {
    if(t == NULL) return 0;
    else return totalNos(t->sae) + totalNos(t->sad) + 1;
}

bool ehCompleta(arvore *t, int nivel, int* nivelFolhas) {
    if (t == NULL) return true;

    if (t->sae == NULL && t->sad == NULL) {
        if (*nivelFolhas == -1) {
            *nivelFolhas = nivel;
            return true;
        } return (nivel == *nivelFolhas);
    } return ehCompleta(t->sae, nivel + 1, nivelFolhas) && ehCompleta(t->sad, nivel + 1, nivelFolhas);
}

int qtd2filhos(arvore *t) {
    if(t == NULL) return 0;
    if(t->sae != NULL && t->sad != NULL) return 1 + qtd2filhos(t->sae) + qtd2filhos(t->sad);
    else return qtd2filhos(t->sae) + qtd2filhos(t->sad);
}

bool ehBalanceada(arvore *t) {
    if (t == NULL) return true;

    int alturaEsq = nivel(t->sae);
    int alturaDir = nivel(t->sad);

    if (abs(alturaEsq - alturaDir) <= 1) return ehBalanceada(t->sae) && ehBalanceada(t->sad);
    else return false;
}

void estatisticasArv(arvore *t) {
    int nivelFolhas = -1;
    bool completa = ehCompleta(t, 0, &nivelFolhas);
    bool balanceada = ehBalanceada(t);

    cout << "> Altura da árvore: " << nivel(t) + 1 << endl;
    cout << "> Altura da sub-árvore esquerda: " << nivel(t->sae) + 1 << endl;
    cout << "> Altura da sub-árvore direita: " << nivel(t->sad) + 1 << endl;
    cout << "> Maior nível da árvore: " << nivel(t) << endl;
    cout << "> É uma árvore completa: ";
    if(completa == true) cout << "Sim" << endl;
    else cout << "Não" << endl;

    cout << "> É uma árvore balanceada: ";
    if (balanceada) cout << "Sim" << endl;
    else cout << "Não" << endl;

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

arvore* retornaTio(arvore *raiz, int num) {
    arvore *pai = retornaPai(raiz, num);
    if (pai == NULL) return NULL;

    arvore *avo = retornaPai(raiz, pai->info);

    if (avo == NULL) return NULL;
    if (avo->sae == pai) return avo->sad;
    else return avo->sae;
}

arvore* retornaIrmao(arvore *raiz, int num) {
    arvore *pai = retornaPai(raiz, num);
    if (pai == NULL) return NULL;

    if (pai->sae->info == num) return pai->sad;
    else return pai->sae;
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

        arvore *tio = retornaTio(raiz, num);
        if (tio != NULL) {
            cout << "> Tio do nó: " << tio->info << endl;
            cout << "> Primos do nó: ";
            if(tio->sae) cout << tio->sae->info << ", ";
            if(tio->sad) cout << tio->sad->info << ", ";
            cout << endl;
        }
        else cout << "> Nó não possui tio e primos!" << endl;

        arvore *irmao = retornaIrmao(raiz, num);
        if (irmao != NULL) {
            cout << "> Irmão do nó: " << irmao->info << endl;
            cout << "> Sobrinhos do nó: ";
            if(irmao->sae) cout << irmao->sae->info << ", ";
            if(irmao->sad) cout << irmao->sad->info << ", ";
            cout << endl;
        }
        else cout << "> Nó não possui irmão e sobrinhos!" << endl;

    } else {
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

void mostraValoresNoNivel(arvore *t, int nivelDesejado, int nivelAtual, bool &encontrado) {
    if (t == NULL) return;
    if (nivelDesejado == nivelAtual) {
        cout << t->info << ", ";
        encontrado = true;
    } else {
        mostraValoresNoNivel(t->sae, nivelDesejado, nivelAtual + 1, encontrado);
        mostraValoresNoNivel(t->sad, nivelDesejado, nivelAtual + 1, encontrado);
    }
}

void lerArquivo(arvore **t) {
    string arch = "entrada.txt";
    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) {
        string linha;
        getline(leitor, linha);

        string acao;
        stringstream ss(linha);
        getline(ss, acao, ' ');

        if(acao == "inserir") {
            string n;
            getline(ss, n);
            int num = stoi(n);

            inserir(t, num);
            cout << "> INSERIR: Número " << num << " inserido com sucesso!";
        }

        else if(acao == "remover") {
            string n;
            getline(ss, n);
            int num = stoi(n);

            bool encontrado;
            *t = remover(*t, num, encontrado);
            if (encontrado) cout << "> REMOVER: Número " << num << " removido com sucesso!";
            else cout << "> REMOVER: Valor " << num << " não encontrado na árvore!";

        }
        else if(acao == "mostrar") {
            string n;
            getline(ss, n);

            if(!testa_vazia(*t)) {
                if(n == "1") mostra_pre(*t);
                else if(n == "2") mostra_sim(*t);
                else if (n == "3") mostra_pos(*t);
                else cout << "> Valor para mostrar inválida";
            }
            else cout << "> Árvore vazia!";

        }
        else cout << "Função inválida";

        cout << endl << "---------------------------------------------" << endl << endl;
    }
}

main() {
    system ("color 05");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, num;
    int cont;
    arvore *t = NULL;

     do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                         #" << endl;
        cout << "# 1 - Ler arquivo texto            #" << endl;
        cout << "# 2 - Incluir                      #" << endl;
        cout << "# 3 - Remover nó                   #" << endl;
        cout << "# 4 - Mostrar pré-ordem            #" << endl;
        cout << "# 5 - Mostrar ordem simétrica      #" << endl;
        cout << "# 6 - Mostrar pós-ordem            #" << endl;
        cout << "# 7 - Mostrar usando matriz        #" << endl;
        cout << "# 8 - Estatísticas da árvore       #" << endl;
        cout << "# 9 - Estatísticas do nó           #" << endl;
        cout << "# 10 - Mostrar valores de um nível #" << endl;
        cout << "# 11 - Excluir árvore              #" << endl;
        cout << "####################################" << endl;
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
                lerArquivo(&t);

                cout << "\n> Leitura do arquivo texto completa!\n";
                fflush(stdin);
                break;

             case 2:
                cout << "> Digite um número para inserir na árvore: ";
                cin >> num;
                inserir(&t, num);
                cout << "> Número " << num << " inserido com sucesso!";
                fflush(stdin);
                break;

             case 3:
                if(!testa_vazia(t)) {
                    cout << "> Digite um número para remover da árvore: ";
                    cin >> num;
                    bool encontrado;
                    t = remover(t, num, encontrado);
                    if (encontrado) cout << "> Número " << num << " removido com sucesso!";
                    else cout << "> Valor " << num << " não encontrado na árvore!";
                    fflush(stdin);
                }
                else cout << "> Árvore vazia!";
                break;

            case 4:
                if(!testa_vazia(t)) {
                    cout << "> Árvore em pré-ordem: \n";
                    mostra_pre(t);
                }
                else cout << "> Árvore vazia!";
                break;

            case 5:
                if(!testa_vazia(t)) {
                    cout << "> Árvore em ordem simétrica: \n";
                    mostra_sim(t);
                }
                else cout << "> Árvore vazia!";
                break;

            case 6:
                if(!testa_vazia(t)) {
                    cout << "> Árvore em pós-ordem: \n";
                    mostra_pos(t);
                }
                else cout << "> Árvore vazia!";
                break;

            case 7:
                if(!testa_vazia(t)) {
                    cont = 0;
                    cout << " Índice |  Número | Filho esquerda | Filho direita " << endl;
                    cout << "--------+---------+----------------+---------------" << endl;
                    mostra_matriz(t, &cont);
                }
                else cout << "> Árvore vazia!";
                break;

            case 8:
                if(!testa_vazia(t)) {
                    cout << "> Estatísticas da árvore: \n";
                    estatisticasArv(t);
                }
                else cout << "> Árvore vazia!";
                break;

            case 9:
                if(!testa_vazia(t)) {
                    cout << "> Digite o nó que deseja ver as estatísticas: ";
                    cin >> num;
                    cout << endl;
                    bool achado;
                    estatisticasNo(t, num, achado, t);
                    if(!achado) cout << "> O nó " << num << " não existe na árvore!" << endl;
                    fflush(stdin);
                }
                else cout << "> Árvore vazia!";
                break;

            case 10: {
                if(!testa_vazia(t)) {
                    int nivel;
                    bool encontrado = false;
                    cout << "Digite o nível que deseja ver os valores da árvore: ";
                    cin >> nivel;
                    cout << "Valores no nível " << nivel << ": ";
                    mostraValoresNoNivel(t, nivel, 0, encontrado);
                    if (!encontrado) cout << "Não há nós neste nível." << endl;
                    cout << endl;
                    fflush(stdin);
                }
                else cout << "> Árvore vazia!";
                break;
            }

            case 11:
                if(!testa_vazia(t)) {
                    excluirArvore(&t);
                    cout << "> Árvore excluída com sucesso!" << endl;
                }
                else cout << "> Árvore vazia!";
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    } while(menu != 0);
}
