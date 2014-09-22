/*
 * ************************************************************************* * 
 * File:    DET.cpp
 * Purpose: Get the determinant of one matrix
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

double DET(double **J, double h)
{
    double det;
    det = J[0][0]*J[1][1]*J[2][2] + J[0][1]*J[1][2]*J[2][0] + J[0][2]*J[1][0]*J[2][1] - J[0][2]*J[1][1]*J[2][0] - J[0][1]*J[1][0]*J[2][2] - J[0][0]*J[1][2]*J[2][1];
    //Because all of our elements are tetrahedrons with equal size here, it is a constant
    return det;
}
