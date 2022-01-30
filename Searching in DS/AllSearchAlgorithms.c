#include <stdio.h>
#include <stdlib.h>

/*Linear Search: Time Complexity for Linear search in worst case is O(n)(because we have to 
search the whole array if data is present at the end of the array).*/

void LinearSearch(void){
    int n, arr[n],i,data;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);                                             //Taking Entry of number of elements present in the array
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);                                    //Taking Entry of array
    printf("Enter the data to be searched!!!\n");
    scanf("%d",&data);                                          //Taking Entry of Data to be searched
    for(i=0;i<n;i++){                                           //Logic Start of Linear Search
        if(arr[i]==data){
            printf("Data is found at index location: %d\n",i);
            break;
        }
    }                                                           //Logic End of Linear Search
    if(i==n)                                                    //Handling situation if the data is not found
    printf("Data is not found in the Array!!!\n");
}

/*Binary Search: Time Complexity for the Binary search in worst case is O(logn)(because binary
search works on the principle of DIVIDE AND CONQUER).*/

void BinarySearch(void){
    int start=0, end, mid, n, arr[n], i, data;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);                                             //Taking Entry of number of elements present in the array
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);                                    //Taking Entry of array
    printf("Enter the data to be searched!!!\n");
    scanf("%d",&data);
    end = n-1;                                                  //Taking Entry of Data to be searched
    while(start<end){
        mid = (start+end)/2;                                    //Logic Start of Binary Search
        if(arr[mid] == data){
            printf("Data is found at index location: %d\n",mid);
            break;
        }
        else if(arr[mid] < data){
            start = mid+1;
            mid = (start+end)/2;
        }
        else if(arr[mid] > data){
            end = mid-1;
            mid = (start+end)/2;
        }                                                       //Logic End of Binary Search
    }
    if(start > end)                                             //Handling situation if the data is not found
    printf("Data is not found in the Array!!!\n");
}

int main(){
    int n;
    while(1){
        printf("\n<------------------------------------------>\n");
        printf("SEARCHING Algorithms in Data Structures\n");
        printf("<------------------------------------------>\n");
        printf("List Operations:\n");
        printf("1. Linear Search!!!\n");
        printf("2. Binary Search!!!\n");
        printf("3. Exit!!!\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
            LinearSearch();
            break;
            case 2:
            BinarySearch();
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }
    return 0;
}