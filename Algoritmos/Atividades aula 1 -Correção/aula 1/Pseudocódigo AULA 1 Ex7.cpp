/* 7 - Fa�a um algoritmo para controlar o pagamento de comiss�o de vendedores de pe�as, levando-se em
considera��o que sua comiss�o ser� de 5% do total da venda e que voc� tem os seguintes dados:
Identifica��o do vendedor
C�digo da pe�a
Pre�o unit�rio da pe�a
Quantidade vendida
Construa o diagrama de blocos do algoritmo desenvolvido e o pseudoc�digo*/

algoritmo "teste"
var
    comissao, venda : inteiro;

in�cio
    escreva("informe a identifica��o do vendedor: ");
    leia(id);

    escreva("Informe o c�digo da pe�a: ");
    leia(cod);

    escreva("Informe o pre�o unit�rio da pe�a: ");
    leia(preco);

    escreva("Informe a quantidade vendida: ")
    leia(qtd);

    //calcular venda e comiss�o
    venda <- qtd * preco
    comissao <- venda + (venda * 0.05)

    //escrever resultados
    escreva("Vendedor: ", id)
    escreva("C�digo: ",cod)
    escreva("Sal�rio mais comiss�o: ", comissao)

fim algoritmo
