#include <stdio.h>
#include <stdlib.h>

int stack[100] = {'\0'}, top = -1;

void push(int data){
    if(top == 99)
    printf("Stack is already FULL!!!\n");
    else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1)
    printf("Stack is already EMPTY!!!\n");
    else{
        printf("The popped element from the stack is: %d",stack[top]);
        top--;
    } 
}

void count(){
    if(top == -1)
    printf("Stack is EMPTY!!!\n");
    else{
        int count = 0;
        int i;
        for(i=top; i>=0; i--)
            count++;
        printf("Number of elements present in the Stack is: %d\n",count);
    }
}

void display(){
    if(top == -1)
    printf("Stack is EMPTY!!!\n");
    else{
        printf("Elements of the Stack are: ");
        int i;
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
        printf("\n");
    }
}

int main()
{
    int i, n;
    while(1)
    {
        printf("\n<---------------------------------------------------->\n");
        printf("Stack Using Array!!!\n<---------------------------------------------------->\n");
        printf("1.)Push data into Stack\n2.)Pop data from Stack\n3.)Count the number of items present in Stack\n4.)Display the items in stack\n5.)Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&i);
        switch(i){
            case 1:
            printf("Enter the data to be entered in stack: ");
            scanf("%d",&n);
            push(n);
            break;
            case 2:
            pop();
            break;
            case 3:
            count();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Enter a valid choice!!!\n");
            break;
        }    
    }
    return 0;
}