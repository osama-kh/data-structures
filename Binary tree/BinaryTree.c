#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "BinaryTree.h"
typedef struct Node node;
struct node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* Left(node* root)
{
	return root->left;
}

node* Right(node* root)
{
	return root->right;
}

node* randomInsertInto(node* root, int value)
{
	if (root == NULL)
		root = NewNode(value);
	else if (rand() % 2 == 0)
		root->left = randomInsertInto(root->left, value);
	else
		root->right = randomInsertInto(root->right, value);
	return root;
}

node* randomTree()
{
	node* root = NULL;
	int size = 1 + rand() % 15;
	printf("\nsize=%d\n", size);
	int i;
	for (i = 1; i <= size; i++)
		root = randomInsertInto(root, 1 + rand() % 50);
	return root;
}

void deleteTree(node* root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int height(node* root)
{
	int Lh, Rh;
	if (root == NULL)
		return -1;
	Lh = height(root->left);
	Rh = height(root->right);
	if (Lh > Rh)
		return Lh + 1;
	else
		return Rh + 1;
}
void PrintGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d  ", root->data);
		
	else if (level > 1)
	{
		PrintGivenLevel(root->left, level - 1);
		PrintGivenLevel(root->right, level - 1);
	}
}
void PrintLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 0; i <= h + 1; i++)
	{
		PrintGivenLevel(root, i);
		printf("\n");
	}
}

void pre_order_traversal(node* root)
{
	if (root != NULL)
	{
		printf("%d  ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void in_order_traversal(node* root)
{
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d  ", root->data);
		in_order_traversal(root->right);
	}
}

int isEmpty(node* root) {//check if the tree embty

	if (root == NULL)
		return 1;

	return 0;
	
}



void printLeaves(node* root) {// print the nodes that are in the end of the tree
	if (root->left == NULL && root->right == NULL) {
		printf("%d\t", root->data);

		return ;
	}
	if (root->left)
		printLeaves(root->left);


	if (root->right)
		printLeaves(root->right);

}

int contains(node* root, int key) {//to search about a specefic key in the tree
	if (!root)
		return 0;

	if (root->data == key)
		return 1;

	else {
		return contains(root->left,key) || contains(root->right,key);
	}

}

int countNodes(node* root) //count the nodes in the tree
{
	int count = 0;
	if (root == NULL) {
		return 0;
	}

	else {
		count = 1;
		return count + countNodes(root->left) + countNodes(root->right);
	}
}

int sumofkey(node* root) {//the sum of the data in the nodes of the tree
	
	int sum = 0;

	if (root == NULL) {
		return 0;
	}
	else {
		sum = root->data;
		return sum + sumofkey(root->left) + sumofkey(root->right);

	}



}

void levelStatistics(node* root, int level) {//give a specefic level information

	printf(" the level %d\n", level );
    PrintGivenLevel(root, level);
	printf("\n the number of nodes in the level:%d\n",countLevel(root, level));

}





int IsPerfect(node* root) {// check if the given tree is a perfect tree
	int x = pow(2  ,(height(root) + 1)) - 1;
	if (x == countNodes(root))
		return 1;
	else {
		return 0;
	}

}

int pow(int x, int y) {//power function(help function)
	int sum = 1,i;
	for (i = 0; i < y; i++)
		sum *= x;

	return sum;

}

int countLevel(node* root, int level)
{	
	int count = 0;
	if (root == NULL)
		return 0;
	if (level == 1)
		return 1;
	else if (level > 1)
	{
		count+=countLevel(root->left, level - 1);
		count+=countLevel(root->right, level - 1);
	}
}