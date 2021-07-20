#include <stdio.h>
#include <stdlib.h>

int fat(int num){
    if(num>0){
  	  return num*fat(num-1);
    }
    else if (num<0)
        return 0;
    else
        return 1;
}

int main()
{
    int num;
	printf("Digite o numero para seber o fatorial dele :\n ");
	scanf("%d", &num);
	printf("\nO fatorial de %d e' %d", num, fat(num));
	return 0;
}
