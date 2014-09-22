/*
 * ************************************************************************
 * File:    main.cpp
 * Purpose: Solve the 3D possion equation by multigrid method
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

int main()
{
    /*
     *   n0 is the number of points in 1D
     *   n1 is the dimension of stiffness matrix, which is determinded by the dimension and the order of basis functions
     *   n2 is the dimension of coefficient matrix after taking off the boundary values
     *   No is the nodes' coordinates
     *   El is the vertex number of the elements
     *   E_N is the sparse matrix of elements_nodes relationship
     *   N_E is the sparse matrix of nodes_elements relationship
     *   MX is the whole coefficient matrix, which is A in Ax = b
     *   Ve is the vector b, which is b in Ax = b
     *   Solution is the solving results
     *   Node is the information of nodes coordinates
     *   Element is the information of elements and their corresponding nodes
     *   ElememtNode is the sparse matrix setup of elements_nodes relatiship
     *   Transpose is the transpose of sparse matrix
     *   Matrixsetup is the setup of the whole coefficient matrix
     *   PCG is the preconditioned conjugate gradient solver
     */
    int i, n0 = 33, n1 = 4, **El, **E_N, **N_E, nn = (n0-2)*(n0-2)*(n0-2);
    double **No, *Solution, h;
    h = 1/double(n0-1);
    double *V = new double [nn];
    for (i=0; i<nn; i++)
        V[i] = 0;
    struct CRS *MX;
    No = Node(n0, h);
    El = Element(n0);
    E_N = ElementNode(El, n0);
    N_E = Transpose(E_N, n0);
    MX = Matrixsetup(V, No, El, E_N, N_E, n0, n1, h);    
    Solution = PCG(No, MX, V, n0, h);
    return 0;
}
