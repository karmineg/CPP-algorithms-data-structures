#include<iostream>
#include<fstream>
using namespace std;
#include"fila-dinamica.hpp"

struct Documento {
    string nome;
    int tamanho;
    int pagina;
    int ano;
    string prioridade;
};

void mostrarDocumentos(NoF<Documento>* F, string tipo) {
    if(F == NULL) cout << "ERRO: " << tipo << " está vazia\n";
    else {
        cout << tipo << "\n";
        cout << "     Endereço |          Nome |   Tamanho(MB) |  Quant. de páginas |        Ano |         Prioridade \n";
        cout << "--------------|---------------|---------------|--------------------|------------|--------------------\n";
        while(F != NULL) {
            Documento d = F->dado;
            cout << setfill(' ') << std::setw(13) << F << " |";
            cout << setfill(' ') << std::setw(14) << d.nome << " |";
            cout << setfill(' ') << std::setw(11) << d.tamanho << " MB |";
            cout << setfill(' ') << std::setw(19) << d.pagina << " |";
            cout << setfill(' ') << std::setw(11) << d.ano << " |";
            cout << setfill(' ') << std::setw(19) << d.prioridade << endl;
            F = F->prox;
        } cout << endl;
    }
}

void Listaunificada(NoF<Documento>* Fu, NoF<Documento>* Fp, NoF<Documento>* Fn) {
    if(Fu == NULL && Fp == NULL && Fn == NULL) cout << "ERRO: Filas vazias";
    else {
        int totalD = 0, totalP = 0;

        while(Fu != NULL) {
            Documento u = Fu->dado;
            totalD++;
            int paginas = u.pagina;
            totalP += paginas;
            Fu = Fu->prox;
        }
        while(Fp != NULL) {
            Documento p = Fp->dado;
            totalD++;
            int pagin = p.pagina;
            totalP += pagin;
            Fp = Fp->prox;
        }
        while(Fn != NULL) {
            Documento n = Fn->dado;
            totalD++;
            int pagi = n.pagina;
            totalP += pagi;
            Fn = Fn->prox;
        }

        cout << " Total de Documentos                    | " << totalD << endl;
        cout << "----------------------------------------|---------------\n";
        cout << " Número de páginas a serem impressas    | " << totalP << endl;
        cout << "----------------------------------------|---------------\n";
    }
}

