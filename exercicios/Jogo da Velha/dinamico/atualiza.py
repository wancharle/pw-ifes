import json
print("Content-Type: application/json")
print("Access-Control-Allow-Origin: * \n")

arquivo = open("bancoDeDados.txt")
dados = arquivo.read()
arquivo.close()

tabuleiro =[]
tabuleiro.append( [coluna for coluna in dados[:3] ])
tabuleiro.append( [coluna for coluna in dados[3:6]]) 
tabuleiro.append( [coluna for coluna in dados[6:9]]) 

#converte array python tabuleiro para o formato json
tabJSON = json.dumps(tabuleiro)

print(tabJSON)
