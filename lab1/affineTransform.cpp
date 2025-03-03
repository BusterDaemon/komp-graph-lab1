#include "affineTransform.h"
#include "math.h"
#include "stdlib.h"

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

float* MirrorXY(float coords[3]) {
    float* res_coords = (float*)calloc(3, sizeof(float));
    if (res_coords == nullptr)
        return nullptr;

    res_coords[0] = coords[0], res_coords[1] = -coords[1], res_coords[2] = 1;
    return res_coords;
}