#include <stdio.h>

#define TAM 100

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarEquipamento() {
    char nome[TAM];
    char codigo[TAM];
    char localizacao[TAM];
    FILE *arquivo;

    // MODO "a" = APPEND - Preserva o que já existe
    arquivo = fopen("equipamentos.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\n--- CADASTRO DE EQUIPAMENTO ---\n");
    
    printf("Nome do equipamento: ");
    fgets(nome, TAM, stdin);

    printf("Codigo de identificacao: ");
    fgets(codigo, TAM, stdin);

    printf("Localizacao: ");
    fgets(localizacao, TAM, stdin);

    // Grava no arquivo
    fprintf(arquivo, "%s;%s;%s", nome, codigo, localizacao);
    // usamos ; como separador

    fclose(arquivo);

    printf("\n>> Equipamento salvo com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n============================\n");
        printf(" LAB DE INFORMATICA\n");
        printf("============================\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos (ainda nao fizemos)\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer(); // ESSENCIAL: limpa o \n que o scanf deixa

        switch(opcao) {
            case 1:
                cadastrarEquipamento(); // <-- AQUI A JUNÇÃO ACONTECE
                break;
            case 2:
                printf("\nAinda vamos fazer essa parte!\n");
                break;
            case 3:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 3);

    return 0;
}