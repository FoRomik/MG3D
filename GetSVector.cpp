/*
 * ************************************************************************* *
 * File:    GetSVector.cpp
 * Purpose: Get the element vector of b in Ax=b
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

double *GetSVector(double **A, double *Sve, double det)
{
    int i;
    if (det < 0) det = -det;
    for (i=0; i<4; i++)
        Sve[i] = Integral(A[i][0], A[i][1], A[i][2], det);
    return Sve;
}
