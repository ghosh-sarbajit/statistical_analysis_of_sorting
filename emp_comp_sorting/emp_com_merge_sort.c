#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>
#define sentinel 2.0
#define SimSize 100

int count;
float seed=41;//liner congruencetial genarator
float urand()
{
	//seed=time(NULL);
	float a,m,c;
	a=1421.0;
	m=32768;
	c=1.0;
	seed=a*seed+c;
	seed=fmod(seed,m);
	return seed/(m-1);
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(float *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	float L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		count++;
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(float *arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}



int main()
{
    FILE *fp;
    fp=fopen("data_mergesort.csv","w+");
    static int ArrSize;
    ArrSize=100;
	while(ArrSize<=3000)
    {
        for(int i=0;i<SimSize;i++)
        {
			//srand(time(NULL));
            count=0;
			//printf("%d\n", count);
			float arr[ArrSize];
			for (int j = 0; j < SimSize; j++)
			{
				arr[j]=urand();//rand()/RAND_MAX;
			}
            mergeSort(arr,0,ArrSize-1);
			if (i==SimSize-1) {
				fprintf(fp, "%d\n", count);
				continue;
			}
            fprintf(fp, "%d,", count);
        }
        //fprintf(fp, "\b\0\n")o;
        ArrSize+=150;
    }
    fclose(fp);
    return 0;
}
