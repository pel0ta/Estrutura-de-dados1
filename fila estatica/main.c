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
        printf("\nA FILA esta cheia:\n");
    }
    else{
        vetp[cont]=valor;
        }
}
void remover(int *vetp){
    int cont=contar(vetp),i;
     for(i=0;i<cont;i++){
        vetp[i]=vetp[i+1];
        }
        cont--;
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
int main()
{
    int vetp[15],valor,opt,i,topo;
    for(i=0;i<15;i++){
        vetp[i]=NULL;
    }

    printf("\nFILA\n\n");
    printf("Menu\n");
    do{
        printf("\n1-Adicionar\n2-Remover\n3-mostrar a fila\n0-sair\n");
        scanf("%d",&opt);
        switch(opt){
        case 1:
                printf("\nDigite o numero que deseja adiccionar na FILA:\n");
                scanf("%d",&valor);
                adiciona(vetp,valor);
            break;
        case 2:
                remover(vetp);
                printf("\no Primeiro elemento foi apagado:\n");
            break;
        case 3:
                printf("\nElementos na fila\n");
                mostrar(vetp);
            break;
        default:
            printf("valor invalido digite novamente:");
        }
    }while(opt!=0);
    return 0;
}
