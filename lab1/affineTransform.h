#ifndef _AFFINE_TRANSFORM_H_
#define _AFFINE_TRANSFORM_H_

float* simpleTransformMove(float matrix[3][3], float coords[3]);
float* simpleTransformScale(float matrix[3][3], float coords[3]);
float* simpleTransformRotate(float matrix[3][3], float angle, float coords[3]);
float* MirrorXY(float coords[3]);

#endif
