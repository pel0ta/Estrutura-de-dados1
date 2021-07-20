#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};
typedef struct Node node;
void inicia(node *FILA);
int menu(void);
void opcao(node *FILA, int op);
node *criaNo();
void insereFim(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);
int vazia(node *FILA);
void contaNo(node *FILA);
void removerNo(node *FIlA);
void buscar(node *FILA);
int tam;
void retiraInicio(node *FILA);
int main(void)
{
    node *FILA = (node *) malloc(sizeof(node));
    if(!FILA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    inicia(FILA);
    int opt;
    do
    {
        opt=menu();
        opcao(FILA,opt);
    }
    while(opt);
    free(FILA);
    return 0;
}

int menu(void)
{
    int opt;
    printf("\nBem vindo ao Banco \n");
    printf("1. adicionar cliente \n");
    printf("2. atender cliente \n");
    printf("3. Esvaziar clientes \n");
    printf("4. Mostrar clientes \n");
    printf("5. Contar clientes \n");
    printf("6. Remover cliente especifico\n");
    printf("7. Buscar cliente Especifico\n");
    printf("8. Sair\n");
    printf("Opcao: ");
    scanf("%d", &opt);
    return opt;
}
void opcao(node *FILA, int op)
{
    switch(op)
    {
    case 1:
        insereFim(FILA);
        break;
    case 2:
        retiraInicio(FILA);
        break;
    case 3:
        libera(FILA);
        break;
    case 4:
        exibe(FILA);
        break;
    case 5:
        contaNo(FILA);
        break;
    case 6:
        removerNo(FILA);
        break;
    case 7:
        buscar(FILA);
        break;
    case 8:
        libera(FILA);
        exit(1);
        break;
    default:
        printf("Comando invalido\n\n");

    }
}
void inicia(node *FILA)
{
    FILA->prox = NULL;
    FILA->num = NULL;
    tam=0;
}
void insereFim(node *FILA)
{
    node *novo=(node *) malloc(sizeof(node));
    if(!novo)
    {
        printf("Sem espaço no banco!\n");
        exit(1);
    }
    printf("Digite sua senha: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    if(vazia(FILA))
        FILA->prox=novo;
    else
    {
        node *tmp = FILA->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
    tam++;
}
void retiraInicio(node *FILA)
{
    if(FILA->prox == NULL)
    {
        printf("FILA ja esta vazia\n");
    }
    else
    {
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
}
int vazia(node *FILA)
{
    if(FILA->prox == NULL)
        return 1;
    else
        return 0;

}
void libera(node *FILA)
{
    if(!vazia(FILA))
    {
        node *proxNode, *atual;
        atual = FILA->prox;
        while(atual != NULL)
        {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
        FILA->prox = NULL;
    }
}

void exibe(node *FILA)
{
    if(vazia(FILA))
    {
        printf("Fila vazia!\n\n");
    }
    else
    {
        node *tmp;
        tmp = FILA->prox;
        while( tmp != NULL)
        {
            printf("\n%d", tmp->num);
            tmp = tmp->prox;
        }
        printf("\n\n");
    }
}
void contaNo(node *FILA)
{
    int cont=0;
    node *tmp;
    tmp = FILA->prox;
    while( tmp != NULL)
    {
        cont++;
        tmp = tmp->prox;
    }
    printf("\na quantidade de elementos eh %d",cont);
}
void removerNo(node *FILA)
{
    int no;
    printf("Digite o no a ser removido\n");
    scanf("%d",&no);
    node *tmp, *aux;
    tmp = FILA->prox;
    aux = FILA;
    while( tmp != NULL)
    {
        if(tmp->num == no)
        {
            aux->prox = tmp->prox;
            tmp = aux->prox;
            tam--;
        }
        else
        {
            aux = tmp;
            tmp=tmp->prox;
        }
    }
}
void buscar(node *FILA)
{
    int no, cont=0, flag =0;
    printf("Digite o no a ser encontrado\n");
    scanf("%d",&no);
    node *tmp, *aux;
    tmp = FILA->prox;
    aux = FILA;
    while( tmp != NULL)
    {
        cont++;
        if(tmp->num == no)
        {
            flag =1;
            printf("\nElemento encontrado na pos: %d", cont);
        }
        aux = tmp;
        tmp=tmp->prox;
    }
    if(cont==0)
    {
        printf("\nFila vazia\n");
    }
    else if(flag == 0)
    {
        printf("\n elemento nao pertence a Fila.\n");
    }
}
