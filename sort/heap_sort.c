#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *arr;
	int n;
	int i;
	printf("How many elements you want to give\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",arr+i);
	printf("Enterd array\n");
	for(i=0;i<n;i++)
	printf("%d\t", *(arr+i));
	printf("\n\n");
	merge_sort(arr,0,n-1);
	printf("Array after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t", *(arr+i));
	printf("\n\n");
	free(arr);
	return 0;
}
