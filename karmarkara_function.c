#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "multi_cost_h.h"

double *vk,*hx,*hv;
double *x0;

double min_val_hv(const double * hv,const double *v,int m)
{
	double min=-100000000000;
	for (int i=0;i<m;i++)
	{
		if ((hv[i]<0)&&((-v[i]/hv[i])<min))
		{
			min = -v[i]/hv[i];
		}
	}
	return min;
}

int karmarkar_iteration(double **a,double *b,double *c,double *x,int m,int n,double gamma)
{
	double * current_vec;
	double **Dv;
	double alpha;
	double *vk;
	int counter;
	current_vec = (double *)malloc(m*sizeof(double));
	double ** current_matr1;
	double **current_matr2;
	Dv = (double **) malloc(m*sizeof(double));
	for (int i=0;i<m;i++)
	{
		Dv[i] = (double *) malloc(m*sizeof(double));
	}
	//while()
    {
    	current_vec = matrxvec(a,x,m,n);
        for (int i=0;i<m;i++)
        {
            vk[i] = b[i] - current_vec[i];
        }
        Dv = diagonalization(vk,m);
        Dv = matrxmatr(Dv,Dv,m,n,m,n);
        current_matr1 = matrxmatr(transpon_matrix(a,n,m),LU_inverse_matrix(Dv,m),m,n,n,m);
        current_matr2 = matrxmatr(current_matr1,a,m,n,m,n);
        current_matr2 = LU_inverse_matrix(current_matr2,n);
        hx = matrxvec(current_matr2,c,n,n);
        hv = matrxvec(a,hx,m,n);
        for (int i=0;i<n;i++)
        {
            hv[i] *=-1;
            if ((hv[i]>=0))
            {
                if (counter==n)
                {
                    printf("No roots");
                    return -1;
                }
                else
                    counter++;
            }
        }
        alpha = gamma * min_val_hv(hv,vk,m);
        for (int i=0;i<m;i++)
        {
            x0[i]+=alpha*hx[i];
        }
    }
}
