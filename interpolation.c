//
// Created by olga on 23.04.19.
//

#include <malloc.h>
#include "headers/interpolation.h"

// returns a and b ???
struct DVector Interpolate(const struct Input_Data* input){
    // define result vector, which contains 2 coordinates
    // res.coordinates[0] - a
    // res.coordinates[1] - b
    // y = ax + b
    if (input->n <=0) {
        // fixme: do something like program exiting
        printf("Your dataset is empty, just like your head, dude.");
    }

    struct DVector res = {2};
    res.coordinates = (floating_point *) calloc(2, sizeof(floating_point));

    // a
    floating_point a_numerator = 0;
    floating_point a_denominator = 0;
    floating_point buff;
    integer nn = input->n;
    for (integer i = 0; i < nn; ++i) {
        buff = nn * input->x->coordinates[i] - 1;
        a_numerator   += input->y->coordinates[i] * buff;
        a_denominator += input->x->coordinates[i] * buff;
    }
    res.coordinates[0] = a_numerator / a_denominator;

    // b
    floating_point b_numerator = 0;
    for (integer i = 0; i < nn; ++i) {
        b_numerator += input->y->coordinates[i];
        b_numerator -= input->x->coordinates[i] *
                       res.coordinates[0];
    }
    res.coordinates[1] = b_numerator / nn;

    return res;
}