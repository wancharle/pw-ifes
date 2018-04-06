# Configurando o ambiente

Na pasta "scripts-uteis" dê um duplo clique no script "configura-tudo.py"

O script abrirá uma janela com opções para configurar o seu ambiente.

Informe o seu usuario e senha de proxy e clique no botão "configurar proxy".

Por fim, clique no botão "configurar python". 

Ao terminar feche a janela e deslogue-se do windows e logue novamente para que as configurações novas entrem em vigor.

## Atualizando o instalador pip

Após deslogar e logar novamente no sistema, abra o prompt de comando do windows e digite o seguinte  comando:
```bash
python -m pip install --upgrade pip
```

Após atualizar o instalador pip, instale o virtualenv

```bash
pip install virtualenv
```

# Criando um projeto Flask

Crie uma pasta "projeto" e abra ela no editor vscode. Em seguida, no terminal do vscode, digite:
```
virtualenv env
```
O comando acima cria um ambiente virtual isolado do python.

Ative o ambiente virtual digitando o comando:
```
env\Scripts\activate
```

Instale o Flask no ambiente virtual digitando o comando:
```
pip install flask
```

Crie um arquivo "app.py" com o seguinte conteudo:
```python
from flask import Flask
app = Flask(__name__)

@app.route("/")
def index():
    return "Ola Mundo!"
```
### Configure o python do VSCode
Pressione CTRL+SHIFT+P e digite **Python: Select Iterpreter** e selecione a versão do python que se encontra na pasta do seu projeto (virtualenv). 

### Configure o VSCode para iniciar o flask
Adicione uma nova configuração na aba de debug. Clique em "add configuration" e adicione a configuração "Python".

O VScode irá abrir o arquivo "launch.json" com as configurações de python que ele conhece. 

Apague todas as configurações com excessão da configuração do flask.

No final o arquivo lauch.json ficará parecido com o arquivo abaixo:

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Python: Flask (0.11.x or later)",
            "type": "python",
            "request": "launch",
            "module": "flask",
            "env": {
                "FLASK_APP": "${workspaceFolder}/app.py"
            },
            "args": [
                "run",
                "--no-debugger",
                "--no-reload"
            ]
        },
    ]
}
```

Ao terminar de salvar o arquivo launch.json pressione F5 para o VSCode iniciar o projeto flask.

Assim que o projeto estiver iniciado, acesse no navegador web o endereço http://localhost:5000/ para visualizar a pagina do projeto.

## 
# links:
1. SQLITEBrowser http://sqlitebrowser.org/
2. Peewee http://pythonclub.com.br/peewee-um-orm-python-minimalista.html
3. Flask http://flask.pocoo.org/