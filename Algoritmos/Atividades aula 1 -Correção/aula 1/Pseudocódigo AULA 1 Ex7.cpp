/* 7 - Faça um algoritmo para controlar o pagamento de comissão de vendedores de peças, levando-se em
consideração que sua comissão será de 5% do total da venda e que você tem os seguintes dados:
Identificação do vendedor
Código da peça
Preço unitário da peça
Quantidade vendida
Construa o diagrama de blocos do algoritmo desenvolvido e o pseudocódigo*/

algoritmo "teste"
var
    comissao, venda : inteiro;

início
    escreva("informe a identificação do vendedor: ");
    leia(id);

    escreva("Informe o código da peça: ");
    leia(cod);

    escreva("Informe o preço unitário da peça: ");
    leia(preco);

    escreva("Informe a quantidade vendida: ")
    leia(qtd);

    //calcular venda e comissão
    venda <- qtd * preco
    comissao <- venda + (venda * 0.05)

    //escrever resultados
    escreva("Vendedor: ", id)
    escreva("Código: ",cod)
    escreva("Salário mais comissão: ", comissao)

fim algoritmo
