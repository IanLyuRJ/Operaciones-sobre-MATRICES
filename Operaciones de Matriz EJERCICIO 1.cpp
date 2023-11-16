#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int FILAS = 5;
    int COLUMNAS = 7;
    int matriz[FILAS][COLUMNAS];
    int sumaDiagonal = 0, sumaPrimeraFila = 0, sumaUltimaColumna = 0;
    int sumaFilasImpares = 0, sumaColumnasPares = 0;
    int sumaTriangularSuperior = 0, sumaTriangularInferior = 0;

    srand(time(NULL));

    printf("Matriz generada:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 10;
            printf("%d ", matriz[i][j]);
			//Intento 6 de usar puros if jajajsa :)
            if (i == j) sumaDiagonal += matriz[i][j];
            if (i == 0) sumaPrimeraFila += matriz[i][j];
            if (j == COLUMNAS - 1) sumaUltimaColumna += matriz[i][j];
            if (i % 2 == 0) sumaFilasImpares += matriz[i][j]; 
            if ((j + 1) % 2 == 0) sumaColumnasPares += matriz[i][j];
            if (i <= j) sumaTriangularSuperior += matriz[i][j];
            if (i >= j) sumaTriangularInferior += matriz[i][j];
        }
        printf("\n");
    }

    printf("\nSuma de la diagonal: %d\n", sumaDiagonal);
    printf("Suma de la fila 1: %d\n", sumaPrimeraFila);
    printf("Suma de la columna 7: %d\n", sumaUltimaColumna);
    printf("-----------------------\n");
    for (int i = 0; i < FILAS; i += 2) {
        int sumaFila = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            sumaFila += matriz[i][j];
        }
        printf("Suma de la fila %d: %d\n", i + 1, sumaFila);
    }
    printf("Suma de las filas impares (1, 3, 5): %d\n", sumaFilasImpares);
    printf("-----------------------\n");
    for (int j = 1; j < COLUMNAS; j += 2) {
        int sumaColumna = 0;
        for (int i = 0; i < FILAS; i++) {
            sumaColumna += matriz[i][j];
        }
        printf("Suma de la columna %d: %d\n", j + 1, sumaColumna);
    }
    printf("Suma de las columnas pares (2, 4, 6): %d\n", sumaColumnasPares);
    printf("-----------------------------\n");
    printf("Suma de la diagonal: %d\n", sumaDiagonal);
    printf("Suma de la triangular superior: %d\n", sumaTriangularSuperior);
    printf("--------------------------\n");
    printf("Suma de la diagonal: %d\n", sumaDiagonal);
    printf("Suma de la triangular inferior: %d\n", sumaTriangularInferior);

    return 0;
}

