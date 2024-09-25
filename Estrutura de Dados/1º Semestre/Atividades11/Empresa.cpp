#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

struct Funcionario {
    int ID;
    string nome;
    char sexo;
};

bool operator==(const Funcionario &F, const int &ID) {
    return (F.ID == ID);
}

ostream& operator << (ostream &o, string* &S) {
    return o << *S << " - " << *(S + 1) << " - " << *(S + 2);
}


string* infSexo(char sexo) {
    string* lista = new string[3];
    if(sexo == 'M' || sexo == 'N') {
        *lista = "o";
        *(lista + 1) = "";
        if(sexo == 'N') *(lista + 1) += " de sexo indefinido";
    } else *lista = "a";
    *(lista + 2) = "" + toupper((*lista)[0]);
    return lista;
}

void cadastrarFunc(int IDF, string nome, char sexo, ListaD<Funcionario>* LF) {
    //cout << "> VERIFICAÇÃO DE INTEGRIDADE DE DADOS <\n\n";
    if((sexo != 'M') && (sexo != 'F') && (sexo != 'N')) { // Verificar sexo
        cout << "> Sexo inserido inválido... cadastro INVALIDADO!\n";
    } else {
        string* infS = infSexo(sexo);

        // Verificar se código já existe
        if(LF->existeVal(IDF) != NULL) cout << "> " << *(infS + 1) << " funcionári" << *infS << *(infS + 2) << " " << nome << " não foi cadastrad" << *infS << " pois o código " << IDF << " JÁ EXISTE!\n";
        else { // Funcionário VÁLIDO...
            cout << "> " << *(infS + 1) << " funcionári" << *infS << *(infS + 2) << " " << nome << " (" << IDF << ") foi cadastrad" << *infS << " com sucesso!";
            Funcionario F = { IDF, nome, sexo };
            LF->adFim(F);
        }
    }
}

void addFuncDep(int IDF, int IDD, ListaD<Funcionario>* LF, ListaD<int>* LP, ListaD<int>* LE, ListaD<int>* LA) {
    Funcionario *F = LF->existeVal(IDF);
    if(F != NULL) { // Funcionário EXISTE na lista prinicipal
        if((IDD != 0) && (IDD != 1) && (IDD != 2)) cout << "> Departamento " << IDD << " inexistente.";
        else { // Departamento inserido VÁLIDO
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
            cout << *(infS + 1) << " funcionári" << *infS << *(infS + 2) << " " << F->nome;

            // Se JÁ existe o ID na lista de departamento
            if(LD->existeVal(F->ID)) cout << " JÁ está inserido";
            else {
                cout << " foi adicionad" << *infS;
                LD->adFim(F->ID);
            } cout << " no departamento de " << tipo << "!";
        }
    } else cout << "> Usuário " << IDF << " inexistente.";
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
        cout << ">";
    }

}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    ListaD<Funcionario> LF;
    ListaD<int> LP, LE, LA;

    string* M = infSexo('M'), *F = infSexo('F'), *N = infSexo('N');
    cout << M << endl << F << endl << N << endl;

    do
    {
        //system("cls");
        cout << "###############MENU DE OPÇÕES################" << endl;
        cout << "# 0 - Sair                                  #" << endl;
        cout << "# 1 - Inserir arquivo de texto              #" << endl;
        cout << "# 2 - Cadastrar funcionário                 #" << endl;
        cout << "# 3 - Adicionar funcionário no departamento #" << endl;
        cout << "# 4 - Remover funcionário                   #" << endl;
        cout << "# 5 - Mostrar funcionários (Mini menu)      #" << endl;
        cout << "#############################################" << endl;
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

                break;

            case 2: { // Cadastrar funcionário
                string nome;
                cout << "> Insira o nome do(a) funcionário(a): ";
                getline(cin, nome);

                char sexo;
                cout << "> Insira o sexo do(a) funcionário(a) (M: Masculino; F: Feminino; N: Prefiro não informar): ";
                cin >> sexo;
                sexo = toupper(sexo);

                int IDF;
                cout << "> Insira o ID do funcionário: ";
                cin >> IDF;

                cadastrarFunc(IDF, nome, sexo, &LF);
                getchar();
                break;
            }

            case 3: { // Inserir funcionário em um dos departamentos
                int IDF;
                cout << "> Insira o ID do funcionário: ";
                cin >> IDF;

                int IDD;
                cout << "> Insira o ID do departamento (0: Produção; 1: Entregas; 2: Atendimento ao cliente): ";
                cin>> IDD;

                addFuncDep(IDF, IDD, &LF, &LP, &LE, &LA);
                getchar();
                break;
            }

            case 4: {
                int IDF;
                cout << "> Insira o ID do funcionário: ";
                cin >> IDF;

                removeFunc(IDF, &LF, &LP, &LE, &LA);
                break;
            }

            case 5:
                //miniMenu("Mostrar...", "Todos os animais em ordem de chegada", "Os três últimos animais da lista", &L, col, funcMostrar);
                break;

        }; getchar();
    }
    while(menu != 0);
}
