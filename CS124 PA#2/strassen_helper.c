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


int padding(int dim) {
  int counter = 1; 
  while (counter < dim) {
    counter *= 2; 
  }
  return counter;
}

void conventional(int dim, int** A, int** B, int** final) {
  for (int i=0; i<dim; i++){
      for (int j=0; j<dim; j++){
          int counter = 0;
          for (int c=0; c<dim; c++){
              counter += A[i][c] * B[c][j];
              final[i][j] = counter;
          }
      }
  }
}

void plus(int dim, int** A, int** B, int** final){
  for (int i=0;i<dim;i++){
    for (int j=0;j<dim;j++){
      final[i][j] = A[i][j] + B[i][j];
    }
  }
}

void minus(int dim, int** A, int** B, int** final){
  for (int i=0;i<dim;i++){
    for (int j=0;j<dim;j++){
      final[i][j] = A[i][j] - B[i][j];
    }
  }
}

int** makeMatrix(int dim){
  int** matrix = (int**)malloc(dim * sizeof(int*));
  for (int i=0;i<dim;i++){
    matrix[i] = (int*)malloc(dim * sizeof(int));
  }
  return matrix; 
}

void strassen(int dim, int** A, int** B, int** final, int crossover) {
  // base case
  if (dim <= crossover){
      conventional(dim,A,B,final);
  }
  else{
    // initialize initial submatrices
    int** A1 = makeMatrix(dim/2);
    int** A2 = makeMatrix(dim/2);
    int** A3 = makeMatrix(dim/2);
    int** A4 = makeMatrix(dim/2);

    int** B1 = makeMatrix(dim/2);
    int** B2 = makeMatrix(dim/2);
    int** B3 = makeMatrix(dim/2);
    int** B4 = makeMatrix(dim/2);

    for (int i=0;i<dim/2;i++){
      for (int j=0;j<dim/2;j++){
        // set values in submatrices
        A1[i][j] = A[i][j];
        A2[i][j] = A[i][j+dim/2];
        A3[i][j] = A[i+dim/2][j];
        A4[i][j] = A[i+dim/2][j+dim/2];

        B1[i][j] = B[i][j];
        B2[i][j] = B[i][j+dim/2];
        B3[i][j] = B[i+dim/2][j];
        B4[i][j] = B[i+dim/2][j+dim/2];
      }
    }

    // initialize calculation matrices
    int** m1 = makeMatrix(dim/2);
    int** m2 = makeMatrix(dim/2);
    int** m3 = makeMatrix(dim/2);
    int** m4 = makeMatrix(dim/2);
    int** m5 = makeMatrix(dim/2);
    int** m6 = makeMatrix(dim/2);
    int** m7 = makeMatrix(dim/2);


    // initialize final submatrices
    int** final1 = makeMatrix(dim/2);
    int** final2 = makeMatrix(dim/2);
    int** final3 = makeMatrix(dim/2);
    int** final4 = makeMatrix(dim/2);


    int** temp1 = makeMatrix(dim/2);
    int** temp2 = makeMatrix(dim/2);

    // m1
    minus(dim/2,B2,B4,temp1);
    strassen(dim/2,A1,temp1,m1, crossover);

    // m2
    plus(dim/2,A1,A2,temp1);
    strassen(dim/2,temp1,B4,m2, crossover);

    // m3
    plus(dim/2,A3,A4,temp1);
    strassen(dim/2,temp1,B1,m3, crossover);

    // m4
    minus(dim/2,B3,B1,temp1);
    strassen(dim/2,A4,temp1,m4, crossover);

    // m5
    plus(dim/2,A1,A4,temp1);
    plus(dim/2,B1,B4,temp2);
    strassen(dim/2,temp1,temp2,m5, crossover);

    // m6
    minus(dim/2,A2,A4,temp1);
    plus(dim/2,B3,B4,temp2);
    strassen(dim/2,temp1,temp2,m6, crossover);

    // m7
    minus(dim/2,A1,A3,temp1);
    plus(dim/2,B1,B2,temp2);
    strassen(dim/2,temp1,temp2,m7, crossover);

    // calculating final1
    plus(dim/2,m5,m4,temp1);
    plus(dim/2,temp1,m6,temp1);
    minus(dim/2,temp1,m2,final1);

    // calculating final2
    plus(dim/2,m1,m2,final2);
    
    // calculating final3
    plus(dim/2,m3,m4,final3);

    // calculating final4
    plus(dim/2,m1,m5,temp1);
    minus(dim/2,temp1,m3,temp1);
    minus(dim/2,temp1,m7,final4);

    // saving final submatrices into final array 
    for (int i=0;i<dim/2;i++){
      for (int j=0;j<dim/2;j++){
        final[i][j] = final1[i][j];
        final[i][j+dim/2] = final2[i][j];
        final[i+dim/2][j] = final3[i][j];
        final[i+dim/2][j+dim/2] = final4[i][j];
      }
    }
    free(A1);
    free(A2);
    free(A3);
    free(A4);

    free(B1);
    free(B2);
    free(B3);
    free(B4);

    free(m1);
    free(m2);
    free(m3);
    free(m4);
    free(m5);
    free(m6);
    free(m7);
    
    free(final1);
    free(final2);
    free(final3);
    free(final4);

    free(temp1);
    free(temp2);
  }
}
