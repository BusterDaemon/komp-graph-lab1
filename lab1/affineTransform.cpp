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

float* simpleTransformRotate(float matrix[3][3], float rotation_matrix[3][3], float coords[3]) {
    float neg_offset_matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {-matrix[2][0], -matrix[2][1], 1}
    };
    float pos_offset_matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {matrix[2][0], matrix[2][1], 1}
    };
    float middle_matrix[3][3] = { 0 };
    float res_matrix[3][3] = { 0 };
    float trigon_rot_matrix[3][3] = {
        {cos(rotation_matrix[0][0]), sin(rotation_matrix[0][1]), 0},
        {-sin(rotation_matrix[1][0]), cos(rotation_matrix[1][1]), 0},
        {0, 0, 1}
    };

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            middle_matrix[i][j] = neg_offset_matrix[i][j] * trigon_rot_matrix[j][i];
        }
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            res_matrix[i][j] = middle_matrix[i][j] * pos_offset_matrix[j][i];
        }
    }

    float* res_coords = (float*)calloc(3, sizeof(float));
    if (res_coords == nullptr) {
        return NULL;
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            res_coords[i] += fabs(coords[i] * res_matrix[j][i]);
        }
    }


    return res_coords;
}