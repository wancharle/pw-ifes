# Javascript Output

## Possibilidades de exibição em JavaScript
JavaScript pode "exibir" dados de diferentes formas:

* Escrevendo em um elemento HTML, através da propriedade **innerHTML** do elemento.
* Escrevendo para a saída HTML usando **document.write()** .
* Escrevendo em uma caixa de alerta, usando **window.alert()**.
* Escrevendo para o console do navegador, usando **console.log()**.

## Usando a propriedade innerHTML

Para acessar um elemento HTML, Javascript pode usar o metodo **document.getElementById(id)**.

O atributo **id** identifica o elemento HTML. A propriedadde **innerHTML** define o conteúdo HTML do elemento.

```HTML
<!DOCTYPE html>
<html>
<body>

<h2>Meu primeiro cabeçalho</h2>
<p>Meu primeiro paragrafo.</p>

<p id="resultado"></p>

<script>
document.getElementById("resultado").innerHTML = 5 + 6;
</script>

</body>
</html> 
```
[Tente vc mesmo](https://www.w3schools.com/code/tryit.asp?filename=FOXZDR18SZQS)

> ** Nota: ** Mudar a propriedade **innerHTML**  é uma das formas mais comuns de se exibir dados em HTML.

## Usando document.write()

