@echo off

echo.
SET /p usuario=Informe o usuario:
SET /P senha=Informe a senha:


git config --global http.proxy http://%usuario%:%senha%@venus.cefetes.br:3128
git config --global https.proxy https://%usuario%:%senha%@venus.cefetes.br:3128

echo Configurado git proxy para o usuario %usuario% com sucesso!!!



