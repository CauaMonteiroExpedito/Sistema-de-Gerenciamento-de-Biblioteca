#include <stdio.h>
#include "../include/livro.h"
#include "../include/usuario.h"
#include "../include/emprestimo.h"

int main() {
    int opcao;
    do {
        printf("\n===== BIBLIOTECA =====\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Cadastrar Usuário\n");
        printf("4. Listar Usuários\n");
        printf("5. Emprestar Livro\n");
        printf("6. Devolver Livro\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: listarLivros(); break;
            case 3: cadastrarUsuario(); break;
            case 4: listarUsuarios(); break;
            case 5: emprestarLivro(); break;
            case 6: devolverLivro(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
