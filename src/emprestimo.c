#include <stdio.h>
#include "../include/livro.h"

void emprestarLivro() {
    int idLivro, qtd;
    printf("ID do livro a emprestar: ");
    scanf("%d", &idLivro);

    Livro* livros = carregarLivros(&qtd);
    for (int i = 0; i < qtd; i++) {
        if (livros[i].id == idLivro) {
            if (livros[i].disponivel) {
                livros[i].disponivel = 0;
                atualizarLivros(livros, qtd);
                printf("Livro emprestado com sucesso!\n");
            } else {
                printf("Livro já está emprestado.\n");
            }
            free(livros);
            return;
        }
    }
    printf("Livro não encontrado.\n");
    free(livros);
}

void devolverLivro() {
    int idLivro, qtd;
    printf("ID do livro a devolver: ");
    scanf("%d", &idLivro);

    Livro* livros = carregarLivros(&qtd);
    for (int i = 0; i < qtd; i++) {
        if (livros[i].id == idLivro) {
            livros[i].disponivel = 1;
            atualizarLivros(livros, qtd);
            printf("Livro devolvido com sucesso!\n");
            free(livros);
            return;
        }
    }
    printf("Livro não encontrado.\n");
    free(livros);
}
