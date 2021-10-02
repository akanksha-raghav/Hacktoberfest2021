
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};


int main()
{
	struct node* head;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp-> data = 10;
	temp-> next = NULL;
	head = temp;
	
	struct node* temp1;
	temp1 = (struct node*)malloc(sizeof(struct node));
	temp1-> data = 11;
	temp1-> next = NULL;
	
	struct node* temp2;
	temp2 = (struct node*)malloc(sizeof(struct node));
	temp2-> data = 17;
	temp2-> next = NULL;
	
    printf(" %d \n" , temp->data, temp);
    printf(" %d \n" , temp1->data, temp1);
    printf(" %d \n", temp2->data, temp2);
   
    
	return 0;
}
