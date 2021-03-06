/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */

void printArray(int n, int *arr)
{
  int i;
  printf("= ");
  for(i=0; i<n-1; i++)
  {
    printf("%d + ", arr[i]);
  }
  printf("%d", arr[i]);
  printf("\n");
}

void partition(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =1;val<=n; val++)
  {
    arr[level] = val;
    partition(n-val,arr, level+1);
  }
}



void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  
   int *arr = malloc(sizeof(int)*value);
   partition(value,arr,0);
   free(arr); 
  
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionIncreasingHelp(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =1;val<=n; val++)
  {
    if((level==0) || arr[level-1]<val)
    {
      arr[level] = val;
      partitionIncreasingHelp(n-val,arr, level+1);
    }
  }
}
void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
     int *arr = malloc(sizeof(int)*value);
   partitionIncreasingHelp(value,arr,0);
   free(arr); 
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partitionDecreasingHelp(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =n;val>0; val--)
  {
    if((level==0) || arr[level-1]>val)
    {
      arr[level] = val;
      partitionDecreasingHelp(n-val,arr, level+1);
    }
  }
}

void partitionDecreasing(int value)
{
  printf("partitionDecreasing %d\n", value);
  
   int *arr = malloc(sizeof(int)*value);
   partitionDecreasingHelp(value,arr,0);
   free(arr); 
}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionOddHelper(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =1;val<=n; val+=2)
  {
    arr[level] = val;
    partitionOddHelper(n-val,arr, level+1);
  }
}
void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  int *arr = malloc(sizeof(int)*value);
   partitionOddHelper(value,arr,0);
   free(arr); 
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionEvenHelper(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =2;val<=n; val+=2)
  {
    arr[level] = val;
    partitionEvenHelper(n-val,arr, level+1);
  }
}
void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
    int *arr = malloc(sizeof(int)*value);
   partitionEvenHelper(value,arr,0);
   free(arr);

}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionOddAndEvenHelper(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  if((level%2)==0)
  {
    for(val =1;val<=n; val+=2)
    {
      arr[level] = val;
      partitionOddAndEvenHelper(n-val,arr, level+1);
    }
  }
  else
  {
    for(val =2;val<=n; val+=2)
    {
      arr[level] = val;
      partitionOddAndEvenHelper(n-val,arr, level+1);
    }
  }
}
void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  int *arr = malloc(sizeof(int)*value);
  partitionOddAndEvenHelper(value,arr,0);
  free(arr);
  
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


int primeChecker(int n)
{
   int i=0;
   if(n<=1)
   {
     return 0;
   }
   for(i=2;i<=n-1;i++)
   {
     if(n%i == 0)
     {
       return 0;
     }
   }
   return 1;
}
int primeTotal(int n)
{
  int i=0;
  int noOfPrimes=0;
  for(i=2; i<=n; i++)
  {
    if(primeChecker(i)==1)
    {
	noOfPrimes++;
    }
  }
  return noOfPrimes;
}

void primeArrayFiller(int value, int Totalnumberofprimes, int *primeArray)
{
  int i=0;
  int j=0;
  for(i=0;i<=value;i++)
  {
    if( primeChecker(i) ==1)
    {
      primeArray[j] = i;
      j++;
    }
  }
   
}
//void partitionPrimeHelper(int n, int *arr, int level, int *primeArray, int totalPrimes)
void partitionPrimeHelper(int n, int *arr, int level)
{
  int val=0; //first value used
  //int ind=0;
  if(n==0)
  {
    //arr[level] = n;
    printArray(level, arr);//
    return;
  }
  for(val =0;val<=/*totalPrimes*/n; val++)
  {
    if(primeChecker(val)==1)
    {
    //arr[level] = primeArray[val];
    //partitionPrimeHelper(n-primeArray[val],arr, level+1, primeArray, totalPrimes);
    arr[level] = val;
    partitionPrimeHelper(n-val,arr, level+1);
    }
  }
}
void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int *arr = malloc(sizeof(int)*value);
 // int noOfPrimes = primeTotal(value);
  //int *primeArray = malloc(sizeof(int)*noOfPrimes);
  //primeArrayFiller(value, noOfPrimes, primeArray);
  //partitionPrimeHelper(value,arr,0, primeArray, noOfPrimes);
  partitionPrimeHelper(value,arr,0);
  free(arr);
  //free(primeArray);
}
