#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[])
{
  printf("Content-type: text/plain\n\n");

  printf("Ola,");
  /* processando algo no servidor que leve 5 segundos */
  Sleep(5000);
  /* fim do processamento */
  printf("mundo!");  
  return 0;
}
