#ifndef __CNNOPERATION
#define __CNNOPERATION

#include "matoperation.h"

//卷积处理
void cnnOperationConvolution(float*** inputmat,imageSize inputSize,
	float*** outputmat,imageSize outputSize,float**** kernel,imageSize kernelSize,
	int paddding,int step);
//池化处理
void cnnOperationPooling(float*** inputmat, imageSize inputSize,
	float*** outputmat, imageSize outputSize,
	imageSize kernelSize, int padding,int step);
//激活函数
void cnnOperationActivation(float*** inputmat, imageSize inputSize, float bias);
//扁平化
void cnnOperationFlatten(float*** input,imageSize inputsize, float*** output, 
	imageSize outputsize);
//全连接处理 一维化然后进行全连接运算
void cnnOperationLinear(float*** inputmat, imageSize inputSize,
		float*** outputmat, imageSize outputSize,float** weight,float* bias);

static float matAndKernelConvolution(float*** mat, imageSize matSize, float*** kernel,
	imageSize kernelSize, int nowrow, int nowcol);
static float matAndKernelMaxPooling(float*** mat, imageSize matSize,
	imageSize kernelSize, int nowrow, int nowcol, int hxh_which_dim);
#endif

