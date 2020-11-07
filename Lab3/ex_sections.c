#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000000
float a[N], b[N], c[N], d[N];

int main (int argc, char *argv[]) 
{
    int i;
    double t1,t2;
    /* Some initializations */
	    t1 = omp_get_wtime();
	#pragma omp parallel
	{
		
			#pragma omp sections
			{
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						a[i] = i * 1.5;
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						b[i] = i + 22.35;
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						c[i] = 0;
						c[i] = sin(a[i] + b[i]);
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						d[i]=0;
						d[i] = sqrt(a[i] * b[i]);
					}
				}
			}
				
    }

    t2 = omp_get_wtime();

    printf("Duration %g\n",t2-t1);

    return 0;
}
