#include <stdio.h>
int main()
{
    int bin,dec,i,sum = 0;
    printf("Enter the Binary number: ");
    scanf("%d",&bin);
    for(i=1;i<=15;i++)
    {
        if((1<<i)&bin)
        sum  += 2^i;
    }
    printf("The Decimal equivalent of %d is:%d\n",bin,sum);
    return 0;
}

