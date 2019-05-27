//
// Created by olga on 10.05.19.
//

#include "interpolation.h"
#include <stdio.h>
#include <malloc.h>

int main(){
    printf("Welcome to my Interpolation Project\n");

//======================= INPUT TYPE =========================

    printf("Please choose input type: \n");
    printf("c/t/b - console/binary file/text file \n");

    character work_type;
    scanf("%c",&work_type);
    integer wrong_input_flag =    work_type == 'c'
                                | work_type == 't'
                                | work_type == 'b';
    //fixme twice printf
    while (wrong_input_flag==0) {
        printf("Please choose correct input type: \n");
        printf("c/t/b - console/binary file/text file \n");
        scanf("%c",&work_type);
        wrong_input_flag = work_type == 'c'
                           | work_type == 't'
                           | work_type == 'b';
    }

//============= INPUT FUNCTIONS + CALCULATE CALL =============

    struct DVector x,y;
    struct Input_Data inputData = {0, &x, &y};
    struct DVector ans_linear;
//    struct DVector ans_cubic;
    if        (work_type == 'c') {
        if (!input(&inputData)) { // exit code == 0 => it's ok
            ans_linear = Calculate  (&inputData);
//            ans_cubic  = Interpolate(&inputData);
        } else {
            return 1;
        }
    } else if (work_type == 'b') {
        printf("tododo");

    } else if (work_type == 't') {
        printf("todododo");
    }

//===================== OUTPUT TYPE ======================

    printf("Please choose output type: \n");
    printf("c/t/b - console/binary file/text file \n");

    scanf("%c",&work_type);
    wrong_input_flag =    work_type == 'c'
                                  | work_type == 't'
                                  | work_type == 'b';
    //fixme twice printf
    while (wrong_input_flag==0) {
        printf("Please choose correct output type: \n");
        printf("c/t/b - console/binary file/text file \n");
        scanf("%c",&work_type);
        wrong_input_flag = work_type == 'c'
                           | work_type == 't'
                           | work_type == 'b';
    }

//===================== OUTPUT FUNCTIONS CALL ======================

    if        (work_type == 'c') {
        output(&ans_linear);
//        output(&ans_cubic);
    } else if (work_type == 'b') {
        printf("tododo");
    } else if (work_type == 't') {
        printf("todododo");
    }

    printf("Thanks for your attention. \n (c) Olga Moskanova, #0 coder (or no)");

    return 0;
}