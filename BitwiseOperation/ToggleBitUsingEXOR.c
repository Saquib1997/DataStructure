#include <stdio.h>
int main()
{
    int a,n,x = 0b1;
    printf("Enter a number: ");
    scanf("%d",&a);
    printf("Enter the bit to be Toggled: ");
    scanf("%d",&n);
    x = x<<n;
    a = a^x;
    printf("The updated number after toggling %d bit is: %d\n",n,a);
    return 0;
}


