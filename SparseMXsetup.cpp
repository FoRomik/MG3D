/*
 * *************************************************************************
 * File:    SparseMXsetup.cpp
 * Purpose: Find the dimension of sparse matrix format of A in Ax = b
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

struct CRS *SparseMXsetup(double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h)
{
    int nn = n0*n0*n0, k, l, m, o, p, q, ttest=0, tcount = 0;
    int test[nn];
    int *count = new int[nn];
    for (k=0; k<nn; k++){
        test[k] = 0;
        count[k] =0;
    }
    for (k=0; k<nn; k++){
        for (l=N_E[0][k]; l<N_E[0][k+1]; l++){
           test[k] = test[k] + E_N[0][N_E[1][l]+1] - E_N[0][N_E[1][l]];
        }
        ttest += test[k];
    }
    /*
     *  test[nn] is an array to find the number of overlapping nodes with each node
     *  ttest is the number of non-zero elements in A
     *  both test and ttest are the max possible number, there can be some repeating ones
     */
    int *tja = new int[ttest];
    for (k=0; k<ttest; k++){
        tja[k] = 0;
    }
    //  tja is to store the column information for non-zero elements in A
    for (k=0; k<nn; k++){
        for (l=N_E[0][k]; l<N_E[0][k+1]; l++)
            for (m=E_N[0][N_E[1][l]]; m<E_N[0][N_E[1][l]+1]; m++){
                q=count[k];
                //  count[nn] is an array to store the number of nonrepeating overlapping nodes with each node 
                if (q==0){
                    tja[tcount] = E_N[1][m];
                    count[k]++;
                }
                //  case: first element
                else if (q==1 && tja[tcount]>E_N[1][m]){
                    tja[tcount+1] = tja[tcount];
                    tja[tcount] = E_N[1][m];
                    count[k]++;
                }
                //  case: two elements; second element is smaller than first element
                else if (tja[tcount+q-1] < E_N[1][m]){
                    tja[tcount+q] = E_N[1][m];
                    count[k]++;
                }
                //  case: N elements; the newest element is the largest
                else{
                    for (o=tcount; o<tcount+q-1; o++){
                        if (tja[o] == E_N[1][m]) o = tcount+q;
                        else if (E_N[1][m] > tja[o] && E_N[1][m] < tja[o+1]){
                            for (p=tcount+q-1; p>o; p--){
                                tja[p+1] = tja[p];
                            }
                            tja[o+1] = E_N[1][m];
                            o = tcount+q;
                            count[k]++;
                        }
                    }
                //  case: N elements; the newest element is neither the largest nor the smallest
                }
        }
        tcount += count[k];
        //  tcount is the total nonrepeating nonzero elements of A
    }
    struct CRS *MMX = new struct CRS;
    int *MX1 = new int [nn+1];
    MX1[0] = 1;
    for (k=1; k<nn+1; k++){
        MX1[k] = MX1[k-1] + count[k-1];
    }
    int *MX2 = new int [tcount+1];
    double *MX3 = new double [tcount+1];
    for (k=1; k<=tcount; k++){
        MX2[k] = tja[k-1];
        MX3[k] = 0;
    }
    MX2[0] = tcount;
    MX3[0] = tcount;
    MMX->row = MX1;
    MMX->column = MX2;
    MMX->value = MX3;
    return (MMX);
}
