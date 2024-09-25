#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

struct aluno {
    int matricula;
    string nome;
    float media;
    float frequencia;
};

typedef struct arv {
    aluno info;
    arv* sae;
    arv* sad;
    int fb; // fator de balanceamento
} arvore;

int testa_vazia(arvore *t) {
    if(t == NULL) return 1;
    if(t->info.matricula == NULL) return 1;
    return 0;
}

int altura(arvore *p) {
    if(p == NULL) return 0;
    else {
        int he = altura(p->sae);
        int hd = altura(p->sad);
        if(he < hd) return (hd + 1);
        else return (he + 1);
    }
}

int fator_bal(arvore *t) {
    int fator = 0;
    if(t->sae) fator += altura(t->sae);
    if(t->sad) fator -= altura(t->sad);
    return fator;
}

void calcula_fb(arvore *t) {
    if(!testa_vazia(t)) {
        t->fb = fator_bal(t);
        if(t->sae != NULL) calcula_fb(t->sae);
        if(t->sad != NULL) calcula_fb(t->sad);
    }
}

arvore* rotacionar_esq_esq(arvore* t) {
    arvore* temp = t;
    arvore* esq = temp->sae;
    temp->sae = esq->sad;
    esq->sad = temp;
    return esq;
}

arvore* rotacionar_esq_dir(arvore* t) {
    arvore* temp = t;
    arvore* esq = temp->sae;
    arvore* dir = esq->sad;
    temp->sae = dir->sad;
    esq->sad = dir->sae;
    dir->sae = esq;
    dir->sad = temp;

    return dir;
}

arvore* rotacionar_dir_esq(arvore* t) {
    arvore* temp = t;
    arvore* dir = temp->sad;
    arvore* esq = dir->sae;

    temp->sad = esq->sae;
    dir->sae = esq->sad;
    esq->sad = dir;
    esq->sae = temp;
    return esq;
}

arvore* rotacionar_dir_dir(arvore *t) {
    arvore *temp = t;
    arvore *dir = temp->sad;
    temp->sad = dir->sae;
    dir->sae = temp;
    return dir;
}

arvore* balancear(arvore *t) {
    arvore* nodo_balanceado = NULL;
    if(t->sae) t->sae = balancear(t->sae);
    if(t->sad) t->sad = balancear(t->sad);

    int fator = t->fb;

    if(fator >= 2) {
        if(t->sae->fb <= -1) nodo_balanceado = rotacionar_esq_dir(t);
        else nodo_balanceado = rotacionar_esq_esq(t);
    } else if(fator <= -2) {
        if(t->sad->fb >= 1) nodo_balanceado = rotacionar_dir_esq(t);
        else nodo_balanceado = rotacionar_dir_dir(t);
    } else nodo_balanceado = t;
    return nodo_balanceado;
}

void inserir(arvore** t, aluno a) {
    if (*t == NULL) {
        *t = new arvore;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->info = a;
    } else {
        if (a.matricula < (*t)->info.matricula) inserir(&(*t)->sae, a);
        else if (a.matricula > (*t)->info.matricula) inserir(&(*t)->sad, a);
    }
}

arvore* minValorNo(arvore* no) {
    arvore* c = no;
    while (c && c->sae != NULL) c = c->sae;
    return c;
}

