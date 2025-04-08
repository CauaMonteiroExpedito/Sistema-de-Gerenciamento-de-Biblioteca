#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int id;
    char nome[100];
} Usuario;

void cadastrarUsuario();
void listarUsuarios();
void salvarUsuario(Usuario usuario);
Usuario* carregarUsuarios(int* quantidade);

#endif
