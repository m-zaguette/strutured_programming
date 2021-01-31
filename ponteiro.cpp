#include<bits/stdc++.h>
#define s(x) scanf("%i",x)
#define pb(x) printf("%i ",(*x));
#define p(x) printf("%i ",x);
using namespace std;
int main(){
	int valor[10],*p_valor, i, x=0;
	
	cin>>x;
	
	while(x--){

		for(i = 0 , p_valor = valor; i<10; i++, p_valor++){
			s(p_valor);
		}
		
		cout<<"Posicao da memoria ocupada: "<<endl;
		for(i = 0 , p_valor = valor; i<10; i++, p_valor++){
			p(p_valor);
			if(i==9){
				cout<<endl;
			}
		}
		
		cout<<"Valor guardado na posicao da memoria: "<<endl;
		for(i = 0 , p_valor = valor; i<10; i++, p_valor++){
			pb(p_valor);
			if(i==9){
				cout<<endl;
			}
		}
	}
}
