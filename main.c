/****************************************************************
*
* ATIVIDADE 1 - ANÁLISE E PROJETO DE ALGORITMOS  
* ALUNO: WELLINGTON JOSÉ L. DA SILVA 
*
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Funções auxiliares 
void display( int *V, int n ){

	for(int i = 0; i < n; i++){

		printf("\n %d", V[i]);
	}
	printf("\n");
}	

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int elementMax(int *V, int n){
	
	int max = V[0];

	for(int i = 1; i < n; i++)
		if(V[i] > max)
			max = V[i];

	return max;
}	

int elementMin(int *V, int n){
	
	int min = V[0];

	for(int i = 1; i < n; i++)
		if(V[i] < min)
			min = V[i];

	return min;
}



// Selection Sort
void selectionSort(int *V, int n){

	int i, j, menor, troca;
	
	for(i = 0; i < n-1; i++){

		menor = i;
		for(j = i+1; j < n; j++){
			if(V[j] < V[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
	}
}

// Insertion Sort
void insertionSort(int *V, int n){

	int i, j, aux;

	for(i = 1; i < n; i++){

		aux = V[i];
		
		for( j = i; (j>0) && (aux < V[j-1]); j--){
			V[j] = V[j-1]; 
		}
		V[j] = aux;
	}

}


int main(int argc, char * argv[]){

	int codigo = 0;
	int tamanho;

	printf("digite o tamanho do array em seguida aperte enter, agora forneça os valores do array separados por espaço ou linha de acordo com o tamanho fornecido:\n");

	scanf("%d",&tamanho);
	int* vetor = (int*)calloc(tamanho,sizeof(int));

	for(int i = 0; i < tamanho; i++){
		
		int el;
		scanf("%d",&el);
		vetor[i] = el;
	}

	
	codigo = atoi(argv[1]);
	int i = 0;

	switch(codigo){

		case 1:
			selectionSort(vetor,tamanho);
		break;
		
		case 2:
			insertionSort(vetor,tamanho);
		break;

		default:
			printf("\n\ncodigo invalido !!\nDigite (./sorting 1) na chamada do programa para usar SelectionSort\nDigite (./sorting 2) na chamada do programa para usar o insertionSort\n\nO vetor digitado foi:");
			break;

	}
	
	printf("array ordenado:");
	display(vetor,tamanho);
	free(vetor);

	return 0;
}




