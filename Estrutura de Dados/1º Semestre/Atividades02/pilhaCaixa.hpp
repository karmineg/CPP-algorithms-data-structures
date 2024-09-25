#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha
#include <string>

struct Caixa
{
 int codigo;
 float peso;
};

struct Pilha
{
    int tam;
    int base;
    int topo;
    Caixa *dados; //Vetor que ser� alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};



///inicializa��o dos dados da pilha
void inicializaP(Pilha *p, int tam)
{
    p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new Caixa[tam];///aloca mem�ria dinamicamente
}


//retorna true se a pilha foi inicializada
//retorna false se a pilha n�o foi inicializada
bool verificaInicializacaoP(Pilha *p) //verifica de a pilha foi inicializada
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}

void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != NULL)
    {
        delete[] (p->dados);
        p->dados = NULL;
    }
}

void esvaziaP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
}

bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

///push
bool empilhaP(Pilha *p, Caixa c) ///push
{
    /// retorna false se a pilha n�o foi inicializada ou se ela est� cheia
    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = c;
        return true;
    }
}



///pop
Caixa desempilhaP(Pilha *p) ///pop
{

    Caixa valor; //inicializar a vari�vel valor, a qual ser� retornada

    ///se a pilha foi inicializada && se n�o estiver vazia, retira valor
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}



///peek
Caixa espiaP(Pilha *p) ///peek
{
    Caixa valor; //inicializar a vari�vel valor, a qual ser� retornada

    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}





void mostraP(Pilha *p, string nome)
{

    cout << "Pilha " << nome << ": " << endl;
    cout << "Tam: " << p->tam << endl;
    cout << "Topo: " << p->topo << endl;
    if(vaziaP(p) == false)
    {
        cout << "   -----------------------------------------" << endl;
        for(int i = p->topo; i > p->base; i--){
            Caixa item = p->dados[i];
            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(24) << "Caixa de c�digo " << item.codigo << " (Peso de " << item.peso << ")|" << endl;
            cout << "   -----------------------------------------" << endl;
        }
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
int buscaP(Pilha *p, int code)
{
    for(int i = p->topo ; i > p->base; i--) {
        if (code == p->dados[i].codigo) return i; // Se for encontrado o c�digo na pilha, impedir usu�rio de adicionar caixa com o referido c�digo :(
    } return -1; // Caso contr�rio, adiciona-se :)
}



#endif // _HPP_PILHA





