#include<stdio.h>
#include<math.h>

void DesvioPadrao (void);

int main(){
  
DesvioPadrao();

return 0;

}

void DesvioPadrao (void){
	
  	float soma,media=0.0;
  	int cont;
	float valores[10];
  	
  	
  	 for(cont=0;cont<10;cont++){
  	 	printf("Digite os valores da pop: ");
  	 	scanf("%f",&valores[cont]);
	   }
	
	 
	 for(cont=0;cont<10;cont++){
	 	soma=soma+valores[cont];
	    		
	 }
	 media=soma/10;
	 //calculo de variancia e depois o desvio 
	 printf("soma=%.1f, media=%.1f",soma,media);
    
    
    //variancia
     float result=0.0;		
	 float variancia=0.0;
	 float desvpadrao=0.0;	
	 
	for(cont=0;cont<10;cont++){
        result=result+((valores[cont]-media)*(valores[cont]-media));  	
	}
		
	printf(" %.1f",result);
    
    variancia=result/9;
    desvpadrao=sqrt(variancia);
    printf("desv padrao = %f",desvpadrao);
}
