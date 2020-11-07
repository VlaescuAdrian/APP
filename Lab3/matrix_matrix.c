#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 62
#define NCA 15
#define NCB 7

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk;
double	a[NRA][NCA],
	b[NCA][NCB],
	c[NRA][NCB];

double t1, t2;
t1 = omp_get_wtime();
#pragma omp parallel sections
  {
    #pragma omp section
    {
        tid = omp_get_thread_num();
        if (tid == 0)
            {
            nthreads = omp_get_num_threads();
            printf("Starting matrix multiple example with %d threads\n",nthreads);
            printf("Initializing matrices...\n");
            }
    }
	#pragma omp section
    {
        for (i=0; i<NRA; i++)
            for (j=0; j<NCA; j++)
            a[i][j]= i+j;
    }
    #pragma omp section
    {
        for (i=0; i<NCA; i++)
            for (j=0; j<NCB; j++)
            b[i][j]= i*j;
    }

	#pragma omp section
    {
        for (i=0; i<NRA; i++)
            for (j=0; j<NCB; j++)
            c[i][j]= 0;
    }
    #pragma omp section
    {
        for (i=0; i<NRA; i++)    
		{
			printf("Thread=%d did row=%d\n",tid,i);
            for(j=0; j<NCB; j++)       
                for (k=0; k<NCA; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }   
    }
  }

   t2 = omp_get_wtime();
  printf("Execution time %g",t2-t1);

}
