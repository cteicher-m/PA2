/****************************************************************************
   * strassen.c
   *
   * Group members
   * Harvard ID: 80983115
   * Harvard ID: 50940144
   ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "strassen_helper.h"

// global variables
int flag, dim;
FILE *file; 

int main(int argc, char* argv[]) {

    if (argc != 4) {
		printf("Usage: ./strassen flag dimension inputfile \n");
		return 0;
    } else {
		flag = atoi(argv[1]);
        dim = atoi(argv[2]);
        file = fopen(argv[3], "r");
    }


    // FILE *newfile = fopen("mock2.txt", "w");

    // for (int i=0;i<2*pow(10,2);i++){
    //     fprintf(newfile, "%d\n",rand());
    // }


    int final_dim = padding(dim);
	int A[final_dim][final_dim];
	int B[final_dim][final_dim];
    int final[final_dim][final_dim];

    if (file == NULL) {
        fprintf(stderr, "can't open %s\n", argv[3]);
    } else {
		for (int i = 0; i < final_dim; i++) {
			for (int j = 0; j < final_dim; j++) {
				if (i < dim && j < dim) {
					fscanf(file, "%d", &A[i][j]);
				}
				else {
					A[i][j] = 0;
				}    		
			}
		}

		for (int i = 0; i < final_dim; i++) {
			for (int j = 0; j < final_dim; j++) {
				if (i < dim && j < dim) {
					fscanf(file, "%d", &B[i][j]);
				}
				else {
					B[i][j] = 0;
				}
			}
		}
    }
   	
   	fclose(file);

    //conventional(final_dim,A,B,final);
    strassen(final_dim,A,B,final);

    // Use conventional and strassens algorithm 
	// Print out results 
}
