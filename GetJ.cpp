/*
 * *************************************************************************
 * File:    GetJ.cpp
 * Purpose: Get the Jacobi matrix for each actual element
 * Author:  Houdong Hu
 * *************************************************************************
 */
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

double **GetJ(double **J, double **A)
{
    /*
     *  The Jacobi matrix for one element with nodes (x1, y1, z1), (x2, y2, z2), (x3, y3, z3) and (x4, y4, z4) is:
     *  x2-x1  x3-x1  x4-x1
     *  y2-y1  y3-y1  y4-y1
     *  z2-z1  z3-z1  z4-z1
     */
    int i, j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++){
            J[i][j] = A[j+1][i] - A[0][i];
    }
    return(J);
}
