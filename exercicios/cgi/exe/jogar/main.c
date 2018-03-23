//#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

 
// -----------------------------------------------------------------------------
char celulas[3][3];


// -----------------------------------------------------------------------------
void inicializaTabuleiroVazio(){
  int l,c;
  for(l=0; l<3;l++){
     for(c=0; c<3;c++){
         celulas[l][c]=' ';
      }
  }
} 


// -----------------------------------------------------------------------------
void carregaTabuleiroDoBancoParaMemoria(){    
    // abre o arquivo para leitura
    FILE *f = fopen("bancoDeDados.txt", "r");
    if (f == NULL){
       // se nao existe arquivo de banco de dados 
       // apenas inicializa o tabuleiro com espacos vazios
       inicializaTabuleiroVazio();
    } else{ 
       rewind(f);
       // le os dados do arquivo e inicializa o tabuleiro com esses dados
       fscanf(f,"%c,%c,%c|",&celulas[0][0],&celulas[0][1],&celulas[0][2]);
       fscanf(f,"%c,%c,%c|",&celulas[1][0],&celulas[1][1],&celulas[1][2]);
       fscanf(f,"%c,%c,%c",&celulas[2][0],&celulas[2][1],&celulas[2][2]);
    }
     // fecha o arquivo     
    fclose(f);     
}


// -----------------------------------------------------------------------------
void salvaTabuleiroNoBanco(){
    // abre o arquivo para leitura
    FILE *f = fopen("bancoDeDados.txt", "w");
    if (f == NULL){
        printf("Error: não foi possivel abrir o arquivo de banco de dados!\n");
        exit(1);
    }
    
    int l,c;
    // imprime os dados no arquivo
    fprintf(f,"%c,%c,%c|",celulas[0][0],celulas[0][1],celulas[0][2]);
    fprintf(f,"%c,%c,%c|",celulas[1][0],celulas[1][1],celulas[1][2]);
    fprintf(f,"%c,%c,%c",celulas[2][0],celulas[2][1],celulas[2][2]);

    // fecha e salva no hd    
    fclose(f);     
}


// -----------------------------------------------------------------------------
void marcaTabuleiro(char letra,int posicao){
  // o indice vai de 0 a 8 representando cada celula do tabuleiro de jogo da velha
  int indice; 
  int l,c;

  for(l=0; l<3;l++){
     for(c=0; c<3;c++){
          // indicie igual numeroLinha * 3 + numeroColuna. Por Exemplo, o centro
          // fica no indice 4, segunda linha(1)*3 + segunda coluna(1) -> 1*3+1=4
          indice = l*3+c;  
          // so marca quando o indice da celula for igual ao da posicao desejada
          if (indice == posicao){
              celulas[l][c]=letra;
          }
     }
  }
}


// -----------------------------------------------------------------------------
void imprimeTabuleiro(){
  int l,c;
  printf("[\n");
  for(l=0; l<3;l++){
       printf(" [");
       for(c=0; c<3;c++){
             printf("\"%c\"",celulas[l][c]);
             if (c<2) printf(",");
     }
     printf("]");
     if (l<2) printf(",\n");
  }
  printf("\n]");  
}

void printErro400(){
    //printf("Status: 400 Bad Request\r\n\r\n");
    printf("Content-Type: text/html\r\n\r\n");
}

void printOk(){
//    printf("Status: 200 OK\r\n\r\n"); ]
      printf("Content-type: text/plain\n\n");
}

// -----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  int posicao;
  char letra;
  // para permitir acentos
  //setlocale(LC_ALL,"Portuguese");

  carregaTabuleiroDoBancoParaMemoria();
  
  char *querystring = getenv("QUERY_STRING");
  char cc[2];
  letra = querystring[6];
  cc[0]=querystring[16];
  cc[1]=0;
  posicao = atoi(cc);
  //printf("%d,%c",posicao,cc);
  //sscanf("?letra=%c&posicao=%c",letra2,posicao2);
  //printf("%s|%c|%c",querystring,,querystring[17]);
  // checando o numero de parametros
  /*if (argc != 3){
    printErro400();
    printf("ERROR: número de parametros errado! Foi fornecido %d parametros!\n");
    printf("Informe dois parametros da seguinte forma:\n\nTERMINAL> jogar.exe  <letra> <posicao>\n\n",argc);	
    return 1;
  }
  
  // obtendo os parametros
  letra = toupper(argv[1][0]);
  posicao = atoi(argv[2]);
  if (letra != 'X' && letra!= 'O'){
    printErro400();
    printf("ERROR: letra incorreta!\nInforme apenas as letras 'X' ou 'O' !\n\n");            
    return 2;
  }
 
  if (posicao < 0 || posicao > 8){
    printErro400();
    printf("ERROR: posição incorreta!\nInforme apenas numeros de '0' a '8' !\n\n");            
    return 3;
  }*/
  printOk();
  marcaTabuleiro(letra,posicao);
  imprimeTabuleiro();
  salvaTabuleiroNoBanco();
  
  return 0;
}
