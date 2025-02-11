#include "affineTransform.h"
#include "math.h"

void simpleTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY) {
    *destX = (startX + af_matrix[2][0]) * af_matrix[0][0] + startY * af_matrix[0][1] + af_matrix[0][2];
    *destY = startX * af_matrix[1][0] + (startY + af_matrix[2][1]) * af_matrix[1][1] + af_matrix[1][2];
}

void rotateTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY) {
    *destX = startX * cos(af_matrix[0][0]) + startY * (-(sin(af_matrix[0][1])));
    *destY = startX * sin(af_matrix[1][0]) + startY * cos(af_matrix[1][1]);
}