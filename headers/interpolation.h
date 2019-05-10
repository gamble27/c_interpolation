//
// Created by olga on 23.04.19.
//

#ifndef INTERPOLATION_MOSKANOVA_INTERPOLATION_H
#define INTERPOLATION_MOSKANOVA_INTERPOLATION_H

#include <lzma.h>


struct DVector{
    size_t dim;
};
typedef struct DVector DVector;


struct Input_Data{
    struct DVector x, y;
};
typedef struct Input_Data Input_Data;


struct DVector* Interpolate(struct Input_Data* input);

#endif //INTERPOLATION_MOSKANOVA_INTERPOLATION_H
