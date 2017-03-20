/****************************************************************************
   * strassen_helper.c
   *
   * Group members
   * Harvard ID: ??
   * Harvard ID: 50940144
   ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
//#include "strassen_helper.h"

int m1, m2, m3, m4, m5, m6, m7;

void conventional(int dim, int A[dim][dim], int B[dim][dim]) {
	int final[dim][dim];
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            for (int c=0; c<dim; c++){
                final[i][j] += A[i][c] * B[c][j];
				//printf("%d\n",final[i][j]);
            }
        }
    }

	for(int a = 0; a < dim; a++) {
		for(int b = 0; b < dim; b++) {
			//printf("%d\n",final[a][b]);
		}
	}
}
void strassen() {}