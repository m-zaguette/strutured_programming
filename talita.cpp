//Metodo dos Minimos Quadrados
//Nome: Marcelo Zaguette Junior RA: 180998;
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void valoresxy(float *px,float *py,int tot);
void mmqmatriz2(float *x, float *pu0, float *pu1, int tot);
void mmqmatriz3(float *x, float *pu0, float *pu1, float *pu2, int tot);
//void preenchermatriz(float *p, int lin, int col);
void preenchermatriz2 (float *pu0, float *pu1, float *py, float *p, int tot, int col);
void preenchermatriz3(float *pu0, float *pu1, float *pu2, float *py, float *p, int tot, int col);
void imprimir (float *p, int lin, int col);
void gauss3 (float *p, int lin, int col);
void gauss2 (float *p, int lin, int col);
void resolve2(float *p, int lin, int col);
void resolve3(float *p, int lin, int col);

int main(){
	int xtot=0,ytot=0;
	int i=0,j=0;
	printf("Digite a quantidade total de x e de y (apenas 1 numero, os dois tem que ser iguais): ");
	scanf("%i",&xtot);
	
	ytot = xtot;
	
	float x[xtot];
	float y[ytot];
	
	valoresxy(x,y,xtot);
	
	int linecol=0;
	
	do
	{
		printf("\nDigite o grau da equacao (1 ou 2): ");
		scanf("%i",&linecol);
		linecol++;
		fflush(stdin);
		printf("\nO grau da equacao e: %i\n",linecol-1);
	}while( (linecol != 2) && (linecol != 3) );
	
	
	float matrizgauss[linecol][linecol+1];
	
	if(linecol==2){
		float u0[xtot],u1[xtot];
		mmqmatriz2(x,u0,u1,xtot);
		preenchermatriz2(u0,u1,y,*matrizgauss, xtot, linecol+1);
	}
	if(linecol==3){
		float u0[xtot],u1[xtot],u2[xtot];
		mmqmatriz3(x,u0,u1,u2,xtot);
		preenchermatriz3(u0,u1,u2,y,*matrizgauss, xtot, linecol+1);
	}
	
	//preenchermatriz(*matrizgauss, linecol, linecol+1);
	
	system("cls");
	
	printf("\tMatriz:\n");
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

void preenchermatriz2 (float *pu0, float *pu1, float *py, float *p, int tot, int col){
	int i=0;
	float u0u0=0,u0u1=0,u1u0=0,u1u1=0,yu0=0,yu1=0;
	for(i=0;i<tot;i++){
		u0u0 += pow(*(pu0+i),2);
		u0u1 += (*(pu0+i)) * (*(pu1+i));
		u1u0 = u0u1;
		u1u1 += pow(*(pu1+i),2);
		yu0 += (*(py+i))*(*(pu0+i));
		yu1 += (*(py+i))*(*(pu1+i));
	}
	*(p+0*col+0) = u0u0;
	*(p+0*col+1) = u0u1;
	*(p+0*col+2) = yu0;
	*(p+1*col+0) = u1u0;
	*(p+1*col+1) = u1u1;
	*(p+1*col+2) = yu1;
}

void preenchermatriz3(float *pu0, float *pu1, float *pu2, float *py, float *p, int tot, int col){
	int i=0;
	float u0u0=0 , u0u1=0 , u0u2 , u1u0=0 , u1u1=0 , u1u2=0 , u2u0=0 , u2u1=0 , u2u2=0 , yu0=0 , yu1=0, yu2=0;
	for(i=0;i<tot;i++){
		u0u0 += pow(*(pu0+i),2);
		u0u1 += (*(pu0+i))*(*(pu1+i));
		u0u2 += (*(pu0+i)) * (*(pu2+i));
		yu0 += (*(py+i))*(*(pu0+i));
		u1u0 = u0u1;
		u1u1 += pow(*(pu1+i),2);
		u1u2 += (*(pu1+i)) * (*(pu2+i));
		yu1 += (*(py+i))*(*(pu1+i));
		u2u0 = u0u2;
		u2u1 = u1u2;
		u2u2 += pow(*(pu2+i),2);
		yu2 += (*(py+i))*(*(pu2+i));
	}
	*(p+0*col+0) = u0u0;
	*(p+0*col+1) = u0u1;
	*(p+0*col+2) = u0u2;
	*(p+0*col+3) = yu0;
	
	*(p+1*col+0) = u1u0;
	*(p+1*col+1) = u1u1;
	*(p+1*col+2) = u1u2;
	*(p+1*col+3) = yu1;
	
	*(p+2*col+0) = u2u0;
	*(p+2*col+1) = u2u1;
	*(p+2*col+2) = u2u2;
	*(p+2*col+3) = yu2;
	
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
	printf("\n\tp(x) = (%.2f) + (%.2f)*x\n",linha1,linha2);
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
	printf("\n\tp(x) = (%.2f) + (%.2f)*x + (%.2f)*x^2\n",linha1,linha2,linha3);
}

void valoresxy(float *px,float *py,int tot){
	int i=0;
	for(i=0;i<tot;i++){
		printf("Valor %i de X: ",i+1);
		scanf("%f",(px+i));
		fflush(stdin);
	}
	for(i=0;i<tot;i++){
		printf("Valor %i de Y: ",i+1);
		scanf("%f",(py+i));
		fflush(stdin);
	}
}

void mmqmatriz2(float *x, float *pu0, float *pu1, int tot){
	int i=0;
	printf(")\nValores de x ( ");
	for(i=0;i<tot;i++){
		printf("%.2f , ",*(x+i));
	}
	printf(")\n");	
	for(i=0;i<tot;i++){
		*(pu0+i) = pow(*(x+i),0);
	}
	for(i=0;i<tot;i++){
		*(pu1+i) = *(x+i);
	}
	printf("Valores de U0 ( ");
	for(i=0;i<tot;i++){
		printf("%.2f , ",*(pu0+i));
	}
	printf(")\nValores de U1 ( ");
	for(i=0;i<tot;i++){
		printf("%.2f , ",*(pu1+i));
	}
	printf(")\n");
}

void mmqmatriz3(float *x, float *pu0, float *pu1, float *pu2, int tot){
	int i=0;
	for(i=0;i<tot;i++){
		*(pu0+i) = pow(*(x+i),0);
	}
	for(i=0;i<tot;i++){
		*(pu1+i) = pow(*(x+i),1);
	}
	for(i=0;i<tot;i++){
		*(pu2+i) = pow(*(x+i),2);
	}
}
