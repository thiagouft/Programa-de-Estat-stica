#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "Calculos.h"

int main()
{
    printf("%s \n",setlocale(LC_ALL,""));
    float *vetor;
    int i,op,tamanho;
    Dlista* lista;
    lista = Create_Lista();
    puts("Digite 1 para entrar no programa e 0 para sair\n");
    scanf("%d",&op);
    while(op != 0){
        printf("Entre com o quantidade de Números da sua Série\n");
        scanf("%d",&tamanho);
        vetor = (float*)malloc(tamanho*sizeof(float));


//Radomizar os Numeros

        printf("\nDigite 1 para radomizar sua série ou 2 para Digitar manualmente os Números\n");
        scanf("%d",&op);
        if(op == 1){
            srand((unsigned)time(NULL));
            for(i=0;i<tamanho;i++)
                vetor[i]=rand() % 1000;
        }else{
            puts("\nDigite sua série de números ");
            for(i=0;i<tamanho;i++)
                scanf("%f",&vetor[i]);
    }

//Ordenar o Vetor

        ordenar(vetor,tamanho);

//Imprimi os Valores

        puts("\nSua Série Abaixo");
        for(i=0;i<tamanho;i++)
            printf("%.1f ",vetor[i]);
        puts("");

        printf("\nAgora Escolha o Cálculo a Ser Feito ou 0 para Sair:\n1- Média\n2- Mediana\n3- Ponto Médio\n4- Moda\n5- Variância\n6- Desvio\n7- Desvio_Médio\n8- Amplitude\n9- Curtose\n10- Assimetria\n");
        scanf("%d",&op);

        while(op!=0)
        {
            switch(op)
        {
        case 1:
        {
            media(vetor,tamanho);
            break;
        }

        case 2:
        {
            mediana(vetor,tamanho);
            break;

        }

        case 3:
        {
            ponto_medio(vetor,tamanho);
            break;
        }
        case 4:
        {
            moda(vetor, tamanho, lista);
            imprimir(lista);
            break;
        }
            case 5:
        {
            variancia(vetor,tamanho);
            break;
        }
        case 6:
        {
            desvio(vetor,tamanho);
            break;
        }
        case 7:
        {
            desvio_medio(vetor,tamanho);
            break;
        }
        case 8:
        {
            amplitude(vetor,tamanho);
            break;
        }
        case 9:
        {
            curtose(tamanho);
            break;
        }
        case 10:
        {
            Assimetria(vetor, tamanho, lista);
            break;
        }
        }

    printf("\nAgora Escolha o Cálculo a Ser Feito ou 0 para Sair:\n1- Média\n2- Mediana\n3- Ponto Médio\n4- Moda\n5- Variância\n6- Desvio\n7- Desvio_Médio\n8- Amplitude\n9- Curtose\n10- Assimetria\n");
    scanf("%d",&op);

    }

    puts("\nDeseja Refazer outro cálculo digite 1 ou digite 0 para encerrar o programa\n");
//    zerar_lista(lista);
    scanf("%d",&op);
    }

    printf("Obrigado\n");



    return 0;
}
