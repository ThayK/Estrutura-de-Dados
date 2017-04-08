/*Nome: Thayanna Klysnney Moreira Nunes
 Matrícula: 16/0146232
 Disciplina: Estrutura de Dados
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* Vai ser criado duas matrizes do tipo 10x10, onde cada uma vai representar um campo de batalha naval. */


void MostrarNaTela(char vetor[10][10]);
void FunctionPreencheMapa(char vetor[10][10]);    
void FunctionPergunta(void);
void FunctionRodaTabuleiro (char vetor[10][10]);
void PlayPlay (void);

char vetor1[10][10];
char vetor2[10][10];
char VetorAcerto1[10][10];
char VetorAcerto2[10][10];

int main(){
         
     printf("\t\t====SEJA BEM-VINDO. VAMOS JOGAR!====\n");
     FunctionPergunta();
    
     return 0;
}

void FunctionPergunta(void){
    
    char opcao1;
    char Aux;
    int i,j;
    
        for(i=0;i<10;i++){			//Colocando água em todos os campos das duas matrizes, jogador 1 e jogador 2
            for(j=0;j<10;j++){
                vetor1[i][j]='~';
            }
        }
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                vetor2[i][j]='~';
            }
        }    
    
 printf("\t=================================================================\n");   
    printf("Jogador 1, voce deseja escolher onde colocar as suas pecas?\nSe sim digite (S)Sim ou (N)Nao para o programa criar automaticamente seu campo: ");
    scanf("%c",&opcao1);
    fflush(stdin);
            
            if((opcao1!='s')&&(opcao1!='S')&& (opcao1!='N')&& (opcao1!='n')){
        printf("\nOpcao invalida");  //meus usuarios podem criar o campo ou podem pedir que o programa gere sozinho
} 
        
            if((opcao1 =='S')||(opcao1 =='s')){
            FunctionPreencheMapa(vetor1);
          
        }
            else{
                if((opcao1 =='N')||(opcao1 =='n'))        {
        printf("Aguarde, estamos gerando seu campo...\n");
		FunctionRodaTabuleiro(vetor1);                    
        }
        
            }
        
    char opcao2;
    
    printf("\t=================================================================\n");
    printf("Jogador 2, voce deseja escolher onde colocar as suas pecas?\nSe sim digite (S)Sim ou (N)Nao para o programa criar automaticamente seu campo: ");
     fflush(stdin);
     scanf("%c",&opcao2);
         
     if((opcao2!='s')&&(opcao2!='S')&& (opcao2!='N')&& (opcao2!='n')){
        printf("\nOpcao invalida");
}
        
            if((opcao2 =='S')||(opcao2 =='s')){
            FunctionPreencheMapa(vetor2);
          
        }
            else{
                if((opcao2 =='N')||(opcao2 =='n')) 
				printf("Aguarde, estamos gerando seu campo...\n");       {
        FunctionRodaTabuleiro(vetor2);                    
        
        }
        
            }
      PlayPlay();        //Depois de formarem os tabuleiros, hora de jogar!!
        
}

