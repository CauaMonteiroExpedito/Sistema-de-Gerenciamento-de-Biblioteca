#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/usuario.h"

#define ARQ_USUARIOS "data/usuarios.txt"

void cadastrarUsuario() {
    Usuario usuario;
    printf("ID do usuário: ");
    scanf("%d", &usuario.id);
    getchar();
    printf("Nome: ");
    fgets(usuario.nome, sizeof(usuario.nome), stdin);

    salvarUsuario(usuario);
    printf("Usuário cadastrado com sucesso!\n");
}

void salvarUsuario(Usuario usuario) {
    FILE* f = fopen(ARQ_USUARIOS, "a");
    if (!f) return;
    fprintf(f, "%d|%s\n", usuario.id, usuario.nome);
    fclose(f);
}

Usuario* carregarUsuarios(int* quantidade) {
    FILE* f = fopen(ARQ_USUARIOS, "r");
    *quantidade = 0;
    if (!f) return NULL;

    Usuario* usuarios = malloc(sizeof(Usuario) * 100);
    while (fscanf(f, "%d|%[^\n]\n", &usuarios[*quantidade].id, usuarios[*quantidade].nome) == 2) {
        (*quantidade)++;
    }
    fclose(f);
    return usuarios;
}

void listarUsuarios() {
    int qtd = 0;
    Usuario* usuarios = carregarUsuarios(&qtd);
    if (qtd == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtd; i++) {
        printf("ID: %d | Nome: %s\n", usuarios[i].id, usuarios[i].nome);
    }
    free(usuarios);
}