void pesquisarDocumento(NoF<Documento>* Fu, NoF<Documento>* Fp, NoF<Documento>* Fn, string tipo) {

    if(tipo == "U"){
        NoF<Documento>* P = nullptr;
        NoF<Documento>* T = nullptr;

        if(Fu != NULL){
            int maior = 0;
            int menor = (Fu->dado).pagina;
            while(Fu != NULL) {
                Documento d = Fu->dado;
                if(d.tamanho >= maior) {
                    if(d.tamanho > maior) {
                        maior = d.tamanho;
                        T = destroiF(T);
                    }
                    T = adicionaF(T, d);
                }

                if(menor >= d.pagina) {
                    if(d.pagina < menor) {
                        menor = d.pagina;
                        P = destroiF(P);
                    }
                    P = adicionaF(P, d);
                }
                Fu = Fu->prox;
            }
        }
        if(T == NULL) cout << "ERRO: Fila dos arquivos de maior tamanho vazio";
        else {
            cout << "Nome(s) do(s) documento(s) com maior tamanho: \n";
            cout << "         Nome |       Tamanho |\n";
            cout << "--------------|---------------|\n";
            while(T != NULL) {
                Documento t = T->dado;
                cout << setfill(' ') << std::setw(13) << t.nome << " |";
                cout << setfill(' ') << std::setw(11) << t.tamanho << " MB |" << endl;
                T = T->prox;
            } cout << endl;
        }

        if(P == NULL) cout << "\nERRO: Fila dos arquivos de menor número de páginas vazio";
        else {
            cout << "\nNome(s) do(s) documento(s) com menos paginas: \n";
            cout << "         Nome |       Páginas |\n";
            cout << "--------------|---------------|\n";
            while(P != NULL) {
                Documento p = P->dado;
                cout << setfill(' ') << std::setw(13) << p.nome << " |";
                cout << setfill(' ') << std::setw(13) << p.pagina << " |" << endl;
                P = P->prox;
            } cout << endl;
        }
    }
    else {
        if(tipo == "P") {
            NoF<Documento>* P = nullptr;
            NoF<Documento>* T = nullptr;

            if(Fp != NULL){
                int maior = 0;
                int menor = (Fp->dado).pagina;
                while(Fp != NULL) {
                    Documento d = Fp->dado;
                    if(d.tamanho >= maior) {
                        if(d.tamanho > maior) {
                            maior = d.tamanho;
                            T = destroiF(T);
                        }
                        T = adicionaF(T, d);
                    }

                    if(menor >= d.pagina) {
                        if(d.pagina < menor) {
                            menor = d.pagina;
                            P = destroiF(P);
                        }
                        P = adicionaF(P, d);
                    }
                    Fp = Fp->prox;
                }
            }
            if(T == NULL) cout << "ERRO: Fila dos arquivos de maior tamanho vazio";
            else {
                cout << "Nome(s) do(s) documento(s) com maior tamanho: \n";
                cout << "         Nome |       Tamanho |\n";
                cout << "--------------|---------------|\n";
                while(T != NULL) {
                    Documento t = T->dado;
                    cout << setfill(' ') << std::setw(13) << t.nome << " |";
                    cout << setfill(' ') << std::setw(11) << t.tamanho << " MB |" << endl;
                    T = T->prox;
                } cout << endl;
            }

            if(P == NULL) cout << "\nERRO: Fila dos arquivos de menor número de páginas vazio";
            else {
                cout << "\nNome(s) do(s) documento(s) com menos paginas: \n";
                cout << "         Nome |       Páginas |\n";
                cout << "--------------|---------------|\n";
                while(P != NULL) {
                    Documento p = P->dado;
                    cout << setfill(' ') << std::setw(13) << p.nome << " |";
                    cout << setfill(' ') << std::setw(13) << p.pagina << " |" << endl;
                    P = P->prox;
                } cout << endl;
            }
        }
        else {
            if(tipo == "N"){
                NoF<Documento>* P = nullptr;
                NoF<Documento>* T = nullptr;

                if(Fn != NULL){
                    int maior = 0;
                    int menor = (Fn->dado).pagina;
                    while(Fn != NULL) {
                        Documento d = Fn->dado;
                        if(d.tamanho >= maior) {
                            if(d.tamanho > maior) {
                                maior = d.tamanho;
                                T = destroiF(T);
                            }
                            T = adicionaF(T, d);
                        }

                        if(menor >= d.pagina) {
                            if(d.pagina < menor) {
                                menor = d.pagina;
                                P = destroiF(P);
                            }
                            P = adicionaF(P, d);
                        }
                        Fn = Fn->prox;
                    }
                }
                if(T == NULL) cout << "ERRO: Fila dos arquivos de maior tamanho vazio";
                else {
                    cout << "Nome(s) do(s) documento(s) com maior tamanho: \n";
                    cout << "         Nome |       Tamanho |\n";
                    cout << "--------------|---------------|\n";
                    while(T != NULL) {
                        Documento t = T->dado;
                        cout << setfill(' ') << std::setw(13) << t.nome << " |";
                        cout << setfill(' ') << std::setw(11) << t.tamanho << " MB |" << endl;
                        T = T->prox;
                    } cout << endl;
                }

                if(P == NULL) cout << "\nERRO: Fila dos arquivos de menor número de páginas vazio";
                else {
                    cout << "\nNome(s) do(s) documento(s) com menos paginas: \n";
                    cout << "         Nome |       Páginas |\n";
                    cout << "--------------|---------------|\n";
                    while(P != NULL) {
                        Documento p = P->dado;
                        cout << setfill(' ') << std::setw(13) << p.nome << " |";
                        cout << setfill(' ') << std::setw(13) << p.pagina << " |" << endl;
                        P = P->prox;
                    } cout << endl;
                }
            }
            else cout << "ERRO: Opção para fila inválida";
        }
    }

}

