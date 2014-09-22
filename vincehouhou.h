/*
 * ************************************************************************
 * File:    vincehouhou.h
 * Purpose: Head file of all cpp codes
 * Author:  Houdong Hu
 * ************************************************************************
 */

#ifndef _VINCEHOUHOU_H_
#define _VINCEHOUHOU_H_

double DET(double **J, double h);
int **Element(int n0);
int **ElementNode(int **El, int n0);
double *ExactSolution(double **No, int n0, double h);
double Integral(double x, double y, double z, double det);
int FindStiff(struct CRS *MX, double **Stiff, int **El, int k);
int FindSve(double *Ve, double *Sve, int **El, int k);
double *GaussEli(struct CRS *M, double *r, int n);
double *Gauss_Seidal(struct CRS *A, double *b, double *z, int *level, int iter);
struct CRS *GetA(int *level, struct CRS *MX, int n0, double h);
double **GetJ(double **J, double **A);
double **GetStiff(double **J, double **IJ, double **IJT, double **IJPR, double **Stiff, double det);
double *GetSVector(double **A, double *Sve, double det);
double **Inverse33MX(double **J, double **IJ, double det, double h);
double **MatrixProduct(double **IJ, double **IJT, double **IJPR, int n);
double *Multigrid(int *level, struct CRS *MX, double *r, int n0, double h);
struct CRS *Matrixsetup(double *V, double **No, int **El, int **E_N, int **N_E,int n0, int n1, double h);
double **Node(int n0, double h);
double *PCG(double **No, struct CRS *MX, double *V, int n0, double h);
double *Prolongation(int *level, double *r);
double *Restriction(int *level, double *r);
struct CRS *SparseMXsetup(double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h);
double *SPMaVecPro(struct CRS *MX, double *p, int n);
int Stiffmatrix(double **A, double **Stiff, double **J, double **IJ, double **IJT, double **IJPR, struct CRS *MX, double *Ve, double *Sve, int **El, int n1, int k, double h);
int **Transpose(int **E_N, int n0);
struct CRS *TransposeSPMX(struct CRS *M, int n);
double VecDotPro(double *a, double *b, int n);
double *VecNumPro(double *p, double belta, int n);
double *VecVecAdd(double *a, double *b, int n);
double *VecVecRed(double *a, double *b, int n);

#endif
