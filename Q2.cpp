#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para os produtos
typedef struct Produto {
    char nome[50];
    struct Produto* next;
} Produto;

// Função para criar um novo produto
Produto* criarProduto(char* nome) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->next = NULL;
    return novoProduto;
}

// Função para inserir produtos de forma ordenada
void inserirOrdenado(Produto** cabeca, Produto* novoProduto) {
    Produto* atual;
    if (*cabeca == NULL || strcmp((*cabeca)->nome, novoProduto->nome) >= 0) {
        novoProduto->next = *cabeca;
        *cabeca = novoProduto;
    } else {
        atual = *cabeca;
        while (atual->next != NULL && strcmp(atual->next->nome, novoProduto->nome) < 0) {
            atual = atual->next;
        }
        novoProduto->next = atual->next;
        atual->next = novoProduto;
    }
}

// Função para imprimir a lista de compras
void imprimirLista(Produto* cabeca) {
    while (cabeca != NULL) {
        printf("%s\n", cabeca->nome);
        cabeca = cabeca->next;
    }
}

int main() {
    Produto* cabeca = NULL;
    int n;
    char nome[50];

    printf("Digite o tamanho da lista de compras: ");
    scanf("%d", &n);
    getchar(); // Limpar buffer de entrada

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0; // Remove newline
        inserirOrdenado(&cabeca, criarProduto(nome));
    }

    printf("Lista de Compras Ordenada:\n");
    imprimirLista(cabeca);

    return 0;
}

