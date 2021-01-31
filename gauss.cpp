//Metodo dos Minimos Quadrados
//Nome: Marcelo Zaguette Junior RA: 180998;
#include<stdio.h>
#include<stdlib.h>
void mmq
void preenchermatriz(float *p, int lin, int col);
void imprimir (float *p, int lin, int col);
void gauss3 (float *p, int lin, int col);
void gauss2 (float *p, int lin, int col);
void resolve2(float *p, int lin, int col);
void resolve3(float *p, int lin, int col);

int main(){
	int xtot=0,ytot=0;
	printf("Digite a quantidade total de x e de y: ");
	scanf("%i %i",&xtot,&ytot);
	
	int linecol=0;
	int i=0,j=0;
	do
	{
		printf("\nDigite o grau da equacao (2 ou 3): ");
		scanf("%i",&linecol);
		fflush(stdin);
		printf("\nO grau da equacao e: %i\n",linecol);
	}while( (linecol != 2) && (linecol != 3) );
	
	float matrizgauss[linecol][linecol+1];
	
	preenchermatriz(*matrizgauss, linecol, linecol+1);
	
	system("cls");
	
	printf("\tMatriz digitada:\n");
	imprimir(*matrizgauss, linecol, linecol+1);
	
	if(linecol == 3){
		gauss3(*matrizgauss,linecol,linecol+1);
	}
	if(linecol == 2){
		gauss2(*matrizgauss,linecol,linecol+1);
	}
	printf("\tResolucao atraves de Gauss:\n");
	imprimir(*matrizgauss,linecol,linecol+1);
	
	if(linecol == 3){
		resolve3(*matrizgauss,linecol,linecol+1);
	}
	if(linecol == 2){
		resolve2(*matrizgauss,linecol,linecol+1);
	}	
	
	return 0;
}

void preenchermatriz (float *p, int lin, int col){
	int i=0, j=0;
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("\nMatriz[%i][%i]: ",i+1,j+1);
			scanf("%f",(p+i*col+j));
			fflush(stdin);
		}
	}
}

void imprimir (float *p, int lin, int col){
	int i=0,j=0;
	printf("\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("\t%.2f",*(p+i*col+j));
		}
		printf("\n");
	}
	printf("\n");
}

void gauss2 (float *p, int lin, int col){
	float pivo = ((*(p+1*col+0))/(*(p+0*col+0)));
	printf("\n");
	//printf("\nO pivo da matriz 2 vai ser: %.2f\n",pivo);
	int i=0,j=0;
	pivo *= -1;
	for(i=0;i<col;i++){
		//Linha2' = Linha2 + Linha1 * (-)pivo;
		*(p+1*col+i) += *(p+0*col+i)*pivo;
	}
}

void gauss3 (float *p, int lin, int col){
	float pivo1 = ((*(p+1*col+0))/(*(p+0*col+0)));
	float pivo2 = ((*(p+2*col+0))/(*(p+0*col+0)));
	//float pivo3 = ((*(p+2*col+1))/(*(p+1*col+1)));
	//printf("\n");
	//printf("\nO primeiro pivo valor: %.2f",pivo1);
	//printf("\nO segundo pivo valor: %.2f",pivo2);
	//printf("\nO terceiro pivo valor: %.2f",pivo3);
	int i=0,j=0;
	pivo1 *= -1;
	pivo2 *= -1;
	for(i=0;i<col;i++){
		//Linha2' = Linha2 + Linha1 * (-)pivo1;
		//Linha3' = Linha3 + Linha1 * (-)pivo2;
		//Linha3' = Linha3 + Linha2 * (-)pivo3;
		*(p+1*col+i) += *(p+0*col+i)*pivo1;	
	}
	for(i=0;i<col;i++){
		*(p+2*col+i) += *(p+0*col+i)*pivo2;
	}
	float pivo3 = ((*(p+2*col+1))/(*(p+1*col+1)));
	//printf("\nO terceiro pivo valor: %.2f",pivo3);
	pivo3 *= -1;
	for(i=0;i<col;i++){
		*(p+2*col+i) += *(p+1*col+i) *pivo3;
	}
}

void resolve2(float *p, int lin, int col){
	int i=0;
	float linha1=0,linha2=0;
	linha2 = (*(p+1*col+2) / *(p+1*col+1));
	linha1 = ((*(p+0*col+2) - (*(p+0*col+1) * linha2))/ *(p+0*col+0));
	printf("\nValor na primeira linha(x): %.2f",linha1);
	printf("\nValor na segunda linha(y): %.2f\n",linha2);
}

void resolve3(float *p, int lin, int col){
	int i=0;
	float linha1=0,linha2=0,linha3=0;
	linha3 = (*(p+2*col+3) / *(p+2*col+2));
	linha2 = ((*(p+1*col+3) - (*(p+1*col+2) * linha3))/ *(p+1*col+1));
	linha1 = (( *(p+0*col+3) - (*(p+0*col+2) * linha3) - (*(p+0*col+1) * linha2)) / *(p+0*col+0));
	printf("\nValor na primeira linha(x): %.2f",linha1);
	printf("\nValor na segunda linha(y): %.2f",linha2);
	printf("\nValor na terceira linha(z): %.2f\n",linha3);
}
