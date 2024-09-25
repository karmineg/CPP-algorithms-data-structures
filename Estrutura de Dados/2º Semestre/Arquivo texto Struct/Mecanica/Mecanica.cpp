#include<iostream>
#include<fstream>
using namespace std;
#include"fila-dinamica.hpp"
#include"pilha-dinamica.hpp"

struct PF {
    string cpf;
    string placa;
    string pacote;
};

struct PJ {
    string cnpj;
    string placa;
};

struct FichaPF {
    PF pessoa;
    float valor;
    int quantidade;
};

struct FichaPJ {
    PJ pessoa;
    float valor;
    int quantidade;
};

void mostrarPessoasF(NoF<PF>* F, string tipo) {
    if(F == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |          CPF |       Placa |  Adiquiriu pacote \n";
        cout << "--------------|--------------|-------------|-------------------\n";
        while(F != NULL) {
            PF f = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(13) << f.cpf << " |";
            cout << setfill(' ') << std::setw(12) << f.placa << " |";
            cout << setfill(' ') << std::setw(18) << f.pacote << endl;
            F = F->prox;
        } cout << endl;
    }
}

void mostrarPessoasJ(NoF<PJ>* F, string tipo) {
    if(F == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |           CNPJ |       Placa \n";
        cout << "--------------|----------------|-------------\n";
        while(F != NULL) {
            PJ f = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(15) << f.cnpj << " |";
            cout << setfill(' ') << std::setw(12) << f.placa << endl;
            F = F->prox;
        } cout << endl;
    }
}

void Listaunificada(NoF<PF>* Fp, NoF<PF>* Fn) {
    if(Fp == NULL && Fn == NULL) cout << "ERRO: Filas vazias em 'LISTARUNIFICADO'";
    else {
        int totalP = 0, totalS = 0, totalN = 0;

        while(Fp != NULL) {
            totalP++;
            totalS++;
            Fp = Fp->prox;
        }
        while(Fn != NULL) {
            totalP++;
            totalN++;
            Fn = Fn->prox;
        }

        cout << " Total de pessoas                             | " << totalP << endl;
        cout << "----------------------------------------------|---------------\n";
        cout << " Total de pessoas que adquiriram o pacote     | " << totalS << endl;
        cout << "----------------------------------------------|---------------\n";
        cout << " Total de pessoas que não adquiriram o pacote | " << totalN << endl;
        cout << "----------------------------------------------|---------------\n";
    }
}

void Atendidas(No<FichaPF>* CARROPF, string tipo) {
 if(CARROPF == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        No<FichaPF>* Paux = nullptr;

        while(CARROPF != NULL) {
            FichaPF f = CARROPF->dado;
            Paux = adicionaP(Paux, f);
            CARROPF = CARROPF->prox;
        }

        cout << tipo << "\n";
        cout << "     Endereço |          CPF |       Placa |  Adiquiriu pacote |       Valor |  Quant. peças \n";
        cout << "--------------|--------------|-------------|-------------------|-------------|---------------\n";
        while(Paux != NULL) {
            FichaPF f = Paux->dado;
            cout << setfill(' ') << std::setw(13) << Paux << " |";
            cout << setfill(' ') << std::setw(13) << (f.pessoa).cpf << " |";
            cout << setfill(' ') << std::setw(12) << (f.pessoa).placa << " |";
            cout << setfill(' ') << std::setw(18) << (f.pessoa).pacote << " |";
            cout << "RS " << setfill(' ') << std::setw(9) << f.valor << " |";
            cout << setfill(' ') << std::setw(13) << f.quantidade << endl;
            Paux = Paux->prox;
        } cout << endl;
    }
}

void Soma(No<FichaPF>* CARROPF) {
    if(CARROPF == NULL) cout << "ERRO: Fichas atendidas de pessoas físicas está vazio em 'SOMA'";
    else {
        float soma = 0;

        while(CARROPF != NULL){
            FichaPF f = CARROPF->dado;
            soma += f.valor;
            CARROPF = CARROPF->prox;
        }

        cout << "Soma dos valores de todos os serviços já realizados | RS " << soma << endl;
    }
}

