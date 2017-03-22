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

int m1, m2, m3, m4, m5, m6, m7;

int padding(int dim) {
	int counter = 1; 
	while (counter < dim) {
		counter *= 2; 
	}
	return counter;
}

int[dim][dim2] conventional(int dim, int A[dim][dim], int B[dim][dim]) {
	int final[dim][dim];
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            int counter = 0;
            for (int c=0; c<dim; c++){
                counter += A[i][c] * B[c][j];
                final[i][j] = counter;
            }
            // printf("%d\n",final[i][j]);
        }
    }

    return final;
}
int[dim][dim] plus(int A[dim][dim], int B[dim][dim]){
  int final[dim][dim];
  for (int i=0;i<dim;i++){
    for (int j=0;j<dim;j++){
      final[i][j] = A[i][j] + B[i][j];
    }
  }
  return final;
}
int minus(int A[dim][dim], int B[dim][dim]){
  int final[dim][dim];
  for (int i=0;i<dim;i++){
    for (int j=0;j<dim;j++){
      final[i][j] = A[i][j] - B[i][j];
    }
  }
  return final
}
void strassen(int dim, int A[dim][dim], int B[dim][dim]) {
  int A1[][] = A(0:dim/2,0:dim/2);
  int A2[][] = A(dim/2:,0:dim/2);
  int A3[][] = A(dim/2:,dim/2:dim/2);
  int A4[][] = A(dim/2:0,dim/2:dim/2);

  int B1[][] = B(0:dim/2,0:dim/2);
  int B2[][] = B(dim/2:,0:dim/2);
  int B3[][] = B(dim/2:,dim/2:dim/2);
  int B4[][] = B(dim/2:0,dim/2:dim/2);

  int final1[dim/2][dim/2];
  int final2[dim/2][dim/2];
  int final3[dim/2][dim/2];
  int final4[dim/2][dim/2];

  if (dim < CROSSOVER){
    conventional(dim, A[dim][dim], B[dim][dim]);
  }
  else{
      m1 = strassens(dim/2,minus(B2,B4),m8);
      m2 = strassens(dim/2,minus(A1,A2),B4);
      m3 = strassens(dim/2,plus(A3,A4),B1);
      m4 = strassens(dim/2,minus(B3,B1),m1);
      m5 = strassens(dim/2,minus(A1,A4),plus(B1,B4));
      m6 = strassens(dim/2,minus(A2,A4),plus(B3,B4));
      m7 = strassens(dim/2,minus(A1,A3),plus,(B1+B2);
  }

  final1 = m5+m4+m6-m2;
  final2 = m1+m2;
  final3 = m3+m4;
  final4 = m1+m5-m3-m7;
}
