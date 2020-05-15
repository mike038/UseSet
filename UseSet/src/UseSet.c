/*
 ============================================================================
 Name        : UseSet.c
 Author      : Miguel Aguilar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\..\..\Set\Set\Set.h"

#define TAM 100

int main(void) {

	int numbers[TAM];
	int n;
	setbuf(stdout,NULL);

	Set bst = set_create(compareInts); //binary search tree

	for (int i=0; i<TAM; i++)
	{
		printf("Dame dato (negativo para salir): ");
		scanf("%d",&n);
		if (n<0) break;
		numbers[i] = n;
		set_add(bst,&numbers[i]);

	}

	printf("Dato a eliminar: ");
	scanf("%d",&n);
	if (set_removeValue((Type)&n,bst))
		printf("Valor eliminado\n");
	else
		printf("Valor no encontrado\n");

	printf("Dato a buscar: ");
		scanf("%d",&n);
		if (set_containsValue((Type)&n,bst))
			printf("Valor encontrado\n");
		else
			printf("Valor no encontrado\n");

	printf("\nÁrbol en preorden\n");
	set_printPreOrder(bst);

	return 0;
}
