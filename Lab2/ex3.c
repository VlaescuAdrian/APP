#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>


#define N 100 //100 files

int main (int argc, char *argv[]) {
	double t1, t2;
	t1 = omp_get_wtime();
	char f[] = "files/f";
	char file[5];
	char snum[5];
	char file_to_open[20];
	
	int sum = 0,i;
	
	char files[101][20];
	for (i = 1 ; i <= 100 ; i++) {
		strcpy(f,"files/f");
		sprintf(snum, "%d", i);
		strcat(f,snum);
		strcpy(file,f);
		stpcpy(files[i],file);
	
	}
	#pragma omp parallel for reduction(+: sum) private(i)
	for (i = 1 ; i <= 100 ; i++) {
		FILE *ptr;
		ptr = fopen(files[i],"r");
		if (ptr == NULL) {
			printf("%s\n",files[i]);
			continue;
		}
		fseek(ptr, 0L, SEEK_END);
		sum += ftell(ptr);
		
		fseek(ptr, 0L, SEEK_SET);
		fclose(ptr);
	}		
	printf("%d\n",sum);
	t2 = omp_get_wtime();
	printf("Execution time %g",t2-t1);
	
}