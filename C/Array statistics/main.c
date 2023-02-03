/*****************************************************************************/
/**
 * @file stats
 * @brief Source file to find fundamental values of an array
 *
 * This source file contains basic array operations with functions those prototypes
 * mentioned in stats.h header file. Using these functions one can find the minimum,
 * maximum, mean and median value of an array, besides can sort and print the given
 * array.
 *
 *
 * @author Berk Topbas
 * @date 20.02.2021
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  unsigned char max=find_maximum(test,SIZE);
  unsigned char min=find_minimum(test,SIZE);
  float mean=find_mean(test,SIZE);
  float median=find_median(test,SIZE);

  /* Statistics and Printing Functions Go Here */

  printf("\nInitial Array\n");
  printf("==============\n");
  print_array(test,SIZE);
  sort_array(test,SIZE);//array sort
  printf("\n\nSorted Array\n");
  printf("==============\n");
  print_array(test,SIZE);//print the sorted array
  print_statistics(test,SIZE);//print values by function print_statistics
  printf("\n\nminimum=%u, maximum=%u, mean=%.2f, median=%.2f\n",min,max,mean,median);//to print the values one by one with functions
  return 0;
}

/* Other Implementation File Code Here */

void sort_array(unsigned char *array,unsigned int n){
   int i,j,temp=0;

   for(i=0;i<n;i++) {
      for(j=0;j<n-1;j++) {
            if(array[j]>array[j+1]){ //swap condition
                temp        = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            }
        }
   }
}

float find_median(unsigned char *array,unsigned int n){

unsigned char a[n];
for (int i=0;i<n;i++)
    a[i]=array[i];// assigning the initial order of elements to another array(a) before sorting
sort_array(array,n);
float median=0;
    // if number of elements are even
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // if number of elements are odd
    else
        median = array[n/2];
for (int i=0;i<n;i++)
    array[i]=a[i];//reassigning the initial elements of from the array "a"
return median;
}

unsigned char find_maximum(unsigned char *array,unsigned int n){

    unsigned char max;
    int i=0;
    max=array[i];
    for (i=0;i<n;i++){
    if (max<array[i])
            max=array[i];
    }
    return max;
 }

unsigned char find_minimum(unsigned char *array,unsigned int n){

    unsigned char min;
    int i=0;
    min=array[i];
    for (i=0;i<n;i++){
    if (min>array[i])
            min=array[i];
    }
    return min;
}

void print_array( unsigned char *array, unsigned int n){
int i; /* counter */
    for (i=0;i<n;i++){
        if (i%10==0){ /* begin new line every 10 values */
        printf("\n");
        }
        printf("%3d,",array[i]);
    }
    printf("\b ");
}

 float find_mean(unsigned char *array, unsigned int n){

 int sum=0;
 float mean;
 for(int i=0;i<n;i++)
        sum+=array[i];
 mean=sum/n;
 return mean;
 }

 void print_statistics(unsigned char *array, unsigned int n){

 unsigned char minimum=find_minimum(array,n);
 unsigned char maximum=find_maximum(array,n);
 float mean=find_mean(array,n);
 float median=find_median(array,n);

printf("\n\nminimum=%u, maximum=%u, mean=%.2f, median=%.2f",minimum,maximum,mean,median);
 }
