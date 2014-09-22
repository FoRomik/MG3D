/*
 * ************************************************************************
 * File:    Restriction.cpp
 * Purpose: Restriction step of a multigrid solver
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
 
double *Restriction(int *level, double *r)
{
    int n0 = (int)(pow(2, (*level)-1)+1);
    int n1 = (int)(pow(2, *level)+1);
    int i, j, k, m, nn = (n0-2)*(n0-2), nnn = (n1-2)*(n1-2), nnnn = (n0-2)*(n0-2)*(n0-2), nnnnn = (n1-2)*(n1-2)*(n1-2);
    double vv[n1][n1][n1], v[n0][n0][n0];
    double *q= new double [nnnn]; 
    for (m=1; m<=nnnnn; m++){
        k = (int)((m-1)/nnn)+1;
        j=(int)((m-1-(k-1)*nnn)/(n1-2))+1;
        i=m-(j-1)*(n1-2)-(k-1)*nnn;
        vv[i][j][k] = r[m-1];
        //cout << i << endl;
        //cout << j << endl;
        //cout << k << endl;
        //cout << vv[i][j][k] << endl;
        //cout << r[m-1] << endl;
    }
    for (m=1; m<=nnnn; m++){
        //out << i << endl;
        k = (int)((m-1)/nn)+1;
        j = (int)((m-1-(k-1)*nn)/(n0-2))+1;
        i = m-(j-1)*(n0-2)-(k-1)*nn;
        //cout << i << endl;
        m = i + (j-1)*n0 + (k-1)*nn;
        //v[i][j][k] = 1/8*vv[2*i][2*j][2*k];
        v[i][j][k] = 0.125*vv[2*i][2*j][2*k] + 0.0625*(vv[2*i-1][2*j][2*k] + vv[2*i+1][2*j][2*k] + vv[2*i][2*j-1][2*k] + vv[2*i][2*j+1][2*k] + vv[2*i][2*j][2*k-1] + vv[2*i][2*j][2*k+1]) + 0.03125*(vv[2*i][2*j-1][2*k-1] + vv[2*i][2*j-1][2*k+1] + vv[2*i][2*j+1][2*k-1] + vv[2*i][2*j+1][2*k+1] + vv[2*i-1][2*j][2*k-1] + vv[2*i-1][2*j][2*k+1] + vv[2*i+1][2*j][2*k-1] + vv[2*i+1][2*j][2*k+1] + vv[2*i-1][2*j-1][2*k] + vv[2*i-1][2*j+1][2*k] + vv[2*i+1][2*j-1][2*k] + vv[2*i+1][2*j+1][2*k]) + 0.015625*(vv[2*i-1][2*j-1][2*k-1] + vv[2*i-1][2*j-1][2*k+1] + vv[2*i-1][2*j+1][2*k-1] + vv[2*i-1][2*j+1][2*k+1] + vv[2*i+1][2*j-1][2*k-1] + vv[2*i+1][2*j-1][2*k+1] + vv[2*i+1][2*j+1][2*k-1] + vv[2*i+1][2*j+1][2*k+1]);
        //cout << v[i][j][k] << endl;
        //cout << i << endl;
        //cout << j << endl;
        //cout << k << endl;
        q[m-1] = v[i][j][k];
        //cout << q[m-1] << endl;
    }
    return q;
}
