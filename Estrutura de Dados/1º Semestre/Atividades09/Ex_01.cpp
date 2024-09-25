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

// "Overloading" para mostrar struct DIRETO pelo m�todo "cout"
ostream& operator << (ostream &o, funcionario &f) {
    return o << f.codigo << " |" << setfill(' ') << setw(11) << f.nome << " |" <<
                setfill(' ') << setw(11) << f.idade << " |" << setfill(' ') << setw(14) << f.salario;
}

// FUN��ES PARA CRIAR NOVO FUNCION�RIO
bool BuscaCod(int codigo, ListaD<funcionario>* L) {
    NoD<funcionario> *F = L->inicio;
    while(F != NULL) {
        if (codigo == (F->dado).codigo) return true;
        F = F->prox;
    }
    return false;
}

funcionario novoFunc(ListaD<funcionario>* L) {
    // Inserir c�digo (N�O pode ser repetido, chave prim�ria)
    int codigo;
    do {
        cout << "> Digite o c�digo do funcion�rio: ";
        cin >> codigo;
        bool existe = BuscaCod(codigo, L);
        if (existe == true) cout << "Esse c�digo j� foi inserido!\n";
        else break;
    } while(true);

    // Inserir nome
    string nome;
    cout << "> Digite o nome do funcion�rio: ";
    cin.ignore();
    getline(cin, nome);

    // Inserir idade (n�o pode ser nulo/negativo)
    int idade;
    do {
        cout << "> Digite a idade do funcion�rio: ";
        cin >> idade;
        if (idade <= 0) cout << "Idade inserida inv�lida!\n";
        else break;
    } while(true);

    // Inserir sal�rio (n�o pode ser nulo/negativo)
    float salario;
        do {
        cout << "> Digite o sal�rio do funcion�rio: ";
        cin >> salario;
        if (salario <= 0) cout << "Sal�rio inserido inv�lido!\n";
        else break;
    } while(true);

    // Criar funcion�rio
    funcionario F = {codigo, nome, idade, salario};
    return F;
}

// FUN��O IMPORTANTE PARA ORDENA��O DE FUNCION�RIOS
bool nomeMenor(funcionario N, funcionario M) { return (N.nome < M.nome); }
bool idadeMenor(funcionario N, funcionario M) { return (N.idade < M.idade); }

// FUN��ES ENVOLVENDO SAL�RIO (C�LCULO DE M�DIA E EXIBI��O DE FUNCION�RIOS)
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
    cout << ">> M�dia salarial: R$ " << media << endl << endl;
    do {
        if((N->dado).salario < media) {
            exib = true;
            qtd = L->mostrarColunas("Funcion�rios com sal�rio MENOR que a m�dia", colunas, false);
            mostrarItem(N, qtd, 2);
            N = N->prox;
            break;
        } else N = N->prox;
    } while(N != NULL);

    while(N != NULL) {
        if((N->dado).salario < media) mostrarItem(N, qtd, 2);
        N = N->prox;
    }

    if(!exib) cout << "!!! N�o h� funcion�rios com sal�rio abaixo da m�dia (TODOS tem mesmo sal�rio) !!!";
}

void mostrarFuncIdade(ListaD<funcionario>* L, string colunas) {
    NoD<funcionario> *N = L->inicio;
    ListaD<funcionario> M;
    while(N != NULL) {
        M.adFim(N->dado);
        N = N->prox;
    } M.ordenar(idadeMenor);
    M.mostrar("Funcion�rios ordenados pela idade", colunas, 2, 'T');
}

int main () {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    string colunas = " C�digo |       Nome |      Idade |      Sal�rio ";

    ListaD<funcionario> L;

    do
    {
        system("cls");
        cout << "######################MENU DE OP��ES#######################" << endl;
        cout << "# 0 - Sair                                                #" << endl;
        cout << "# 1 - Inserir funcion�rio no in�cio da lista              #" << endl;
        cout << "# 2 - Inserir funcion�rio no final da lista               #" << endl;
        cout << "# 3 - Remover o funcion�rio do in�cio da lista            #" << endl;
        cout << "# 4 - Remover o funcion�rio do final da lista             #" << endl;
        cout << "# 5 - Mostrar funcion�rios da lista                       #" << endl;
        cout << "# 6 - Mostrar m�dia dos sal�rios                          #" << endl;
        cout << "# 7 - Ordenar lista de funcion�rios pelo nome             #" << endl;
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
                cout << "> Funcion�rio registrado com sucesso!";
                getchar();
                break;

            case 2:
                L.adFim(novoFunc(&L));
                cout << "> Funcion�rio registrado com sucesso!";
                getchar();
                break;

            case 3:
                if(L.tam == 0) cout << "> N�O H� funcion�rios na lista!";
                else cout << "> Funcion�rio de nome " << L.removeInicio().nome << " removido do in�cio da lista com sucesso!";
                break;

            case 4:
                if(L.tam == 0) cout << "> N�O H� funcion�rios na lista!";
                else cout << "> Funcion�rio de nome " << L.removeFim().nome << " removido do final da lista com sucesso!";
                break;

            case 5: {
                int num;
                cout << "MOSTRAR..." << endl;
                cout << "#################################################" << endl;
                cout << "# 0: lista de funcion�rios                      #" << endl;
                cout << "# 1: primeiro funcion�rio da lista              #" << endl;
                cout << "# 2: �ltimo funcion�rio da lista                #" << endl;
                cout << "# 3: funcion�rios com sal�rio MENOR que a m�dia #" << endl;
                cout << "# 4: lista INVERTIDA de funcion�rios            #" << endl;
                cout << "# 5: lista de funcion�rios ordenados pela idade #" << endl;
                cout << "#################################################" << endl << endl;
                do {
                    cout << ">> Insira um dos n�meros da lista acima: ";
                    cin >> num;
                    if(num < 0 || num > 5) cout << "!!! N�MERO INSERIDO INV�LIDO !!!\n";
                    else break;
                } while(true);
                system("cls");

                if(num == 0) {
                    L.mostrar("Lista de funcion�rios", colunas, 2, 'T');
                } else if(num == 1) {
                    L.mostrar("Primeiro funcion�rio registrado", colunas, 2, 'I');
                } else if(num == 2) {
                    L.mostrar("�ltimo funcion�rio registrado", colunas, 2, 'F');
                } else if(num == 3) {
                    if(L.tam == 0) cout << "> N�O H� funcion�rios na lista!";
                    else mostrarFuncMedia(&L, mediaTot(&L), colunas);
                } else if(num == 4) {
                    L.mostrarDesdeFim("Lista INVERTIDA de funcion�rios", colunas, 2);
                } else {
                    mostrarFuncIdade(&L, colunas);
                } getchar();
                break;
            }

            case 6:
                if(L.tam == 0) cout << "> N�O H� funcion�rios na lista!";
                else cout << "> M�dia salarial (aritm�tica): R$ " << mediaTot(&L);
                break;

            case 7:
                L.ordenar(nomeMenor);
                break;

        }; getchar();
    }
    while(menu != 0);
}

