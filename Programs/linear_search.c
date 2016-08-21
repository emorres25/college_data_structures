#include<stdio.h>

int main()
{
	int arr[11];
	int i, j, found_index=15,query, temp;
	for(i=0;i<10;i++)
	{
		printf("Enter the %d element: ", i);
		scanf("%d", &arr[i]);
	}

	printf("Enter the number that you wish to search for: ");
	scanf("%d", &query);

	for(i=0;i<10;i++)
	{
		if(arr[i]!=query)
			continue;
		else
			found_index = i;
	}
	if(found_index==15)
		printf("The search returned no such value.\n");
	else
		printf("%d exists at %d index in the array.\n", query, found_index);
	
}