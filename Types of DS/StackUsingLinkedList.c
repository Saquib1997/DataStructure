#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head;

void push(int n){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if(head == NULL){
        temp->link = NULL;
        head = temp;
    }
    else{
        temp->link = head;
        head = temp;
    }
}
 
void pop(){
     if(head == NULL)
     printf("Stack is Empty!!!\n");
     else if(head->link == NULL){
        free(head);
        head = NULL;
     }
     else{
        struct node *temp;
        temp = head;
        head = head->link;
        free(temp);
        temp = NULL;    
     }
}

void count(){
    struct node *temp;
    temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->link;
    }
    printf("Total number of elements in stack is: %d",count);
}

void print(){
    if(head == NULL)
    printf("The Stack is Empty\n");
    else{
    struct node *temp;
    temp = head;
    printf("The Elements present in stack is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    }
}

int main()
{
    head = NULL;
    int i, n;
    while(1){
        printf("\n<------------------------------------------------>\n");
        printf("List Operations\n");
        printf("1.Push Data into Stack\n");
        printf("2.Pop Data from Stack\n");
        printf("3.Count the number of members in stack\n");
        printf("4.Print the Data present in Stack\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0){
            printf("Enter only an Integer\n");
            exit(0);
        } 
        
        else{
            switch (i){
                case 1:
                printf("Enter the data to be inserted at the beginning: ");
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
                print();
                break;
                case 5:
                exit(0);
                break;
            }
        }
    }
return 0;
}