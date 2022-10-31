// implemente sistema para execucao da fila dinâmica

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

Fila *criaFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insereFila(Fila *f, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int removeFila(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia");
        return -1;
    } else {
        No *aux = f->inicio;
        int valor = aux->valor;
        f->inicio = aux->prox;
        free(aux);
        return valor;
    }
}

void imprimeFila(Fila *f) {
    No *aux = f->inicio;
    while (aux != NULL) {
        printf("\n %d", aux->valor);
        aux = aux->prox;
    }
}

int main() {
    Fila *f = criaFila();
    insereFila(f, 10);
    insereFila(f, 20);
    insereFila(f, 30);
    insereFila(f, 40);
    insereFila(f, 50);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    return 0;
}
