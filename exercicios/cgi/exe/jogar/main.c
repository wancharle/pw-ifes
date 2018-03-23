#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "cgi.h"
 
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
       fscanf(f,"%c%c%c",&celulas[0][0],&celulas[0][1],&celulas[0][2]);
       fscanf(f,"%c%c%c",&celulas[1][0],&celulas[1][1],&celulas[1][2]);
       fscanf(f,"%c%c%c",&celulas[2][0],&celulas[2][1],&celulas[2][2]);
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
    fprintf(f,"%c%c%c",celulas[0][0],celulas[0][1],celulas[0][2]);
    fprintf(f,"%c%c%c",celulas[1][0],celulas[1][1],celulas[1][2]);
    fprintf(f,"%c%c%c",celulas[2][0],celulas[2][1],celulas[2][2]);

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
// -----------------------------------------------------------------------------
void printErro400(){
    printf("Status: 400 Bad Request\n");
    printf("Content-type: application/json\n\n");
}
void printOk(){
    printf("Status: 200 OK\n");
    printf("Content-type: application/json\n\n");
}

// -----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  setlocale(LC_ALL,"Portuguese");
  char letra[100] = "";
  char posicao[100] = "";
  int numeroPosicao;
    
  carregaTabuleiroDoBancoParaMemoria();
  
  // ler parametros
  getAllParams();
  getParam("letra", letra);
  getParam("posicao", posicao);
  
  // converte  e checka parametros
  numeroPosicao = atoi(posicao); // converte para inteiro
  if (posicao[0] != '0' && numeroPosicao==0){
     printErro400();
     printf("{ \"erro\": \"Voce deve informar um numero de 0 a 8 no parametro posicao!\"}");
     return 400;
  }
  if (numeroPosicao < 0 || numeroPosicao > 8){
     printErro400();
     printf("{ \"erro\": \"Voce deve informar um numero de 0 a 8 no parametro posicao!\"}");
     return 400;
  }

  // imprime o resultado
  printOk();
  marcaTabuleiro(letra[0],atoi(posicao));
  imprimeTabuleiro();
  salvaTabuleiroNoBanco();
  
  return 0;
}
