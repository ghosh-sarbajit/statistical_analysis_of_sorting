#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define SimSize 100
float seed=67;//liner congruencetial genarator
float urand()
{
	float a,m,c;
	a=1421.0;
	m=32768;
	c=1.0;
	seed=a*seed+c;
	seed=fmod(seed,m);
	return seed/(m-1);
}

// generates an array of ArrSize and returns number of shifts required to sort the array
int insertionSort(int ArrSize)
{
    int count;//for number of shifts
    float arr[ArrSize];
    float key;
	int i, j;
	//array generate
	for(i=0;i<ArrSize;i++)
    {
        arr[i]=urand();
    }
	for (i = 1; i < ArrSize; i++)
    {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
        {
            count++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
    return count;
}
int main()
{
    FILE *fp;
    fp=fopen("data.csv","w+");
    int count;
    static int ArrSize;
    ArrSize=100;
    while(ArrSize<=1000)
    {
        for(int i=0;i<SimSize;i++)
        {
            count = insertionSort(ArrSize);
			if (i==SimSize-1) {
				fprintf(fp, "%d\n", count);
				continue;
			}
            fprintf(fp, "%d,", count);
        }
        //fprintf(fp, "\b\0\n");
        ArrSize+=100;
    }
    fclose(fp);
    return 0;
}
