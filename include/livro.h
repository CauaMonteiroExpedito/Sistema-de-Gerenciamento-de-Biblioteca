#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int id;               // <-- Campo usado no empréstimo e devolução
    char titulo[100];
    char autor[100];
    int disponivel;       // <-- Campo que indica se está disponível (1) ou emprestado (0)
} Livro;

void cadastrarLivro();
void listarLivros();
Livro* carregarLivros(int *qtd);
void atualizarLivros(Livro *livros, int qtd);

#endif
