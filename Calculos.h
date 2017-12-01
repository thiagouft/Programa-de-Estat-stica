
typedef struct no{
    int moda;
    int quantidade;
    struct no * prox;
}Dno;

typedef struct {
    Dno * inicio;
}Dlista;



Dlista * Create_Lista(){
    Dlista * novo = (Dlista*)malloc(sizeof(Dlista));
    if(novo){
        novo->inicio = NULL;
    }else
        puts("Não Alocou\n");
    return novo;
}

int Inserir_Lista(Dlista* L, int moda, int quantidade){
    Dno* aux;
    aux = L->inicio;
    while(aux != NULL){
        if(aux->moda == moda)
                return 0;
        aux = aux->prox;
    }
    Dno* novo = (Dno*)malloc(sizeof(Dno));
    if(novo){
        novo->moda = moda;
        novo->quantidade = quantidade;
        novo->prox = NULL;
    }else
        return 0;

    if(!L->inicio){
        L->inicio = novo;
        return 1;
    }else{
        aux = L->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        return 1;
    }
}

//void zerar_lista(Dlista* L){
//    Dno * aux;
//    aux = L->inicio;
//    int i = 0;
//
//    while(aux != NULL){
//        aux = aux->prox;
//    }
//    free
//}

void imprimir(Dlista* L){
    Dno * aux;
    int i = 0;
    aux = L->inicio;
    while(aux != NULL){
        printf("\nO numero %d repetiu %d vezes na serie\n",aux->moda, aux->quantidade);
        aux = aux->prox;
        i++;
    }
    if(i == 0){
        printf("\nNão tem Moda\n");
    }
    else if(i == 1)
        printf("\nClassificação: Moda Normal\n");
    else if(i == 2)
        printf("\nClassificação: Moda Bimodal\n");
    else
        printf("\nClassificação: Multimodal\n");

}
void ordenar(float *vetor, int k)
{
    int i,j,aux;

    for(i=0;i<k-1;i++)
        for(j=0;j<k-1;j++)
    {
        if(vetor[j]>vetor[j+1])
        {
            aux=vetor[j];
            vetor[j]=vetor[j+1];
            vetor[j+1]=aux;
        }
    }

}

float media(float *vetor, int tam)
{
    float soma = 0,media;
    int i;

    for(i=0;i<tam;i++)
        soma+=vetor[i];
    media=soma/tam;
    printf("\nA media é = %.2f\n",media);
    return media;
}

float mediana(float *vetor, int tam)
{
    float mediana;
    if(tam%2==0)
    {
        mediana=(vetor[(tam/2)-1]+vetor[((tam/2)+1)-1])/2;
        printf("\nA Mediana é = %.2f\n",mediana);
        return mediana;
    }
    else
    {
        mediana=vetor[((tam+1)/2)-1];
        printf("\nA Mediana é = %.2f\n",mediana);
        return mediana;
    }

}

void ponto_medio(float *vetor, int tam)
{
    float ponto_medio;

    ponto_medio=(vetor[tam-1]+vetor[0])/2;
    printf("\nO valor do Ponto Médio = %.2f\n",ponto_medio);
}

void moda(float *vetor, int tam, Dlista* L)
{
    int cont=0,i,j;

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(vetor[i]==vetor[j])
                cont++;

        }
        if(cont > 1){
            Inserir_Lista(L,vetor[i],cont);
        }
        cont=0;

    }
}

void curtose(int tam){

    float curtose, quartil1 = 25, decil1 = 10, quartil2 = 75, decil2 = 90;


    quartil1=(quartil1*tam)/100;
    decil1=(quartil1*tam)/100;

    quartil2=(quartil2*tam)/100;
    decil2=(quartil2*tam)/100;

    curtose = (((quartil2 - quartil1)) / 2*(decil2 - decil1));

    if(curtose<0.263){
        printf("\nCurva Leptocúrtica %.2f \n",curtose);


    }else{
        if(curtose>0.263){
        printf("\nCurva Platicúrtica%.2f \n",curtose);
    }else
        printf("\nCurva Mesocúrtica %.2f \n",curtose);
}
}

