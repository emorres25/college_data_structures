#include<stdio.h>




void main()
{
	int i, j, index, value, temp;
	int arr[15];
	for(i=0;i<=9;i++)
	{
		printf("Enter the %d element for array: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\n");
	printf("Enter the index of where you'd want to insert the element: ");
	scanf("%d", &index);
	printf("\nEnter the value of the element: ");
	scanf("%d", &value);


	for(i=12;i>=index;i--)
	{
		j=i-1;
		temp = arr[j];
		arr[i] = arr[j];
		
	}
	arr[index] = value;
	for(i=0;i<=12;i++)
	{
		printf("%d  ", arr[i]);
	}
	
}