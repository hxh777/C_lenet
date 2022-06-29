/*
	@author hhy/WatterCutter
	@date 2022/2
*/

#include "matoperation.h"
#include <stdio.h>


/*
	@params 
		mat: a 2D matrix pointer
		matSize: an imageSize of the matrix
		it: a pointer to store the (i,j)address of the max value
	@retval:
		none 
*/
void matOperationMaxIt(float** mat,imageSize matSize,int* it)
{
	float max = mat[0][0];
	for (int i = 0;i < matSize.rowsc;i++) 
		for (int j = 0;j < matSize.colsc;j++) 
			if(max<mat[i][j]){
				max = mat[i][i];
				it[0] = i;
				it[1] = j;
			}
}
/*
	@func 
		expand the size of input matrix by addc and addr,
	@params 
		inoutmat: a 2D matrix pointer
		r: the number of rows of the input matrix 
		c: the number of cols of the matrix
		addc: expand number of the cols
		addr: expeand number of the rows
	@retval:
		a matrix whose size should be res[r+addr][c+addc] 
*/
float** matOperationEdgeExpand(float** inputmat, int r,int c ,int addc, int addr)
{
	float** res = (float**)malloc((r + 2 * addr) * sizeof(float*)); 
	for (int i = 0;i < (r + 2 * addr);i++)
		res[i] = (float*)malloc((c + 2 * addc) * sizeof(float));
				
	for (int j = 0;j < (r + 2 * addr);j++) {
		for (int i = 0;i < (c + 2 * addc);i++) {
			if (j < addr || i < addc || j >= (r + addr) || i >= (c + addc))
				res[j][i] = (float)0.0;
			else{
				res[j][i] = inputmat[j-addr][i-addr];
			}
		}
	}	
	return res;
}