void FunctionRodaTabuleiro (char vetor[10][10]){ //Essa função demora para ser exeutada, pois primeiro eu verifico a primeira posição do meu "barco"...
												//Depois eu crio uma variavel direcao que pode gerar 4 valores, nos quais eu defini que meu "barco" vai	...
												//crescer ou para o lado direito ou esquerdo, cima ou baixo, porém, voce pode veriicar que...
												//tem alguns poréns ao criar esse barco em alguns locais, como o tamnho dele ultrapassar minha matriz.
												//Para poder montar outro "barco", eu faço com que ao entrar em um dos meus ifs, eu faço minha variavel..
												//ter um valor, no qual vai ser a flag para entrar no outro laço e montar os outros barcos.
												//Como em alguns casos eu preciso montar mais de 1 barco por tipo, então criei um cont para contar a ...
												//quantidade de vezes que foi criado um barco.
   int i,j,eixox,eixoy,eixoxx,eixoyy,cont=0;
   int flag=4, contbarco=0, direcao,auxEixox,auxEixoy; 
 	int x=0,cont2=0; 
   	srand((unsigned)time(NULL));
    eixox=rand()%10;
    eixoy=rand()%10;
    srand((unsigned)time(NULL));
    direcao=rand()%3;  //escolho a direcao para qual o meu barquinho vai seguir, elas estao separadas em descer , subir, lado direito e lado esquerdo


  while(x==0){
   
	if((direcao==0)&&(eixox>=5)){
		vetor[eixox][eixoy]='A';
		vetor[eixox-1][eixoy]='A';
		vetor[eixox-2][eixoy]='A';
		vetor[eixox-3][eixoy]='A';
		vetor[eixox-4][eixoy]='A';
		x=1;
		//MostrarNaTela(vetor);
	}	
	else{
		if((direcao==1)&&(eixox<=5)){
			vetor[eixox][eixoy]='A';
			vetor[eixox+1][eixoy]='A';
			vetor[eixox+2][eixoy]='A';
			vetor[eixox+3][eixoy]='A';
			vetor[eixox+4][eixoy]='A';
			x=1;
		//	MostrarNaTela(vetor);
		}
	else{
		if((direcao==2)&&(eixoy>=5)){
			vetor[eixox][eixoy]='A';
			vetor[eixox][eixoy-1]='A';
			vetor[eixox][eixoy-2]='A';
			vetor[eixox][eixoy-3]='A';
			vetor[eixox][eixoy-4]='A';
			x=1;
		//	MostrarNaTela(vetor);
		}
	else{
		if((direcao==3)&& (eixoy<=5)){
			vetor[eixox][eixoy]='A';
			vetor[eixox][eixoy+1]='A';
			vetor[eixox][eixoy+2]='A';
			vetor[eixox][eixoy+3]='A';
			vetor[eixox][eixoy+4]='A';
			x=1;
		//	MostrarNaTela(vetor);
		}
	}
	}	
	}
	if(x==1){
	  x=2;	//flag para sair do laço
	}
	else{
    x=0;  //Caso em nem um caso consiga entrar no if eu vou gerar novas posições
   srand((unsigned)time(NULL));
   direcao=rand()%3;
   }
}


//COMECA O 'T'
srand((unsigned)time(NULL));
    eixox=rand()%10;
    eixoy=rand()%10;
    srand((unsigned)time(NULL));
    direcao=rand()%3;
    

while(x==2){  //esse  x=2 veio do while de cima, para poder chegar até aqui e formar o proximo barco.
 			  //Nesse caso e nos outros nós temos um if antes de entrar e montar os barcos...
			   //No primeiro caso A, não precisava colocar pois todos os campos eram água..
			   //Nos casos abaixo podemos ter "barcos" preenchidos nas posições em que a função rand gerar...
			   //e não podemos preencher em cima desses campos ocupados 		
	if((direcao==0)&&(eixox>=5)){
	 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox-1][eixoy]=='~')&&(vetor[eixox-2][eixoy]=='~')&&(vetor[eixox-3][eixoy]=='~')){
		
		vetor[eixox][eixoy]='T';
		vetor[eixox-1][eixoy]='T';
		vetor[eixox-2][eixoy]='T';
		vetor[eixox-3][eixoy]='T';
		x=1;
		cont++;
		//MostrarNaTela(vetor);
 }	
}
	else{
		if((direcao==1)&&(eixox<=5)){
		 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox+1][eixoy]=='~')&&(vetor[eixox+2][eixoy]=='~')&&(vetor[eixox+3][eixoy]=='~'))	{
		 
			vetor[eixox][eixoy]='T';
			vetor[eixox+1][eixoy]='T';
			vetor[eixox+2][eixoy]='T';
			vetor[eixox+3][eixoy]='T';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==2)&&(eixoy>=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy-1]=='~')&&(vetor[eixox][eixoy-1]=='~')&&(vetor[eixox][eixoy-1]=='~')){
		
			vetor[eixox][eixoy]='T';
			vetor[eixox][eixoy-1]='T';
			vetor[eixox][eixoy-2]='T';				//No decorrer do programa vou diminuindo as condições dentro do if, pois o tamanho dos "barcos" vão diminuindo
			vetor[eixox][eixoy-3]='T';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==3)&& (eixoy<=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy+1]=='~')&&(vetor[eixox][eixoy+2]=='~')&&(vetor[eixox][eixoy+3]=='~')){
		
			vetor[eixox][eixoy]='T';
			vetor[eixox][eixoy+1]='T';
			vetor[eixox][eixoy+2]='T';
			vetor[eixox][eixoy+3]='T';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	}
	}	
	}
	if((x==1)&&(cont==2)){ //cont==2 porque eu tenho que criar dois "barcos"
	  x=3;	
	}
	else{
    x=2;
   srand((unsigned)time(NULL)); 
   direcao=rand()%3;   
   cont2++;
  
    if(cont2>5){	//Criei uma regra que se passarem pelos campos 5 vezes e nao formar nem um barco então eu troco a posição
      eixox=rand()%10;
      eixoy=rand()%10;	
	  cont2=0;	
	}
   
   }
	
}

