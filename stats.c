/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c>
 * @brief <The stats.c file contains implementations of functions for performing statistical analysis on an array of data.>
 *
 * <This includes functions to print statistics such as minimum, maximum, mean, and median values of the data set. Additionally, it provides a function to print the array elements, find the median and mean values, and sort the array in descending order. Each function is carefully implemented to ensure accurate and efficient computation of statistical metrics, enabling users to gain insights into the characteristics of the data. This file serves as a comprehensive toolkit for basic statistical analysis in C programming, facilitating learning and experimentation in the field of embedded software development.>
 *
 * @author <Avishka Vishwajith>
 * @date <2024/05/09 >
 *
 */



#include <stdio.h>
#include "stats.h"

#define SIZE (40)

int main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    printf("Original Array:\n");
    print_array(test, SIZE);

    printf("\n");
    print_statistics(test, SIZE);

    return 0;
}
void print_statistics(unsigned char* data, unsigned int length) {
    printf("Statistics of the array:\n");
    printf("Minimum: %d\n", find_minimum(data, length));
    printf("Maximum: %d\n", find_maximum(data, length));
    printf("Mean: %d\n", find_mean(data, length));
    printf("Median: %d\n", find_median(data, length));
}

void print_array(unsigned char* data, unsigned int length) {
    printf("Array elements:\n");
    for (unsigned int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

unsigned char find_median(unsigned char* data, unsigned int length) {
    sort_array(data, length);
    if (length % 2 == 0) {
        return (data[length / 2 - 1] + data[length / 2]) / 2;
    } else {
        return data[length / 2];
    }
}

unsigned char find_mean(unsigned char* data, unsigned int length) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum / length;
}

unsigned char find_maximum(unsigned char* data, unsigned int length) {
    unsigned char max = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char* data, unsigned int length) {
    unsigned char min = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

void sort_array(unsigned char* data, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (data[j] < data[j + 1]) {
                unsigned char temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