void Assimetria(float *vetor, int tam, Dlista * L){
    float soma = 0,media;
    int i;
    for(i=0;i<tam;i++)
        soma+=vetor[i];
    media=soma/tam;

    float mediana;
    if(tam%2==0)
    {
        mediana=(vetor[(tam/2)-1]+vetor[((tam/2)+1)-1])/2;
    }
    else
    {
        mediana=vetor[((tam+1)/2)-1];
    }

    Dno * aux;
    i = 0;
    float maior, moda;
    aux = L->inicio;
    if(L->inicio){
        moda = L->inicio->moda;
        maior = L->inicio->quantidade;
    }

    while(aux != NULL){
        if(aux->quantidade > maior){
            maior = aux->quantidade;
            moda = aux->moda;
        }
        aux = aux->prox;
        i++;
    }
    if(i == 0){
        moda = 0;
    }
    printf("Moda = %d", moda);

    if((media == mediana) && (mediana == moda))
        puts("\nA curva da distribuição é SIMÉTRICA\n");
    else if((media < mediana) && (mediana < moda))
        puts("\nA curva da distribuição é ASSIMETRIA NEGATIVA\n");
    else if((media > mediana) && (mediana > moda))
        puts("\nA curva da distribuição é ASSIMETRIA POSITIVA\n");
    else
        puts("Não detectou Simetria");


}




void amplitude(float *vetor,int tam){
int i;
float maior,menor,result;

    maior=vetor[0]; menor=vetor[0];

        for(i=0;i<tam;i++){
        if(maior<vetor[i]){
            maior=vetor[i];
}
    if(menor>vetor[i]){
        menor=vetor[i];

}

    }
    result=maior-menor;
    printf("\nA amplitude = %.2f \n",result);


}

void desvio(float *vetor,int tam){
    int i,tam2=tam-1;
    float soma = 0,media=0,desvio_a,desvio_p,result1,result2,cv;

    for(i=0;i<tam;i++)
        soma+=vetor[i];
    media=soma/tam;

    for(i=0;i<tam;i++){
        vetor[i]=vetor[i]-media;
    }

    for(i=0;i<tam;i++){

    vetor[i]=vetor[i]*vetor[i];
    }
    soma=0;

    for(i=0;i<tam;i++){
        soma+=vetor[i];
    }
    desvio_a=soma/tam2;
    desvio_p=soma/tam;
    result1=sqrt( desvio_a );
    result2=sqrt(desvio_p);


    cv=desvio_a/media;

    printf("\nO coeficiente de variacao é = %.2f\n",cv);
    printf("\nO desvio amostral ou padrão é = %.2f\n",result1);
    printf("\nO desvio populacional é = %.2f\n",result2);

}


void desvio_medio(float *vetor,int tam){
    int i;
    float soma = 0,media=0,desvio_m;

    for(i=0;i<tam;i++)
        soma+=vetor[i];
    media=soma/tam;

    for(i=0;i<tam;i++){
        vetor[i]=vetor[i]-media;
    }

    for(i=0;i<tam;i++){
        soma+=vetor[i];
    }
    desvio_m=soma/tam;
   printf("\nO desvio medio = %.2f\n",desvio_m);
}

void variancia(float *vetor,int tam){
    int i,tam2=tam-1;
    float soma = 0,media=0,variancia_a,variancia_p;

    for(i=0;i<tam;i++)
        soma+=vetor[i];
    media=soma/tam;

    for(i=0;i<tam;i++){
        vetor[i]=vetor[i]-media;
    }

    for(i=0;i<tam;i++){

    vetor[i]=vetor[i]*vetor[i];
    }
    soma=0;

    for(i=0;i<tam;i++){
        soma+=vetor[i];
    }
    variancia_a=soma/tam2;
    variancia_p=soma/tam;
    printf("\nA variancia amostral  = %.2f\n",variancia_a);
    printf("\nA variancia populacional = %.2f\n",variancia_p);
}