//COMECA O 'C'
 
srand((unsigned)time(NULL));
    eixox=rand()%10;
    eixoy=rand()%10;
    srand((unsigned)time(NULL));
    direcao=rand()%3;
    cont=0;
    cont2=0;

while(x==3){
	if((direcao==0)&&(eixox>=5)){
	 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox-1][eixoy]=='~')&&(vetor[eixox-2][eixoy]=='~')){
		
		vetor[eixox][eixoy]='C';
		vetor[eixox-1][eixoy]='C';
		vetor[eixox-2][eixoy]='C';
		x=1;
		cont++;
		//MostrarNaTela(vetor);
 }	
}
	else{
		if((direcao==1)&&(eixox<=5)){
		 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox+1][eixoy]=='~')&&(vetor[eixox+2][eixoy]=='~'))	{
		 
			vetor[eixox][eixoy]='C';
			vetor[eixox+1][eixoy]='C';
			vetor[eixox+2][eixoy]='C';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==2)&&(eixoy>=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy-1]=='~')&&(vetor[eixox][eixoy-1]=='~')){
		
			vetor[eixox][eixoy]='C';
			vetor[eixox][eixoy-1]='C';
			vetor[eixox][eixoy-2]='C';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==3)&& (eixoy<=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy+1]=='~')&&(vetor[eixox][eixoy+2]=='~')){
		
			vetor[eixox][eixoy]='C';
			vetor[eixox][eixoy+1]='C';
			vetor[eixox][eixoy+2]='C';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	}
	}	
	}
	if((x==1)&&(cont==3)){
	 // MostrarNaTela(vetor);
	  x=4;	
	}
	else{
    x=3;
   srand((unsigned)time(NULL));
   direcao=rand()%3;
   cont2++;

    if(cont2>5){
      eixox=rand()%10; //gerando os valores
      eixoy=rand()%10;	
	  cont2=0;	
	}
   
   }
	
} 

//COMECA O 'S'

srand((unsigned)time(NULL));
    eixox=rand()%10;
    eixoy=rand()%10;
    srand((unsigned)time(NULL));
    direcao=rand()%3;
    cont=0;
    cont2=0;

while(x==4){
	if((direcao==0)&&(eixox>=5)){
	 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox-1][eixoy]=='~')){
		
		vetor[eixox][eixoy]='S';
		vetor[eixox-1][eixoy]='S';
		x=1;
		cont++;
		//MostrarNaTela(vetor);
 }	
}
	else{
		if((direcao==1)&&(eixox<=5)){
		 if((vetor[eixox][eixoy]=='~')&&(vetor[eixox+1][eixoy]=='~'))	{
		 
			vetor[eixox][eixoy]='S';
			vetor[eixox+1][eixoy]='S';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==2)&&(eixoy>=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy-1]=='~')){
		
			vetor[eixox][eixoy]='S';
			vetor[eixox][eixoy-1]='S';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	else{
		if((direcao==3)&& (eixoy<=5)){
		if((vetor[eixox][eixoy]=='~')&&(vetor[eixox][eixoy+1]=='~')){
		
			vetor[eixox][eixoy]='S';
			vetor[eixox][eixoy+1]='S';
			x=1;
			cont++;
		//	MostrarNaTela(vetor);
		}
	}
	}
	}	
	}
	if((x==1)&&(cont==4)){
	  //MostrarNaTela(vetor);
	  x=7;	
	}
	else{
    x=4;
   srand((unsigned)time(NULL));
   direcao=rand()%3;
   cont2++;

    if(cont2>5){
      eixox=rand()%10;
      eixoy=rand()%10;	
	  cont2=0;	
	}
   
   }
	
} 
   
}

