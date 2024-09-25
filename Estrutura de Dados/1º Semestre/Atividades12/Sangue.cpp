#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

struct Funcionario {
    int ID;
    string nome;
    char sexo;
};

bool operator==(const Funcionario &F, const int &ID) { return (F.ID == ID); }

bool operator<(const Funcionario &F1, const Funcionario &F2) { return (F1.ID < F2.ID); }

ostream& operator<< (ostream &o, Funcionario &F) {
    return o << F.ID << " |" << setfill(' ') << setw(5) << F.sexo << " |" << setfill(' ') << setw(11) << F.nome;
}

string* infSexo(char sexo) {
    string* lista = new string[2];
    if(sexo == 'M' || sexo == 'N') {
        *lista = "o";
        *(lista + 1) = "O funcionário";
        if(sexo == 'N') *(lista + 1) += " de sexo indefinido";
    } else {
        *lista = "a";
        *(lista + 1) = "A funcionária";
    } return lista;
}

void mostraFunc(ListaD<Funcionario>* LF, string col) {
    LF->mostrar("Lista de todos os funcionários", col, 2, 'T');
}

void mostrarPeloId(ListaD<int>* L, ListaD<Funcionario>* LF, string nome, string col) {
    int qtd = L->mostrarColunas(nome, col, true);

    NoD<int>* N = L->inicio;
    while(N != NULL) {
        mostrarItem(LF->existeNo(N->dado), qtd, 2);
        N = N->prox;
    }
}

void mostraDep(int IDD, ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA, string col) {
    string dep = "Funcionários do departamento de ";
    if(IDD == 0) mostrarPeloId(LP, LF, dep + "produção", col);
    else if(IDD == 1) mostrarPeloId(LE, LF, dep + "entregas", col);
    else if(IDD == 2) mostrarPeloId(LA, LF, dep + "atendimento ao cliente", col);
    else cout << "!!! Departamento " << IDD << " INEXISTENTE !!!";
}

void mostraFuncEmComum(int IDD1, int IDD2, ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA, string col) {
    bool inval1 = (IDD1 < 0 || IDD1 > 2);
    bool inval2 = (IDD2 < 0 || IDD2 > 2);
    if(inval1 && inval2) {
        cout << "> Departamentos " << IDD1 << " e " << IDD2 << " INEXISTENTES!!!";
    } else {
        if(inval1) cout << "> Departamento " << IDD1 << " INEXISTENTE!!";
        else if(inval2) cout << "> Departamento " << IDD2 << " INEXISTENTE!!";
        else {
            if(IDD1 == IDD2) {
                cout << "> Departamentos inseridos são iguais!!";
                return;
            }
            ListaD<int> Lres;

            string nome;
            if((IDD1 == 0 && IDD2 == 1) || (IDD1 == 1 && IDD2 == 0)) {
                Lres = LP->intersectLista(*LE);
                nome = "produção e entrega";
            }
            else if((IDD1 == 0 && IDD2 == 2) || (IDD1 == 2 && IDD2 == 0)) {
                Lres = LP->intersectLista(*LA);
                nome = "produção e atendimento";
            }
            else if((IDD1 == 1 && IDD2 == 2) || (IDD1 == 2 && IDD2 == 1)) {
                Lres = LE->intersectLista(*LA);
                nome = "entrega e atendimento";
            }

            mostrarPeloId(&Lres, LF, "Funcionários em comum nos departamentos de " + nome, col);
            //Lres.mostrar("Funcionários em comum nos departamentos de " + nome, col, 2, 'T');
        }
    }
}

void cadastrarFunc(int IDF, string nome, char sexo, ListaD<Funcionario>* LF) {
    if((sexo != 'M') && (sexo != 'F') && (sexo != 'N')) { // Verificar sexo
        cout << "> Sexo inserido inválido... cadastro INVALIDADO!\n";
    } else {
        string* infS = infSexo(sexo);

        // Verificar se código já existe
        if(LF->existeVal(IDF) != NULL) cout << "> " << *(infS + 1) << " " << nome << " não foi cadastrad" << *infS << " pois o código " << IDF << " JÁ EXISTE!\n";
        else { // Funcionário VÁLIDO...
            cout << "> " << *(infS + 1) << " " << nome << " (" << IDF << ") foi cadastrad" << *infS << " com sucesso!";
            Funcionario F = { IDF, nome, sexo };
            LF->adOrdenado(F);
        }
    }
}

