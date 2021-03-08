#include "insertion-selection.h"

int n_trocas,n_compara;
void inicializarTAD( Lista *l, int TAM ){
	int x,i;
	srand(1);
	for(i=0;i<TAM;i++){
	x = rand()%TAM;
	inserirPosicao(l,i,x);
	}
}

void insertionSort( Lista *l ){
	n_trocas = 0;
	n_compara = 0;
	Elemento* i;
	Elemento* j;
	for(i=l->comeco->proximo;i!=NULL;i=i->proximo){
		for(j=i;j->anterior!=NULL;j=j->anterior){
			n_compara++;
			if(j->anterior->valor > j->valor ){
				n_trocas++;
				int aux;
				aux = j->valor;
				j->valor = j->anterior->valor;
				j->anterior->valor = aux;
			}else{
				break;
		}
		}
	}
}

void selectionSort( Lista *l ){
	n_trocas = 0;
	n_compara = 0;
	Elemento *i;
	Elemento *j;
	Elemento *k;
	for(i=l->comeco;i->proximo!=NULL;i=i->proximo){
	k = i;
		for(j=i->proximo;j!=NULL;j=j->proximo){
			n_compara++;
			if(j->valor < k->valor){
				k = j;
			}	
		}
		if(k!=i){		
			n_trocas++;
			int aux;
			aux = k->valor;
			k->valor = i->valor;
			i->valor = aux;
		}
	}
}

void dadosOrdenacao( int TAM, double tempo ){
	printf("Numero de elementos:%d\n",TAM);
	printf("Numero de trocas:%d\n",n_trocas);
	printf("Numero de comparacoes:%d\n",n_compara);
	printf("Tempo de execução:%lf segundos\n",tempo);
}
