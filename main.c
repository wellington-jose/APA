/****************************************************************
*
* ATIVIDADES - ANÁLISE E PROJETO DE ALGORITMOS 
* IMPLEMENTAÇÃO DO SELECTIONSORT, INSERTIONSORT, QUICKSORT E MERGESORT 
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

// Quicksort  
int particiona(int *V, int inicio, int fim){

	int esquerda, direita, pivo, aux;
	esquerda = inicio;
	direita = fim;
	pivo = V[inicio];

	while(esquerda<direita){

		while(V[esquerda] <= pivo){
			esquerda++;
		}
		while(V[direita] > pivo){
			direita--;
		}
		if(esquerda < direita){
			aux = V[esquerda];
			V[esquerda] = V[direita];
			V[direita] = aux;
		}
	}
	V[inicio] = V[direita];
	V[direita] = pivo;
	return direita;

}
void quickSort(int *V, int inicio, int fim){
	
	int pivo;
	if(fim > inicio){

		pivo = particiona(V,inicio,fim);
		quickSort(V,inicio,pivo-1);
		quickSort(V,pivo+1,fim);
	}
}


//Merge Sort
int  merge(int *V, int inicio, int meio, int fim){

	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio + 1;
	temp = (int*) malloc(tamanho*sizeof(int));

	if(temp != NULL){

		for(i = 0; i < tamanho; i++){

			if(!fim1 && !fim2){

				if(V[p1] < V[p2]){
					temp[i] = V[p1++];
				}else{
					temp[i] = V[p2++];
				}
				if(p1 > meio){
					fim1 = 1;
				}
				if(p2 > fim){
					fim2 = 1;
				}

			}else{
				if(!fim1){
					temp[i] = V[p1++];
				}else{
					temp[i] = V[p2++];	
				}
			}
		}
		for(j=0, k = inicio; j<tamanho; j++, k++){
			V[k] = temp[j];
		}

	}
	free(temp); 
}
void mergeSort(int *V, int inicio, int fim){
	
	int meio;
	if(inicio < fim){

		meio = (inicio + fim)/2;
		mergeSort(V, inicio, meio);
		mergeSort(V, meio+1, fim);
		merge(V,inicio, meio, fim);		
	}
}



// Counting sort
void countingSort(int *V, int n){

	
    int output[n];
    int range, min, max;
    min = elementMin(V,n);
    max = elementMax(V,n);
    range = max - min + 1;

    int count[range] = {0}, i;
 
    
    for(i = 0; i < n; i++)
        ++count[V[i]-min];
 
    for (i = 1; i < range; i++)
        count[i] += count[i-1];
 
    for (i = 0; i < n; i++)
    {
        output[ count[ V[i] -min]-1] = V[i];
        --count[V[i] - min];
    }
 
    for (i = 0; i < n; i++)
        V[i] = output[i];    	
    	
}


// Heapsort
void heapify(int head, int size, int* list){
	
	int max = head;
	int left = head*2 + 1;
	int right = head*2 + 2;
	int aux;

	if(left > size-1)
		left = head;

	if(right > size-1)
		right = head;	

	if(list[max] < list[left])
		max = left;

	if(list[max] < list[right])
		max = right;

	aux = list[max];
	list[max] = list[head];
	list[head] = aux;

	if(max != head)
		heapify(max, size, list);
}


void maxHeapify(int* v, int n){
	for(int i = n/2; i >= 0; i--){
		heapify(i, n, v);
	}
}

void heapSort(int* v, int n){
	
	maxHeapify(v,n);
	int aux;
	for(int i = n-1; i > 0; i--){
		heapify(0, i+1, v);
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
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
			printf("\narray ordenado pelo selectionSort\n");
		break;
		
		case 2:
			insertionSort(vetor,tamanho);
			printf("\narray ordenado pelo insertionSort\n");
		break;

		case 3:
			quickSort(vetor, 0, tamanho-1);
			printf("\narray ordenado pelo quickSort\n");
		break;

		case 4:
			mergeSort(vetor, 0, tamanho-1);
			printf("\narray ordenado pelo mergeSort\n");
		break;

		case 5:
			countingSort(vetor, tamanho);
			printf("\narray ordenado pelo CoutingSort\n");
		break;	

		case 6:
			heapSort(vetor,tamanho);
			printf("\narray ordenado pelo HeapSort\n");
		break;	

		default:
			printf("\n\ncodigo invalido !!\nDigite (./sorting 1) na chamada do programa para usar SelectionSort\nDigite (./sorting 2) na chamada do programa para usar o insertionSort\n\nO vetor digitado foi:");
			break;

	}
	
	//printf("array ordenado:");
	display(vetor,tamanho);
	free(vetor);

	return 0;
}




