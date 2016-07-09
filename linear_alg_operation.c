#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "multi_cost_h.h"

double* matrxvec(double **matrix1,double *vector1,int m_matr,int n_matr)
{
	double* result_vec;
	result_vec=(double*)malloc(n_matr*sizeof(double));
	double sum=0;
	for (int i=0;i<m_matr;i++)
	{
		for (int j=0;j<n_matr;j++)
		{
			sum+=matrix1[i][j]*vector1[j];
		}
		result_vec[i] = sum;
		sum=0;
	}
	return result_vec;
}

double** matrxmatr(double** matrix1,double** matrix2,int m_matr1,int n_matr1,int m_matr2,int n_matr2)
{
	double sum=0;
	double **result_matrix;
	result_matrix=(double**)malloc(m_matr1*sizeof(double));
		for (int i=0;i<m_matr1;i++)
		{
			result_matrix[i]=(double*)malloc(n_matr2*sizeof(double));
		}
	for (int i=0;i<m_matr1;i++)
	{
		for (int j=0;j<m_matr2;j++)
		{
			for (int r = 0;r<n_matr1;r++)
			{
				sum+=matrix1[i][r]*matrix2[r][j];
			}
			result_matrix[i][j] = sum;
			sum=0;
		}
	}
	return result_matrix;
}


double **transpon_matrix(double **matr,int n,int m)
{
	double **rez;
	rez = (double **)malloc(n*sizeof(double *));
	for (int i=0;i<n;i++)
		rez[i] = (double *)malloc(m*sizeof(double));
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			rez[j][i] = matr[i][j];
	return rez;
}

double **diagonalization(const double * vec,int m)
{
	double **matr_rez;
	matr_rez = (double **)malloc(m*sizeof(double));
	for (int i=0;i<m;i++)
	{
		matr_rez[i] = (double *)malloc(m*sizeof(double));
	}
	for (int i=0;i<m;i++)
	{
		matr_rez[i][i] = vec[i];
	}
	return matr_rez;
}

