#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define SimSize 100
float seed=91;//liner congruencetial genarator
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

void swap(float *a,float *b)
{
    float temp;
    temp = *a;
    *a=*b;
    *b = temp;
}

// generates an array of ArrSize and returns number of swaps required to sort the array
int bubblesort(int ArrSize)
{
	int count;//for number of shifts
    float arr[ArrSize];
	int i, j;
	int flag;
	//array generate
	for(i=0;i<ArrSize;i++)
    {
        arr[i]=urand();
    }
	for (i = 0; i < ArrSize-1; i++)
	{
		flag = 0;
		for (j = 0; j < ArrSize-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
			swap(arr+j, arr+j+1);
			count++;
			flag=1;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (flag == 0)
			break;
	}
	return count;
}
int main()
{
    FILE *fp;
    fp=fopen("data_bubble.csv","w+");
    int count;
    static int ArrSize;
    ArrSize=100;
	while(ArrSize<=1000)
    {
        for(int i=0;i<SimSize;i++)
        {
            count = bubblesort(ArrSize);
			if (i==SimSize-1) {
				fprintf(fp, "%d\n", count);
				continue;
			}
            fprintf(fp, "%d,", count);
        }
        //fprintf(fp, "\b\0\n")
        ArrSize+=100;
    }
    fclose(fp);
    return 0;
}