void FunctionPreencheMapa(char vetor[10][10]){
    									
    int i,j,m,n,contbarco,barcos;   //Essa função eu deixo com que meu usuario insira os "barcos"
    int cont=0;
    int Maux=0,Naux=0;
     //char vetor[10][10];
     char troca;
    
     for (i=0;i<10;i++){
         for(j=0;j<10;j++){
             vetor[i][j]='~';
         }
     }
     MostrarNaTela(vetor);
    
	printf("\t=================================================================\n");
    printf("Primeiro vamos colocar 1 porta-avioes. Sao 5 casas seguidas que ele deve ocupar!\n");    
    for    (contbarco=0;contbarco<5;contbarco++){
        
        
        printf("*Preencha sempre em posicoes sequencias!*\n");
        printf("Coloque a linha que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&m);
        fflush(stdin);
        
        printf("\nColoque a coluna que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&n);    
        fflush(stdin);
    
        if((cont == 1)&&((((Naux<n) && (n>5)) || ((Maux<m)&&(m>5))) ||
        (((Naux>n) && (n<5)) || ((Maux>m)&&(m<5))) )){	
         												//Nesse if eu trabalho o fato que a minha primeira posição meu usuário pode colocar...
         												//em qualquer lugar do campo, porém...a minha segunda posição do barco só pode ser colocada..
         												//em locais onde não ultrapasse a matriz...
            printf  ("\nPosicao invalida!");
            exit(0);   
        }
        

    
        for(i=0;i<10;i++){
          for(j=0;j<10;j++){
              if((m == i) && (n == j)){
                
                Maux=m; //eu salvo a posicao nessas variaveis, pois no if de cima. Na verificação da segunda posicao, como explicado, eu devo comparar...
                		//com as posicoes novas que estão sendo inseridas...
                Naux=n;    
                
                //fazer o flag
                
                if(vetor[i][j] == '~'){	//verifico se o local esta preenchido com '~'(agua), se sim, eu posso preencher, se nao, nao posso.
                  vetor[i][j]= 'A';
                cont++;
            }
                else{
                  printf("\nLocal preenchido");
                  exit(0);    
                }
                
           }
              
        }    
    }
}
    MostrarNaTela(vetor);
    
     Maux=0;
     Naux=0;
     cont=0;
     printf("\t=================================================================\n");
	 printf("Segundo vamos colocar 2 Navios-Tanque. Sao 4 casas seguidas que ele deve ocupar!\n");
    
    for(barcos=0;barcos<2;barcos++){ //quantidade de "barcos" que precisam ser colocados
    
     printf("Proximo Navio-Tanque!\n");
    for    (contbarco=0;contbarco<4;contbarco++){
    	printf("*Preencha sempre em posicoes sequencias!*\n");
        printf("Coloque a linha que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&m);
        fflush(stdin);
        
        printf("\nColoque a coluna que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&n);    
        fflush(stdin);
        
        if((cont == 1)&&((((Naux<n) && (n>4)) || ((Maux<m)&&(m>4))) ||
        (((Naux>n) && (n<4)) || ((Maux>m)&&(m<4))) )){
            printf  ("\nPosicao invalida!");
            exit(0);   
        }
                
        for(i=0;i<10;i++){
          for(j=0;j<10;j++){
              if((m == i) && (n == j)){
                  
                  Maux=m;
                Naux=n;    
                if(vetor[i][j] == '~'){
                  vetor[i][j]='T';
                cont++;    
             }
               else{
                   printf("\nPosicao invalida!");
                   exit(0);
               }
              
          }    
        }
    }
    }
 }
	
    MostrarNaTela(vetor);
    Maux=0; //zerando as variaveis para serem usadas novamente...
     Naux=0;
     cont=0;
    
    printf("\t=================================================================\n");
    printf("Terceiro vamos colocar 3 Contratorpedeiros. Sao 3 casas seguidas que ele deve ocupar!\n");
    for(barcos=0;barcos<3;barcos++){
        printf("Proximo Contratorpedeiros!\n");
    for    (contbarco=0;contbarco<3;contbarco++){
    	printf("*Preencha sempre em posicoes sequencias!*\n");
        printf("Coloque a linha que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&m);
        fflush(stdin);
        
        printf("\nColoque a coluna que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&n);    
        fflush(stdin);
        
        if((cont == 1)&&((((Naux<n) && (n>3)) || ((Maux<m)&&(m>3))) ||
        (((Naux>n) && (n<3)) || ((Maux>m)&&(m<3))) )){
            printf  ("\nPosicao invalida!");
            exit(0);   
        }
                
        for(i=0;i<10;i++){
          for(j=0;j<10;j++){
              if((m == i) && (n == j)){
                 
                Maux=m;
                Naux=n;    
                if(vetor[i][j] == '~'){
                  vetor[i][j]='C';
                cont++;    
                 }
               else{
                   printf("\nPosicao invalida!");
                exit(0);               
               }
          }    
        }
    }
}
}
     
    MostrarNaTela(vetor);
    
    Maux=0;
    Naux=0;
    cont=0;
    
	printf("\t=================================================================\n");
    printf("Por ultimo vamos colocar 4 Submarinos. Sao 2 casas seguidas que ele deve ocupar!\n");
    for(barcos=0;barcos<4;barcos++){
     printf("Proximo Submarino\n");
    for(contbarco=0;contbarco<2;contbarco++){
    	printf("*Preencha sempre em posicoes sequencias!*\n");
        printf("Coloque a linha que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&m);
        fflush(stdin);
        
        printf("\nColoque a coluna que deseja colocar o pedaco do seu barco: ");
        scanf("%d",&n);    
        fflush(stdin);
        
    if((cont == 1)&&((((Naux<n) && (n>2)) || ((Maux<m)&&(m>2))) ||
        (((Naux>n) && (n<2)) || ((Maux>m)&&(m<2))) )){
            printf  ("\nPosicao invalida!");
            exit(0);   
        }
        
        for(i=0;i<10;i++){
          for(j=0;j<10;j++){
              if((m == i) && (n == j)){
                Maux=m;
                Naux=n;    
                if(vetor[i][j] == '~'){
                  vetor[i][j]= 'S';
                cont++;
              }
              else{
                  printf("\nPosicao invalida!");
                  exit(0);
              }
          }    
        }
    }
}    
}
	 
    MostrarNaTela(vetor);


}

void MostrarNaTela(char vetor[10][10]){
    
    int i,j;    
    printf("\t=================================================================\n");
	printf("\t\t\t==============SEU MAPA!==============\n");
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                printf("\t %c",vetor[i][j]);
            }
            printf("\n\n");
        }    
    
}

void PlayPlay (void){
    
    int m,n,i,j,k,x,w,t;
    int pontuacao1=0, pontuacao2=0;
    int men=1,fim=2;
    	//Essa função é o momento do jogo, depois que os vetores preenchidos estão montados, independente se o usuario pediu para gerar..
    	//ou se o usuario pediu para que fosse gerado automaticamente...
                       
    for(k=0;k<10;k++){
      for(x=0;x<10;x++){
          VetorAcerto1[k][x]='~';
      }
    }
    k=1;   //so para preencher o VetorAuxiliar para ver se acertou na agua com ~
    x=1;
    for(w=0;w<10;w++){
      for(t=0;t<10;t++){
          VetorAcerto2[w][t]='~';
      }
    }
    w=1; //Igualo a 1 as variaveis para nao entrar mais nesses laços de repeticao
    t=1;
    
    while((pontuacao1<30) || (pontuacao2<30)){ //Para ganhar o primeiro tem que fazer 30 pontos, ou seja acertar 30 quadradinhos ou melhor, locais onde estao os barcos do parceiro
    
    if(men==1){
        
    printf("Jogador 1, em qual linha quer jogar bomba: ");
    scanf("%d",&m);
    fflush(stdin);
    
    printf("Jogador 1, em qual coluna quer jogar bomba: ");
    scanf("%d",&n);
    fflush(stdin);
        
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){ /*A,T,C,S*/
                if((m == i)&&(n==j)){
                    if(vetor2[i][j]=='~'){
                        printf("Agua!");       //ifs encadeados para verificar as opcoes e o que tem na posição solicitada pelo jogador 1
                    }
                    else{
                    if(vetor2[i][j]=='A'){
                           printf("Voce acertou um Porta-Aviao. Ganhou 1 ponto\n!");
                         pontuacao1++;  
                         VetorAcerto1[i][j]='A';
                    }
                      else{
                          if(vetor2[i][j]=='T'){
                              printf("Voce acertou um Navio-Tanque. Ganhou 1 ponto!\n");
                             pontuacao1++;
                             
                                VetorAcerto1[i][j]='T';
                          }
                          else{
                              if(vetor2[i][j]=='C'){
                              printf("Voce acertou um Contratorpedeiros. Ganhou 1 ponto!\n");
                             pontuacao1++;
                        
                                VetorAcerto1[i][j]='C';
                              }
                          else{
                              if(vetor2[i][j]=='S'){
                               printf("Voce acertou um Submarino.Ganhou 1 ponto!\n");
                               pontuacao1++;
                              
                                VetorAcerto1[i][j]='S';
                          }
                }
                }
                }
                }
                }
                
            }
        }
        for(i=0;i<10;i++){  //Mostrando na tela o acerto ou nao da jogada de cima, ifs encadeados
      for(j=0;j<10;j++){
          printf("\t %c", VetorAcerto1[i][j]);
      }
      printf("\n");
    }
    
        
        men=2;  //PARA FICAR ALTERNANDO OS JOGADORES
    }
    
    if(men==2){
        
    printf("Jogador 2, em qual linha quer jogar bomba: ");
    scanf("%d",&m);
    fflush(stdin);
    
    printf("Jogador 2, em qual coluna quer jogar bomba: ");
    scanf("%d",&n);
    fflush(stdin);
        
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){ /*A,T,C,S*/
                if((m == i)&&(n==j)){
                    if(vetor1[i][j]=='~'){
                        printf("Agua!");
                    }
                    
                     else{
                    
                      if(vetor1[i][j]=='A'){
                           printf("Voce acertou um Porta-Aviao. Ganhou 1 ponto!\n");
                         pontuacao1++;   
                        
                                VetorAcerto2[i][j]='A';
                                
                                
                            
                      }
                        else{
                        
                          if(vetor1[i][j]=='T'){
                              printf("Voce acertou um Navio-Tanque. Ganhou 1 ponto!\n");
                             pontuacao1++;
                             
                                VetorAcerto2[i][j]='T';
                                
                                
                            
                          }
                          else{
                          
                              if(vetor1[i][j]=='C'){
                              printf("Voce acertou um Contratorpedeiros. Ganhou 1 ponto!\n");
                             pontuacao1++;
                        
                                VetorAcerto2[i][j]='C';
                                
                                
                            
                              }
                          else{
                          
                              if(vetor1[i][j]=='S'){
                              
                               printf("Voce acertou um Submarino. Ganhou 1 ponto!\n");
                               pontuacao1++;
                          
                                VetorAcerto2[i][j]='S';
                                
                                
                            
                            }
                 }}}}
                }
            }
}
        
     for(i=0;i<10;i++){ //mostrando na tela depois de atacar seu adversario se voce acertou ou nao
      for(j=0;j<10;j++){
          printf("\t %c", VetorAcerto2[i][j]);
      }
      printf("\n");
    }
        men=1;
    }
}
      printf("Campo do Jogador 1\n");  //Depois que alguem acertou os 30, sai do laço  e informamos quem ganhou
      MostrarNaTela(vetor1);
      printf("\n");
      printf("Campo do Jogador 2\n");
      MostrarNaTela(vetor2);
      printf("\n");
	  if(pontuacao1>pontuacao2){
            printf("Parabens, jogador 1 ganhou!");
        }
        else{
            if(pontuacao1<pontuacao2){
                printf("Parabens, jogador 2 ganhou!");
            }
        else{
              printf("Empate");
                
        }     
        }
} 
