/*
 * ************************************************************************
 * File:    TransposeSPMX.cpp
 * Purpose: Transpose of a CRS sparse matrix
 * Author:  Houdong Hu
 * ************************************************************************
 */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

struct CRS *TransposeSPMX(struct CRS *M, int n)
{
    int i, j, test[n], count[n];
    for (i=0; i<n; i++){
        test[i] = 0;
        count[i] = 0;
    }
    for (i=0; i<n; i++)
        for (j=M->row[i]; j<M->row[i+1]; j++){
            test[M->column[j]]++;
    }
    int tcount;
    for (i=0; i<n; i++){
        tcount += test[i];
    }
    int *M1 = new int [n+1];
    int *M2 = new int [tcount+1];
    double *M3 = new double [tcount+1];
    M1[0] = 1;
    M2[0] = tcount;
    M3[0] = tcount;
    for (i=1; i<=n; i++){
        M1[i] = M1[i-1]+test[i-1];
    }
    for (i=0; i<n; i++)
        for (j=M->row[i]; j<M->row[i+1]; j++){
            M2[M1[M->column[j]]+count[M->column[j]]] = i;
            M3[M1[M->column[j]]+count[M->column[j]]] = M->value[j];
            count[M->column[j]]++;
    } 
    struct CRS *MT = new struct CRS;
    MT->row = M1;
    MT->column = M2;
    MT->value = M3;
    return (MT);
}