void lerArquivo(NoF<Documento>* Fp, NoF<Documento>* Fn, NoF<Documento>* Fu) {
    cout << "#####################################################\n";
    cout << "##                    DOCUMENTOS                   ##\n";
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
            mostrarDocumentos(Fu, "Documentos urgentes");
            mostrarDocumentos(Fp, "Documentos prioritários");
            mostrarDocumentos(Fn, "Documentos não prioritários");
        }
        else if(acao == "IMPRIMIR") {
            if(Fu != NULL){
                Documento d = Fu->dado;
                cout << "Documento '" << d.nome << "' de prioridade " << d.prioridade << " foi impresso";
                Fu = removeF(Fu);
            }
            else {
                if(Fp != NULL){
                    Documento d = Fp->dado;
                    cout << "Documento '" << d.nome << "' de prioridade " << d.prioridade << " foi impresso";
                    Fp = removeF(Fp);
                }
                else {
                        if(Fn != NULL){
                            Documento d = Fn->dado;
                            cout << "Documento '" << d.nome << "' de prioridade " << d.prioridade << " foi impresso";
                            Fn = removeF(Fn);
                        }
                        else cout << "ERRO: Não há nenhum documento para impressão";
                }

            }
        }
        else if(acao == "LISTAR") {
            Listaunificada(Fu, Fp, Fn);
        }
        else if(acao == "REGISTRAR") {
            string nome;
            getline(ss, nome, ' ');

            string num;
            getline(ss, num, ' ');
            int tamanho = stoi(num);

            string nu;
            getline(ss, nu, ' ');
            int paginas = stoi(nu);

            string n;
            getline(ss, n, ' ');
            int ano = stoi(n);

            string prioridade;
            getline(ss, prioridade);

            if(tamanho <= 0) cout << "ERRO: O tamanho do documento não pode ser nulo ou negativo em 'REGISTRAR'";
            else {
                if(paginas <= 0) cout << "ERRO: As páginas do documento não pode ser nulo ou negativo em 'REGISTRAR'";
                else {
                    if(ano > 2023) cout << "ERRO: Ano inserido para o documento não pode ser superior ao atual ano em 'REGISTRAR'";
                    else if(ano <= 0) cout << "ERRO: O ano do documento não pode ser nulo ou negativo em 'REGISTRAR'";
                    else {

                    if(prioridade != "U" && prioridade != "P" && prioridade != "N") cout << "Opção para priridade do documento inválida em 'REGISTRAR'";
                    else {
                        string newPrioridade;
                        if(prioridade == "U") newPrioridade = "Urgente";
                        else if(prioridade == "P") newPrioridade = "Prioritário";
                        else newPrioridade = "Não prioritário";

                        Documento D = { nome, tamanho, paginas, ano, newPrioridade };
                        if(prioridade == "U") Fu = adicionaF(Fu, D);
                        else if(prioridade == "P") Fp = adicionaF(Fp, D);
                        else Fn = adicionaF(Fn, D);

                        cout << "O documento '" << nome << "' de prioridade " << newPrioridade << " foi registrado";
                        }
                    }
                }
            }
        }
        else if(acao == "PESQUISA") {
            string tipo;
            getline(ss, tipo);

            pesquisarDocumento(Fu, Fp, Fn, tipo);
        }
        else {
               cout << "Função inválida";
        }
        cout << endl << "==========================================================================================================" << endl << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    NoF<Documento>* Fp = nullptr;
    NoF<Documento>* Fn = nullptr;
    NoF<Documento>* Fu = nullptr;

    lerArquivo(Fp, Fn, Fu);
}
