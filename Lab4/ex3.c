#include <mpi.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
#define n 10

int a[1000]; 

int copied_array[1000]; 
  
int main(int argc, char* argv[]) 
{ 
    float coef;
  
    int pid, np, elems_per_proc, elems_recv; 
    MPI_Status status; 
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &pid); 
    MPI_Comm_size(MPI_COMM_WORLD, &np); 

    
    if (pid == 0) { 
        
        
        scanf("%f",&coef);
        printf("Coeficientul introdus este: %f\n",coef);

        for (int i = 0 ; i < n ; i++) {
          a[i] = i + 1;
        }

        int index, i; 
        elems_per_proc = n / np; 

        if (np > 1) { 

            for (i = 1; i < np - 1; i++) { 
                index = i * elems_per_proc;
                MPI_Send(&elems_per_proc, 1, MPI_INT, i, 0, MPI_COMM_WORLD); 
                MPI_Send(&a[index], elems_per_proc, MPI_INT, i, 0, MPI_COMM_WORLD); 
            } 

            index = i * elems_per_proc; 
            int elements_left = n - index; 

            //last proc could not have elems_per_proc elements to sum them
            //could have less or could have more

            MPI_Send(&elements_left, 1, MPI_INT, i, 0, MPI_COMM_WORLD); 
            MPI_Send(&a[index], elements_left, MPI_INT, i, 0, MPI_COMM_WORLD); 
        } 

        MPI_Bcast(&coef, 1, MPI_INT, 0, MPI_COMM_WORLD);


        float sum = 0; 
        for (i = 0; i < elems_per_proc; i++) sum += a[i]; 
        sum *= coef;

        float temp_sum = 0; 
        for (i = 1; i < np; i++) { 
            MPI_Recv(&temp_sum, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status); 
            sum += temp_sum; 
        } 
  
        printf("Suma este : %f\n", sum); 
    } 
    else { 
        MPI_Recv(&elems_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&copied_array, elems_recv, MPI_INT, 0, 0, MPI_COMM_WORLD, &status); 
        
        MPI_Bcast(&coef, 1, MPI_INT, 0, MPI_COMM_WORLD);

        float partial_sum = 0; 

        for (int i = 0; i < elems_recv; i++) partial_sum += copied_array[i]; 
        partial_sum *= coef;
        
        //send partial sum back to master
        MPI_Send(&partial_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
    } 
  
    MPI_Finalize(); 
  
    return 0; 
} 