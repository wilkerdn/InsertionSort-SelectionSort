#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int valor;
	struct elemento *proximo;
	struct elemento *anterior;
} Elemento;

typedef struct {
  Elemento *comeco;	
} Lista;

Lista* criaLista();

void liberaLista(Lista* l);

int estahVazia(Lista* l);

int estahCheia(Elemento* elem);

int inserirPosicao(Lista* l, int posicao, int v);

int removerPosicao(Lista* l, int posicao, int* v);

void mostrarLista(Lista* l);
