/****************************************************************************
   * strassen_helper.h
   *
   * Group members
   * Harvard ID: 80983115
   * Harvard ID: 50940144
   ***************************************************************************/

// definitions

// prototypes
int padding(int dim);
void conventional(int dim, int A[dim][dim], int B[dim][dim]);
void strassen(int dim, int A[dim][dim], int B[dim][dim]);
