# Aula 2

## Ligue o servidor CGI python

Execute o arquivo servidor.py para ligar o servidor CGI para todos os arquivos presentes na pasta da aula.

## Acesse os arquivos pelo navegador e pelo telnet

## Paginas estáticas e Paginas dinâmicas
Acesse ola.py pelo navegador(versão estatica e dinamica):

![firefox ola.py estatico](/aulas/img/putty-3.PNG)
![firefox ola.py dinamico](/aulas/img/putty-4.PNG)

Observe que na versão estática o código não é executado e todo o conteúdo do arquivo é exibido.
Porém, na versão dinâmica o código é executado e somente o que for impresso pelo programa que será exibido na pagina.

Isso acontece porque existe uma distinção feita pelo servidor web relacionada a paginas web. Ele divide as requisições requisições estaticas e requisicoes dinâmicas:

1. **Requisições estáticas**: são pedidos para **baixar** arquivos. E pode ser qualquer arquivo tanto os mais comuns(pdf, img, docx, videos etc) e até arquivos binários(.exe, .bin) ou de códigos de linguagens desktop ou web(.py,.php) que não  serão executados.

2. **Requisições dinãmicas**: são pedidos para **executar** "programas" no computador onde esta instalado o servidor. Neste caso, o servidor web(Apache, Nginx, IIS etc) não transfere o arquivo do programa pedido(nem os binários e nem os codigos). O servidor apenas executa o programa e envia somente a saída impressa pela execução do programa. (ou seja, manda para o usuário apenas o que o programa imprimiu na tela)

Essa diferença de comportamento ocorre a nível de rede via protocolo HTTP. Portanto, não importa a linguagem de programação que vc utiliza, nem o navegador (firefox, IE ou chrome), nem o servidor web (Apache, IIS, ou NGINX), nem o sistema operacional (Windows, Linux, MacOS). Toda a internet e web funciona **obedecendo** esse protocolo HTTP. E isso pode ser testado, por exemplo,  verificando o acesso de uma pagina via telnet sem utilizar um navegador web:

Acesse ola.py pelo telnet via puttytel (versão estatica e dinamica):
![putty ola.py estatico](/aulas/img/putty-1.PNG)
![putty ola.py dinamico](/aulas/img/putty-2.PNG)

### Acessando uma pagina binária: Ola.exe
Acesse ola.exe pelo telnet via puttytel:

![a](/aulas/img/putty-5.PNG)

Na versão estatica acima o telnet exibe os caracteres binarios, num navegador ele exibiria o download do arquivo.

![a](/aulas/img/putty-6.PNG)

Na versão dinamica acima o ola.exe é executa e só o que esse programa imprimir que será exibido.

### Ola.exe com pausa para processamento de informação

Acesse ola.exe, com pausa durante a requisicao,  pelo telnet via puttytel:

![a](/aulas/img/putty-7.PNG)

Observe a pausa ocorrida acima e que só apos alguns segundos o programa devolve a resposta como abaixo:

![a](/aulas/img/putty-8.PNG)

