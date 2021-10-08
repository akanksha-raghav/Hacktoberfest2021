#include <stdio.h>
#include <stdlib.h>

int arr[100];
int top=-1;

void push(int value){
    if(top>=100){
        printf("\nStack Overflow\n");
        return;
    }
    arr[top+1]=value;
    top++;
}

void pop(){
    if(top==-1){
        printf("\nThere are no elements in the Stack.\n");
    }
    top--;
}

void peek(){
    if(top==-1){
        printf("\nThe Stack is underflow.\n");
        return;
    }
    printf("The top element in the Stack is %d\n",arr[top]);
}

void display(){
    if(top==-1){
        printf("\nThe Stack is underflow.\n");
        return;
    }
    int temp=top;
    printf("\nThe elements in stack are:\n");
    for (int i = temp; i >=0; i--)
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