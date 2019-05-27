//
// Created by olga on 23.04.19.
//

//================= LIBRARIES SECTION ==================

#include <malloc.h>
#include "headers/interpolation.h"

//================ TASK FUNCTIONS SECTION ==============

// returns a and b as a 2-dimentional DVector
struct DVector Calculate(const struct Input_Data *inputData){
    // define result vector, which contains 2 coordinates
    // res.coordinates[0] - a
    // res.coordinates[1] - b
    // y = ax + b
    if (inputData->n <=0) {
        // fixme: do something like program exiting
        printf("Your dataset is empty, just like your head, dude.");
    }

    struct DVector res = {2};
    res.coordinates = (floating_point *) calloc(2, sizeof(floating_point));

    // a
    floating_point a_numerator = 0;
    floating_point a_denominator = 0;
    floating_point buff;
    integer nn = inputData->n;
    for (integer i = 0; i < nn; ++i) {
        buff = nn * inputData->x->coordinates[i] - 1;
        a_numerator   += inputData->y->coordinates[i] * buff;
        a_denominator += inputData->x->coordinates[i] * buff;
    }
    res.coordinates[0] = a_numerator / a_denominator;

    // b
    floating_point b_numerator = 0;
    for (integer i = 0; i < nn; ++i) {
        b_numerator += inputData->y->coordinates[i];
        b_numerator -= inputData->x->coordinates[i] *
                       res.coordinates[0];
    }
    res.coordinates[1] = b_numerator / nn;

    return res;
}


struct DVector Interpolate(const struct Input_Data *inputData){
    // define result vector, which contains 2 coordinates
    // res.coordinates[0] - a
    // ....
    // res.coordinates[3] - d
    // y = ax

    if (inputData->n <= 0) {
        // fixme: do something like program exiting
        printf("Your dataset is empty, just like your head, dude.");
    }

    struct DVector res = {4};
    res.coordinates = (floating_point *) calloc(res.dim, sizeof(floating_point));

    return res;
}

//================ INPUT SECTION ==============

integer input(Input_Data *inputData){
    printf("How many (x,y) pairs will be there?\n");
    printf("Please note:\n");
    printf("x is height (cm)\n");
    printf("y is weight (kg)\n");
    scanf("%i", &inputData->n);
    if (inputData->n <= 0) {
        printf("dataset length must be greater than 0");
        return 1;
    }
    if (inputData->x == NULL
        | inputData->y == NULL) {
        printf("you have not provided any containers for dataset in your program");
        printf("\nSegmentation fault");
        return 1;
    }

    inputData->x->dim = inputData->n;
    inputData->y->dim = inputData->n;
    inputData->x->coordinates =
            (floating_point *)
            calloc(inputData->x->dim, sizeof(floating_point));
    inputData->y->coordinates =
            (floating_point *)
            calloc(inputData->y->dim, sizeof(floating_point));
    for (integer i = 0; i < inputData->n; ++i) {
        printf("x[%i]=", i+1);
        scanf("%f", &inputData->x->coordinates[i]);

        printf("y[%i]=", i+1);
        scanf("%f", &inputData->y->coordinates[i]);
    }

    return 0;
}

integer inputBinaryFile(char *file, Input_Data *inputData){
    file_t inp_file = fopen(file, "rb");
    if (inp_file == NULL) {
        printf("error opening file");
        return 1; // like exit status or stuff
    }



    return 0;
}

integer inputTextFile  (char *file, Input_Data *inputData){

    return 0;
}

//=============== OUTPUT SECTION ==============

void output(DVector *result) {
    printf("y=");
    for (integer i = 0; i < result->dim - 2; ++i) {
        printf("%.2fx^%i+",
               result->coordinates[i],
               (integer) result->dim - i - 1);
    }
    printf("%.2fx+", result->coordinates[result->dim - 2]);
    printf("%.2f\n", result->coordinates[result->dim - 1]);
}