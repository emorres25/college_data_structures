#include<stdio.h>

int main()
{
	int arr[12];
	int i, j, temp, value, index;
	for(i=0;i<=9;i++)
	{
		printf("Enter the %d element: ", i);
		scanf("%d", &arr[i]);
	}


	printf("Enter the index of element you want to delete: ");
	scanf("%d", &index);

	for(i=index;i<=12;i++)
	{
		j=i+1;
		arr[i] = arr[j];
	}



	for(i=0;i<=10;i++)
	{
		printf("%d  ", arr[i]);
	}
	
}