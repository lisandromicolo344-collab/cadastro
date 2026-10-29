#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO "equipamentos.txt"
#define TAM 100

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para remover o \n que o fgets deixa
void removerQuebraLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void cadastrarEquipamento() {
    char nome[TAM];
    char codigo[TAM];
    char localizacao[TAM];
    
    FILE *arquivo;

    // Abrir em modo "a" = append, preserva o que ja existe
    arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\n--- CADASTRO DE EQUIPAMENTO ---\n");
    
    printf("Nome do equipamento: ");
    fgets(nome, TAM, stdin);
    removerQuebraLinha(nome);

    printf("Codigo de identificacao: ");
    fgets(codigo, TAM, stdin);
    removerQuebraLinha(codigo);

    printf("Localizacao (ex: Lab 01, Sala 03): ");
    fgets(localizacao, TAM, stdin);
    removerQuebraLinha(localizacao);

    // Grava no formato: nome;codigo;localizacao
    // Usando fprintf() conforme solicitado
    fprintf(arquivo, "%s;%s;%s\n", nome, codigo, localizacao);

    fclose(arquivo); // Fecha com fclose()
    
    printf("\n>> Equipamento cadastrado com sucesso!\n");
}

void listarEquipamentos() {
    FILE *arquivo;
    char linha[TAM * 3];

    // Abrir em modo "r" = leitura
    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("\nNenhum equipamento cadastrado ainda ou arquivo nao encontrado.\n");
        return;
    }

    printf("\n--- LISTA DE EQUIPAMENTOS CADASTRADOS ---\n");
    printf("------------------------------------------------\n");

    int contador = 0;
    // Usa fgets() para ler linha a linha conforme solicitado
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
        removerQuebraLinha(linha);
        
        // Quebra a linha pelo separador ;
        char *nome = strtok(linha, ";");
        char *codigo = strtok(NULL, ";");
        char *local = strtok(NULL, ";");

        if (nome && codigo && local) {
            printf("Equipamento %d:\n", contador);
            printf("  Nome........: %s\n", nome);
            printf("  Codigo......: %s\n", codigo);
            printf("  Localizacao.: %s\n", local);
            printf("------------------------------------------------\n");
        }
    }

    if (contador == 0) {
        printf("Arquivo vazio.\n");
    }

    fclose(arquivo);
}

int main() {
    int opcao;

    do {
        printf("\n========================================\n");
        printf(" SISTEMA DE GERENCIAMENTO DE LABORATORIO\n");
        printf("========================================\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = 0;
        } else {
            limparBuffer(); // limpa o \n do scanf
        }

        switch (opcao) {
            case 1:
                cadastrarEquipamento();
                break;
            case 2:
                listarEquipamentos();
                break;
            case 3:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}