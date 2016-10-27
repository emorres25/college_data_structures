#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node* right;
	struct Node* left;
};
struct Node* root = NULL;
struct Node* new_node;


struct Node* Insert(struct Node* root, int data)
{
	if(root==NULL)
	{
		new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->data = data;
		new_node->left = new_node->right = NULL;
		root = new_node;
	}
	else if(data <= root->data)
	{
		new_node = Insert(root->left, data);
		root->left = new_node;
	}
	else
	{
		new_node = Insert(root->right, data);
		root->right = new_node;
	}
	return root;
}

bool Search(struct Node* root, int val)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data == val)
	{
		return true;
	}
	else if(val <= root->data){
		return Search(root->left, val);
	}
	else{
		return Search(root->right, val);
	}
}


void menu()
{
	printf("\n-----Menu-----\n1. Enter a new value\n2. Search for a value\n3. Print all the values\n4. Exit\n");
}

int main()
{	
	int opt, data,val, is;
	bool ans;
	menu();
	while(1)
	{
		scanf("%d", &opt);
		switch(opt)
		{
			case(1):
				printf("Enter the new value: ");
				scanf("%d", &data);
				root = Insert(root, data);
				break;
			case(2):
				printf("Enter the value to be searched: ");
				scanf("%d", &val);
				ans = Search(root, val);
				if(ans==true)
					printf("Found!\n");
				else
					printf("Not Found!\n");

			case(4):
				exit(0);
			default:
				printf("Invalid option!\n");
				break;
		}
	}
}