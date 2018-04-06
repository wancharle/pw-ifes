# -*- coding: utf-8 -*-
import _winreg as reg
import os
import ConfigParser
import tkMessageBox

def configura_pytho_path():
    print("Configurando python path...")
    key = reg.OpenKey(reg.HKEY_CURRENT_USER, 'Environment', 0, reg.KEY_ALL_ACCESS)
    # use this if you need to modify the system variable and if you have admin privileges
    #key = reg.OpenKey(reg.HKEY_LOCAL_MACHINE, r'SYSTEM\CurrentControlSet\Control\Session Manager\Environment', 0, reg.KEY_ALL_ACCESS) 
    try:
        value, _ = reg.QueryValueEx(key, 'PATH')
    except WindowsError:
        # in case the PATH variable is undefined
        value = ''
    if not "Python27" in value:
        value +=r";C:\Python27;C:\Python27\Scripts" 
        print("Alterado variavel path")
    reg.SetValueEx(key, 'PATH', 0, reg.REG_EXPAND_SZ, value)
    reg.CloseKey(key)
    tkMessageBox.showinfo("Configura Python","Python configurado! Deslogue e logue novamente no windows para que alterações tenham efeito!")

def get_pip_file_path():
    dir_pip = os.path.join(os.getenv("appdata"),"pip")
    return os.path.join(dir_pip,"pip.ini")

def configura_proxy_pip(usuario,senha):
    print("Configurando proxy do pip...")
 
    Config = ConfigParser.ConfigParser()
    Config.add_section("global") 
    Config.set("global","proxy","http://%s:%s@venus.cefetes.br:3128" % (usuario,senha))   
    # cria diretório de conf do pip se não existe

    pip_config_file = get_pip_file_path()
    dir_pip = os.path.dirname(pip_config_file)
    if not os.path.exists(dir_pip):
        os.makedirs(dir_pip)
        print(u"Criado diretório pip em:%s"+dir_pip)
    with open(pip_config_file,"w") as iniFile:
        Config.write(iniFile)
    tkMessageBox.showinfo("Configura Proxy", "Proxy pip configurado!")

def remove_senhas():
    os.unlink(get_pip_file_path())
    tkMessageBox.showinfo("Apagar Senhas", "Apagado todas senhas! Agora é seguro deslogar da maquina")

