#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i, pos;
	struct node {
		int data;
		struct node *next;
	};

	struct node *new_node, *current;
	struct node *head = NULL;

	printf("Enter the number of students: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data for %d student: ", i+1);
		scanf("%d", &new_node->data);

		if(head==NULL)
		{
			head = new_node;
			current=new_node;
		}
		else{
			current->next = new_node;
			current = new_node;
		}
	}

	printf("The following is the created list: \n");

	current = head;
	while(current!=NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");



	new_node = (struct node *)malloc(sizeof(struct node));


	printf("Where do you want to insert the new data?: ");
	scanf("%d", &pos);
	printf("\nEnter the new data: ");
	scanf("%d", &new_node->data);



	printf("\n\n\nAbhi tum yaha pe ho: ");
	current = head;
	for(i=0;i<pos;i++)
	{
		printf("%d ", current->data);
		current = current->next;
	}



	return 0;
}