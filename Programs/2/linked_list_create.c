#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
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
	return 0;
}