/*
 * ************************************************************************* 
 * File:    Stiffmatrix.cpp
 * Purpose: Add the stiffness matrix of each element to A
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

int Stiffmatrix(double **A, double **Stiff, double **J, double **IJ, double **IJT, double **IJPR, struct CRS *MX, double *Ve, double *Sve, int **El, int n1, int k, double h)
{
    /*
     *  we use the 3D standard piecewise basis sets, which are x, y, z, 1-x-y-z, Gradient_basis are the gradients of the basis sets
     */
    double det;
    J = GetJ(J, A);
    det = DET(J, h);
    IJ = Inverse33MX(J, IJ, det, h);
    Stiff = GetStiff(J, IJ, IJT, IJPR, Stiff, det);
    Sve = GetSVector(A, Sve, det); 
    FindStiff(MX, Stiff, El, k);
    FindSve(Ve, Sve, El, k);
    /*
     *  J is the Jacobi matrix from actual elements to standard elements
     *  DET is the determinant of the Jacobi matrix
     *  Inverse33MX is the inverse matrix of a 3*3 matrix
     *  GetStiff is the stiffness matrix of one element
     *  FindStiff is to find the corresponding position of stiffness matrix in the whole coefficient matrix
     */
     return 0;
}
    

    
