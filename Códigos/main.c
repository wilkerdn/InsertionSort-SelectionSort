#include "insertion-selection.h"
#define TAM 10
int main(int argc, char** argv){	
	clock_t t;
	int x;
	t = clock();
	Lista* l;
	l = criaLista();
	inicializarTAD(l,TAM);
	printf("Para usar InsertionSort, tecle 1; SelectionSort, tecle 2\n");
	scanf("%d",&x);
	if(x==1){
	insertionSort(l);
	}else{
	selectionSort(l);
	}  
	mostrarLista(l);
	liberaLista(l);
	dadosOrdenacao(TAM,((double)t)/CLOCKS_PER_SEC);
	return 0;
}