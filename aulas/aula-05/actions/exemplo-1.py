# -*- coding: utf-8 -*-
import os, sys

# coleta informações sobre os dados do formulário
metodo_de_envio = os.environ["REQUEST_METHOD"]
dados_GET = os.environ["QUERY_STRING"]
dados_POST = sys.stdin.read()

# imprime cabeçalho padrão
print("Content-type: text/html; charset=utf-8;\n\n")

# imprime a reposta
template_html = """
<h1>Dados enviados</h1>
<p>Seu dados foram recebidos da seguinte forma:<p>
<p>Método: %s </p>
<p>Dados GET: %s </p>
<p>Dados POST: %s </p>
 """ % (metodo_de_envio, dados_GET, dados_POST)
print(template_html)