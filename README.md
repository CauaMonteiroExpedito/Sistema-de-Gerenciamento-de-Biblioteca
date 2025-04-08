# 📚 Sistema de Gerenciamento de Biblioteca

Este é um projeto simples de um **Sistema de Biblioteca** desenvolvido em linguagem C, utilizando arquivos `.txt` para armazenar os dados de livros. Ele permite cadastrar livros, listar, emprestar e devolver, tudo via terminal.

---

## 🛠️ Funcionalidades

-  Cadastro de livros
-  Listagem de livros disponíveis ou emprestados
-  Empréstimo de livros
-  Devolução de livros
-  Armazenamento em arquivos `.txt` (sem necessidade de banco de dados)

---

## 🗂️ Estrutura de Pastas

```
Biblioteca/
├── data/
│   └── livros.txt         # Arquivo onde os livros são salvos
├── include/
│   └── livro.h            # Declarações e struct do livro
├── src/
│   ├── main.c             # Menu principal do sistema
│   ├── livro.c            # Funções para cadastro e listagem
│   └── emprestimo.c       # Funções para emprestar e devolver
├── Makefile               # Para compilar todos os arquivos de forma automatizada
└── README.md              # Este arquivo
```

---

## 💻 Como rodar o projeto

### 🔹 Pré-requisitos

- [GCC](https://gcc.gnu.org/)
- [Make](https://www.gnu.org/software/make/) (opcional, mas recomendado)

### 🔹 Compilando com Makefile (Linux ou Windows com MinGW)

```bash
make
```

### 🔹 Ou compilando manualmente:

```bash
gcc src/main.c src/livro.c src/emprestimo.c -o biblioteca
```

### 🔹 Rodando o programa:

```bash
./biblioteca
```
Ou no Windows:
```bash
biblioteca.exe
```

---

## 📝 Formato do arquivo `livros.txt`

Os dados dos livros são salvos no seguinte formato:

```
ID|Título|Autor|Disponível
```

Exemplo:

```
1|Dom Casmurro|Machado de Assis|1
2|O Cortiço|Aluísio Azevedo|0
```

Onde `1` significa disponível e `0` significa emprestado.

---

## ✨ Melhorias futuras

- Sistema de usuários (admin e leitor)
- Busca de livros por título ou autor
- Interface gráfica com Curses ou outra lib
- Backup automático

---

## 👨‍💻 Desenvolvido por

Cauã Monteiro Expedito — _Estudante de Análise e Desenvolvimento de Sistemas_
