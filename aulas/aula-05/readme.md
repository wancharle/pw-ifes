# Aula 5 - Formulários

Nesta aula vc ficará sabendo tudo que precisa saber sobre formulários na internet.

## Formulários em HTML
O formulário é o meio que permite criar mais interatividade entre a programação e o usuário.

É por meio dele que recebemos os dados fornecidos pelos usuários para armazezar num banco de dados, processar ou testar algumas condições.

Um formulário é representado no HTML através da tag **\<form>**. Um formulário possui vários campos que permitem a entrada de dados. Segue abaixo uma lista das mais utilizadas para criação de formulários:

| Tag        | Descrição |
|------------|------------------------|
| \<form>    |Define um formulário |
| \<input>   | Define um campo de entrada de dados genérico|
|\<textarea> | Define um campo de entrada de texto com múltiplas linhas|
| \<label> | Define um rótulo para um campo de entrada de dados |
| \<select> | Define uma lista selecionável (também chamada de drop-down box) |
| \<option> | Define uma opção (item da lista) do drop-down box.
| \<button> | Define um botão


Os formulários fazem parte do código html, portanto devem ser definidos como as tags dessa linguagem. Ou seja, sempre com uma tag de abertura (\<form>) e outra de fechamento (\</form>).  O conteúdo do formulário(elementos/campos de captura de dados) deve ser inserido entre entre essas duas tags, como demostra o exemplo a seguir.

### Exemplo

Nesse exemplo, temos 1 formulário que possui 3 campos (2 de texto e 1 botão) cujos dados são enviados para a página "exemplo-1.py" quando o usuário clica no botao enviar.

```html
<form action="/actions/exemplo-1.py" method="GET">
  Nome:<br>
  <input type="text" name="nome" value="Mickey">
  <br>
  Sobrenome:<br>
  <input type="text" name="sobrenome" value="Mouse">
  <br><br>
  <input type="submit" value="enviar">
</form> 
```
Para testar esse exemplo:
1. Inicie o servidor http cliando no arquivo "servidor.py" (caso ainda não esteja iniciado)
2. Abra o endereço http://localhost/exemplo-1.html no seu navegador preferido.

### O atributo action
Como podemos observar no exemplo, a tag \<form> possui um atributo **action**.

O atributo **action** define a ação a ser executada quando o formulário é submetido(enviado).

Normalmente, os dados do formulário são enviados para uma página da Web no servidor quando o usuário clica no botão de envio.

No exemplo acima, os dados do formulário são enviados para uma página no servidor chamada "/exemplo-1.py". Esta página contém um script do lado do servidor que manipula os dados do formulários.

Observação: Se o atributo **action** não for informado pelo programado, a ação destino passa a ser a própria pagina.

### O atributo target

O atributo target especifica se o resultado enviado será aberto em uma nova aba do navegador, em um quadro ou na janela atual.

O valor padrão é "_self", que significa que o formulário será enviado na janela atual.

Para tornar o resultado do formulário aberto em uma nova aba do navegador, use o valor "_blank".

### O atributo method
O atributo method especifica o método HTTP (GET ou POST) a ser usado ao enviar os dados do formulário.

#### Quando usar o GET?

O método padrão ao enviar dados de formulário é GET.

No entanto, quando o GET é usado, os dados do formulário apresentado ficarão visíveis no campo de endereço da página:
<pre>/exemplo-1.py?nome=Mickey&sobrenome=Mouse</pre>

Notas sobre GET:

1. Anexa dados de formulário ao URL em pares *nome*/*valor*
2. O tamanho de um URL é limitado (cerca de 3000 caracteres)
3. Nunca use o GET para enviar dados confidenciais! (será visível no URL)
4. Útil em envios onde se pretende marcar as paginas de resultados nos favoritos do navegador
5. GET é melhor para dados não seguros, com strings de consultas e filtros

#### Quando usar o POST?

Sempre use o POST se os dados do formulário contiverem informações confidenciais ou pessoais. O método POST não exibe os dados do formulário enviado no campo de endereço da página.

Notas sobre o POST:

1. O POST não tem limitações de tamanho e pode ser usado para enviar grandes quantidades de dados.
2. Submissões de formulário com o POST não podem ser marcadas nos favoritos.

Faça um teste: 
1. Altere o atributo method do exemplo 1 para "POST" e salve o arquivo.
2. Acesse http://localhost/exemplo-1.html e envie o formulário. 

Com o teste acima percebemos que os dados continuam sendo enviados, porém eles não são exibidos na URL. 

## Processando formulários

Para processar os dados de um formulário é necessário que cada campo tenha um atributo **name**, pois para acessar os dados informados no no fomulário a linguagem de script do lado servidor precisa saber de qual campo estamos nos referindo.

### Exemplo 

O exemplo a seguir exibe um formulário cheio de campos dos mais diversos tipos. Observe que todos possuem um atributo **name**.

```html
<form action="/actions/exemplo-2.py" method="GET">
  <p>Campo texto:<input type="text" name="campo_texto"></p>
  <p>Campo senha:<input type="password" value="123" name="campo_senha"></p>
  <p>Campo radio:
   <input type="radio" name="campo_radio" value="sim" checked> sim
   <input type="radio" name="campo_radio" value="nao"> não
   <input type="radio" name="campo_radio" value="outro"> outro
  </p>
 
 <p>Campo checkbox: 
 <input type="checkbox" name="campo_checkbox" value="marcado"> </p>
  
 <p>Campo select carro: 
   <select name="campo_select">
    <option value="volvo">Volvo</option>
    <option value="Saab">Saab</option>
    <option value="Fiat">Fiat</option>
    <option value="Audi">Audi</option>
   </select> 
 </p>
<p><input type="submit" value="enviar"></p>
</form>
```

Os dados do formulário acima podem ser acessados após envio pela pagina "exemplo-2.py" que simplismente os imprime. Segue o código da pagina:

```python
# -*- coding: utf-8 -*-
import cgi, cgitb

# coleta informações sobre os dados do formulário
form = cgi.FieldStorage() 
texto = form.getvalue('campo_texto')
senha = form.getvalue('campo_senha')
radio = form.getvalue('campo_radio')
checkbox = "sim" if form.getvalue('campo_checkbox') == "marcado" else "não"
carro = form.getvalue('campo_select')

# imprime cabeçalho padrão
print("Content-type: text/html; charset=utf-8;\n\n")

# imprime a reposta
template_html = """
<h1>Dados enviados</h1>
<p>Texto: %s <p>
<p>Senha: %s </p>
<p>Radio selecionado: %s </p>
<p>Checkbox marcado?: %s</p>
<p>Carro selecionado: %s </p>
 """ % (texto, senha, radio, checkbox, carro)
print(template_html)
```

Como pode-se observar para acessar os dados de um campo basta chamar a função **.getvalue("\<name do campo>")** do objeto formulário form.

Para testar esse exemplo faça o seguinte:
1. Inicie o servidor http cliando no arquivo "servidor.py" (caso ainda não esteja iniciado)
2. Abra o endereço http://localhost/exemplo-2.html no seu navegador preferido.


# Envio de arquivos



