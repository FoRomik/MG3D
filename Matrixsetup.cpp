/*
 * *************************************************************************
 * File:    Matrixsetup.cpp
 * Purpose: Set up A, for Ax=b
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

struct CRS *Matrixsetup(double *V, double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h)
{
    /* 
     *  Definition and Initialization 
     *  A is the coordinates of the four nodes for each element
     *  Stiff is the stiffness matrix for each element
     *  J is the Jacobi matrix from each element to standard elements
     *  IJ is the inverse matrix of Jacobi matrix
     *  IJT is the transpose matrix of IJ
     *  SparseMXsetup is to find the dimension of sparse matrix format of A  in Ax = b
     *  for loop is to add the contribution of each element into A
     *  Stiffmatrix is how to add the stiffness matrix of each element to A
     */
    int i, j, k, l, p, q, n = (n0-1)*(n0-1)*(n0-1)*6, nn = n0*n0, nnn = (n0-2)*(n0-2), nnnn = n0*n0*n0; 
    double **A = new double*[4];
    double **Stiff = new double*[4];
    double **J = new double*[3];
    double **IJ = new double*[3];
    double **IJT = new double*[3];
    double **IJPR = new double*[3];
    for (i=0; i<4; i++){
        A[i] = new double[3];
        for (j=0; j<3; j++)
            A[i][j] = 0;
        Stiff[i] = new double[4];
        for (j=0; j<4; j++)
            Stiff[i][j] = 0;
    }
    for (i=0; i<3; i++){
        J[i] = new double[3];
        IJ[i] = new double[3];
        IJT[i] = new double[3];
        IJPR[i] = new double[3];
        for (j=0; j<3; j++){
            J[i][j] = 0;
            IJ[i][j] = 0;
            IJT[i][j] = 0;
            IJPR[i][j] = 0;
        }            
    }
    double *Ve = new double [nnnn];
    double *Sve = new double [4];
    for (i=0; i<nnnn; i++)
        Ve[i] = 0;
    for (i=0; i<4; i++)
        Sve[i] = 0;
    struct CRS *MX;
    MX = SparseMXsetup(No, El, E_N, N_E, n0, n1, h);
   for (i=0; i<n; i++){ 
       for (j=0; j<4; j++)
            for (k=0; k<3; k++){
                A[j][k] = No[El[i][j]][k];
       }
       Stiffmatrix(A, Stiff, J, IJ, IJT, IJPR, MX, Ve, Sve, El, n1, i, h);
   }
   struct CRS *MMX = new struct CRS;
   int *MMX1 = new int [(n0-2)*(n0-2)*(n0-2)+1];
   MMX1[0] = 1;
   int *MMX2 = new int [MX->column[0]+1];
   double *MMX3 = new double [MX->column[0]+1];
   int tcount=0, tvcount=0, t, x, y, z;
   for (k=1; k<n0-1; k++)
        for (j=1; j<n0-1; j++)
            for (i=1; i<n0-1; i++){
                 p = i + j*n0 + k*nn;
                 q = i-1 + (j-1)*(n0-2) + (k-1)*nnn;
                 x = p%n0;
                 if (x!=0 && x!=n0-1){
                    y = (p%nn-x)/n0;
                    if (y!=0 && y!=n0-1){
                        z = (p-x-y*n0)/nn;
                        if (z!=0 && z!=n0-1){
                           V[tvcount]=Ve[p];
                           tvcount++;
                        }
                    }
                 }
                 int ccount=0;
                 for (l=MX->row[p]; l<MX->row[p+1]; l++){
                    t = MX->column[l];
                    x = t%n0;
                    if (x!=0 && x!=n0-1){
                        y = (t%nn-x)/n0;
                        if (y!=0 && y!=n0-1){
                            z = (t-x-y*n0)/nn;
                            if (z!=0 && z!=n0-1){
                                tcount++;
                                ccount++;
                                MMX2[tcount]= x-1 + (y-1)*(n0-2) + (z-1)*nnn;
                                MMX3[tcount]=MX->value[l];
                            }
                        }
                    }
                }
                MMX1[q+1] = MMX1[q] + ccount;
    }
    int *MMX22 = new int[tcount+1];
    double *MMX33 = new double[tcount+1];
    for (i=1; i<tcount+1; i++){
        MMX22[i] = MMX2[i];
        MMX33[i] = MMX3[i];
    }
    double max = 0;
    for (i=1; i<tvcount; i++){
        if(V[i]>max) max = V[i];
    }
    MMX22[0] = tcount;
    MMX33[0] = tcount;
    MMX->row = MMX1;
    MMX->column = MMX22;
    MMX->value = MMX33;
    return(MMX);
}
