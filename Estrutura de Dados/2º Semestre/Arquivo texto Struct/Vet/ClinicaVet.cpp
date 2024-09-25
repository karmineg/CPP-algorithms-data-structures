#include<iostream>
#include<fstream>
using namespace std;
#include"fila-dinamica.hpp"
#include"pilha-dinamica.hpp"

struct Ficha {
    string nome;
    int idade;
    string tipo;
    string estado;
};

void mostrarFichas(NoF<Ficha>* F, string tipo) {
    if(F == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |          Nome |    Idade |          Tipo |        Estado \n";
        cout << "--------------|---------------|----------|---------------|---------------\n";
        while(F != NULL) {
            Ficha f = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(14) << f.nome << " |";
            cout << setfill(' ') << std::setw(9) << f.idade << " |";
            cout << setfill(' ') << std::setw(14) << f.tipo << " |";
            cout << setfill(' ') << std::setw(14) << f.estado << endl;
            F = F->prox;
        } cout << endl;
    }
}

void mostrarAtendidas(No<Ficha>* P, string tipo) {
    if(P == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |          Nome |    Idade |          Tipo |        Estado \n";
        cout << "--------------|---------------|----------|---------------|---------------\n";
        while(P != NULL) {
            Ficha f = P->dado;
            cout << setfill(' ') << std::setw(13) << P << " |";
            cout << setfill(' ') << std::setw(14) << f.nome << " |";
            cout << setfill(' ') << std::setw(9) << f.idade << " |";
            cout << setfill(' ') << std::setw(14) << f.tipo << " |";
            cout << setfill(' ') << std::setw(14) << f.estado << endl;
            P = P->prox;
        } cout << endl;
    }
}

void Listaunificada(NoF<Ficha>* Fn, NoF<Ficha>* Fp) {
    if(Fn == NULL && Fp == NULL) cout << "ERRO: Filas vazias";
    else {
        float totalT = 0, totalP = 0, totalD = 0;

        while(Fp != NULL) {
            totalP++;
            if((Fp->dado).tipo == "Doméstico") totalD++;
            Fp = Fp->prox;
        }
        while(Fn != NULL) {
            totalT++;
            if((Fn->dado).tipo == "Doméstico") totalD++;
            Fn = Fn->prox;
        }
        totalT += totalP;

        cout << " Total de fichas                        | " << totalT << endl;
        cout << "----------------------------------------|---------------\n";
        cout << " Total de animais domésticos            | " << totalD << endl;
        cout << "----------------------------------------|---------------\n";
        cout << " Porcentagem de animais em estado grave | " << (100.0*totalP/totalT) << "%\n";
    }
}

