#include<iostream>
using namespace std;

#include "pilha-template.hpp"
#include "filadinamica-template.hpp"

struct Ficha {
    string nome;
    int idade;
    char C; // Atributo variável (pode ser tipo ou estado)
};

string funcTipo(char C) {
    if(C == 'S') return "Selvagem";
    return "Doméstico";
}
string funcEstado(char C) {
    if(C == 'E') return "Estável";
    return "Grave";
}
void mostrarAttr(string prop, string nome) {
    cout << "\n\n>> " << nome << "\n\n";
    cout << "     Endereço |            Nome |        Idade |";
    cout << setfill(' ') << std::setw(16) << prop + "\n";
    cout << "--------------|-----------------|--------------|--------------\n";
}
template<typename N> void mostrarItem(N* F, string(*funcProp)(char)) {
    Ficha D = F->dado;
    cout << setfill(' ') << std::setw(13) << F << " |";
    cout << setfill(' ') << std::setw(16) << D.nome << " |";
    cout << setfill(' ') << std::setw(13) << D.idade << " |";
    cout << setfill(' ') << std::setw(13) << funcProp((F->dado).C) << endl;
    F = F->prox;
}
template<typename N> mostrarFichas(N* F, string prop, string nome, string(*funcProp)(char)) {
    if(F == NULL) cout << "\n\n!!! NÃO há fichas " << nome << " registradas !!!";
    else {
        mostrarAttr(prop, "Lista de fichas " + nome);
        while(F != NULL) {
            mostrarItem(F, funcProp);
            F = F->prox;
        }
    }
}

char ch(NoF<Ficha>* F) {
    return (F->dado).C;
}

void informFicha(NoF<Ficha>* Fp, NoF<Ficha>* Fn) {
    float totalT = 0, totalP = 0, totalD = 0;
    while(Fp != NULL) {
        totalP++;
        if((Fp->dado).C == 'D') totalD++;
        Fp = Fp->prox;
    } while(Fn != NULL) {
        totalT++;
        if((Fn->dado).C == 'D') totalD++;
        Fn = Fn->prox;
    } totalT += totalP;
    cout << " Total de fichas                        | " << totalT << endl;
    cout << "----------------------------------------|---------------\n";
    cout << " Total de animais domésticos            | " << totalD << endl;
    cout << "----------------------------------------|---------------\n";
    cout << " Porcentagem de animais em estado grave | ";
    if(totalT == 0) cout << "SEM ITENS\n";
    else cout << (100.0*totalP/totalT) << "%\n";
}

int adicionaAnimal(int* menor, No<Ficha>* ANIM) {
    Ficha D = ANIM->dado;
    int idade = D.idade;
    if(D.C == 'G') {
        if(*menor == -1) {
            *menor = idade;
            return 1;
        } else {
            if(*menor >= idade) {
                if(*menor > idade) {
                    *menor = idade;
                    return 2;
                } return 1;
            }
        }
    } return 0;
}

void mostrarNomeAnim(No<Ficha>* F) {
    cout << "\n ** " << (F->dado).nome << " (Endereço " << F << ")";
}

No<Ficha>* adicionaAnim(No<Ficha>* F, Ficha D, char E) {
    D.C = E;
    return adicionaP(F, D);
}

void animalNovo(No<Ficha>* animS, No<Ficha>* animD) { // Pegar o animal em estado grave mais novo
    if(animS == NULL && animD == NULL) cout << "!!! NÃO HÁ itens em nenhuma das pilhas !!!";
    else {
        No<No<Ficha>*>* ANIM = nullptr;
        int *menor = new int(-1);
        int qtdS = 0;
        // ANALISA QUAIS OS ANIMAIS COM MENOR IDADE
        while(animS != NULL) {
            int ind = adicionaAnimal(menor, animS);
            if(ind >= 1) {
                if(ind == 2) {
                    qtdS = 0;
                    ANIM = destroiP(ANIM);
                } ANIM = adicionaP(ANIM, animS);
                qtdS++;
            } animS = animS->prox;
        } while(animD != NULL) {
            int ind = adicionaAnimal(menor, animD);
            if(ind >= 1) {
                if(ind == 2) ANIM = destroiP(ANIM);
                ANIM = adicionaP(ANIM, animD);
            } animD = animD->prox;
        }
        // MOSTRAR ANIMAIS
        if(*menor == -1) cout << "!!! NÃO foi encontrado animais em estado grave !!!";
        else {
            cout << ">> Menor idade encontrada: " << *menor;
            if(qtdS > 0) {
                cout << "\n\n>> Animais selvagens: ";
                for(qtdS; qtdS > 0; qtdS--) {
                    mostrarNomeAnim(ANIM->dado);
                    ANIM = ANIM->prox;
                }
            } if(ANIM != NULL) {
                cout << "\n\n>> Animais domésticos: ";
                do {
                    mostrarNomeAnim(ANIM->dado);
                    ANIM = ANIM->prox;
                } while(ANIM != NULL);
            }
        }
    }
}

