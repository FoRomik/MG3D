/*
 * ************************************************************************
 * File:    f.cpp
 * Purpose: test b in Ax=b
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

double f(double x, double y, double z, double det)
{
    double a, pi = 3.1415926, b = 3*pi*pi;
    a = b * det * sin(pi*x) * sin(pi*y) * sin(pi*z) / 24;
    return a;
}
