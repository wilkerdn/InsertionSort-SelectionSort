#include "lista.h"

Lista* criaLista() {
	Lista* l;
	
	l = (Lista*) malloc(sizeof(Lista));
	
	l->comeco = NULL;
	
	return l;
}

void liberaLista(Lista* l) {
	Elemento* q = l->comeco;
	
	while (q != NULL) {
		Elemento* temp = q->proximo;
		free(q);
		q = temp;
	}
	
	free(l);
}

int estahVazia(Lista* l) {
	if (l->comeco == NULL){
	   return 1;
	} else {
	   return 0;
   }
}

int estahCheia(Elemento* elem) {
	if(elem != NULL){
		return 0;
	} else {
		return 1;
	}
}

int inserirPosicao(Lista* l, int posicao, int v) {
	
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	
	if (estahCheia(novo) == 0) {
	
    	novo->valor = v;
	    novo->proximo = NULL;
	    novo->anterior = NULL;
		
		if(posicao > 0){
			Elemento *atual = l->comeco;
			int idx;
			
			for(idx=1; ((atual!=NULL) && (idx < posicao)); idx++){
			   atual = atual->proximo;
			}
			
			novo->anterior = atual;
			novo->proximo = atual->proximo;
			
			if(atual->proximo != NULL){
				atual->proximo->anterior = novo;
			}
			
			atual->proximo = novo;
		} else {
			novo->proximo = l->comeco;
			l->comeco = novo;
		}
	    
	    return 1; //inserção com sucesso
	    
	} else 
	  return 0; //Não há espaço na memória

}

int removerPosicao(Lista* l, int posicao, int* v) {
	if (estahVazia(l) == 1) {
	    return 0;
	} else {
		
		if(posicao > 0){
			Elemento *atual = l->comeco->proximo;
			int idx;
			
			for(idx=1; ((atual!=NULL) && (idx < posicao)); idx++){
			   atual = atual->proximo;
			}
			
			atual->anterior->proximo = atual->proximo;
			if(atual->proximo != NULL){
				atual->proximo->anterior = atual->anterior;
			}
			free(atual);
			
		} else {
			Elemento *temp = l->comeco;
			*v = temp->valor;
			l->comeco = l->comeco->proximo;
			if(temp->proximo != NULL){
				temp->proximo->anterior = NULL;
			}
			free(temp);			// elemento removido sucesso
		}
		
		return 1;
	}
}

void mostrarLista2(Lista* l) {
	
	Elemento* p;
	
	int i = 0;
	
	for (p=l->comeco; p!=NULL; p=p->proximo) {
		printf("%d. elemento = %d (anterior = %d, proximo = %d)\n",
		i, p->valor,
		(p->anterior != NULL ? p->anterior->valor : -1 ),
		(p->proximo != NULL ? p->proximo->valor : -1) );
		i++;
	}
	getchar();
}

void mostrarLista(Lista* l) {
	
	Elemento* p;
	
	int i = 0;
	
	for (p=l->comeco; p!=NULL; p=p->proximo) {
		printf("elemento = %d ",p->valor);
		
		if(p->anterior != NULL){
			printf("(anterior = %d, ",p->anterior->valor);
		} else {
			printf("(anterior = NULL, ");
		}
		
		if(p->proximo != NULL){
			printf("proximo = %d)\n",p->proximo->valor);
		} else {
			printf("proximo = NULL)\n");
		}
		
		i++;
	}
	printf("\n");
}