arvore* remover(arvore* t, int matricula, bool& encontrado) {
    if (t == NULL) {
        encontrado = false;
        return NULL;
    }
    if (matricula < t->info.matricula)
        t->sae = remover(t->sae, matricula, encontrado);
    else if (matricula > t->info.matricula)
        t->sad = remover(t->sad, matricula, encontrado);
    else {
        encontrado = true;
        if (t->sae == NULL) {
            arvore* temp = t->sad;
            delete t;
            return temp;
        } else if (t->sad == NULL) {
            arvore* temp = t->sae;
            delete t;
            return temp;
        }
        arvore* temp = minValorNo(t->sad);
        t->info = temp->info;
        t->sad = remover(t->sad, temp->info.matricula, encontrado);
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

bool ehCompleta(arvore *t, int nivel, int* nivelFolhas) {
    if (t == NULL) return true;

    if (t->sae == NULL && t->sad == NULL) {
        if (*nivelFolhas == -1) {
            *nivelFolhas = nivel;
            return true;
        } return (nivel == *nivelFolhas);
    } return ehCompleta(t->sae, nivel + 1, nivelFolhas) && ehCompleta(t->sad, nivel + 1, nivelFolhas);
}

int quant_fb(arvore *t, int tipo) {
    if (t == NULL) return 0;
    int cont = 0;
    if (tipo == 1) { if (t->fb == -1) cont++; }
    else if (tipo == 2) { if (t->fb == 1) cont++; }
    else if (tipo == 3) { if (t->fb == 0) cont++; }
    cont += quant_fb(t->sae, tipo);
    cont += quant_fb(t->sad, tipo);
    return cont;
}

void excluirArvore(arvore **t) {
    if(*t != NULL) {
        excluirArvore(&(*t)->sae);
        excluirArvore(&(*t)->sad);
        delete *t;
        *t = NULL;
    }
}

arvore* buscar_matricula(arvore* t, int matricula) {
    if (t == NULL) return NULL;
    if (matricula == t->info.matricula) return t;
    if (matricula < t->info.matricula) return buscar_matricula(t->sae, matricula);
    else return buscar_matricula(t->sad, matricula);
}

void mostra_pre(arvore *t, int profundidade = 0) {
    if(!testa_vazia(t)) {
        cout << string(profundidade, '.') << t->info.matricula << endl;
        mostra_pre(t->sae, profundidade + 1);
        mostra_pre(t->sad, profundidade + 1);
    }
}

void mostrar(arvore *t, int *cont) {
    cout << setfill(' ') << setw(7) << *cont << " |";
    cout << setfill(' ') << setw(11) << t->info.matricula << " |";
    cout << setfill(' ') << setw(10) << t->info.nome << " |";
    cout << setfill(' ') << setw(6) << fixed << setprecision(1) << t->info.media << " |";
    cout << setfill(' ') << setw(10) << fixed << setprecision(1) << t->info.frequencia << "%\n";
    *cont += 1;

    if(t->sae != NULL) mostrar(t->sae, cont);
    if(t->sad != NULL) mostrar(t->sad, cont);
}

void mostrar_aprovados(arvore *t, int *cont) {
    if (t->info.media >= 6 && t->info.frequencia >= 75) {
        cout << setfill(' ') << setw(7) << *cont << " |";
        cout << setfill(' ') << setw(11) << t->info.matricula << " |";
        cout << setfill(' ') << setw(10) << t->info.nome << " |";
        cout << setfill(' ') << setw(6) << fixed << setprecision(1) << t->info.media << " |";
        cout << setfill(' ') << setw(10) << fixed << setprecision(1) << t->info.frequencia << "%\n";
        *cont += 1;
    }
    if(t->sae != NULL) mostrar_aprovados(t->sae, cont);
    if(t->sad != NULL) mostrar_aprovados(t->sad, cont);
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

        if(acao == "Inserir") {
            string n;
            getline(ss, n, ' ');
            int num = stoi(n);

            string nom;
            getline(ss, nom, ' ');

            string m;
            getline(ss, m, ' ');
            float med = stof(m);

            string f;
            getline(ss, f);
            float freq = stof(f);

            aluno a = { num, nom, med, freq };

            arvore* existe = buscar_matricula(*t, num);
            if (existe != NULL) {
                cout << "\n> Aluno com matrícula " << num << " já está cadastrado!" << endl;
            }
            else {
                inserir(t, a);
                calcula_fb(*t);
                *t = balancear(*t);
                calcula_fb(*t);
                cout << "> Aluno de mátricula " << num << " cadastrado com sucesso!";
            }
        }

        else if(acao == "Remover") {
            string n;
            getline(ss, n);
            int num = stoi(n);

            bool encontrado = false;
            *t = remover(*t, num, encontrado);
            if (encontrado) {
                calcula_fb(*t);
                *t = balancear(*t);
                calcula_fb(*t);
                cout << "> REMOVER: Aluno com matrícula " << num << " removido com sucesso!" << endl;
            }
            else cout << "> REMOVER: Aluno com matrícula " << num << " não encontrado!" << endl;
        }
        else if(acao == "Mostrar") {
            if(!testa_vazia(*t)) {
                cout << "MOSTRAR:\n\n";
                int cont = 0;
                cout << " Índice |  Matrícula |      Nome | Média | Frequência " << endl;
                cout << "--------+------------+-----------+-------+------------" << endl;
                mostrar(*t, &cont);
            }
            else cout << "> Árvore vazia!";

        }
        else if(acao == "Aprovados") {
            if(!testa_vazia(*t)) {
                cout << "APROVADOS:\n\n";
                int cont = 0;
                cout << " Índice |  Matrícula |      Nome | Média | Frequência " << endl;
                cout << "--------+------------+-----------+-------+------------" << endl;
                mostrar_aprovados(*t, &cont);
            }
            else cout << "> Árvore vazia!";

        }
        else cout << "Função inválida";

        cout << endl << "--------------------------------------------------------------------" << endl << endl;
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
        cout << "##########MENU DE OPÇÕES########" << endl;
        cout << "# 0 - Sair                     #" << endl;
        cout << "# 1 - Ler arquivo texto        #" << endl;
        cout << "# 2 - Incluir aluno            #" << endl;
        cout << "# 3 - Remover aluno            #" << endl;
        cout << "# 4 - Mostrar alunos           #" << endl;
        cout << "# 5 - Mostrar alunos aprovados #" << endl;
        cout << "# 6 - Mostrar árvore           #" << endl;
        cout << "# 7 - Excluir árvore           #" << endl;
        cout << "################################" << endl;
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

             case 2: {
                 int mat;
                 string nome;
                 float med, freq;

                cout << "> Informe a matrícula do aluno: ";
                cin >> mat;

                arvore* existe = buscar_matricula(t, mat);
                if (existe != NULL) {
                    cout << "\n> Aluno com matrícula " << mat << " já está cadastrado!" << endl;
                    fflush(stdin);
                    break;
                }
                else {
                    cout << "\n> Informe o nome do aluno: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "\n> Informe a média do aluno: ";
                    cin >> med;
                    cout << "\n> Informe a frequência do aluno (%): ";
                    cin >> freq;

                    aluno a = { mat, nome, med, freq };
                    inserir(&t, a);
                    calcula_fb(t);
                    t = balancear(t);
                    calcula_fb(t);
                    cout << "> Aluno de mátricula " << mat << " cadastrado com sucesso!";
                    fflush(stdin);
                }

                break;
             }

             case 3:
                if(!testa_vazia(t)) {
                    int matr;
                    cout << "> Informe a matrícula do aluno a ser removido: ";
                    cin >> matr;

                    bool encontrado = false;
                    t = remover(t, matr, encontrado);
                    if (encontrado) {
                        calcula_fb(t);
                        t = balancear(t);
                        calcula_fb(t);
                        cout << "> Aluno com matrícula " << matr << " removido com sucesso!" << endl;
                    }
                    else cout << "> Aluno com matrícula " << matr << " não encontrado!" << endl;
                    fflush(stdin);
                }
                else cout << "> Árvore vazia!";
                break;

            case 4:
                if(!testa_vazia(t)) {
                    int cont = 0;
                    cout << " Índice |  Matrícula |      Nome | Média | Frequência " << endl;
                    cout << "--------+------------+-----------+-------+------------" << endl;
                    mostrar(t, &cont);
                }
                else cout << "> Árvore vazia!";
                break;

            case 5:
                if(!testa_vazia(t)) {
                    int cont = 0;
                    cout << " Índice |  Matrícula |      Nome | Média | Frequência " << endl;
                    cout << "--------+------------+-----------+-------+------------" << endl;
                    mostrar_aprovados(t, &cont);
                }
                else cout << "> Árvore vazia!";
                break;

            case 6:
                if(!testa_vazia(t)) {
                    mostra_pre(t);
                }
                else cout << "> Árvore vazia!";
                break;

            case 7:
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
