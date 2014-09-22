/*
 * ************************************************************************* * 
 * File:    GetStiff.cpp
 * Purpose: Get the stiffness matrix of each element
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

double **GetStiff(double **J, double **IJ, double **IJT, double **IJPR, double **Stiff, double det)
{
    int i, j;
    if (det < 0) det = -det;
    /*
     *  we use the 3D standard piecewise basis sets, which are x, y, z, 1-x-y-z, Gradient_basis are the gradients of the basis sets
     */
    for (i=0; i<3; i++)
        for (j=0; j<3; j++) 
            IJT[i][j] = IJ[j][i];
    /*
     *  Stiffness matrix can be calculate by
     *  \int \gradientdown\phi_{i}\gradientdown\phi_{j} d\Omega_{k} =
     *  \int detJ*\gradientdown'\phi_{i}^{T}*J^{-1}*J^{-T}*\gradientdown'\phi_{j} d\Omega_{k}'
     *  Since the basis sets are piecewise functions, so all the integrant will be a constant 
     */
    IJPR = MatrixProduct(IJ, IJT, IJPR, 3);         
    Stiff[0][0] = (IJPR[0][0] + IJPR[0][1] + IJPR[0][2] + IJPR[1][0] + IJPR[1][1] + IJPR[1][2] + IJPR[2][0] + IJPR[2][1] + IJPR[2][2]) * det / 6;
    Stiff[0][1] = -(IJPR[0][0] + IJPR[1][0] + IJPR[2][0]) * det / 6;
    Stiff[0][2] = -(IJPR[0][1] + IJPR[1][1] + IJPR[2][1])* det / 6;
    Stiff[0][3] = -(IJPR[0][2] + IJPR[1][2] + IJPR[2][2]) * det / 6;
    Stiff[1][0] = -(IJPR[0][0] + IJPR[0][1] + IJPR[0][2]) * det / 6;
    Stiff[1][1] = IJPR[0][0] * det / 6;
    Stiff[1][2] = IJPR[0][1] * det / 6;
    Stiff[1][3] = IJPR[0][2] * det / 6;
    Stiff[2][0] = -(IJPR[1][0] + IJPR[1][1] + IJPR[1][2]) * det / 6;
    Stiff[2][1] = IJPR[1][0] * det / 6;
    Stiff[2][2] = IJPR[1][1] * det / 6;
    Stiff[2][3] = IJPR[1][2] * det / 6;
    Stiff[3][0] = -(IJPR[2][0] + IJPR[2][1] + IJPR[2][2]) * det / 6;
    Stiff[3][1] = IJPR[2][0] * det / 6;
    Stiff[3][2] = IJPR[2][1] * det / 6;
    Stiff[3][3] = IJPR[2][2] * det / 6;
    return(Stiff);
}

