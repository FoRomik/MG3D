/*
 * ************************************************************************
 * File:    main.cpp
 * Purpose: Product of a CRS sparse matrix and a vector
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

double *SPMaVecPro(struct CRS *MX, double *p, int n)
{
    int i, j;
    double *q = new double [n];
    for (i=0; i<n; i++){
        q[i] = 0;
        for (j=MX->row[i]; j<MX->row[i+1]; j++){
            q[i] += MX->value[j]*p[MX->column[j]];
        }
    }
    return (q);
}
