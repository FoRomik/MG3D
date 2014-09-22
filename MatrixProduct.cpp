/*
 * *************************************************************************
 * File:    MatrixProduct.cpp
 * Purpose: n-dimensional matrix product
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
using namespace std;

double **MatrixProduct(double **IJ, double **IJT, double **IJPR, int n)
{
    int i, j, k;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            IJPR[i][j] = 0;
            for (k=0; k<n; k++)
                IJPR[i][j] += IJ[i][k]*IJT[k][j];
    }
    return(IJPR);
}


    

