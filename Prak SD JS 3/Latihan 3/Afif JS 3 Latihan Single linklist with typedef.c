// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
	int data;
	struct LinkedList *next;
};

typedef struct LinkedList node;

node *head = NULL;
node *second = NULL;
node *third = NULL;
int main()
{
	head = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));
	third = (node*)malloc(sizeof(node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	return 0;
}