/* Fa�a um algoritmo que calcule o valor de uma presta��o em atraso, utilizando a f�rmula: total =
valor + (valor * ((taxa / 100) * dias)). Mostre o valor inicial e o valor corrigido. Construa o diagrama de
blocos e o pseudoc�digo deste algoritmo. */

algoritmo "presta��o"
var
    prestacao, valor, taxa, dias: real;

inic�o
    escreva("Informe o valor: ")
    leia(valor);

    escreva("Informe a taxa: ")
    leia(taxa);

    escreva("Informe os dias: ")
    leia(dias);

    prestacao <- total = valor+(valor * ((taxa / 100) * dias))

    escreva("Presta��o: ", pretacao, "$")

fim algoritmo
