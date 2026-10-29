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
