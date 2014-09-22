/*
 * ************************************************************************
 * File:    makefile
 * Author:  Houdong Hu
 * ************************************************************************
 */

OBJS = main.o Node.o Element.o ElementNode.o Transpose.o Matrixsetup.o SparseMXsetup.o Stiffmatrix.o GetJ.o DET.o Inverse33MX.o GetStiff.o MatrixProduct.o FindStiff.o GetSVector.o FindSve.o Integral.o PCG.o ExactSolution.o VecVecRed.o SPMaVecPro.o Multigrid.o VecDotPro.o VecVecAdd.o VecNumPro.o GetA.o Gauss_Seidal.o Restriction.o Prolongation.o GaussEli.o TransposeSPMX.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

vincehouhou : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o vincehouhou

main.o : main.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) main.cpp

Node.o : Node.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Node.cpp

Element.o : Element.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Element.cpp

ElementNode.o : ElementNode.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) ElementNode.cpp

Transpose.o : Transpose.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Transpose.cpp

Matrixsetup.o : Matrixsetup.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Matrixsetup.cpp

SparseMXsetup.o : SparseMXsetup.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SparseMXsetup.cpp

Stiffmatrix.o : Stiffmatrix.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Stiffmatrix.cpp

GetJ.o : GetJ.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GetJ.cpp

DET.o : DET.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) DET.cpp

Inverse33MX.o : Inverse33MX.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Inverse33MX.cpp

GetStiff.o : GetStiff.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GetStiff.cpp

MatrixProduct.o : MatrixProduct.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) MatrixProduct.cpp

FindStiff.o : FindStiff.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) FindStiff.cpp

GetSVector.o : GetSVector.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GetSVector.cpp

FindSve.o : FindSve.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) FindSve.cpp

Integral.o : Integral.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Integral.cpp

PCG.o : PCG.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) PCG.cpp

ExactSolution.o : ExactSolution.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) ExactSolution.cpp

VecVecRed.o : VecVecRed.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecVecRed.cpp

SPMaVecPro.o : SPMaVecPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SPMaVecPro.cpp

Multigrid.o : Multigrid.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Multigrid.cpp

VecDotPro.o : VecDotPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecDotPro.cpp

VecVecAdd.o : VecVecAdd.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecVecAdd.cpp

VecNumPro.o : VecNumPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecNumPro.cpp

GetA.o : GetA.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GetA.cpp

Gauss_Seidal.o : Gauss_Seidal.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Gauss_Seidal.cpp

Restriction.o : Restriction.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Restriction.cpp

Prolongation.o : Prolongation.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Prolongation.cpp

GaussEli.o : GaussEli.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GaussEli.cpp

TransposeSPMX.o : TransposeSPMX.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) TransposeSPMX.cpp


clean:
	\rm *.o vincehouhou


