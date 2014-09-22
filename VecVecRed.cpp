/*
 * ************************************************************************
 * File:    VecVecRed.cpp
 * Purpose: Substraction of two vectors
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

double *VecVecRed(double *a, double *b, int n)
{
    int i;
    double *c = new double [n];
    for (i=0; i<n; i++){
        c[i] = a[i] - b[i];
    }
    return c;
}
