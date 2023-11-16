#include <stdio.h>

int main() {
    int matriz[3][3];
    int sumaDiagonal1 = 0, sumaDiagonal2 = 0;
    int sumaFila[3] = {0}, sumaColumna[3] = {0};
    int esMagica = 1; 


    printf("Ingrese los valores de la matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
            sumaFila[i] += matriz[i][j];
            sumaColumna[j] += matriz[i][j];
        }
        sumaDiagonal1 += matriz[i][i];
        sumaDiagonal2 += matriz[i][2 - i];
    }


    int sumaReferencia = sumaFila[0];
    for (int i = 0; i < 3; i++) {
        if (sumaFila[i] != sumaReferencia || sumaColumna[i] != sumaReferencia) {
            esMagica = 0;
            break;
        }
    }
    if (sumaDiagonal1 != sumaReferencia || sumaDiagonal2 != sumaReferencia) {
        esMagica = 0;
    }

    
    for (int i = 0; i < 3; i++) {
        printf("Suma de la fila %d: %d\n", i + 1, sumaFila[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("Suma de la columna %d: %d\n", i + 1, sumaColumna[i]);
    }
    printf("-----------------------\n");
    printf("Suma de la diagonal: %d\n", sumaDiagonal1);
    printf("Suma de la diagonal secundaria: %d\n", sumaDiagonal2);


    if (esMagica) {
        printf("La matriz es magica.\n");
    } else {
        printf("La matriz no es mágica.\n");
    }

    return 0;
}

