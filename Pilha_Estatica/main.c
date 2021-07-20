#include <stdio.h>
#include <stdlib.h>
int contar(int *vetp){
    int i,cont=0;
    for(i=0;i<15;i++){
        if(vetp[i]!=NULL){
            cont++;
        }
    }
    return cont;
}
void adiciona(int *vetp,int *valor){
    int cont=contar(vetp);
    if(cont==15){
        printf("\nA pilha esta cheia:\n");
    }
    else{
        vetp[cont]=valor;
        }
}
void remover(int *vetp){
    int cont=contar(vetp);
    if(cont==0)
        printf("Nao tem elementos pra excluir:");
    else
        vetp[cont-1]=NULL;
}
void topop(int*vetp){
    int cont=contar(vetp);
    printf("%d",vetp[cont-1]);
}
void mostrar(int *vetp){
    int i, cont=contar(vetp);
    for(i=0;i<cont;i++){
        printf("%d\t",vetp[i]);
    }
}

void excluiesp(int *vetp,int *valor){
    int cont=contar(vetp),vetaux[15],j=0,i;
    for(i=0;i<cont;i++){
        if(vetp[i]!=valor){
            vetaux[j]=vetp[i];
            j++;
        }
    }
    for(i=0;i<cont;i++){
        vetp[i]=NULL;
    }
    for(i=0;i<j;i++){
        vetp[i]=vetaux[i];
    }
}
int main()
{
    int vetp[15],valor,opt,i,topo;
    for(i=0;i<15;i++){
        vetp[i]=NULL;
    }

    printf("\nPILHA\n\n");
    printf("Menu\n");
    do{
        printf("\n1-Adicionar\n2-Remover\n3-Topo\n4-mostrar a pilhar\n5-excluir elemento especifico\n6-Mostrar top\n0-sair\n");
        scanf("%d",&opt);
        switch(opt){
        case 1:
                printf("\nDigite o numero que deseja adiccionar na pilha:\n");
                scanf("%d",&valor);
                adiciona(vetp,valor);
            break;
        case 2:
                remover(vetp);
                printf("\no Ultimo elemento foi apagado:\n");
            break;
        case 3:
                printf("\nO topo e :\n");
                topop(vetp);
            break;
        case 4:
                printf("\nElementos na pilha\n");
                mostrar(vetp);
            break;
        case 5:
                printf("\nDigite o elemento que deseja excluir\n");
                scanf("%d",&valor);
                excluiesp(vetp,valor);
            break;
        default:
            printf("valor invalido digite novamente:");
        }
    }while(opt!=0);
    return 0;
}
