#include <stdio.h>
#include <stdlib.h>

struct Node{
int num;
struct Node *prox;
};
typedef struct Node node;
void inicia(node *PILHA);
int menu(void);
void opcao(node *PILHA, int op);
node *criaNo();
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
int vazia(node *LISTA);
void contaNo(node *LISTA);
void removerNo(node *LISTA);
void buscar(node *LISTA);
int tam;
void retiraInicio(node *LISTA);
int main(void)
{
node *PILHA = (node *) malloc(sizeof(node));
if(!PILHA){
printf("Sem memoria disponivel!\n");
exit(1);
}
inicia(PILHA);
int opt;
do{
opt=menu();
opcao(PILHA,opt);
}while(opt);
free(PILHA);
return 0;
}

int menu(void){
int opt;
printf("\nEscolha a opcao\n");
printf("1. Adicionar\n");
printf("2. Remove\n");
printf("3. Esvaziar\n");
printf("4. Mostrar\n");
printf("5. Contar\n");
printf("6. Remover No Especifico\n");
printf("7. Buscar No Especifico\n");
printf("8. Sair\n");
printf("Opcao: ");
scanf("%d", &opt);
return opt;
}
void opcao(node *PILHA, int op){
switch(op){
case 1:
insereInicio(PILHA);
break;
case 2:
retiraInicio(PILHA);
break;
case 3:
libera(PILHA);
break;
case 4:
exibe(PILHA);
break;
case 5:
contaNo(PILHA);
break;
case 6:
removerNo(PILHA);
break;
case 7:
buscar(PILHA);
break;
case 8:
libera(PILHA);
exit(1);
break;
default:
printf("Comando invalido\n\n");

}
}
void inicia(node *PILHA)
{
PILHA->prox = NULL;
PILHA->num = NULL;
tam=0;
}
void insereInicio(node *PILHA)
{
node *novo=(node *) malloc(sizeof(node));
if(!novo){
printf("Sem memoria disponivel!\n");
exit(1);
}
printf("Novo elemento: ");
scanf("%d", &novo->num);
node *oldHead = PILHA->prox;
PILHA->prox = novo;
novo->prox = oldHead;
tam++;
}
void retiraInicio(node *PILHA)
{
if(PILHA->prox == NULL){
printf("Pilha ja esta vazia\n");
}else{
node *tmp = PILHA->prox;
PILHA->prox = tmp->prox;
tam--;
free(tmp);
}
}
int vazia(node *PILHA){
if(PILHA->prox == NULL)
return 1;
else
return 0;
}
void libera(node *PILHA)
{
if(!vazia(PILHA)){
node *proxNode, *atual;
atual = PILHA->prox;
while(atual != NULL){
proxNode = atual->prox;
free(atual);
atual = proxNode;
}
PILHA->prox = NULL;
}
}

void exibe(node *PILHA)
{
if(vazia(PILHA)){
printf("Pilha vazia!\n\n");
}
else{
node *tmp;
tmp = PILHA->prox;
while( tmp != NULL){
printf("\n%d", tmp->num);
tmp = tmp->prox;
}
printf("\n\n");
}
}
void contaNo(node *PILHA){
int cont=0;
node *tmp;
tmp = PILHA->prox;
while( tmp != NULL){
cont++;
tmp = tmp->prox;
}
printf("\na quantidade de elementos eh %d",cont);
}
void removerNo(node *PILHA){
int no;
printf("Digite o no a ser removido\n");
scanf("%d",&no);
node *tmp, *aux;
tmp = PILHA->prox;
aux = PILHA;
while( tmp != NULL){
if(tmp->num == no){
aux->prox = tmp->prox;
tmp = aux->prox;
tam--;
}
else{
aux = tmp;
tmp=tmp->prox;
}
}
}
void buscar(node *PILHA){
int no, cont=0, flag =0;
printf("Digite o valor a ser encontrado\n");
scanf("%d",&no);
node *tmp, *aux;
tmp = PILHA->prox;
aux = PILHA;
while( tmp != NULL){
cont++;
if(tmp->num == no){
flag =1;
printf("\nvalor  encontrado na pos: %d", cont);
}
aux = tmp;
tmp=tmp->prox;
}
if(cont==0)
{ printf("\nPilha vazia\n");
}
else if(flag == 0){
        printf("\n elemento nao pertence a Pilha.\n");
    }
}
