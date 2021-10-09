#include <stdio.h>
#include <stdlib.h>

int arr[100];
int front=-1;
int last=-1;

void push(int value){
    if(last>=100){
        printf("\nQueue Overflow\n");
        return;
    }
    if(front==-1){
        arr[last+1]=value;
        front++;
        last++;
        return;
    }
    arr[last+1]=value;
    last++;
}

void pop(){
    if(front==-1 || front==last+1){
        printf("\nThere are no elements in the Queue.\n");
        return;
    }
    front++;
}

void peek(){
    if(front==-1 || last==-1 || front==last+1){
        printf("\nThe Queue is underflow.\n");
        return;
    }
    printf("\nThe front element in the Queue is %d\n",arr[front]);
}

void display(){
    if(front==-1 || last==-1 || front==last+1){
        printf("\nThe Queue is underflow.\n");
        return;
    }
    int temp=last;
    printf("\nThe elements in Queue are:\n");
    for (int i = front; i <=temp; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}

int main(){
    while (1)
    {
        printf("\n=======Menu=======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n\n");
        int c,n;
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        
        default:
            printf("Please select a valid option.");
        }
    }
    

    return 0;
}