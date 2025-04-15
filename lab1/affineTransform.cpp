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

float* simpleTransformRotate(float matrix[3][3], float rot_matrix[3][3], float* coords) {
    
    
    float** pos_offset_mat = (float**)calloc(3, sizeof(float*));
    if (pos_offset_mat == nullptr)
        return nullptr;
    for (size_t i = 0; i < 3; i++) {
        pos_offset_mat[i] = (float*)calloc(3, sizeof(float));
        if (pos_offset_mat[i] == nullptr)
            return nullptr;
        pos_offset_mat[i][i] = 1;
        if (i == 2) {
            pos_offset_mat[2][0] = matrix[2][0];
            pos_offset_mat[2][1] = matrix[2][1];
        }
    }

    float** neg_offset_mat = (float**)calloc(3, sizeof(float*));
    if (neg_offset_mat == nullptr)
        return nullptr;
    for (size_t i = 0; i < 3; i++) {
        neg_offset_mat[i] = (float*)calloc(3, sizeof(float));
        if (pos_offset_mat[i] == nullptr) return nullptr;
        neg_offset_mat[i][i] = 1;
        if (i == 2) {
            neg_offset_mat[2][0] = -matrix[2][0];
            neg_offset_mat[2][1] = -matrix[2][1];
        }
    }

    float** rotation = (float**)calloc(3, sizeof(float*));
    if (rotation == nullptr)
        return nullptr;
    for (size_t i = 0; i < 3; i++)
        rotation[i] = (float*)calloc(3, sizeof(float));
    
    
    
    
    float middle_stolbnyak_1[3] = {
        coords[0] * neg_offset_mat[0][0] + coords[1] * neg_offset_mat[1][0] + coords[2] * neg_offset_mat[2][0],
        coords[0] * neg_offset_mat[0][1] + coords[1] * neg_offset_mat[1][1] + coords[2] * neg_offset_mat[2][1],
        coords[0] * neg_offset_mat[0][2] + coords[1] * neg_offset_mat[1][2] + coords[2] * neg_offset_mat[2][2]
    };

    float middle_stroka_2[3] = {
        middle_stolbnyak_1[0] * cos(rot_matrix[0][0]) + middle_stolbnyak_1[0] * -sin(rot_matrix[1][0]) + middle_stolbnyak_1[0] * 0,
        middle_stolbnyak_1[1] * sin(rot_matrix[0][1]) + middle_stolbnyak_1[1] * cos(rot_matrix[1][1]) + middle_stolbnyak_1[1] * 0,
        middle_stolbnyak_1[2]
    };
    float res_coords[3] = {
        middle_stroka_2[0] * pos_offset_mat[0][0] + middle_stroka_2[1] * pos_offset_mat[1][0] + middle_stroka_2[2] * pos_offset_mat[2][0],
        middle_stroka_2[1] * pos_offset_mat[0][1] + middle_stroka_2[1] * pos_offset_mat[1][1] + middle_stroka_2[2] * pos_offset_mat[2][1],
        middle_stroka_2[2] * pos_offset_mat[0][2] + middle_stroka_2[1] * pos_offset_mat[1][2] + middle_stroka_2[2] * pos_offset_mat[2][2]
    };
    

    return res_coords;
}

float* MirrorXY(float coords[3]) {
    float* res_coords = (float*)calloc(3, sizeof(float));
    if (res_coords == nullptr)
        return nullptr;

    res_coords[0] = coords[0], res_coords[1] = -coords[1], res_coords[2] = 1;
    return res_coords;
}