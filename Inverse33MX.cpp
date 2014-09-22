/*
 * ************************************************************************* 
 * File:    Inverse33MX.cpp
 * Purpose: Get the inverse matrix of 3*3 matrix
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

double **Inverse33MX(double **J, double **IJ, double det, double h)
{
    IJ[0][0] = (J[2][2]*J[1][1] - J[2][1]*J[1][2])/det;
    IJ[0][1] = -(J[2][2]*J[0][1] - J[2][1]*J[0][2])/det;
    IJ[0][2] = (J[1][2]*J[0][1] - J[1][1]*J[0][2])/det;
    IJ[1][0] = -(J[2][2]*J[1][0] - J[2][0]*J[1][2])/det;
    IJ[1][1] = (J[2][2]*J[0][0] - J[2][0]*J[0][2])/det;
    IJ[1][2] = -(J[1][2]*J[0][0] - J[1][0]*J[0][2])/det;
    IJ[2][0] = (J[2][1]*J[1][0] - J[2][0]*J[1][1])/det;
    IJ[2][1] = -(J[2][1]*J[0][0] - J[2][0]*J[0][1])/det;
    IJ[2][2] = (J[1][1]*J[0][0] - J[1][0]*J[0][1])/det;
    return(IJ);
}

