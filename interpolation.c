//
// Created by olga on 23.04.19.
//

#include <lzma.h>

struct DVector{
    size_t dim;
    // float?? coordinates
};

struct Input_Data{
    /*
     * x - height
     * y - weight
     *
     * */
    struct DVector x, y;
};

// returns a and b ???
struct DVector* Interpolate(struct Input_Data* input){
    struct DVector* res = {0};

    return res;
}

// input from stdin
void input_vector(){

}

// input from text file
void finput_vector(){

};