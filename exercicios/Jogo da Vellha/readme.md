#Jogo da Velha:
1 - monte uma tabela/div com 3x3 celulas.

2- coloque bordas nas celulas/divs das tabelas para 
a estrutura ficar igual ao jogo da velha original.
``` 
___|__|___
___|__|___
   |  |
```

3- quando clicar numa celula/div, mostre um alerta com o 
conteúdo dela('0' ou 'X')

4- quando clicar numa celula e ela estiver vazia, altere o conteúdo
para "X" ou "O" de acordo com vez do jogador.
	- 1 detectar que a celula esta vazia.
		usamos o "if"
	- ALTERAR O CONTEUDO DELA
		usamos o innerHTML
	- PARA X OU 0 DE ACORDO COM A VEZ DO JOGADOR.
		usamos a variavel jogador para saber.


5- VERIFICAR SE tem GANHADOR 
  Parte 1- verificar se o jogador X ganhou
  Parte 2- verificar se of jagador 0 ganhou
  Parte 3- verificar se ninguem ganhou ou que acabou o jogo.

6 - Adicionar Placar 
 Parte 1- Adicionar elemento HTML que exibe o placar (Jogador 'X' 4 x 5 Jogador Y)
 Parte 2- Posicionar o placar no centro da pagina.
 PArte 3- Controlar o placar.
