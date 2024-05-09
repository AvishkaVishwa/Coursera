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
 * @file <stats.h> 
 * @brief <ontains declarations for functions that perform statistical analysis on an array of unsigned characters.>
 *
 * <These functions include finding the minimum, maximum, mean, and median values of the array, as well as sorting the array in ascending order. This header file serves as an interface for users of the statistical analysis functions, providing them with the function prototypes and allowing them to use these functions in their programs without needing to know their internal implementations.>
 *
 * @author <Avishka Vishwajith>
 * @date <2024/05/09>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints statistics of an array including minimum, maximum, mean, and median.
 *
 * Given an array of data and its length, this function calculates and prints
 * the minimum, maximum, mean, and median of the data set.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 */
void print_statistics(unsigned char* data, unsigned int length);

/**
 * @brief Prints an array of data to the screen.
 *
 * Given an array of data and its length, this function prints the elements
 * of the array to the screen.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 */
void print_array(unsigned char* data, unsigned int length);

/**
 * @brief Finds the median value of an array of data.
 *
 * Given an array of data and its length, this function calculates and returns
 * the median value of the data set.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 * @return Median value of the array
 */
unsigned char find_median(unsigned char* data, unsigned int length);

/**
 * @brief Finds the mean value of an array of data.
 *
 * Given an array of data and its length, this function calculates and returns
 * the mean value of the data set.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 * @return Mean value of the array
 */
unsigned char find_mean(unsigned char* data, unsigned int length);

/**
 * @brief Finds the maximum value of an array of data.
 *
 * Given an array of data and its length, this function calculates and returns
 * the maximum value of the data set.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 * @return Maximum value of the array
 */
unsigned char find_maximum(unsigned char* data, unsigned int length);

/**
 * @brief Finds the minimum value of an array of data.
 *
 * Given an array of data and its length, this function calculates and returns
 * the minimum value of the data set.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 * @return Minimum value of the array
 */
unsigned char find_minimum(unsigned char* data, unsigned int length);

/**
 * @brief Sorts an array of data in descending order.
 *
 * Given an array of data and its length, this function sorts the array
 * in descending order, with the largest value at index 0 and the smallest
 * value at the last index.
 *
 * @param data Pointer to the array of data
 * @param length Length of the array
 */
void sort_array(unsigned char* data, unsigned int length);

#endif /* __STATS_H__ */

