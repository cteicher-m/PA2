/****************************************************************************
   * strassen.c
   *
   * Group members
   * Harvard ID: ??
   * Harvard ID: 50940144
   ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "strassen_helper.h"

// global variables
int flag,
	dim;
// int A[dim][dim];
// int B[dim][dim];
FILE *file; 

// prototypes
void conventional(int dim, int A[dim][dim], int B[dim][dim]);

int main(int argc, char* argv[]) {
    if (argc != 4) {
		printf("Usage: ./strassen flag dimension inputfile \n");
		return 0;
    } else {
		flag = atoi(argv[1]);
        dim = atoi(argv[2]);
        file = fopen(argv[3], "r");
    }

    int A[dim][dim];
	int B[dim][dim];

    if (file == NULL) {
        fprintf(stderr, "can't open %s\n", argv[3]);
        //exit;
    } else {
		for (int i = 0; i < pow(dim,2)/2; i++) {
			for (int j = 0; j < pow(dim,2)/2; j++ ) {
				if (i < dim && j<dim) {
					fscanf(file, "%d", &A[i][j]);
				}
				else {
					A[i][j] = 0;
				}

           		
			}
		}

		for (int i = pow(dim,2)/2; i < pow(dim,2); i++) {
			for (int j = pow(dim,2)/2; j < pow(dim,2); j++ ) {
				if (!fscanf(file, "%d", &B[i][j])) 
           			break;
           		//printf("%d\n",B[i][j]);
			}
		}
    }
   
    // A[0][0] = 1;
    // A[0][1] = 2;
    // A[0][2] = 3;
    // A[1][0] = 4;
    // A[1][1] = 5;
    // A[1][2] = 6;
    // A[2][0] = 7;
    // A[2][1] = 8;
    // A[2][2] = 9;

    // B[0][0] = 2;
    // B[0][1] = 3;
    // B[0][2] = 4;
    // B[1][0] = 5;
    // B[1][1] = 6;
    // B[1][2] = 7;
    // B[2][0] = 8;
    // B[2][1] = 9;
    // B[2][2] = 10;

    for (int a=0;a<dim;a++){
    	for (int b=0;b<dim;b++){
    		printf("%d\n",A[a][b]);
    	}
    }

    // for (int a=0;a<dim;a++){
    // 	for (int b=0;b<dim;b++){
    // 		printf("%d\n",B[a][b]);
    // 	}
    // }
    //conventional(dim,&A,&B);

    // Use conventional and strassens algorithm 
	// Print out results 
}