void MaiorRev(No<FichaPF>* CARROPF) {
    if(CARROPF == NULL) cout << "ERRO: Fichas atendidas de pessoas físicas está vazio em 'REVISAOMAIOR'";
    else {
        No<FichaPF>* PF = nullptr;
        float maior = (CARROPF->dado).valor;

        while(CARROPF != NULL){
            FichaPF f = CARROPF->dado;
            if(f.valor >= maior) {
                if(f.valor > maior) {
                    maior = f.valor;
                    PF = destroiP(PF);
                }
                PF = adicionaP(PF, f);
            }
            CARROPF = CARROPF->prox;
        }

        cout << "CPF(s) da(s) pessoas(s)  que realizou a revisão com maior valor: \n";
        cout << "         CPF |         Valor |\n";
        cout << "-------------|---------------|\n";
        while(PF != NULL) {
            FichaPF p = PF->dado;
            cout << setfill(' ') << std::setw(12) << (p.pessoa).cpf << " |";
            cout << "RS " << setfill(' ') << std::setw(11) << p.valor << " |" << endl;
            PF = PF->prox;
        } cout << endl;
    }
}

void MenorRev(No<FichaPJ>* CARROPJ) {
    if(CARROPJ == NULL) cout << "ERRO: Fichas atendidas de pessoas jurídicas está vazio em 'REVISAOMENOR'";
    else {
        No<FichaPJ>* PJ = nullptr;
        float menor = (CARROPJ->dado).valor;

        while(CARROPJ != NULL){
            FichaPJ j = CARROPJ->dado;
            if(menor >= j.valor) {
                if(j.valor < menor) {
                    menor = j.valor;
                    PJ = destroiP(PJ);
                }
                PJ = adicionaP(PJ, j);
            }
            CARROPJ = CARROPJ->prox;
        }

        cout << "CNPJ(s) da(s) empresas(s) que realizou a revisão com menor valor: \n";
        cout << "          CNPJ |         Valor |\n";
        cout << "---------------|---------------|\n";
        while(PJ != NULL) {
            FichaPJ p = PJ->dado;
            cout << setfill(' ') << std::setw(13) << (p.pessoa).cnpj << " |";
            cout << "RS " << setfill(' ') << std::setw(11) << p.valor << " |" << endl;
            PJ = PJ->prox;
        } cout << endl;

    }
}

void MaiorPecas(No<FichaPF>* CARROPF, No<FichaPJ>* CARROPJ) {
    if(CARROPF == NULL && CARROPJ == NULL) cout << "ERRO: Fichas atendidas vazias em 'MAIORPECAS'";
    else {
        No<string>* P = nullptr;
        No<int>* Q = nullptr;
        float maior = (CARROPF->dado).quantidade;

        while(CARROPF != NULL){
            FichaPF f = CARROPF->dado;
            if(f.quantidade >= maior) {
                if(f.quantidade > maior) {
                    maior = f.quantidade;
                    P = destroiP(P);
                    Q = destroiP(Q);
                }
                P = adicionaP(P, (f.pessoa).placa);
                Q = adicionaP(Q, f.quantidade);
            }
            CARROPF = CARROPF->prox;
        }

        while(CARROPJ != NULL){
            FichaPJ j = CARROPJ->dado;
            if(j.quantidade >= maior) {
                if(j.quantidade > maior) {
                    maior = j.quantidade;
                    P = destroiP(P);
                    Q = destroiP(Q);
                }
                P = adicionaP(P, (j.pessoa).placa);
                Q = adicionaP(Q, j.quantidade);
            }
            CARROPJ = CARROPJ->prox;
        }

        cout << "Placa(s) que realizou a revisão com o maior número de peças: \n";
        cout << "       Placa |  Quantidade |\n";
        cout << "-------------|-------------|\n";
        while(P != NULL) {
            string placas = P->dado;
            int quant = Q->dado;
            cout << setfill(' ') << std::setw(12) << placas << " |";
            cout << setfill(' ') << std::setw(12) << quant << " |" << endl;
            P = P->prox;
        } cout << endl;
    }
}

