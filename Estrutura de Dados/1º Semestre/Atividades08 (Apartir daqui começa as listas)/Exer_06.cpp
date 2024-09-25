/*6. Um grupo de pesquisa em seguran�a da informa��o est� estudando a frequ�ncia de uso de senhas
semelhantes pelos usu�rios de um determinado sistema. Assim, foi criada uma lista contendo as
senhas dos usu�rios. Uma das an�lises a ser realizada � a verifica��o de senhas n�o seguras. Uma
senha pode ser considerada �n�o segura� se ela possuir uma quantidade muito pequena de
caracteres ou for utilizada por uma quantidade muito grande de usu�rios. Para classificar as senhas
n�o seguras, voc� deve criar uma lista simplesmente encadeada contendo todas as senhas com
menos de 4 caracteres ou cuja frequ�ncia de utiliza��o � maior que 5 (ou seja, senhas que aparecem
mais que cinco vezes na lista). Crie a fun��o naoSeguras que recebe uma lista de senhas e retorna
outra lista contendo todas as senhas n�o seguras existentes. */

#include<iostream>
using namespace std;

#include "lista-template.hpp"

struct Maior { // "Struct" que armazena a senha com quatro d�gitos, pelo menos
    string senha; // Senha
    int cont; // Contador
};

struct Insegura {
    string senha;
    string motivo;
};

ostream& operator << (ostream &o, Insegura &s) { return o << s.senha << " |" << setfill(' ') << setw(24) << s.motivo; }

void removerString(No<string>** L1, string(*funcao)(No<string>**)) {
    if(*L1 != NULL) cout << "!!! Senha '" << funcao(L1) << "' removido  com sucesso !!!";
    else cout << "!!! Lista de senhas EST� VAZIA !!!";
}

void adicionarMaior(No<Maior>** maiores, string s) {
    No<Maior>* m = *maiores;
    // Analisar se senha j� foi contabilizada antes
    while(m != NULL) {
        Maior D = m->dado;
        if(D.senha == s) {
            (m->dado).cont++;
            return;
        } m = m->prox;
    } // Criar novo "maior" (iniciando contagem)
    Maior M = { s, 1 };
    adicionarFim(maiores, M);
}

bool existeS(No<Insegura>* L, string dado) { // Fun��o que retorna os endere�os dos n�s que possuem o valor
    while(L != NULL) {
        if((L->dado).senha == dado) return true; // Encontrado uma ocorr�ncia do elemento na lista
        L = L->prox;
    } return false;
}

No<Insegura>** senhasInseguras(No<string>* S) {
    No<Insegura>** inseg = new No<Insegura>*();
    No<Maior>** maiores = new No<Maior>*();

    while(S != NULL) {
        string s = S->dado;
        if(!existeS(*inseg, s) && s.length() < 4) {
            string motivo = "Apenas " + to_string(s.length()) + " d�gito(s)";
            Insegura I = { s, motivo };
            adicionarFim(inseg, I); // Se o comprimento � menor que quatro, automaticamente adicionar como inseguro
        } else adicionarMaior(maiores, s); // Caso contr�rio, fazer a contagem
        S = S->prox;
    }

    while(*maiores != NULL) {
        Maior M = (*maiores)->dado;
        if(M.cont > 5) {
            string motivo = "Encontrado " + to_string(M.cont) + " vezes";
            Insegura I = { M.senha, motivo };
            adicionarFim(inseg, I);
        } *maiores = (*maiores)->prox;
    }

    return inseg;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<string>** S = new No<string>*();

    do
    {
        system("cls");
        cout << "#########MENU DE OP��ES###########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Adicionar uma senha        #" << endl;
        cout << "# 2 - Remover �ltima senha       #" << endl;
        cout << "# 3 - Remover primeira senha     #" << endl;
        cout << "# 4 - Mostrar Senhas N�O seguras #" << endl;
        cout << "# 5 - Mostrar todas as senhas    #" << endl;
        cout << "##################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu) {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: {
                string novaS;
                cout << ">> Digite uma nova senha: ";
                cin >> novaS;
                adicionarFim(S, novaS);
                cout << "!!! Senha adicionada com SUCESSO !!!";
                getchar();
                break;
            }

            case 2:
                removerString(S, removeFim);
                break;

            case 3:
                removerString(S, removeInicio);
                break;

            case 4:
                mostrar(*senhasInseguras(*S), "Lista de senhas N�O seguras", "          Senha |                  Motivo", 2);
                break;

            case 5:
                mostrar(*S, "Lista de todas as senhas", "          Senha", 0);
                break;

            default:
                cout << "!!! Op��o inv�lida !!!";
        } getchar();
    } while(menu != 0);
}