int adicionaAnimal(int* menor, No<Ficha>* ANIM) {
    Ficha F = ANIM->dado;
    int idade = F.idade;
    if(F.estado == "Grave") {
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

void animalmaisNovo(No<Ficha>* animS, No<Ficha>* animD) {
    if(animS == NULL && animD == NULL) cout << "ERRO: Não há animais atendidos em 'MENORIDADE'";
    else {
        No<No<Ficha>*>* ANIM = nullptr;
        int *menor = new int(-1);
        int qtdS = 0;
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

        if(*menor == -1) cout << "ERRO: não foi encontrado animais em estado grave";
        else {
            cout << "Menor idade encontrada: " << *menor;
            if(qtdS > 0) {
                cout << "\nAnimais selvagens: ";
                for(qtdS; qtdS > 0; qtdS--) {
                    cout << (ANIM->dado->dado).nome << ", ";
                    ANIM = ANIM->prox;
                }
            }
            if(ANIM != NULL) {
                cout << "\nAnimais domésticos: ";
                do {
                    cout << (ANIM->dado->dado).nome << ", ";
                    ANIM = ANIM->prox;
                } while(ANIM != NULL);
            }
        }
    }
}

void lerArquivo(NoF<Ficha>* Fp, NoF<Ficha>* Fn, No<Ficha>* animS, No<Ficha>* animD) {
    cout << "#####################################################\n";
    cout << "##               CLINICA VETERINARIA               ##\n";
    cout << "#####################################################\n\n";

    string arch = "entrada.txt";
    ifstream leitor;
    leitor.open(arch, ios::out);

    while(!leitor.eof()) {
        string linha;
        getline(leitor, linha);

        string acao;
        stringstream ss(linha);
        getline(ss, acao, ' ');

        if(acao == "MOSTRAR") {
            mostrarFichas(Fp, "Fichas prioritárias");
            mostrarFichas(Fn, "Fichas não prioritárias");
        }
        else if(acao == "ATENDER") {
            string num;
            getline(ss, num, ' ');
            int qtd = stoi(num);
            int C = 0;

            if(Fp != NULL) {
                if(Fn != NULL) {
                    int QTD = 0;
                    if(qtd <= 0) cout << "ERRO: Remova, pelo menos, uma ficha da fila";
                    else if(qtd > 3) cout << "ERRO: Quantidade maior do que 3 (máximo)";
                    else {
                        while(Fp != NULL && QTD < qtd) {
                            Ficha F = Fp->dado;
                            if((Fp->dado).tipo == "Selvagem") animS = adicionaP(animS, F);
                            else animD = adicionaP(animD, F);
                            cout << "O animal " << F.tipo << " de nome '" << F.nome << "' em estado " << F.estado << " foi atendido" ;
                            Fp = removeF(Fp);
                            QTD++;
                        } C += QTD;

                        if(C >= 3) {
                            Ficha F = Fn->dado;
                            if((Fn->dado).tipo == "Selvagem") animS = adicionaP(animS, F);
                            else animD = adicionaP(animD, F);
                            cout << "O animal " << F.tipo << " de nome '" << F.nome << "' em estado " << F.estado << " foi atendido" ;
                            Fn = removeF(Fn);
                            C -= 3;
                        }
                        else {
                            if(qtd <= 0) cout << "ERRO: Remova, pelo menos, uma ficha da fila";
                            else {
                                while(Fp != NULL && qtd > 0) {
                                    Ficha F = Fn->dado;
                                    if((Fp->dado).tipo == "Selvagem") animS = adicionaP(animS, F);
                                    else animD = adicionaP(animD, F);
                                    cout << "O animal " << F.tipo << " de nome '" << F.nome << "' em estado " << F.estado << " foi atendido" ;
                                    Fp = removeF(Fp);
                                    qtd--;
                                } C = 0;
                            }
                        }
                    }
                }
            }
            else {
                if(Fn != NULL) {
                    Ficha F = Fn->dado;
                    if((Fn->dado).tipo == "Selvagem") animS = adicionaP(animS, F);
                    else animD = adicionaP(animD, F);
                    cout << "O animal " << F.tipo << " de nome '" << F.nome << "' em estado " << F.estado << " foi atendido" ;
                    Fn = removeF(Fn);
                    C = 0;
                }
                else cout << "ERRO: Nenhuma ficha para ser atentida";
            }
        }
        else if(acao == "LISTARUNI") {
            Listaunificada(Fn, Fp);
        }
        else if(acao == "LISTARJA") {
            mostrarAtendidas(animS, "Fichas já atendidas de animais selvagens");
            mostrarAtendidas(animD, "Fichas já atendidas de animais domésticos");
        }
        else if(acao == "REGISTRAR") {
            string nome;
            getline(ss, nome, ' ');

            string num;
            getline(ss, num, ' ');
            int idade = stoi(num);

            string tipo;
            getline(ss, tipo, ' ');

            string estado;
            getline(ss, estado);

            if(idade < 0) cout << "ERRO: A idade não pode ser negativa em 'REGISTRAR'";
            else {
                if(tipo != "S" && tipo != "D") cout << "Opção para tipo do animal inválida em 'REGISTRAR'";
                else {
                    string newTipo;
                    if(tipo == "S") newTipo = "Selvagem";
                    else newTipo = "Doméstico";

                    if(estado != "E" && estado != "G") cout << "Opção para estado do animal inválida em 'REGISTRAR'";
                    else {
                        string newEstado;
                        if(estado == "E") newEstado = "Estável";
                        else newEstado = "Grave";

                        Ficha A = { nome, idade, newTipo, newEstado };
                        if(estado == "E") Fn = adicionaF(Fn, A);
                        else Fp = adicionaF(Fp, A);

                        cout << "Ficha do animal " << newTipo << " de nome '" << nome << "' e idade " << idade << " em estado " << newEstado << " foi registrado";
                    }
                }
            }
        }
        else if(acao == "MENORIDADE") {
            animalmaisNovo(animS, animD);
        }
        else if(acao == "REMOVER") {
            string T;
            getline(ss, T);

            if(T != "S" && T != "D") cout << "ERRO: Opção inserida inválida em 'REMOVER'";
            else {
                if(T == "S") {
                    if(animS == NULL) cout << "ERRO: Não há ficha de animais selvagens para remoção";
                    else {
                        cout << "Removido da pilha o animal selvagem de nome " << (animS->dado).nome;
                        animS = removeP(animS);
                    }
                } else {
                    if(animD == NULL) cout << "ERRO: Não há ficha de animais domésticos para remoção";
                    else {
                        cout << "Removido da pilha o animal doméstico de nome " << (animD->dado).nome;
                        animD = removeP(animD);
                    }
                }
            }
        }
        else {
               cout << "Função inválida";
        }
        cout << endl << "========================================================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    NoF<Ficha>* Fp = nullptr;
    NoF<Ficha>* Fn = nullptr;
    No<Ficha>* animS = nullptr;
    No<Ficha>* animD = nullptr;

    lerArquivo(Fp, Fn, animS, animD);
}
