# -*- coding: utf-8 -*-

from configuracoes import configura_pytho_path, configura_proxy_pip, remove_senhas
from Tkinter import *

class Aplicativo(Frame):
    
    def __init__(self, master=None):
        Frame.__init__(self, master,width=320,height=240)
        self.pack_propagate(0)
        self.pack()
        self.constroiJanela()
    
    def constroiJanela(self):
        # criando containers
        self.container1 = Frame(self)
        self.container2 = Frame(self)
        self.container3 = Frame(self)
        self.container1.pack()
        self.container2.pack(pady=10)
        self.container3.pack(pady=10)

        # criando elementos do container 1
        self.legenda = Label(self.container1)
        self.legenda['text'] = "Informe seu usuario e senha do proxy"
        self.legenda['wraplength'] = "300"
        self.legenda.pack(fill=BOTH,expand=1,pady=10)

        # criando elementos do container 2
        self.legUsuario = Label(self.container2,text="Usuario:")
        self.legUsuario.pack()
        self.inputUsuario = Entry(self.container2)
        self.inputUsuario.pack()

        self.legSenha = Label(self.container2,text="Senha:")
        self.legSenha.pack()
        self.inputSenha = Entry(self.container2,show="*")
        self.inputSenha.pack()


        # criando elementtos do conainer 3
        self.botaoProxy = Button(self.container3, text="Configurar Proxy")
        self.botaoProxy["command"] = self.execute_no_click_do_botao_proxy
        self.botaoProxy.pack(side="left",padx="5")

        self.botaoPy = Button(self.container3, text="Configurar Python")
        self.botaoPy["command"] = self.execute_no_click_do_botao_py
        self.botaoPy.pack(side="left",padx="5")

        self.botaoApagar = Button(self.container3, text="Apagar senhas")
        self.botaoApagar["command"] = remove_senhas
        self.botaoApagar.pack(padx="5")

        
    def execute_no_click_do_botao_proxy(self):
        usuario = self.inputUsuario.get()
        senha = self.inputSenha.get()
        configura_proxy_pip(usuario, senha)

    def execute_no_click_do_botao_py(self):
        configura_pytho_path()


if __name__ == "__main__":
    janela = Tk()
    janela.title("Configura tudo!")
    app = Aplicativo(master=janela)
    app.mainloop()