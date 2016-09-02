#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#include "pmpi.h"

#define PMPI_ID (3)

/* int PMPI_Init(int *arg_0, char ***arg_1); */
/* int MPI_Init(int *arg_0, char ***arg_1) */
/* {  */
/*   int ret = 0; */
/*   BEFORE_CALL; */
/*   ret = PMPI_Init(arg_0, arg_1); */
/*   AFTER_CALL; */
/*   return ret; */
/* } */

int PMPI_Barrier(MPI_Comm comm);
int MPI_Barrier(MPI_Comm comm)
{
  int ret = 0;
  BEFORE_CALL;
  ret = PMPI_Barrier(comm);
  AFTER_CALL;
  return ret;
}


int PMPI_Finalize();
int MPI_Finalize()
{ 
  int ret = 0;
  BEFORE_CALL;
  ret = PMPI_Finalize();
  AFTER_CALL;
  return ret;
}

