#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SimSize 100
float seed=94;//liner congruencetial genarator
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


int swap_no;
int comp_no;

void swap(float *a,float *b)
{
    float temp;
    temp = *a;
    *a=*b;
    *b = temp;
}

// function build Max Heap where value
// of each child is always smaller
// than value of their parent
void buildMaxHeap(float *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		// if child is bigger than parent
		if (arr[i] > arr[(i - 1) / 2])
		{
			int j = i;
			// swap child and parent until
			// parent is smaller
			while (arr[j] > arr[(j - 1) / 2])
			{
				comp_no++;
				swap(arr+j, arr + ((j - 1) / 2));
				j = (j - 1) / 2;
			}
		}
	}
}

void heapSort(float *arr, int n)
{


	for (int i = n - 1; i > 0; i--)
	{
		// swap value of first indexed
		// with last indexed
		swap(arr + 0, arr + i);
        swap_no++;
		// maintaining heap property
		// after each swapping
		int j = 0, index;

		do
		{
			index = (2 * j + 1);

			// if left child is smaller than
			// right child point index variable
			// to right child
			if (arr[index] < arr[index + 1] && index < (i - 1))
				index++;

			// if parent is smaller than child
			// then swapping parent with child
			// having higher value
			if (arr[j] < arr[index] && index < i)
            {
                swap(arr + j, arr + index);
                swap_no++;
            }


			j = index;

		} while (index < i);
	}
}

// Driver Code to test above
int main()
{
    FILE *fp;
    FILE *fp1;
    fp=fopen("data_heapsort.csv","w+");
    fp1=fopen("data_heapbuild.csv","w+");
    int count;
    static int ArrSize;
    ArrSize=100;
	while(ArrSize<=1000)
    {
        for(int i=0;i<SimSize;i++)
        {
            comp_no=0;
            swap_no=0;
            float arr[ArrSize];
            for(int j=0;j<ArrSize;j++)
            {
                arr[j]=urand();
            }
            buildMaxHeap(arr,ArrSize);
            heapSort(arr,ArrSize);
			if (i==SimSize-1) {
				fprintf(fp, "%d\n", swap_no);
				fprintf(fp1,"%d\n",comp_no);
				continue;
			}
            fprintf(fp, "%d,", swap_no);
            fprintf(fp1,"%d,",comp_no);
        }
        //fprintf(fp, "\b\0\n")
        ArrSize+=100;
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