void addFuncDep(int IDF, int IDD, ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA) {
    if(IDD < 0 || IDD > 2) cout << "> Departamento " << IDD << " inexistente.";
    else { // Departamento inserido VÁLIDO
        Funcionario *F = LF->existeVal(IDF);
        if(F != NULL) { // Funcionário EXISTE na lista prinicipal
            ListaD<int>* LD = nullptr;
            string tipo;
            if(IDD == 0) {
                LD = LP;
                tipo = "produção";
            } else if(IDD == 1) {
                LD = LE;
                tipo = "entregas";
            } else {
                LD = LA;
                tipo = "atendimento ao cliente";
            }

            string* infS = infSexo(F->sexo);
            cout << *(infS + 1) << " " << F->nome;

            // Se JÁ existe o ID na lista de departamento
            if(LD->existeVal(F->ID)) cout << " JÁ está inserido";
            else {
                cout << " foi adicionad" << *infS;
                LD->adFim(F->ID);
            } cout << " no departamento de " << tipo << "!";
        } else cout << "> Usuário " << IDF << " inexistente.";
    }
}

void removeFunc(int IDF, ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA) {
    Funcionario *F = LF->removeUmVal(IDF);
    if(F == NULL) { // Usuário inexistente
        cout << "> Usuário " << IDF << " inexistente.";
    } else { // Usuário existe e JÁ foi removido


        int *p = LP->removeUmVal(IDF),
            *e = LE->removeUmVal(IDF),
            *a = LA->removeUmVal(IDF);
        bool inserido = false;

        string* infS = infSexo(F->sexo);
        cout << "> " << *(infS + 1) << " " << F->nome << " removid" << *infS;

        if(p != NULL) {
            if(!inserido) {
                cout << " nos seguintes departamentos: ";
                inserido = true;
            } else cout << ", ";
            cout << "Produção";
        }
        if(e != NULL) {
            if(!inserido) {
                cout << " nos seguintes departamentos: ";
                inserido = true;
            } else cout << ", ";
            cout << "Entrega";
        }
        if(a != NULL) {
            if(!inserido) {
                cout << " nos seguintes departamentos: ";
                inserido = true;
            } else cout << ", ";
            cout << "Atendimento ao cliente";
        }

        if(inserido) cout << ";";
        else cout << "!";
    }
}

void lerArquivo(ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA, string col) {
    string arch;
    cout << ">> Insira o nome do arquivo: ";
    cin >> arch;
    cout << endl;

    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) { // Se leitor NÃO chegou até o final do arquivo
        string linha;
        getline(leitor, linha);

        if(linha == "mostraFunc") {
            mostraFunc(LF, col);
        } else {
            string acao;
            stringstream ss(linha);
            getline(ss, acao, ' ');
            if(acao == "cadastrarFunc") {
                string id, nome, M;
                getline(ss, id, ' ');
                getline(ss, nome, ' ');
                getline(ss, M, '\n');
                cadastrarFunc(stoi(id), nome, M[0], LF);
            }
            else if(acao == "addFuncDep") {
                string id, dep;
                getline(ss, id, ' ');
                getline(ss, dep);
                addFuncDep(stoi(id), stoi(dep), LF, LP, LE, LA);
            }
            else if(acao == "removeFunc") {
                string id;
                getline(ss, id);
                removeFunc(stoi(id), LF, LP, LE, LA);
            }
            else if(acao == "mostraDep") {
                string dep;
                getline(ss, dep);
                mostraDep(stoi(dep), LF, LP, LE, LA, col);
            }
            else if(acao == "mostraFuncEmComum") {
                string dep1, dep2;
                getline(ss, dep1, ' ');
                getline(ss, dep2);
                mostraFuncEmComum(stoi(dep1), stoi(dep2), LF, LP, LE, LA, col);
            }
            else {
                cout << "!!! FUNÇÃO INVÁLIDA !!!";
            }
        }

        cout << endl << "===========================================================" << endl << endl;
    }

    getchar();
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    ListaD<Funcionario> LF;
    ListaD<int> LP, LE, LA;
    string col = "  ID | Sexo |       Nome";

    lerArquivo(&LF, &LP, &LE, &LA, col);
}
