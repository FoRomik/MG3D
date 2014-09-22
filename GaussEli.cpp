/*
 * ************************************************************************* *
 * File:    GaussEli.cpp
 * Purpose: Conduct Gauss elimination
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

double *GaussEli(struct CRS *M, double *r, int n)
{
    int i, j;
    struct CRS *MT;
    MT = TransposeSPMX(M, n);
    for (i=0; i<n; i++){
        for (j=MT->row[i]+1; j<MT->row[i+1]; j++){
            r[MT->column[j]] -= r[i]*MT->value[j]/MT->value[MT->row[i]];
            
        }
    }
    for (i=0; i<n; i++){
       r[i] = r[i]/MT->value[MT->row[i]];
    }
    return (r);
}
