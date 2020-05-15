/*
 * UseSet.c
 *
 *  Created on: May 14, 2020
 *      Author: Miguel Aguilar
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\..\Set\Set.h"

#define TAM 100

int main(void) {

	int numbers[TAM];
	int n, opcion = 0;
	setbuf(stdout, NULL);

	Set bst = set_create(compareInts); //binary search tree

	while (opcion != 8) {
		printf("\nElige una opcion: \n");
		printf("1. Agregar datos.\n");
		printf("2. Buscar un dato\n");
		printf("3. Eliminar un dato\n");
		printf("4. Imprimir en formato Pre-Orden\n");
		printf("5. Imprimir en formato In-Orden\n");
		printf("6. Imprimir en formato Post-Orden\n");
		printf("7. Eliminar arbol\n");
		printf("8. Salir\n");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			for (int i = 0; i < TAM; i++) {
				printf("Dame dato (negativo para salir): ");
				scanf("%d", &n);
				if (n < 0)
					break;
				numbers[i] = n;
				set_add(bst, &numbers[i]);
			}
			break;
		case 2:
			printf("Dato a buscar: ");
			scanf("%d", &n);
			if (set_containsValue((Type) &n, bst))
				printf("Valor encontrado\n");
			else
				printf("Valor no encontrado\n");
			break;
		case 3:
			printf("Dato a eliminar: ");
			scanf("%d", &n);
			if (set_removeValue((Type) &n, bst))
				printf("Valor eliminado\n");
			else
				printf("Valor no encontrado\n");
			break;
		case 4:
			printf("\nÁrbol en Pre-orden\n");
			set_printPreOrder(bst);
			break;
		case 5:
			printf("\nÁrbol en In-orden\n");
			set_printInOrder(bst);
			break;
		case 6:
			printf("\nÁrbol en Post-orden\n");
			set_printPostOrder(bst);
			break;
		case 7:

			break;
		}

	}

	return 0;
}
