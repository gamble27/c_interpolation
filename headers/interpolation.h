//
// Created by olga on 23.04.19.
//

#ifndef INTERPOLATION_MOSKANOVA_INTERPOLATION_H
#define INTERPOLATION_MOSKANOVA_INTERPOLATION_H

#define integer int
#define floating_point float

#include <lzma.h> // get size_t thing

//================ STRUCTURES DEFINITION SECTION  ==============


struct DVector{
    size_t dim;
    floating_point *coordinates;
};
typedef struct DVector DVector;


struct Input_Data{
    int n; // length of arrays.
    struct DVector *x, *y;
};
typedef struct Input_Data Input_Data;

//================ TASK FUNCTIONS SECTION ==============

struct DVector Interpolate(const struct Input_Data* input);

//================ INPUT SECTION ==============
//void input_vector();
//void finput_vector();

//================ OUTPUT SECTION ==============

#endif //INTERPOLATION_MOSKANOVA_INTERPOLATION_H
