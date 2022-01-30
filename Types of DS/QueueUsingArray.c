#include <stdio.h>
#include <stdlib.h>

int queue[100] = {'\0'}, front = -1, rear = -1;

//We will do enqueue from the rear side array in queue
void enqueue(int data){
    if(rear == 99)
    printf("Queue is already FULL!!!\n");
    else{
        if(front == -1)
        front = 0;
        rear++;
        queue[rear] = data;
    }
}

//We will do dequeue from the front side of array in queue
void dequeue(){
    if(front == -1 || front > rear)
    printf("Queue is already EMPTY!!!\n");
    else{
        printf("The dequeued element from the queue is: %d",queue[front]);
        front++;
    } 
}

//Count can be done from the either side of the queue 
void count(){
    if(front == -1 || front > rear)
    printf("Queue is EMPTY!!!\n");
    else{
        int count = 0;
        int i;
        for(i=front; i<=rear; i++)
            count++;
        printf("Number of elements present in the Queue is: %d\n",count);
    }
}

//We display the elements from front to rear in queue
void display(){
    if(front == -1 || front > rear)
    printf("Queue is EMPTY!!!\n");
    else{
        int i;
        printf("The elements of the queue is: ");
        for(i=front; i<=rear; i++)
        printf("%d ",queue[i]);
    }
}

int main()
{
    int i, n;
    while(1)
    {
        printf("\n<---------------------------------------------------->\n");
        printf("Queue Using Array!!!\n<---------------------------------------------------->\n");
        printf("1.)Enqueue data into Queue\n2.)Dequeue data from Queue\n3.)Count the number of items present in Queue\n4.)Display the items in Queue\n5.)Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&i);
        switch(i){
            case 1:
            printf("Enter the data to be enqueued in Queue: ");
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