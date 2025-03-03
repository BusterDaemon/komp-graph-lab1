#include "affineTransform.h"
#include "math.h"
#include "stdlib.h"

void simpleTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY) {
    *destX = (startX + af_matrix[2][0]) * af_matrix[0][0] + startY * af_matrix[0][1] + af_matrix[0][2];
    *destY = startX * af_matrix[1][0] + (startY + af_matrix[2][1]) * af_matrix[1][1] + af_matrix[1][2];
}

void rotateTransform(int af_matrix[3][3], int startX, int startY, int* destX, int* destY) {
    *destX = startX * cos(af_matrix[0][0]) + startY * (-(sin(af_matrix[0][1])));
    *destY = startX * sin(af_matrix[1][0]) + startY * cos(af_matrix[1][1]);
}

float* simpleTransformMove(float matrix[3][3], float coords[3]) {
    float* res_coords = (float *)calloc(3, sizeof(float));
    if (res_coords == nullptr) {
        return NULL;
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            res_coords[i] = matrix[2][i] + coords[i];
        }
    }

    return res_coords;
}

float* simpleTransformScale(float matrix[3][3], float coords[3]) {
    float* res_coords = (float*)calloc(3, sizeof(float));
    if (res_coords == nullptr) {
        return NULL;
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (i == j)
                res_coords[i] = coords[i] * matrix[i][j];
        }
    }

    return res_coords;
}

float* simpleTransformRotate(float matrix[3][3], float angle, float coords[3]) {
    float rad = acos(-1);
    float *res_coords = (float*)calloc(3, sizeof(float));
    if (res_coords == nullptr)
        return nullptr;

    res_coords[2] = 1;
    res_coords[0] = coords[0] * cos(rad) - (coords[1]) * sin(rad) + 430;
    res_coords[1] = coords[0] * sin(rad) + (coords[1]) * cos(rad) + 430;

    return res_coords;
}