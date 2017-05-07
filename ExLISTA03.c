#include<stdio.h>
#include<math.h>

float DesvioPadrao (int max, float vetor[]);

int main(){
	int i, max;
	float VoltaFunction;
	
	printf("Digite o maximo de numeros que deseja calcular o desvio:\n");
	scanf("%d",&max);
	
	float vetor[max];   
     
     for(i=0;i<max;i++){
     	printf("Digite o valor: \n");
     	scanf("%f",&vetor[i]);
	 }
    
    VoltaFunction=DesvioPadrao(max,vetor);
 	 printf("Desvio padrao e: %f",VoltaFunction);

return 0;

}

float DesvioPadrao (int max, float vetor[]){
	
  	float soma,media=0.0;
  	int cont;
  	
  for(cont=0;cont<max;cont++){
	 	soma=soma+vetor[cont];
	    		
	 }
	 media=soma/max;
	 //calculo de variancia e depois o desvio 
	 printf("soma=%.1f, media=%.1f",soma,media);
    
    
    //variancia
     float result=0.0;		
	 float variancia=0.0;
	 float desvpadrao=0.0;	
	 
	for(cont=0;cont<max;cont++){
        result=result+((vetor[cont]-media)*(vetor[cont]-media));  	
	}
		
	printf(" %.1f",result);
    
    variancia=result/(max-1);
    desvpadrao=sqrt(variancia);
    
    return desvpadrao;
}