main() {
    system ("color F2");
    //setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    int C = 0;
    char tipo;

    NoF<Ficha>* Fp = nullptr,
    * Fn = nullptr;
    No<Ficha>* animS = nullptr,
    * animD = nullptr;

    do {
        system("cls");
        cout << "#########################MENU DE OPÇÕES#########################" << endl;
        cout << "# 0 - Sair                                                     #" << endl;
        cout << "# 1 - Criar ficha de atendimento e adicionar na fila           #" << endl;
        cout << "# 2 - Atender ficha da fila                                    #" << endl;
        cout << "# 3 - Mostrar os dados das fichas de atendimento das filas     #" << endl;
        cout << "# 4 - Listar as informações sobre as filas de forma unificada  #" << endl;
        cout << "# 5 - Listar as fichas já atendidas                            #" << endl;
        cout << "# 6 - Remover uma ficha da pilha                               #" << endl;
        cout << "# 7 - Mostrar o nome do animal em estado grave com menor idade #" << endl;
        cout << "################################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "Programa finalizado.";
                break;
            case 1: {
                // Nome
                string nome;
                cout << "> Dados para a ficha clínica\n\n> Informe o nome do animal: ";
                getline(cin, nome);
                // Idade
                int idade;
                do {
                    cout << "> Informe a idade do animal(em anos): ";
                    cin >> idade;
                    if(idade < 0) cout << "!!! A idade não pode ser negativa !!!\n";
                    else break;
                } while(true);
                // Tipo
                char tipo;
                do {
                    cout << "> Informe o tipo do animal ('S' para selvagem, 'D' para doméstico): ";
                    cin >> tipo;
                    tipo = toupper(tipo);
                    if(tipo != 'S' && tipo != 'D') cout << "!!! Opção inserida INVÁLIDA !!!\n";
                    else break;
                } while(true);
                // Quadro clínico
                char estado;
                do {
                    cout << "> Informe o quadro clínico do animal ('E' para estável, 'G' para grave): ";
                    cin >> estado;
                    estado = toupper(estado);
                    if(estado != 'E' && estado != 'G') cout << "!!! Opção inserida INVÁLIDA !!!\n";
                    else break;
                } while(true);

                Ficha D = { nome, idade, tipo };
                if(estado == 'E') Fn = adicionaF(Fn, D);
                else Fp = adicionaF(Fp, D);

                cout << "\n> Ficha registrada!";
                getchar();
                break;
            }

            case 2: {
                if(Fp != NULL) { // Fila prioritária NÃO está vazia!!
                    int qtd;
                    if(Fn != NULL) { // Fila NÃO prioritária NÃO está vazia!! (No máximo, 3 prioritárias e 1 não p.)
                        int QTD = 0;
                        do {
                            cout << ">> Atender quantas fichas prioritárias? (Máximo três fichas) ";
                            cin >> qtd;
                            if(qtd <= 0) cout << "!!! REMOVER, pelo menos, uma ficha !!!\n";
                            else if(qtd > 3) cout << "!!! Considerando que HÁ !!!\n";
                            else break;
                        } while(true);

                        // Mostrar fichas PRIORITÁRIAS removidas e contar
                        mostrarAttr("Tipo", "Fichas prioritárias ATENDIDAS");
                        while(Fp != NULL && QTD < qtd) {
                            mostrarItem(Fp, funcTipo);
                            // Retirando da fila dos graves
                            if(ch(Fp) == 'S') animS = adicionaAnim(animS, Fp->dado, 'G');
                            else animD = adicionaAnim(animD, Fp->dado, 'G');
                            Fp = removeF(Fp);
                            QTD++;
                        } C += QTD;
                        // Mostrar ficha NÃO prioritária
                        if(C >= 3) {
                            mostrarAttr("Tipo", "Ficha não prioritária ATENDIDA");
                            mostrarItem(Fn, funcTipo);
                            // Retirando da fila dos estáveis
                            if(ch(Fn) == 'S') animS = adicionaAnim(animS, Fn->dado, 'E');
                            else animD = adicionaAnim(animD, Fn->dado, 'E');
                            Fn = removeF(Fn);
                            C -= 3;
                        }
                    } else { // Fila NÃO prioritária VAZIA!! (Prioritárias indefinida)
                        do {
                            cout << ">> Atender quantas fichas prioritárias? (Sem limite máximo) ";
                            cin >> qtd;
                            if(qtd <= 0) cout << "!!! REMOVER, pelo menos, uma ficha !!!\n";
                            else break;
                        } while(true);

                        // Mostrar fichas PRIORITÁRIAS removidas e contar
                        mostrarAttr("Tipo", "Fichas prioritárias ATENDIDAS");
                        while(Fp != NULL && qtd > 0) {
                            mostrarItem(Fp, funcTipo);
                            // Retirando da fila dos graves
                            if(ch(Fp) == 'S') animS = adicionaAnim(animS, Fp->dado, 'G');
                            else animD = adicionaAnim(animD, Fp->dado, 'G');
                            Fp = removeF(Fp);
                            qtd--;
                        } C = 0; // Zerar contagem de prioritários
                    }
                } else { // Fila NÃO prioritária VAZIA!! (Uma ficha por vez)
                    if(Fn != NULL) {
                        mostrarAttr("Tipo", "Ficha não prioritárias ATENDIDA");
                        mostrarItem(Fn, funcTipo);
                        // Retirando da fila dos estáveis
                        if(ch(Fn) == 'S') animS = adicionaAnim(animS, Fn->dado, 'E');
                        else animD = adicionaAnim(animD, Fn->dado, 'E');
                        Fn = removeF(Fn);
                        C = 0; // Aqui também zerar contagem de prioritários
                    } else cout << "!!! NENHUMA FICHA PARA SER ATENDIDA !!!";
                } getchar();
                break;
            }

            case 3:
                cout << ">> FICHAS REGISTRADAS:";
                mostrarFichas(Fp, "Tipo", "prioritárias", funcTipo);
                mostrarFichas(Fn, "Tipo", "não prioritárias", funcTipo);
                break;

            case 4: {
                informFicha(Fp, Fn);
                break;
            }
            case 5:
                cout << ">> FICHAS JÁ ATENDIDAS:";
                mostrarFichas(animS, "Estado", "de animais selvagens", funcEstado);
                mostrarFichas(animD, "Estado", "de animais domésticos", funcEstado);
                break;

            case 6: {
                char C;
                do {
                    cout << "Qual pilha você deseja acessar para remover uma ficha? ('S' para selvagens, 'D' para dom�sticos) ";
                    cin >> C;
                    C = toupper(C);
                    if(C != 'S' && C != 'D') cout << "!!! Opção inserida INV�LIDA !!!\n";
                    else break;
                } while(true);

                if(C == 'S') {
                    if(animS == NULL) cout << "!!! NÃO HÁ ficha de animais selvagens para REMOVER !!!";
                    else {
                        mostrarAttr("Estado", "Ficha de animal selvagem REMOVIDA");
                        mostrarItem(animS, funcEstado);
                        animS = removeP(animS);
                    }
                } else {
                    if(animD == NULL) cout << "!!! NÃO HÁ ficha de animais domésticos para REMOVER !!!";
                    else {
                        mostrarAttr("Estado", "Ficha de animal doméstica REMOVIDA");
                        mostrarItem(animD, funcEstado);
                        animD = removeP(animD);
                    }
                } getchar();
                break;
            }

            case 7:
                animalNovo(animS, animD);
                break;

            default:
                cout << "> Opção inválida!";

        }; getchar();
    }
    while(menu != 0);
}
