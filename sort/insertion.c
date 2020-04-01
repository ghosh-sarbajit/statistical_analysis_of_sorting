#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int n,*ptr,key;
	printf("How many elements you want to give\n");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",ptr+i);
	printf("Enterd array\n");
	for(i=0;i<n;i++)
	printf("%d\t", *(ptr+i));
	printf("\n\n");
	//insertion sort
	for(j=1;j<n;j++)
	{
		key=*(ptr+j);
		i=j-1;
		while(i>-1 && *(ptr+i)>key)
		{
			*(ptr+i+1)=*(ptr+i);
			i--;
		}
		*(ptr+i+1)=key;
	}
	printf("Array after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t", *(ptr+i));
	return 0;
}