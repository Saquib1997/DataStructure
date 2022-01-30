#include <stdio.h>
#include <stdlib.h>

/*Optimized Bubble Sort: Time Complexity for Bubble Sort algorithm in worst case is O(n^2)(because we are using 
two for loops in this algorithm).*/

void BubbleSort(void){
    int n, i, j, temp=0, flag = 0;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);                                     //Taking Entry of number of elements present in the array
    int arr[n];                                                 
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){                                   //Taking Entry of array
        scanf("%d",&arr[i]);
    }                                    
    for(i=0;i<n-1;i++){                                 //Logic Start for BUBBLE SORT
        flag = 0;
        for(j=0;j<n-1-i;j++){                           //Here, (n-1-i) is taken to avoid the comparision of already sorted elements 
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)                                   //When in any pass, no swapping is done, then array is sorted already
        break;                                          
        }                                               //Logic End for BUBBLE SORT
    printf("The Sorted array is: ");                    //Printing Sorted Array
    for(i=0;i<n;i++)
        printf("%d ",arr[i]); 
    printf("\n");                                                   
}

/*Selection Sort: Time Complexity for Selection Sort algorithm in worst case is O(n^2)(because we are using 
two for loops in this algorithm).*/

void SelectionSort(){
int n, i, j, MaxPos, temp;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);                                     //Taking Entry of number of elements present in the array
    int arr[n];                                                 
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){                                   //Taking Entry of array
        scanf("%d",&arr[i]);
    }                                    
    for(i=0;i<n-1;i++){                                 //Logic Start for SELECTION SORT
        MaxPos = i;                                     
        for(j=i+1;j<n;j++){                              
            if(arr[MaxPos]>arr[j]){                     //Logic to find the position of maximum element present in array
               MaxPos = j;                              //Updating the MaxPos varible with 
            }
        }
        if (MaxPos != i){                               //Logic to update the ith position with maximum element of array
            temp = arr[MaxPos];
            arr[MaxPos] = arr[i];
            arr[i] = temp;
        }                                         
    }                                                   //Logic End for SELECTION SORT
    printf("The Sorted array is: ");                    
    for(i=0;i<n;i++)                                    //Printing Sorted Array
        printf("%d ",arr[i]); 
    printf("\n");  
}

int main(){
    int n;
    while(1){
        printf("\n<------------------------------------------>\n");
        printf("SORTING Algorithms in Data Structures\n");
        printf("<------------------------------------------>\n");
        printf("List Operations:\n");
        printf("1. Bubble Sort!!!\n");
        printf("2. Selection Sort!!!\n");
        printf("3. Some Sort!!!\n");
        printf("4. Exit!!!\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
            BubbleSort();
            break;
            case 2:
            SelectionSort();
            break;
            case 3:
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }
    return 0;
}
