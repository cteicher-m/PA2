/****************************************************************************
   * strassen_helper.h
   *
   * Group members
   * Harvard ID: 80983115
   * Harvard ID: 50940144
   ***************************************************************************/

// definitions
#define CROSSOVER 90
   
// prototypes
int padding(int dim);
void conventional(int dim, int** A, int** B, int** final);
void strassen(int dim, int** A, int** B, int** final, int crossover);
void plus(int dim, int** A, int** B, int** final);
void minus(int dim, int** A, int** B, int** final);
int** makeMatrix(int dim);
