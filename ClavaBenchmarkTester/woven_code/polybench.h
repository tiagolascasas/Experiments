#ifndef _POLYBENCH_H_
#define _POLYBENCH_H_

#include <stdlib.h>
/**
* This version is stamped on May 10, 2016
*
* Contact:
*   Louis-Noel Pouchet <pouchet.ohio-state.edu>
*   Tomofumi Yuki <tomofumi.yuki.fr>
*
* Web address: http://polybench.sourceforge.net
*/

/*
* polybench.h: this file is part of PolyBench/C
*
* Polybench header for instrumentation.
*
* Programs must be compiled with `-I utilities utilities/polybench.c'
*
* Optionally, one can define:
*
* -DPOLYBENCH_TIME, to report the execution time,
*   OR (exclusive):
* -DPOLYBENCH_PAPI, to use PAPI H/W counters (defined in polybench.c)
*
*
* See README or utilities/polybench.c for additional options.
*
*/

/*Array padding. By default, none is used.*/

/*default:*/

/*Inter-array padding, for use with . By default, none is used.*/

/*default:*/

/*C99 arrays in function prototype. By default, do not use.*/

/*default:*/

/*Scalar loop bounds in SCoPs. By default, use parametric loop bounds.*/

/*default:*/

/*Use the 'restrict' keyword to declare that the different arrays do not
* alias. By default, we do not use it as it is only supported in C99 and
* even here several compilers do not properly get it.
*/

/*default:*/

/*Macros to reference an array. Generic for heap and stack arrays
(C99).  Each array dimensionality has his own macro, to be used at
declaration or as a function argument.
Example:
int b[x] => POLYBENCH_1D_ARRAY(b, x)
int A[N][N] => POLYBENCH_2D_ARRAY(A, N, N)
*/

/*Macros for using arrays in the function prototypes.*/

/*Macros for using arrays within the functions.*/

/*Macros to allocate heap arrays.
Example:
polybench_alloc_2d_array(N, M, double) => allocates N x M x sizeof(double)
and returns a pointer to the 2d array
*/

/*Macros for array declaration.*/

/*Dead-code elimination macros. Use argc/argv for the run-time check.*/

/*Performance-related instrumentation. See polybench.c*/

/*PAPI support.*/

/*Timing support.*/

extern double polybench_program_total_flops;
extern void polybench_timer_start();
extern void polybench_timer_stop();
extern void polybench_timer_print();
/*PAPI support.*/
/*Function prototypes.*/
extern void * polybench_alloc_data(unsigned long long n, int elt_size);
extern void polybench_free_data(void *ptr);
/*PolyBench internal functions that should not be directly called by*/
/*the user, unless when designing customized execution profiling*/
/*approaches.*/
extern void polybench_flush_cache();
extern void polybench_prepare_instruments();
/*!POLYBENCH_H*/
#endif
