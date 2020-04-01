#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define SimSize 100

int count_comp;
int count_swap;
float seed=51;//liner congruencetial genarator
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
// Inplace Implementation
void merge(float *arr, int start, int mid, int end)
{
	int start2 = mid + 1;

	// If the direct merge is already sorted
	if (arr[mid] <= arr[start2]) {
		return;
	}

	// Two pointers to maintain start
	// of both arrays to merge
	while (start <= mid && start2 <= end)
	{
		count_comp++;
		// If element 1 is in right place
		if (arr[start] <= arr[start2]) {
			start++;
		}
		else
		{
			float value = arr[start2];
			count_swap++;
			int index = start2;

			// Shift all the elements between element 1
			// element 2, right by 1.
			while (index != start)
			{
				arr[index] = arr[index - 1];
				index--;
				count_swap++;
			}
			arr[start] = value;
			count_swap++;

			// Update all the pointers
			start++;
			mid++;
			start2++;
		}
	}
}

void mergeSort(float *arr, int l, int r)
{
    if (l < r)
        {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
        }
}


int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("data_mergesort_inplace_comp.csv","w+");
	if(fp1 == NULL)
	{
		printf("Error !!, file1 not opened\n");
	}
	fp2=fopen("data_mergesort_inplace_swap.csv","w+");
	if(fp2 == NULL)
	{
		printf("Error !!, file2 not opened\n");
	}
    static int ArrSize;
    ArrSize=200;
	while(ArrSize<=4000)
    {
        for(int i=0;i<SimSize;i++)
        {
			count_comp = 0;
			count_swap = 0;
			float arr[ArrSize];
			for (int j = 0; j < SimSize; j++)
			{
				arr[j]=urand();
			}
            mergeSort(arr,0,ArrSize-1);
			if (i==SimSize-1)
			{
				fprintf(fp1, "%d\n", count_comp);
				fprintf(fp2, "%d\n", count_swap);
				continue;
			}
            fprintf(fp1, "%d,", count_comp);
			fprintf(fp2, "%d,", count_swap);
        }
        //fprintf(fp, "\b\0\n");
        ArrSize+=200;
    }
    fclose(fp1);
	fclose(fp2);
    return 0;
}
