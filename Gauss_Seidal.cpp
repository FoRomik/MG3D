/*
 * ************************************************************************* *
 * File:    Gauss_Seidal.cpp
 * Purpose: Conduct Gauss Seidal iteration
 * Author:  Houdong Hu
 * ************************************************************************* */


#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h" 
using namespace std;

double *Gauss_Seidal(struct CRS *A, double *b, double *z, int *level, int iter)
{
    int i, j, count = 0, n1 = (int)(pow(2, *level)+1), n = (n1-2)*(n1-2)*(n1-2);
    struct CRS *M = new struct CRS;
    int *M1 = new int [n+1];
    M1[0] = 1;
    int *M2 = new int [(A->column[0]+n)/2+1];
    double *M3 = new double [(A->column[0]+n)/2+1], *r, *x;
    for (i=0; i<n; i++){
        for (j=A->row[i]; j<A->row[i+1]; j++){
            if (A->column[j]<=i){
                count++;
                M1[i+1]++;
                M2[count] = A->column[j];
                M3[count] = A->value[j];
            }
        }
        M1[i+1] += M1[i];
    }
    M2[0] = count;
    M3[0] = count;
    M->row = M1;
    M->column = M2;
    M->value = M3;
    for (i=0; i<iter; i++){
        r = VecVecRed(b, SPMaVecPro(A, z, n), n);
        x = GaussEli(M, r, n);
        z = VecVecAdd(z, x, n);
    }
    return(z);
}
