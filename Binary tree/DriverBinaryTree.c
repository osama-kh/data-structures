#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"BinaryTree.h"

int main()
{
	srand(time(NULL));
	node* root;
	int H, num, NumToSearch;
	root = randomTree();
	H = height(root);
	printf("\n\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);
	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);
	// The run of the homwork function
	printf("\n\nIs the Tree empty? \n");
	printf("%d\n", isEmpty(root));
	printf("\n\n the Tree's leaves  \n");
	printLeaves(root);
	printf("\n\n search a key in the Tree \n");
	int key;
	scanf_s("%d", &key);
	printf("%d\n", contains(root, key));
	printf("\n\n the number of the nodes in the Tree: \n");
	printf("%d\n", countNodes(root));
	printf("\n\n the sum of the nodes in the Tree: \n");
	printf("%d\n", sumofkey(root));
	int level;
	printf("\n Enter the target level:\n");
	scanf_s("%d", &level);
	levelStatistics(root, level);
	printf("\n is the tree perfect?:\n");
	printf("%d\n", IsPerfect(root));
	deleteTree(root);
	printf("\nTree deleted\n");




	return 0;
}