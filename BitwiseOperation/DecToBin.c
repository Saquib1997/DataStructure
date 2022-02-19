#include <stdio.h>
int main()
{
    int bin,dec,i;
    printf("Enter the Decimal number: ");
    scanf("%d",&dec);
    for(i=15;i>=0;i--)
    {
        if((1<<i)&dec)
        printf("1");
        else
        printf("0");
    }
    printf("\n");
    return 0;
}


