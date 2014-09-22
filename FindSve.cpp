/*
 * ************************************************************************* *
 * File:    FindSve.cpp
 * Purpose: Construct b in Ax=b
 * Author:  Houdong Hu
 * ************************************************************************* */


#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"

int FindSve(double *Ve, double *Sve, int **El, int k)
{
    int i;
    for (i=0; i<4; i++)
        Ve[El[k][i]] += Sve[i];
    return i;
}
