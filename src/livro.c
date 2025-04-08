#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/livro.h"

// Função para cadastrar um novo livro
void cadastrarLivro() {
    Livro novo;

    printf("=== Cadastro de Livro ===\n");
    printf("ID: ");
    scanf("%d", &novo.id);
    getchar(); // Limpa o buffer do teclado

    printf("Título: ");
    fgets(novo.titulo, sizeof(novo.titulo), stdin);
    strtok(novo.titulo, "\n"); // Remove o \n do final

    printf("Autor: ");
    fgets(novo.autor, sizeof(novo.autor), stdin);
    strtok(novo.autor, "\n"); // Remove o \n do final

    novo.disponivel = 1; // Ao cadastrar, o livro começa disponível

    // Abre o arquivo no modo append para não apagar o conteúdo existente
    FILE *arquivo = fopen("data/livros.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros!\n");
        return;
    }

    // Grava os dados no formato: id|titulo|autor|disponivel
    fprintf(arquivo, "%d|%s|%s|%d\n", novo.id, novo.titulo, novo.autor, novo.disponivel);
    fclose(arquivo);

    printf("Livro cadastrado com sucesso!\n");
}

// Função para listar todos os livros
void listarLivros() {
    FILE *arquivo = fopen("data/livros.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    Livro livro;
    char linha[200];

    printf("=== Lista de Livros ===\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, "|");
        if (token != NULL) livro.id = atoi(token);

        token = strtok(NULL, "|");
        if (token != NULL) strcpy(livro.titulo, token);

        token = strtok(NULL, "|");
        if (token != NULL) strcpy(livro.autor, token);

        token = strtok(NULL, "|\n");
        if (token != NULL) livro.disponivel = atoi(token);

        printf("ID: %d\n", livro.id);
        printf("Título: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Disponível: %s\n", livro.disponivel ? "Sim" : "Não");
        printf("-------------------------\n");
    }

    fclose(arquivo);
}
