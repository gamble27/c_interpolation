//
// Created by olga on 10.05.19.
//

#include "interpolation.h"
#include <stdio.h>
#include <malloc.h>

//struct DVector Interpolate(const struct Input_Data* input){
//    // define result vector, which contains 2 coordinates
//    // res.coordinates[0] - a
//    // res.coordinates[1] - b
//    // y = ax + b
//    if (input->n <=0) {
//        // fixme: do something like program exiting
//        printf("Your dataset is empty, just like your head, dude.");
//    }
//
//    struct DVector res = {2};
//    res.coordinates = (floating_point *) calloc(2, sizeof(floating_point));
//
//    // a
//    floating_point a_numerator = 0;
//    floating_point a_denominator = 0;
//    floating_point buff;
//    integer nn = input->n;
//    for (integer i = 0; i < nn; ++i) {
//        buff = nn * input->x->coordinates[i] - 1;
//        a_numerator   += input->y->coordinates[i] * buff;
//        a_denominator += input->x->coordinates[i] * buff;
//    }
//    res.coordinates[0] = a_numerator / a_denominator;
//
//    // b
//    floating_point b_numerator = 0;
//    for (integer i = 0; i < nn; ++i) {
//        b_numerator += input->y->coordinates[i];
//        b_numerator -= input->x->coordinates[i] *
//                       res.coordinates[0];
//    }
//    res.coordinates[1] = b_numerator / nn;
//
//    return res;
//}

int main(){

    struct Input_Data inp;
    inp.n = 2;
    struct DVector x1, y1;

    x1.dim = 2;
    x1.coordinates = calloc(x1.dim, sizeof(floating_point));
    x1.coordinates[0] = 0;
    x1.coordinates[1] = 1;

    y1.dim = 2;
    y1.coordinates = calloc(y1.dim, sizeof(floating_point));
    y1.coordinates[0] = 2;
    y1.coordinates[1] = 3;

    inp.x = &x1;
    inp.y = &y1;

    struct DVector v1;
    v1 = Interpolate(&inp);
    printf("%zu", v1.dim);

    free(x1.coordinates);
    free(y1.coordinates);
    free(v1.coordinates);

    return 0;
}