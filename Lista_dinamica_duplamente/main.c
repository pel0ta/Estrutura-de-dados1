#include <stdio.h>
#include <stdlib.h>
struct Node{
int num;
struct Node *prox;
};
typedef struct Node node;
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
int vazia(node *LISTA);
void contaNo(node *LISTA);
void removerNo(node *LISTA);
void buscar(node *LISTA);
int tam;
void retiraInicio(node *LISTA);
void retiraFim(node *LISTA);
int main(void)
{
node *LISTA = (node *) malloc(sizeof(node));
if(!LISTA){
printf("Sem memoria disponivel!\n");
exit(1);
}
inicia(LISTA);
int opt;
do{
opt=menu();
opcao(LISTA,opt);
}while(opt);
free(LISTA);
return 0;
}

int menu(void){
int opt;
printf("\nEscolha a opcao\n");
printf("1. Adicionar no inicio\n");
printf("2. Adicionar no fim\n");
printf("3. Retirar do inicio\n");
printf("4. Retirar do fim\n");
printf("5. Esvaziar\n");
printf("6. Mostrar\n");
printf("7. Contar\n");
printf("8. Remover No Especifico\n");
printf("9. Buscar No Especifico\n");
printf("10. Sair\n");
printf("Opcao: "); scanf("%d", &opt);
return opt;
}
void opcao(node *LISTA, int op){
switch(op){
case 1:
insereInicio(LISTA);
break;
case 2:
insereFim(LISTA);
break;
case 3:
retiraInicio(LISTA);
break;
case 4:
retiraFim(LISTA);
break;
case 5:
libera(LISTA);
break;
case 6:
exibe(LISTA);
break;
case 7:
contaNo(LISTA);
break;
case 8:
removerNo(LISTA);
break;
case 9:
buscar(LISTA);
break;
case 10:
libera(LISTA);
exit(1);
break;
default:
printf("Comando invalido\n\n");

}
}
void inicia(node *LISTA)
{
LISTA->prox = NULL;
LISTA->num = NULL;
tam=0;
}
void insereInicio(node *LISTA)
{
node *novo=(node *) malloc(sizeof(node));
if(!novo){
printf("Sem memoria disponivel!\n");
exit(1);
}
printf("Novo elemento: ");
scanf("%d", &novo->num);
node *oldHead = LISTA->prox;
LISTA->prox = novo;
novo->prox = oldHead;
tam++;
}
void insereFim(node *LISTA)
{
node *novo=(node *) malloc(sizeof(node));
if(!novo){
printf("Sem memoria disponivel!\n");
exit(1);
}

printf("Novo elemento: ");
scanf("%d", &novo->num);
novo->prox = NULL;
if(vazia(LISTA))
LISTA->prox=novo;
else{
node *tmp = LISTA->prox;

while(tmp->prox != NULL)
tmp = tmp->prox;
tmp->prox = novo;
}
tam++;
}

void retiraInicio(node *LISTA)
{
if(LISTA->prox == NULL){
printf("Lista ja esta vazia\n");
}else{
node *tmp = LISTA->prox;

LISTA->prox = tmp->prox;

tam--;
free(tmp);

}
}
void retiraFim(node *LISTA)
{
if(LISTA->prox == NULL){
printf("Lista ja vazia\n\n");
}else{
node *ultimo = LISTA->prox,
*penultimo = LISTA;
while(ultimo->prox != NULL){
penultimo = ultimo;
ultimo = ultimo->prox;
}
penultimo->prox = ultimo->prox;

tam--;

}
}
int vazia(node *LISTA){
if(LISTA->prox == NULL)
return 1;
else
return 0;

}
void libera(node *LISTA)
{
if(!vazia(LISTA)){
node *proxNode, *atual;
atual = LISTA->prox;
while(atual != NULL){
proxNode = atual->prox;

free(atual);
atual = proxNode;
}
LISTA->prox = NULL;
}
}

void exibe(node *LISTA)
{
if(vazia(LISTA)){
printf("Lista vazia!\n\n");
}
else{
node *tmp;
tmp = LISTA->prox;
while( tmp != NULL){
printf("\n%d", tmp->num);
tmp = tmp->prox;
}
printf("\n\n");
}
}
void contaNo(node *LISTA){
int cont=0;
printf("\na quantidade de elementos eh %d",tam);
node *tmp;
tmp = LISTA->prox;
while( tmp != NULL){
cont++;
tmp = tmp->prox;
}
printf("\na quantidade de elementos eh %d",cont);
}
void removerNo(node *LISTA){
int no;
printf("Digite o no a ser removido\n");
scanf("%d",&no);
node *tmp, *aux;
tmp = LISTA->prox;
aux = LISTA;
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
void buscar(node *LISTA){
int no, cont=0, flag =0;
printf("Digite o no a ser encontrado\n");
scanf("%d",&no);
node *tmp, *aux;
tmp = LISTA->prox;
aux = LISTA;
while( tmp != NULL){
cont++;
if(tmp->num == no){
flag =1;
printf("\nno encontrado na pos: %d", cont);
}
aux = tmp;
tmp=tmp->prox;
}
if(cont==0)
{ printf("\nlista vazia\n");
}
else if(flag == 0){printf("\n elemento nao pertence a lista.\n");}
}
