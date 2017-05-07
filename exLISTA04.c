#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Matriz (int *m, int *n);
int main(){
    int m,n,i,j;
	
	 printf("Digite o numero de linhas: \n");
	 scanf("%d",&m);
	 
	 printf("Digite o numero de colunas: \n");
	 scanf("%d",&n);
	
     int vetor[m][n];
	 srand((unsigned)time(NULL));	 
      for(i=0;i<m;i++){
      	for(j=0;j<n;j++){
      	  vetor[i][j]= (rand()% 100) * 5;	
		  }
	  }
      
	  for(i=0;i<m;i++){
      	for(j=0;j<n;j++){
      	  printf("%d ",vetor[i][j]);
		  }
	  	printf("\n");
	  }	
	
	
	return 0;
}


