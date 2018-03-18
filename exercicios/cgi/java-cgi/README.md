# Olá mundo! em java-cgi

## Iniciando servidor cgi

Dê dois cliques no arquivo servidor-java.py para iniciar o servidor cgi com suporte a java.
![executanto servidor](/aulas/img/java-1.PNG)

## Acesse o site

Acesse o site no navegador pelo endereço http://localhost/index.html

![executanto servidor](/aulas/img/java2.PNG)

A pagina-estática acima oferece 3 opções de enviar dados para a pagina-dinâmica ola.class. Essa pagina, ola.class, foi compilada com o seguinte comando:
```
javac ola.java
```

### Enviando por GET
Ao escolher enviar pelo método GET temos o seguinte resultado:

![executanto servidor](/aulas/img/java3.PNG)

Observe que o método de envio foi identificado.

Observe que todos os parametros do formuário GET foram identificados na seção Variáveis GET.

E o mais importante, observe que essas variavéis tem seu conteúdo exposto também na barra de endereço do navegador

### Enviando por POST
Ao escolher o segundo formulário(POST) temos a reposta abaixo:
![executanto servidor](/aulas/img/java4.PNG)

Observe que acontece algo similar com o que aconteceu antes, porém agora nao temos as variáveis expostas na barra de endeços do navegador.

### Enviando por POST + GET
Por fim, deve-se observar que é possível enviar dados pelos dois métodos ao mesmo tempo como mostra a imagem abaixo:

![executanto servidor](/aulas/img/java5.PNG)
