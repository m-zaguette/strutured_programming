#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
Alocar espa�o para armazenar as temperaturas di�rias registradas durante um m�s.
O programa deve mostrar diariamente (a medida que as temperaturas s�o
inclu�das) a maior temperatura e o dia em que ocorreu. Utilizar fun��o para
aloca��o din�mica.*/
//Ser ou n�o ser, eis a quest�o.
void aloca(int **p, int tam);
void recebe(int *p, int tam);
void imprime(int *m,int tam,int *d);
void imprimetudo(int *p, int *m, int tam, int *d);
void maiorfunc(int *p, int *m, int tam, int *d);
int main(){
	int *ptr = NULL;
	int tam=0;
	int maior=0;
	int parar=0;
	int dia=0;
	time_t t;
	srand((unsigned) time(&t));
	
	do{
	aloca(&ptr,tam+1);
	recebe(ptr,tam);
	maiorfunc(ptr, &maior,tam+1,&dia);
	imprime(&maior,tam+1,&dia);
	tam++;
	printf("\nDeseja continuar? <1/0>\n");
	scanf("%i",&parar);
	fflush(stdin);
	}while(parar!=0);
	
	imprimetudo(ptr,&maior,tam,&dia);
	
	return 0;
}

void aloca(int **p, int tam){
	if(	(*p = (int *) realloc (*p, tam * sizeof(int)))==NULL){
		printf("\tErro na Alocacao\n");
		exit(1);
	}
	printf("\nFuncao Aloca - Endereco: %u", *p);
}

void recebe(int *p, int tam){
	int i=0;
	printf("\nFuncao recebe - Digite os valores \n");
	printf("Endereco: %u - Valor = ",p+tam);
	//scanf("%i",p+tam);
	*(p+tam) = rand()%100;
	printf("%i\n",*(p+tam));
	fflush(stdin);
}

void maiorfunc(int *p, int *m, int tam, int *d){
	int i=0;
	for(i=0;i<tam;i++){
		if(*m < *(p+i)){
			*m = *(p+i);
			*d = i+1;
		}
	}
}

void imprime(int *m,int tam,int *d){
	printf("\nFuncao imprime\nO maior valor entre %i dias eh: %i graus que ocorreu no dia %i\n",tam,*m,*d);
}


void imprimetudo(int *p, int *m, int tam, int *d){
	int i=0;
	printf("\n");
	for(i=0;i<tam;i++){
		printf("O valor da temperatura no dia %i foi %i graus\n",i+1,*(p+i));
	}
	printf("O maior valor entre eles foi %i graus que ocorreu no dia %i\n",*m,*d);
}
