#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge_sort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);
void imprime_vet(int *v, int tam);
void insertion_sort(int *v, int n);

void merge_sort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim) /2);
		merge_sort(v, inicio, meio);
		merge_sort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

void merge(int *v, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i,j,k;
	int fim1 =0, fim2=0;
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*)malloc(tamanho *sizeof(int));
	if(temp != NULL){
		for(i=0; i < tamanho; i++){
			if(!fim && !fim2){
				if(v[p1] < v[p2])
					temp[i]=v[p1++];
				else
					temp[i]=v[p2++];
	
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}
			else{
				if(!fim1)
					temp[i]=v[p1++];
				else
					temp[i]=v[p2++];
			}
		}
	//	imprime_vet(temp, tamanho);
		for(j=0,k=inicio; j<tamanho; j++, k++){
			v[k]=temp[j];
	//		printf("[%d]", temp[j]);		
		}
	}
	free(temp);
}

void insertion_sort(int *v, int n){
	int i, j, aux, x;

	for(i=+1; i<n; i++){
		x = v[i];
		j = i;
		while(x < v[j-1] && j > 0){
			v[j] = v[j-1];
			j--;
		}
		v[j] =x;
	}
}

void imprime_vet(int *v, int tam){
	for(int i = 0; i < tam; i++){
		printf(" %d ", v[i]);
	}
	printf("\n");
}


void main(){
	int *v;
	int tam;
	
	printf("Tamanho vetor\n");
	scanf("%d", &tam);
	
	v = (int*)malloc(sizeof(int) * tam);
	
	for(int i = 0; i < tam; i++){
		scanf("%d", &v[i]);
	}
	imprime_vet(v, tam);
	merge_sort(v, 0, tam);
	imprime_vet(v, tam);

	free(v);
}
