#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *tail;

void InsertBeg(int n){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->link = NULL;
    if(tail == NULL){
        tail = temp;
        tail->link = tail;
    }
    else{
        temp->link = tail->link;
        tail->link = temp;
    }
}

void InsertEnd(int n){

}

void DeleteBeg(){

}

void DeleteEnd(){

}

void InsertLoc(int loc, int n){

}

void DeleteLoc(int n){
    
}

void PrintList(void){
    struct node *temp;
    temp = tail->link;
    printf("The Data present in Circular Singly Linked List is: ");
    do{
        printf("%d ",temp->data);
        temp = temp->link;
    } while(temp != tail->link);
    printf("\n");
}

int main()
{
    tail = NULL;
    int i, n, loc;
    while(1){
        printf("\n<--------------------------------------------------------->\n");
        printf("CIRCULAR SINGLY LINKED LIST!!!\n");
        printf("<--------------------------------------------------------->\n");
        printf("List Operations\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Delete from Beginning\n");
        printf("4.Delete from End\n");
        printf("5.Insert at a specific location\n");
        printf("6.Delete from a specific location\n");
        printf("7.Printing and Traversing\n");
        printf("8.Exit\n");
        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0){
            printf("Enter only an Integer\n");
            exit(0);
        } 
    else{
        switch (i){
            case 1:
            printf("Enter the data to insert at the beginning : ");
            scanf("%d",&n);
            InsertBeg(n);
            break;
            case 2:
            printf("Enter the data to insert at the beginning : ");
            scanf("%d",&n);
            InsertEnd(n);
            break;
            case 3:
            DeleteBeg();
            break;
            case 4:
            DeleteEnd();
            break;
            case 5:
            printf("Enter the location where you want to Insert node : ");
            scanf("%d",&loc);
            printf("Enter the data to insert at location %d : ",loc);
            scanf("%d",&n);
            InsertLoc(loc, n);
            break;
            case 6:
            printf("Enter the location from where you want to Delete node : ");
            scanf("%d",&loc);
            DeleteLoc(loc);
            break;
            case 7:
            PrintList();
            break;
            case 8:
            exit(0);
            break;
            }
    }
}
return 0;
}
