#ifndef _AFFINE_TRANSFORM_H_
#define _AFFINE_TRANSFORM_H_

void simpleTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY);
void rotateTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY);
float* simpleTransformMove(float matrix[3][3], float coords[3]);
float* simpleTransformScale(float matrix[3][3], float coords[3]);
float* simpleTransformRotate(float matrix[3][3], float rotation_matrix[3][3], float coords[3]);

#endif
