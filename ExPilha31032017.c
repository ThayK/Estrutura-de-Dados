/*Empilha,Desimpilha -> PILHA
 Thayanna Klysnney, UnB, Estrutura de Dados*/
#include<stdio.h>
#include<stdlib.h>

int MAX=10;

struct Pilha{
	int topo;
	int vetor[10];
	
};

int empilhar (int vlr);
int desempilhar (void);
int pilhacheia(void);
int pilhavazia(void);
Pilha p;

int main(){
   int opcao,valor;
   int valorfun;
   p.topo=-1;
  
 while(1){ //TORNO O LAÇO SEMPRE VERDADEIRO E INFINITO
   printf("\nO que deseja\n");
   printf("(1)Empilhar\n");
   printf("(2)Desimpilhar\n");
   printf("Opcao: ");
   scanf("%d",&opcao); 
   fflush(stdin);
   
   
   
	  if(opcao==1){
	  	if(pilhacheia()==1){ //CHAMO UMA FUNÇÃO PARA SER FEITA A VERIFICAÇÃO SE A PILHA ESTÁ CHEIA, POIS SE ESTIVER NÃO PODEMOS COLOCAR MAIS ELEMENTOS
	  		printf("Pilha cheia");
	  		exit(1);
		  }
		  
		printf("Digite o valor que deseja empilhar\n");
	  	scanf("%d",&valor); //CASO A PILHA NAO ESTEJA CHEIA COLOCAMOS MAIS ELEMENTOS
	  	
	  	empilhar(valor); //PASSO O VALOR INSERIDO PELO USUÁRIO PARA MINHA FUNÇÃO
	 	 
	  	printf("Empilhado: %d, posicao: %d",p.vetor[p.topo],p.topo);  
	  }
   	
		else{
   	  	
		if(opcao==2){
			if(pilhavazia()==1) //NA OPÇÃO ACIMA VERIFIQUEI SE A PILHA ESTAVA CHEIA, AGORA VERIFICO SE ELA ESTÁ VAZIA, POIS SE ESTIVER NÃO TEMOS COMO RETIRAR NADA
			{
				printf("Pilha vazia");
				exit(1);
			}
			valorfun=desempilhar(); //NESSE CASO, A MINHA FUNCAO RETORNA ALGO PARA MEU PROGRAMA, POR ISSO CRIEI UMA VARIAVEL PARA RECEBER ALGO DA FUNÇÃO 'VALORFUN'
		     					
			 printf("Desempilhado: %d, posicao: %d\n",valorfun,p.topo); 
			 p.topo--;	
			 }
		 }
}
	return 0;
}

int empilhar (int vlr){
	p.topo++;  //DECLAREI MINHA VARIAVEL COMO TOPO=-1 ANTES POIS A POSIÇÃO 0 CONTA COMO POSIÇÃO, PORTANTO A PRIMEIRA POSICAO SERA 0. 
	p.vetor[p.topo]=vlr;  //O VALOR QUE MEU USUARIO INSERIU VAI SER COLOCADO NA POSICAO P.TOPO++
	return p.topo,p.vetor[p.topo];  
}
 
int desempilhar (void){
	
	int auxposition;
	int auxvalor;   
	auxvalor=p.vetor[p.topo];//QUANDO DESEMPILHO PEGO O ULTIMO VALOR E RETIRO DA PILHA, POR ISSO CRIO UMA VARIAVEL AUXILIAR NA QUAL VAI SALVAR ESSE ULTIMO VALOR 
	return auxvalor;
} 

int pilhacheia(void){
	
	if(p.topo<MAX){	//NO INICIO DO PROGRAMA FOI PRE-DEFINIDO QUAL SERIA O MAXIMO DE ELEMENTOS QUE TERIA NA MINHA PILHA , NO CASO 10, POR ISSO SO PODEMOS 
		return 0;   //CONTIN...COLOCAR ELEMENTOS ATE QUE A PILHA<10
	}
	else{
		return 1;	//RETURN 1 OU 0, SIGNIFICA EU RETORNAR SE ISSO É VERDADEIRO OU FALSO
	}
}

int pilhavazia(void){
	if(p.topo==-1)	{
	
		return 1;
}
   else{
   	return 0;
   }
}