void lerArquivo(NoF<PF>* Fp, NoF<PF>* Fn, NoF<PJ>* Fj, No<FichaPF>* CARROPF, No<FichaPJ>* CARROPJ) {
    cout << "###################################################\n";
    cout << "##                    MECANICA                   ##\n";
    cout << "###################################################\n\n";

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
            mostrarPessoasF(Fp, "Pessoas físicas prioritárias");
            mostrarPessoasF(Fn, "Pessoas físicas não prioritárias");
            mostrarPessoasJ(Fj, "Pessoas jurídicas");
        }
        else if(acao == "ATENDER") {
            string num;
            getline(ss, num, ' ');
            float valor = stof(num);

            string n;
            getline(ss, n);
            int pecas = stoi(n);

            if(Fp != NULL){
                if(valor <= 0) cout << "ERRO: Valor não pode ser negativo ou nulo em 'ATENDER'";
                else {
                    if(pecas <= 0) cout << "ERRO: Quantidade de peças trocadas não pode ser negativo ou nulo em 'ATENDER'";
                    else {
                        PF f = Fp->dado;
                        FichaPF F = { f, valor, pecas };
                        CARROPF = adicionaP(CARROPF, F);
                        cout << "Pessoa física de CPF " << f.cpf << " foi atendida";
                        Fp = removeF(Fp);
                    }
                }
            }
            else {
                if(Fn != NULL){
                    if(valor <= 0) cout << "ERRO: Valor não pode ser negativo ou nulo em 'ATENDER'";
                    else {
                        if(pecas <= 0) cout << "ERRO: Quantidade de peças trocadas não pode ser negativo ou nulo em 'ATENDER'";
                        else {
                            PF f = Fn->dado;
                            FichaPF F = { f, valor, pecas };
                            CARROPF = adicionaP(CARROPF, F);
                            cout << "Pessoa física de CPF " << f.cpf << " foi atendida";
                            Fn = removeF(Fn);
                        }
                    }
                }
                else {
                    if(Fj != NULL){
                        if(valor <= 0) cout << "ERRO: Valor não pode ser negativo ou nulo em 'ATENDER'";
                        else {
                            if(pecas <= 0) cout << "ERRO: Quantidade de peças trocadas não pode ser negativo ou nulo em 'ATENDER'";
                            else {
                                PJ j = Fj->dado;
                                FichaPJ J = { j, valor, pecas };
                                CARROPJ = adicionaP(CARROPJ, J);
                                cout << "Pessoa jurídica de CNPJ " << j.cnpj << " foi atendida";
                                Fj = removeF(Fj);
                            }
                        }
                    }
                    else cout << "ERRO: Todas as filas estão vazias em 'ATENDER'";
                }
            }

        }
        else if(acao == "CRIARORDEM") {
            string tipo;
            getline(ss, tipo, ' ');

            string id;
            getline(ss, id, ' ');


            if(tipo == "PF") {
                string placa;
                getline(ss, placa, ' ');

                string pacote;
                getline(ss, pacote);
                if(id.length() != 11) cout << "ERRO: Quantidade de dígitos para CPF inválida em 'CRIARORDEM'";
                else {
                    if(placa.length() != 7) cout << "ERRO: Quantidade de dígitos para placa inválida em 'CRIARORDEM'";
                    else {
                        if(pacote != "S" && pacote != "N") cout << "ERRO: Opção inválida para pacote em 'CRIARORDEM'";
                        else {
                            PF F = { id, placa, pacote };
                            if(pacote == "S") Fp = adicionaF(Fp, F);
                            else Fn = adicionaF(Fn, F);
                            cout << "Pessoa física de CPF " << id << " foi criado ordem de serviço";
                        }
                    }
                }

            }
            else if(tipo == "PJ") {
                string placa;
                getline(ss, placa);

                if(id.length() != 14) cout << "ERRO: Quantidade de dígitos para CNPJ inválida em 'CRIARORDEM'";
                else {
                    if(placa.length() != 7) cout << "ERRO: Quantidade de dígitos para placa inválida em 'CRIARORDEM'";
                    else {
                        PJ J = { id, placa };
                        Fj = adicionaF(Fj, J);
                        cout << "Pessoa jurídica de CNPJ " << id << " foi criado ordem de serviço";
                    }
                }

            }
            else cout << "ERRO: Valor inválido para tipo de pessoa em 'CRIARORDEM'";
        }
        else if(acao == "LISTARUNIFICADO") {
            Listaunificada(Fp, Fn);
        }
        else if(acao == "LISTARATENDI") {
            Atendidas(CARROPF, "Fichas atendidas de pessoas físicas");
        }
        else if(acao == "SOMA") {
            Soma(CARROPF);
        }
        else if(acao == "REVISAOMAIOR") {
            MaiorRev(CARROPF);
        }
        else if(acao == "REVISAOMENOR") {
            MenorRev(CARROPJ);
        }
        else if(acao == "MAIORPECAS") {
            MaiorPecas(CARROPF, CARROPJ);
        }
        else {
               cout << "Função inválida";
        }
        cout << endl << "==============================================================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    NoF<PF>* Fp = nullptr;
    NoF<PF>* Fn = nullptr;
    NoF<PJ>* Fj = nullptr;
    No<FichaPF>* CARROPF = nullptr;
    No<FichaPJ>* CARROPJ = nullptr;

    lerArquivo(Fp, Fn, Fj, CARROPF, CARROPJ);
}
