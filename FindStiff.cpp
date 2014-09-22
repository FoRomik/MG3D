/*
 * ************************************************************************* * 
 * File:    FindStiff.cpp
 * Purpose: Find the corresponding position of stiffness matrix in the whole coefficient matrix
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

int FindStiff(struct CRS *MX, double **Stiff, int **El, int k)
{
    int i, j;
    for (i=0; i<4; i++)
        for (j=MX->row[El[k][i]]; j<MX->row[El[k][i]+1]; j++){
            if (El[k][0] == MX->column[j]) MX->value[j] += Stiff[i][0];
            else if (El[k][1] == MX->column[j]) MX->value[j] += Stiff[i][1];
            else if (El[k][2] == MX->column[j]) MX->value[j] += Stiff[i][2];
            else if (El[k][3] == MX->column[j]) MX->value[j] += Stiff[i][3];
    }
    return 0;
}
         
