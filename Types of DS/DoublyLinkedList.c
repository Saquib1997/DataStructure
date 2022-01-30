#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

void InsertBeg(int n){
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->data = n;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertEnd(int n){
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->data = n;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        struct node *temp, *tp;
        tp = head;
        while(tp->next != NULL)
        tp = tp->next;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->prev = tp;
        tp->next = temp;
    }
}

void InsertLoc(int loc, int n){
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->data = n;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        struct node *temp = NULL, *tp = NULL, *new = NULL;
        temp = head;
        while(loc != 0){
            temp = temp->next;
            loc--;
        }
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        if(temp->next == NULL){
            new->prev = temp;
            temp->next = new;
            new->next = NULL;
        }
        else{
            tp = temp->prev;
            new->prev = tp;
            tp->next = new;
            new->next = temp;
            temp->prev = new;
        }    
    }
}

void DeleteBeg(void){
    if(head == NULL)
    printf("Doubly Linked List is empty!!!\n");
    else{
       struct node *temp;
       temp = head;
       head = head->next;
       free(temp);
       temp = NULL; 
    }
}

void DeleteEnd(void){
    if(head == NULL)
    printf("Doubly Linked List is empty!!!\n");
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp, *tp;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;  
        tp = temp->prev;
        tp->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void print(void){
    if(head == NULL)
    printf("The Doubly Linked List is Empty!!!");
    else{
        struct node *ptr;
        ptr = head;
        printf("The Elements of Doubly Linked List are: ");
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int i, n, loc;

    while(1){
        printf("\n<----------------------------------------------------->\n");
        printf("Doubly Linked List\n");
        printf("<----------------------------------------------------->\n");
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
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d",&n);
                InsertBeg(n);
                break;
                case 2:
                printf("Enter the data to be inserted at the end: ");
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
                printf("Enter the location where data to be inserted: ");
                scanf("%d",&loc);
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d",&n);
                InsertLoc(loc, n);
                break; 
                case 7:
                print();
                break;
                case 8:
                exit(0);
                break;
            }
        }
    }
return 0;
}
