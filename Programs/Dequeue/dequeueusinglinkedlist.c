#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void pushFront(int value){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
    if(head==NULL){
        head=n;
        n->data=value;
        n->next=NULL;
        return;
    }

    n->next=head;
    n->data=value;
    head=n;
}

void pushLast(int value){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
    if(head==NULL){
        head=n;
        n->data=value;
        n->next=NULL;
        return;
    }

    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->data=value;
    n->next=NULL;
}

void popFront(){
    struct Node* temp=head;
    if(head==NULL){
        printf("\nDequeue is empty.\n");
        return;
    }

    head=head->next;
    temp->next=NULL;
}

void popLast(){
    struct Node* temp=head;
    if(head==NULL){
        printf("\nDequeue is empty.\n");
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
}

void peekFront(){
    if (head==NULL)
    {
        printf("\nDequeue is empty.\n");
        return;
    }

    printf("The front element is: %d\n",head->data);
}

void peekLast(){
    if (head==NULL)
    {
        printf("\nDequeue is empty.\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("The last element is: %d\n",temp->data);
}

void display(){
    struct Node* temp=head;
    if(head==NULL){
        printf("\nDequeue is empty.\n");
        return;
    }
    printf("\nElements of dequeue are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}


int main(){
    while (1)
    {
        printf("\n=======Menu=======\n");
        printf("1. Push Front\n");
        printf("2. Push Last\n");
        printf("3. Pop Front\n");
        printf("4. Pop Last\n");
        printf("5. Peek Front\n");
        printf("6. Peek Last\n");
        printf("7. Display\n");
        printf("8. Exit\n\n");
        int c,n;
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&n);
            pushFront(n);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&n);
            pushLast(n);
            break;
        case 3:
            popFront();
            break;
        case 4:
            popLast();
            break;
        case 5:
            peekFront();
            break;
        case 6:
            peekLast();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        
        default:
            printf("Please select a valid option.");
        }
    }

    return 0;
}