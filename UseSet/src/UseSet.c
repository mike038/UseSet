/*
 * UseSet.c
 *
 *  Created on: May 14, 2020
 *      Author: Miguel Aguilar
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\..\..\Set\Set\Set.h"

#define TAM 100

int main(void) {
	setbuf(stdout, NULL);

	int numbers[TAM];
	int n, opcion = 0, i = 0;

	Set bst = set_create(compareInts); //binary search tree

	while (opcion != 9) {
		printf("Elige una opcion: \n");
		printf("1. Crear árbol.\n");
		printf("2. Agregar un dato\n");
		printf("3. Buscar un dato\n");
		printf("4. Eliminar un dato\n");
		printf("5. Imprimir en formato Pre-Orden\n");
		printf("6. Imprimir en formato In-Orden\n");
		printf("7. Imprimir en formato Post-Orden\n");
		printf("8. Eliminar arbol\n");
		printf("9. Salir\n");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			for (i = 0; i < TAM; i++) {
				printf("Dame dato (negativo para salir): ");
				scanf("%d", &n);
				if (n < 0)
					break;
				numbers[i] = n;
				set_add(bst, &numbers[i]);
			}
			break;
		case 2:
			printf("Dato a agregar: ");
			scanf("%d", &n);
			i = set_size(bst) + 1;
			numbers[i] = n;
			if (set_agregar(bst, &numbers[i]))
				printf("Valor agregado correctamente!\n\n");

			else
				printf("El valor no se puede agregar!\n\n");
			break;
		case 3:
			printf("Dato a buscar: ");
			scanf("%d", &n);
			if (set_containsValue((Type) &n, bst))
				printf("Valor encontrado\n\n");
			else
				printf("Valor no encontrado\n\n");
			break;
		case 4:
			printf("Dato a eliminar: ");
			scanf("%d", &n);
			if (set_removeValue((Type) &n, bst))
				printf("Valor eliminado\n\n");
			else
				printf("Valor no encontrado\n\n");
			break;
		case 5:
			printf("\nÁrbol en Pre-orden\n");
			set_printPreOrder(bst);
			printf("\n\n");
			break;
		case 6:
			printf("\nÁrbol en In-orden\n");
			set_printInOrder(bst);
			printf("\n\n");
			break;
		case 7:
			printf("\nÁrbol en Post-orden\n");
			set_printPostOrder(bst);
			printf("\n\n");
			break;
		case 8:
			set_destroy(bst);
			printf("Se ha eliminado el árbol\n\n");
			break;
		}

	}

	return 0;
}
