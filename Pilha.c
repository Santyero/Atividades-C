#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no
{
    int valor;
    struct no *anterior;
} No;

typedef struct fila
{
    No *anterior;
    No *atual;
} Fila;

Fila *criaFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->atual = NULL;
    f->anterior = NULL;
    return f;
}

void inserir(Fila *f, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = f->atual;
    f->atual = novo;
}

void remover(Fila *f)
{
    No *aux = f->atual;
    while(aux->anterior != f->anterior)
    {
        aux = aux->anterior;
    }
    f->anterior = aux;
    free(aux->anterior);
    aux->anterior = NULL;
}


void imprime(Fila *f)
{
    No *aux = f->atual;
    if(aux == NULL) {
        printf("lista vazia");
    }
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->anterior;
    }
}

void recebe_dados(Fila *f)
{
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    inserir(f, valor);
}

int main()
{
    Fila *fila = criaFila();
    char tecla;

    while (tecla != 'S' && tecla != 's')
    {
        printf("\n[I]ncluir [L]istar [D]eletar [S]air\n");
        scanf(" %c", &tecla);
        if (tecla == 'i' || tecla == 'I')
        {
            recebe_dados(fila);
        }
        else if (tecla == 'l' || tecla == 'L')
        {
            imprime(fila);
        }
        else if (tecla == 'd' || tecla == 'D')
        {
            remover(fila);
        }
        else if (tecla == 's' || tecla == 'S')
        {
            printf("Saindo\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
    }
    return 0;
}
