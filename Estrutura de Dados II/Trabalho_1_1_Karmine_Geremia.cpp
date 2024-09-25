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

void excluirArvore(arvore **t) {
    if(*t != NULL) {
        excluirArvore(&(*t)->sae);
        excluirArvore(&(*t)->sad);
        delete *t;
        *t = NULL;
    }
}

int qtdDescendentes(arvore *t) {
    if(t == NULL) return 0;
    return 1 + qtdDescendentes(t->sae) + qtdDescendentes(t->sad);
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

void verifIso(arvore *t1, arvore *t2, bool* ehiso) {
    if(*ehiso == false) return;

    if((t1->sae == NULL && t2->sae == NULL && t1->sad == NULL && t2->sad == NULL) ||
       (t1->sae != NULL && t2->sae != NULL && t1->sad == NULL && t2->sad == NULL) ||
       (t1->sae == NULL && t2->sae == NULL && t1->sad != NULL && t2->sad != NULL) ||
       (t1->sae != NULL && t2->sae != NULL && t1->sad != NULL && t2->sad != NULL)) {


        if(t1->sae != NULL) verifIso(t1->sae, t2->sae, ehiso);
        if(t1->sad != NULL) verifIso(t1->sad, t2->sad, ehiso);
    } else *ehiso = false;

}

void lerArquivo(arvore **t1, arvore **t2, int op) {
    string arch;
    if(op == 1) arch = "entrada1.txt";
    if(op == 2) arch = "entrada2.txt";
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

            if(op == 1){
                inserir(t1, num);
                cout << "> INSERIR: Número " << num << " inserido com sucesso em A1!";
            }
            if(op == 2){
                inserir(t2, num);
                cout << "> INSERIR: Número " << num << " inserido com sucesso em A2!";
            }
        }
        else if(acao == "remover") {
            string n;
            getline(ss, n);
            int num = stoi(n);

            bool encontrado;
            if(op == 1){
                *t1 = remover(*t1, num, encontrado);
                if (encontrado) cout << "> REMOVER: Número " << num << " removido com sucesso em A1!";
                else cout << "> REMOVER: Valor " << num << " não encontrado em A1!";
            }
            if(op == 2){
                *t2 = remover(*t2, num, encontrado);
                if (encontrado) cout << "> REMOVER: Número " << num << " removido com sucesso em A2!";
                else cout << "> REMOVER: Valor " << num << " não encontrado em A2!";
            }
        }
        else cout << "Função inválida";

        cout << endl << "---------------------------------------------" << endl << endl;
    }
}

main() {
    system ("color 05");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, num, op;
    int cont;
    arvore *t1 = NULL;
    arvore *t2 = NULL;

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
        cout << "# 8 - Verificar se é isomorfo      #" << endl;
        cout << "# 9 - Excluir árvore              #" << endl;
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
                cout << "> Deseja ler entrada 1 ou 2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    cout << endl;
                    lerArquivo(&t1, &t2, op);

                    cout << "\n> Leitura do arquivo texto completa!\n";
                    fflush(stdin);
                    break;
                } else {
                    cout << "\n> Opção para leitura de texto inválida";
                    fflush(stdin);
                    break;
                }

             case 2:
                cout << "> Deseja inserir em A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    cout << endl;
                    cout << "> Digite um número para inserir na árvore: ";
                    cin >> num;
                    if(op == 1) inserir(&t1, num);
                    if(op == 2) inserir(&t2, num);
                    cout << "> Número " << num << " inserido com sucesso!";
                    fflush(stdin);
                    break;
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

             case 3:
                cout << "> Deseja remover um valor em A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    cout << endl;
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            cout << "> Digite um número para remover de A1: ";
                            cin >> num;
                            bool encontrado;
                            t1 = remover(t1, num, encontrado);
                            if (encontrado) cout << "> Número " << num << " removido com sucesso em A1!";
                            else cout << "> Valor " << num << " não encontrado na árvore em A1!";
                        }
                        else cout << "> A1 vazia!";
                        fflush(stdin);
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            cout << "> Digite um número para remover de A2: ";
                            cin >> num;
                            bool encontrado;
                            t2 = remover(t2, num, encontrado);
                            if (encontrado) cout << "> Número " << num << " removido com sucesso em A2!";
                            else cout << "> Valor " << num << " não encontrado na árvore em A2!";
                        }
                        else cout << "> A2 vazia!";
                        fflush(stdin);
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            case 4:
                cout << "> Deseja mostrar A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            cout << "> A1 em pré-ordem: \n";
                            mostra_pre(t1);
                        }
                        else cout << "> A1 vazia!";
                        fflush(stdin);
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            cout << "> A2 em pré-ordem: \n";
                            mostra_pre(t2);
                        }
                        else cout << "> A2 vazia!";
                        fflush(stdin);
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            case 5:
                cout << "> Deseja mostrar A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            cout << "> A1 em ordem simétrica: \n";
                            mostra_sim(t1);
                        }
                        else cout << "> A1 vazia!";
                        fflush(stdin);
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            cout << "> A2 em ordem simétrica: \n";
                            mostra_sim(t2);
                        }
                        else cout << "> A2 vazia!";
                        fflush(stdin);
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            case 6:
                cout << "> Deseja mostrar A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            cout << "> A1 em pós-ordem: \n";
                            mostra_pos(t1);
                        }
                        else cout << "> A1 vazia!";
                        fflush(stdin);
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            cout << "> A2 em pós-ordem: \n";
                            mostra_pos(t2);
                        }
                        else cout << "> A2 vazia!";
                        fflush(stdin);
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            case 7:
                cout << "> Deseja mostrar A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            cont = 0;
                            cout << " Índice |  Número | Filho esquerda | Filho direita " << endl;
                            cout << "--------+---------+----------------+---------------" << endl;
                            mostra_matriz(t1, &cont);
                        }
                        else cout << "> A1 vazia!";
                        fflush(stdin);
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            cont = 0;
                            cout << " Índice |  Número | Filho esquerda | Filho direita " << endl;
                            cout << "--------+---------+----------------+---------------" << endl;
                            mostra_matriz(t2, &cont);
                        }
                        else cout << "> A2 vazia!";
                        fflush(stdin);
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            case 8: {
                bool ehiso = true;

                if(t1 != NULL && t2 != NULL) verifIso(t1, t2, &ehiso);
                else if(!(t1 == NULL && t1 == NULL)) ehiso = false;

                if(ehiso) cout << "> A1 e A2 SÃO isomorfas! :)";
                else cout << "> A1 e A2 NÃO são isomorfas... :(";
                break;
            }

            case 9:
                cout << "> Deseja apagar A1 ou A2?: ";
                cin >> op;
                if((op == 1) || (op == 2)) {
                    if(op == 1){
                        if(!testa_vazia(t1)) {
                            excluirArvore(&t1);
                            cout << "> A1 excluída com sucesso!" << endl;
                        }
                        else cout << "> A1 vazia!";
                        break;
                    }
                    if(op == 2){
                        if(!testa_vazia(t2)) {
                            excluirArvore(&t2);
                            cout << "> A2 excluída com sucesso!" << endl;
                        }
                        else cout << "> A2 vazia!";
                        break;
                    }
                } else {
                    cout << "\n> Opção de árvore inválida";
                    fflush(stdin);
                    break;
                }

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    } while(menu != 0);
}
