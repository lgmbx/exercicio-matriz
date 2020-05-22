#include <stdio.h>

int main(){


    char produto[5][20] = {"Mesa", "Livro", "Sofa", "Fogao", "Cama"};

    float matrizInicial[5][4];
    float matrizResultado[5][4];

    float transporte[5];

    float somaTotalProduto[5];
    float somaTotalArmazem[4];

    float maiorPreco = 0;
    //variaveis para referenciar o produto de maior valor
    int idProduto = 0, idArmazem = 0;




    //ENTRADA DE CUSTO DO TRANSPORTE DE CADA ITEM
    printf("*******INSIRA O CUSTO DO TRANSPORTE DE CADA ITEM*******\n");
    for(int i = 0; i < 5; i++){
        printf("CUSTO DO TRANSPORTE > %s: ", produto[i]);
        scanf("%f", &transporte[i]);
    }



    //ENTRADA DE PREÇO DOS ITENS DE CADA ARMAZEM
    printf("*******INSIRA O PRECO DE CADA PRODUTO EM SEU RESPECTIVO ARMAZEM*******\n");
    for(int i = 0; i < 5; i++){
        printf("\n");
        for(int j = 0; j < 4; j++){

           printf("%s - Armazem %d: ", produto[i], j);
           scanf("%f", &matrizInicial[i][j]);
        }
    }


    //PRINT MATRIZ INICIAL
    printf("\n**********MATRIZ INICIAL**********\n");
    for(int i = 0; i < 5; i++){
        printf("%s\t", produto[i]);

        for(int j = 0; j < 4; j++){
            printf("%.2f\t", matrizInicial[i][j]);
        }
        printf("\n");
    }


    //CALCULO DOS IMPOSTOS
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(matrizInicial[i][j] <= 50){
                matrizResultado[i][j] = matrizInicial[i][j] + (matrizInicial[i][j] * 0.05);
            }
            else if(matrizInicial[i][j] <= 100){
                matrizResultado[i][j] = matrizInicial[i][j] + (matrizInicial[i][j] * 0.1);
            }
            else{
                matrizResultado[i][j] = matrizInicial[i][j] + (matrizInicial[i][j] * 0.2);
            }
        }
    }


    //PRINT MATRIZ IMPOSTO
    printf("\n\n**********MATRIZ IMPOSTOS**********\n");
    for(int i = 0; i < 5; i++){
        printf("%s\t", produto[i]);

        for(int j = 0; j < 4; j++){
            printf("%.2f\t", matrizResultado[i][j]);

            //teste de maior
            if(maiorPreco < matrizResultado[i][j]){
                maiorPreco = matrizResultado[i][j];
                idProduto = i;
                idArmazem = j;
            }

        }
        printf("\n");
    }


    //SOMA TOTAL DE CADA PRODUTO
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            somaTotalProduto[i] += matrizResultado[i][j];
        }
    }

    //RESULTADO DA SOMA TOTAL DE CADA PRODUTO
    printf("\n\n*******SOMA TOTAL DE CADA PRODUTO*******\n");
    for(int i = 0; i < 5; i++){
        printf("PRODUTO 1: %s - TOTAL: %.2f\n", produto[i], somaTotalProduto[i]);
    }



    //SOMA TOTAL DE CADA ARMAZEM
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 5; i++){
            somaTotalArmazem[j] += matrizResultado[i][j];
        }
    }

    //RESULTADO DA SOMA TOTAL DE CADA ARMAZEM
    printf("\n\n*******SOMA TOTAL DE CADA ARMAZEM*******\n");
    for(int i = 0; i < 4; i++){
        printf("Armazem %d - TOTAL: %.2f\n", i, somaTotalArmazem[i]);
    }


    //PRODUTO MAIOR VALOR
    printf("\n\n******* MAIOR VALOR *******\n");
    printf("PRODUTO: %s --- VALOR: %.2f --- ARMAZEM: %d\n\n", produto[idProduto], maiorPreco, idArmazem);


    //ATUALIZANDO A MATRIZ COM CUSTO DE TRANSPORTE E IMPOSTOS
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            matrizResultado[i][j] += transporte[i];
        }
    }


    //PRINT MATRIZ RESULTADO
    printf("\n**********MATRIZ RESULTANTE**********\n");
    for(int i = 0; i < 5; i++){
        printf("%s\t", produto[i]);

        for(int j = 0; j < 4; j++){
            printf("%.2f\t", matrizResultado[i][j]);
        }
        printf("\n");
    }


return 0;
}
