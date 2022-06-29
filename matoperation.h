#ifndef __MATOPERATION
#define __MATOPERATION


#include <malloc.h>

//矩阵尺寸
typedef struct IS{
	int numsc;//数量
	int dimsc;//维度
	int rowsc;//行数
	int colsc;//列数
}imageSize;


void matOperationMaxIt(float** mat,imageSize matSize,int* it);
float** matOperationEdgeExpand(float** mat, int r,int c, int addc, int addr);



#endif