
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct t_no {
    int info;
    struct t_no *ant;
};

void inicia_lista(struct t_no *cabeca) {
    cabeca=NULL;
}

void insere_final(struct t_no *cabeca, int valor) {
    if (cabeca == NULL) {
        cabeca = (t_no*) malloc(sizeof(t_no));
        cabeca->info = valor;
        cabeca->ant = NULL;
    
    } else {
        t_no *novo = (t_no*) malloc(sizeof(t_no));
        novo->info = valor;
        novo->ant = cabeca;
        cabeca = novo;
    }
}

void mostra_todos(struct t_no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
    } else {
        t_no *aux = cabeca;
        while (aux != NULL) {
            printf("%d  ", aux->info);
            aux = aux->ant;
        }
        printf("\n");
    }
}

apaga_final(struct t_no *cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
    } else {
        t_no *aux = cabeca;
        cabeca = cabeca->ant;
        free(aux);
    }
}

main(){
    struct t_no *pilha;
    inicia_lista(pilha);
    char tecla;
    int valor;

    while (tecla!='S' && tecla!='s') {
        printf("[I]ncluir [L]istar [D]eletar [S]air");
        tecla=getch();
        if (tecla=='i' || tecla=='I')
        {
            printf ("Valor:");
            scanf ("%d",&valor);
            insere_inicio (pilha, valor);
        }
        else if (tecla=='l' || tecla=='L')
        {
            mostra_todos(pilha);
        }
        else if (tecla=='d' || tecla=='D')
        {
            apaga_final(pilha);
        }
        else if (tecla=='s' || tecla=='S')
        {
            printf("Saindo");
        }
        else
        {
            printf("Opcao invalida");
        }
    }
}
