#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

struct funcionario {
    int codigo;
    string nome;
    int idade;
    float salario;
};

// "Overloading" para mostrar struct DIRETO pelo método "cout"
ostream& operator << (ostream &o, funcionario &f) {
    return o << f.codigo << " |" << setfill(' ') << setw(11) << f.nome << " |" <<
                setfill(' ') << setw(11) << f.idade << " |" << setfill(' ') << setw(14) << f.salario;
}

// FUNÇÕES PARA CRIAR NOVO FUNCIONÁRIO
bool BuscaCod(int codigo, ListaD<funcionario>* L) {
    NoD<funcionario> *F = L->inicio;
    while(F != NULL) {
        if (codigo == (F->dado).codigo) return true;
        F = F->prox;
    }
    return false;
}

funcionario novoFunc(ListaD<funcionario>* L) {
    // Inserir código (NÃO pode ser repetido, chave primária)
    int codigo;
    do {
        cout << "> Digite o código do funcionário: ";
        cin >> codigo;
        bool existe = BuscaCod(codigo, L);
        if (existe == true) cout << "Esse código já foi inserido!\n";
        else break;
    } while(true);

    // Inserir nome
    string nome;
    cout << "> Digite o nome do funcionário: ";
    cin.ignore();
    getline(cin, nome);

    // Inserir idade (não pode ser nulo/negativo)
    int idade;
    do {
        cout << "> Digite a idade do funcionário: ";
        cin >> idade;
        if (idade <= 0) cout << "Idade inserida inválida!\n";
        else break;
    } while(true);

    // Inserir salário (não pode ser nulo/negativo)
    float salario;
        do {
        cout << "> Digite o salário do funcionário: ";
        cin >> salario;
        if (salario <= 0) cout << "Salário inserido inválido!\n";
        else break;
    } while(true);

    // Criar funcionário
    funcionario F = {codigo, nome, idade, salario};
    return F;
}

// FUNÇÃO IMPORTANTE PARA ORDENAÇÃO DE FUNCIONÁRIOS
bool nomeMenor(funcionario N, funcionario M) { return (N.nome < M.nome); }
bool idadeMenor(funcionario N, funcionario M) { return (N.idade < M.idade); }

// FUNÇÕES ENVOLVENDO SALÁRIO (CÁLCULO DE MÉDIA E EXIBIÇÃO DE FUNCIONÁRIOS)
float mediaTot(ListaD<funcionario>* L) {
    float total = 0;
    NoD<funcionario>* N = L->inicio;
    do {
        total += (N->dado).salario;
        N = N->prox;
    } while(N != NULL);
    return total/(float)(L->tam);
}

void mostrarFuncMedia(ListaD<funcionario>* L, float media, string colunas) {
    NoD<funcionario>* N = L->inicio;
    bool exib = false;
    int qtd;
    cout << ">> Média salarial: R$ " << media << endl << endl;
    do {
        if((N->dado).salario < media) {
            exib = true;
            qtd = L->mostrarColunas("Funcionários com salário MENOR que a média", colunas, false);
            mostrarItem(N, qtd, 2);
            N = N->prox;
            break;
        } else N = N->prox;
    } while(N != NULL);

    while(N != NULL) {
        if((N->dado).salario < media) mostrarItem(N, qtd, 2);
        N = N->prox;
    }

    if(!exib) cout << "!!! Não há funcionários com salário abaixo da média (TODOS tem mesmo salário) !!!";
}

void mostrarFuncIdade(ListaD<funcionario>* L, string colunas) {
    NoD<funcionario> *N = L->inicio;
    ListaD<funcionario> M;
    while(N != NULL) {
        M.adFim(N->dado);
        N = N->prox;
    } M.ordenar(idadeMenor);
    M.mostrar("Funcionários ordenados pela idade", colunas, 2, 'T');
}

int main () {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    string colunas = " Código |       Nome |      Idade |      Salário ";

    ListaD<funcionario> L;

    do
    {
        system("cls");
        cout << "######################MENU DE OPÇÕES#######################" << endl;
        cout << "# 0 - Sair                                                #" << endl;
        cout << "# 1 - Inserir funcionário no início da lista              #" << endl;
        cout << "# 2 - Inserir funcionário no final da lista               #" << endl;
        cout << "# 3 - Remover o funcionário do início da lista            #" << endl;
        cout << "# 4 - Remover o funcionário do final da lista             #" << endl;
        cout << "# 5 - Mostrar funcionários da lista                       #" << endl;
        cout << "# 6 - Mostrar média dos salários                          #" << endl;
        cout << "# 7 - Ordenar lista de funcionários pelo nome             #" << endl;
        cout << "###########################################################" << endl;
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
                L.adInicio(novoFunc(&L));
                cout << "> Funcionário registrado com sucesso!";
                getchar();
                break;

            case 2:
                L.adFim(novoFunc(&L));
                cout << "> Funcionário registrado com sucesso!";
                getchar();
                break;

            case 3:
                if(L.tam == 0) cout << "> NÃO HÁ funcionários na lista!";
                else cout << "> Funcionário de nome " << L.removeInicio().nome << " removido do início da lista com sucesso!";
                break;

            case 4:
                if(L.tam == 0) cout << "> NÃO HÁ funcionários na lista!";
                else cout << "> Funcionário de nome " << L.removeFim().nome << " removido do final da lista com sucesso!";
                break;

            case 5: {
                int num;
                cout << "MOSTRAR..." << endl;
                cout << "#################################################" << endl;
                cout << "# 0: lista de funcionários                      #" << endl;
                cout << "# 1: primeiro funcionário da lista              #" << endl;
                cout << "# 2: último funcionário da lista                #" << endl;
                cout << "# 3: funcionários com salário MENOR que a média #" << endl;
                cout << "# 4: lista INVERTIDA de funcionários            #" << endl;
                cout << "# 5: lista de funcionários ordenados pela idade #" << endl;
                cout << "#################################################" << endl << endl;
                do {
                    cout << ">> Insira um dos números da lista acima: ";
                    cin >> num;
                    if(num < 0 || num > 5) cout << "!!! NÚMERO INSERIDO INVÁLIDO !!!\n";
                    else break;
                } while(true);
                system("cls");

                if(num == 0) {
                    L.mostrar("Lista de funcionários", colunas, 2, 'T');
                } else if(num == 1) {
                    L.mostrar("Primeiro funcionário registrado", colunas, 2, 'I');
                } else if(num == 2) {
                    L.mostrar("Último funcionário registrado", colunas, 2, 'F');
                } else if(num == 3) {
                    if(L.tam == 0) cout << "> NÃO HÁ funcionários na lista!";
                    else mostrarFuncMedia(&L, mediaTot(&L), colunas);
                } else if(num == 4) {
                    L.mostrarDesdeFim("Lista INVERTIDA de funcionários", colunas, 2);
                } else {
                    mostrarFuncIdade(&L, colunas);
                } getchar();
                break;
            }

            case 6:
                if(L.tam == 0) cout << "> NÃO HÁ funcionários na lista!";
                else cout << "> Média salarial (aritmética): R$ " << mediaTot(&L);
                break;

            case 7:
                L.ordenar(nomeMenor);
                break;

        }; getchar();
    }
    while(menu != 0);
}

