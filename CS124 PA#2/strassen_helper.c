/****************************************************************************
   * strassen_helper.c
   *
   * Group members
   * Harvard ID: 80983115
   * Harvard ID: 50940144
   ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "strassen_helper.h"

//int m1, m2, m3, m4, m5, m6, m7;

int padding(int dim) {
	int counter = 1; 
	while (counter < dim) {
		counter *= 2; 
	}
	return counter;
}

void conventional(int dim, int A[dim][dim], int B[dim][dim]) {
	int final[dim][dim];
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            int counter = 0;
            for (int c=0; c<dim; c++){
                counter += A[i][c] * B[c][j];
                final[i][j] = counter;
            }
            printf("%d\n",final[i][j]);
        }
    }
}

void strassen(int dim, int A[dim][dim], int B[dim][dim]) {}