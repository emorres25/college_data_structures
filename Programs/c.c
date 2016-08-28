#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};
struct node *head = NULL;


void printlist()
{
	struct node *current;
	printf("The following is the created list: \n");

	current = head;
	while(current!=NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}


void insertlist(int pos, int new_data)
{
	struct node *current, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->next = NULL;
	new_node->data = new_data;
	int i;
	current = head;
	for(i=0;i<pos-2;i++)
	{
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

}


void createlist(int n)
{
	struct node *new_node, *current;
	int i;
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
}

int main()
{
	int n,i, pos, new_data;

	struct node *new_node, *current;
	
	printf("Enter the number of students: ");
	scanf("%d", &n);

	createlist(n);

	printlist();


	printf("Where do you want to insert the new data?: ");
	scanf("%d", &pos);
	printf("\nEnter the new data: ");
	scanf("%d", &new_data);
	

	//printf("\n\n\nAbhi tum yaha pe ho: ");

	insertlist(pos, new_data);
	
	printlist();

	return 0;
}