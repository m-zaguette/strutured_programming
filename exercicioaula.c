#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void alocac(char **p, int tam);
void alocai(int **p, int tam);
void maiuscula(char *p, int tam);
void imprimir(char *p, int tam);
void ordenar(char *p, int tam);
void limpar(char *p, int tam);

int main(){
	
	char *p = NULL;
	char *pfinal = NULL;
	char parar;
	int tamtot=0;
	int tam=0;
	int contador=0;
	char aux[50];
	int *pint = NULL;
	
	do{
		printf("Digite o %i nome: ",contador+1);
		gets(aux);
		fflush(stdin);
		
		tam = strlen(aux);
		
		tam++;
		
		tamtot += tam;
		
		alocac(&p,tamtot);
		
		alocac(&pfinal,tamtot);
	
		if(contador==0){
			strcpy(p,aux);
		}else{
			strcat(p,aux);
		}
		
		maiuscula(aux,tamtot);
		
		if(contador==0){
			strcpy(pfinal,aux);
		}else{
			strcat(pfinal,aux);
		}
		
		contador++;
		
		
		printf("Deseja continuar? <S/N> ");
		scanf("%c",&parar);
		fflush(stdin);
		
		strcat(p," ");
		
	}while(parar!='N' && parar!='n');
	
	imprimir(p,tamtot);
	imprimir(pfinal,tamtot);
	
	ordenar(pfinal,tamtot);
	
	imprimir(pfinal,tamtot);


	/*limpar(pfinal, tamtot);
	imprimir(p);
	imprimir(pfinal);
	ordenar(pfinal,tamtot);
	limpar(pfinal, tamtot);
	ordenar(pfinal,tamtot);
	imprimir(p);
	imprimir(pfinal);
	*/
	alocai(&pint,tamtot);
	
	
	
}

void alocac(char **p, int tam){
	if( (*p = (char *) realloc (*p, tam*sizeof(char)))== NULL){
		printf("Deu ruim nos char campeao\n");
		exit(1);
	}
}

void maiuscula(char *p, int tam){
	int i=0;
	for(i=0;i<tam;i++){
		if(*(p+i) >= 'a' && *(p+i) <= 'z'){
			*(p+i) -= 32;
		}
	}
}

void imprimir(char *p, int tam){
	int i=0;
	printf("\n");
	for(i=0;i<tam;i++){
		printf("%c",*(p+i));
	}
	printf("\n");	
}

void ordenar(char *p, int tam){
	int i=0,j=0;
	char aux;
	int contador=0;
	
	for(i=0;i<tam;i++){
		for(j=0;j<tam-1;j++){
			//if(*(p+i) == '~'){
			//	contador++;
			//}
			if( *(p+j) > *(p+j+1)){
				aux = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = aux;
			}
		}
	}
	//*(p+(tam-contador)) = '\0';
}

void alocai(int **p, int tam){
	if( (*p = (int *) realloc (*p, tam*sizeof(int))) == NULL){
		printf("Deu ruim nos inteiros campeao\n");
		exit(1);
	}
}

void limpar(char *p, int tam){
	int i=0;
	for(i=0;i<tam;i++){
		if(*(p+i) == (*p+i+1)){
			*(p+i) = '~';
			*(p+i+1) = '~';
		}
	}
}
