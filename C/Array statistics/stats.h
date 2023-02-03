/*****************************************************************************/
/**
 * @file stats.h
 * @brief This file has a set of functions to find
 * fundamental elements of an array.
 *
 * This file contains 7 functions and their descriptions,
 * those defined in order to find  median, mean, maximum,
 * minimum values,print them, print the given array and sort it.
 *
 * @author Berk Topbas
 * @date 20.02.2021
 *
 */

#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

// function to sort the array in descending(!) order

void sort_array(unsigned char *array,unsigned int n);

/**
 * @brief C program to sort an array.
 *
 * By comparing all element with each other and
 * swapping them if they meet the condition(in our
 * case we sort from largest to smallest so if the
 * previous element smaller than the next, we swap in
 * order to send the smallest to end) an array can be
 * sorted in desired way.
 *
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return void function
 */

// function to calculate the median of the array
float find_median(unsigned char *array,unsigned int n);

/**
 * @brief C program to calculate the median of
 * an array.
 *
 * Basically a median is the value present at the center of a
 * sorted array list. To calculate the median first we need to
 * sort the list in ascending or descending order.
 * If the number of elements are even , then the median
 * will the average of two numbers in the middle.
 * But the number is odd then the middle element
 * of the array after sorting will be considered as the median.
 *
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return median value of the array as float type
 */

 // function to find maximum value of an array
 unsigned char find_maximum(unsigned char *array,unsigned int n);

/**
 * C program to calculate the largest element of
 * an array.
 *
 * By comparing all element with each other and assigning
 * the larger one to the max value, max value of an array
 * can be reached.
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return maximum value of the array as unsigned char type
 */

  // function to find minimum value of an array
 unsigned char find_minimum(unsigned char *array,unsigned int n);

/**
 * C program to calculate the smallest element of
 * an array.
 *
 * By comparing all element with each other and assigning
 * the smaller one to the min value, min value of an array
 * can be reached.
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return minimum value of the array as unsigned char type
*/

 void print_array(unsigned char *array,unsigned int n);

 /**
 * C program to print the given array.
 *
 * Prints the given array by 10 elements in each line.
 *
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return void function(prints the given array by index)

 */

 float find_mean(unsigned char *array, unsigned int n);


 /**
 * C program to calculate the mean value of
 * an array.
 *
 * Basically mean value of an array is ratio of sum
 * of all elements to size of the array. To calculate
 * the mean first we need to add up all elements and
 * divide it by the size.
 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return mean value of the array as float type.
 */

 void print_statistics(unsigned char *array, unsigned int n);

 /**
 * C program to prints the statistics of an array
 *
 * prints the minimum, maximum, mean  and median values
 * of the array

 * @param *array points to the address where the array begins
 * @param n is size of the array
 * @return void function(prints the minimum, maximum, mean  and median values
 * of the array)
 */

#endif // STATS_H_INCLUDED
