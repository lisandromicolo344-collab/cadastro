# Sistema de Laboratório de Informática - Em C

Sistema simples para cadastrar e consultar equipamentos, com persistência em arquivo de texto.

## Funcionalidades
- [x] Menu com Cadastrar, Listar e Sair
- [x] Cadastro com nome, código e localização
- [x] Armazenamento em `equipamentos.txt`
- [x] Consulta de todos os equipamentos
- [x] Usa `fopen()`, `fprintf()`, `fgets()` e `fclose()`

## Como compilar e executar

### Windows
```bash
gcc main.c -o sistema.exe
./sistema.exe

## Exemplo de dados:

Nome: Computador Dell Optiplex i5 | Codigo: EQ001 | Localizacao: Laboratorio 01 - Bancada A1
Nome: Computador Dell Optiplex i7 | Codigo: EQ002 | Localizacao: Laboratorio 01 - Bancada A2
Nome: Projetor Epson PowerLite | Codigo: EQ003 | Localizacao: Laboratorio 01 - Sala de Reuniao
Nome: Switch TP-Link 24 Portas | Codigo: EQ004 | Localizacao: Rack Central - Lab 01
Nome: Impressora HP LaserJet | Codigo: EQ005 | Localizacao: Laboratorio 01 - Apoio
