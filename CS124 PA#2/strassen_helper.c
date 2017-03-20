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
            int counter = 0;
            for (int c=0; c<dim; c++){
                // printf("%d\n",final[i][j]);
                //printf("%i * %i\n",A[i][c],B[c][j]);
                counter += A[i][c] * B[c][j];
                final[i][j] = counter;
				//printf("Adding %i\n",A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[c][2]);
            }

            printf("total is %i\n",final[i][j]);
        }
    }

	for(int a = 0; a < dim; a++) {
		for(int b = 0; b < dim; b++) {
			//printf("%d\n",final[a][b]);
		}
	}
}
void strassen() {}
