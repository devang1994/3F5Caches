#include <iostream>
#include "inst_compact.h"
#include <stdio.h>      //added these 2 header files 
#include <stdlib.h> 

using namespace std;

const int matrixSize = 100;
int blockingFactor = 20; //removed the const 
int a[matrixSize][matrixSize];
int b[matrixSize][matrixSize];
int c[matrixSize][matrixSize];

int main( int argc, char *argv[]) { // edited this line to allow for command line arguments
 
  blockingFactor=atoi(argv[1]);  //setting the blocking factor to the command line argument

  //cout<<blockingFactor;
  int i, j, k, jj, kk, r;

  // Initialise the matrices arbitrarily
  for (i=0; i < matrixSize; i++)
    for (j=0; j < matrixSize; j++) {
      b[i][j] = i + j; c[i][j] = i - j; a[i][j] = 0;
    }

  // Work out a = b * c, using a blocking algorithm
  for (i=0; i < matrixSize; i++)
    for (j=0; j < matrixSize; j++) {
      b[i][j] = i + j; c[i][j] = i - j; a[i][j] = 0;
    }

  // Work out a = b * c, using a blocking algorithm
  jj = 0;
  kk = 0;
  while (jj < matrixSize) {
    while (kk < matrixSize) {
      for (i=0; i < matrixSize; i++) 
	for (j=jj; j < jj + blockingFactor; j++) {
	  r = 0;
	  for (k=kk; k < kk + blockingFactor; k++) {
	    INST_R(b[i][k]);
	    INST_R(c[k][j]);
	    r += b[i][k] * c[k][j];
	  }
	  INST_R(a[i][j]);
	  a[i][j] = a[i][j] + r;
	  INST_W(a[i][j]);
	}
      kk += blockingFactor;
    }
   kk = 0;
   jj += blockingFactor;
  }

 /* // Display the product
  for (i=0; i < matrixSize; i++) {
    for (j=0; j < matrixSize; j++) cerr << a[i][j] << ' ';
    cerr << endl;
  }*/

}
