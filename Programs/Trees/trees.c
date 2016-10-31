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

void Max(struct Node* root)
{
	if(root==NULL)
		printf("The tree doesn't exist\n");
	else if(root->right==NULL)
		printf("Maximum value in the tree is: %d\n", root->data);
	else
		Max(root->right);
}

void Min(struct Node* root)
{
	if(root==NULL)
		printf("The tree doesn't exist\n");
	else if(root->left==NULL)
		printf("Minimum value in the tree is: %d\n", root->data);
	else
		Min(root->left);
}

int Height(struct Node* root)
{
	if(root==NULL)
		return -1;
	else{
		int leftHeight = Height(root->left);
		int rightHeight = Height(root->right);

		if(leftHeight>rightHeight)
			return leftHeight+1;
		else
			return rightHeight+1;
	}
}


void menu()
{
	printf("\n\t-----Menu-----\n\t1. Enter a new value\n\t2. Search for a value\n\t3. Print all the values\n\t4. Maximum\n\t5. Minimum\n\t6. Height\n\t7. Exit\n");
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
				break;
			case(4):
				Max(root);
				break;
			case(5):
				Min(root);
				break;
			case(6):
				printf("The height of the tree is: %d\n", Height(root));
				break;
			case(7):
				exit(0);
			default:
				printf("Invalid option!\n");
				break;
		}
	}
}