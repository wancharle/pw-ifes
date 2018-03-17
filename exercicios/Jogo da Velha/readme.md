# Jogo da Velha: (Tic Tac Toe)
## Passo a Passo (Walkthrough)

1. Monte uma tabela/div com 3x3 celulas.

2.  Coloque bordas nas celulas/divs das tabelas para a estrutura ficar igual ao jogo da velha original.
``` 
___|__|___
___|__|___
   |  |
```

3.  Quando clicar numa celula/div, mostre um alerta com o conteúdo dela('0' ou 'X')

4.  Quando clicar numa celula e ela estiver vazia, altere o conteúdo para "X" ou "O" de acordo com vez do jogador.
    * Detectar que a celula esta vazia: use a estrutura "if"
    * Alterar o conteudo da celula: use a propriedade innerHTML da celula
    * Descobrir a vez do jogador: criar uma variavel 'jogador' que marque a letra do jogador atual.

5. Verifique se tem ganhador 

   a. Verifique se o jogador X ganhou com estruturas ifs
   
   b. Verifique se o jogador O ganhou com estruturas ifs
   
   c. Verifique se ninguem ganhou ou que acabou o jogo.

6. Adicionar Placar 

   a. Adicionar elemento HTML que exibe o placar (Jogador 'X' 4 x 5 Jogador Y)
   
   b. Posicionar o placar no centro da pagina.
   
   c. Controlar o placar.
