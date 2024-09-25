/* Faça um algoritmo que calcule o valor de uma prestação em atraso, utilizando a fórmula: total =
valor + (valor * ((taxa / 100) * dias)). Mostre o valor inicial e o valor corrigido. Construa o diagrama de
blocos e o pseudocódigo deste algoritmo. */

algoritmo "prestação"
var
    prestacao, valor, taxa, dias: real;

inicío
    escreva("Informe o valor: ")
    leia(valor);

    escreva("Informe a taxa: ")
    leia(taxa);

    escreva("Informe os dias: ")
    leia(dias);

    prestacao <- total = valor+(valor * ((taxa / 100) * dias))

    escreva("Prestação: ", pretacao, "$")

fim algoritmo
