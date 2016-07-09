#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "multi_cost_h.h"
#include <malloc.h>
double ** LU_inverse_matrix(double** a,int n)
{
	double **M_obr;
	double **LU;
	double sum=0;
	M_obr = (double **)malloc(n*sizeof(double));
	for (int i=0;i<n;i++)
	{
		M_obr[i] = (double *)malloc(n*sizeof(double));
	}
	LU = (double **)malloc(n*sizeof(double));
	for (int i=0;i<n;i++)
	{
		LU[i] = (double *)malloc(n*sizeof(double));
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum=0;
			if(i<=j)
			{
				for(int k=0;k<i;k++)
					sum+=LU[i][k]*LU[k][j];
				LU[i][j]=a[i][j]-sum;
			}
			else
			{
				for(int k=0;k<j;k++)
					sum+=LU[i][k]*LU[k][j];
				//if(LU[j][j]==0)
				//	don't solve
				LU[i][j]=(a[i][j]-sum)/LU[j][j];
			}
		}
	}
	int p;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			sum=0;
			if(i==j)
			{
				for(p=j+1;p<n;p++)
					sum+=LU[j][p]*M_obr[p][j];
				M_obr[j][j]=(1-sum)/LU[j][j];
			}
			else if(i<j)
			{
				for(p=i+1;p<n;p++)
					sum+=LU[i][p]*M_obr[p][j];
				M_obr[i][j]=-sum/LU[i][i];
			}
			else
			{
				for(p=j+1;p<n;p++)
					sum+=M_obr[i][p]*LU[p][j];
				M_obr[i][j]=-sum;
			}
		}
	}
	for(int i=0; i<n;i++)
		free(LU[i]);
	free(LU);
	return M_obr;
}
