#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head;

void enqueue(int n){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if(head == NULL){
        temp->link = NULL;
        head = temp;
    }
    else{
        struct node *temp2;
        temp2 = head;
        while(temp2->link != NULL)
            temp2 = temp2->link;
        temp2->link = temp;
        temp->link = NULL;
        temp2 = NULL; 
    }
}
 
void dequeue(){
     if(head == NULL)
     printf("Queue is Empty!!!\n");
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
    printf("Total number of elements in Queue is: %d",count);
}

void print(){
    if(head == NULL)
    printf("The Queue is Empty\n");
    else{
    struct node *temp;
    temp = head;
    printf("The Elements present in Queue is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    }
}

int main(){
    head = NULL;
    int n,i;
    while(1){
        printf("\n<----------------------------------------------------->\n");
        printf("List of Operations!!!\n");
        printf("1.) Enqueue data in Queue\n");
        printf("2.) Dequeue data in Queue\n");
        printf("3.) Count number of elements present Queue\n");
        printf("4.) Print Elements present in Queue\n");
        printf("5.) Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&i);
        switch(i) {
            case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d",&n);
            enqueue(n);
            break;
            case 2:
            dequeue();
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
            default:
            printf("Enter a valid operation\n");
            break;
        }
    }
    return 0; 
}