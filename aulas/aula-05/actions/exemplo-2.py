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