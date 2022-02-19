// Application of Bitwise OR operator is that we can SET any specified bit using masking technique with Bitwise OR operator
// Here in this code we have to set the 5th bit of the entered number for that we have used the MASK as 0x10
// 0b11 is binary number with decimal equivalent of 3
// 0x10 is a Hexadecimal number with decimal equivalent of 32 and binary equivalent of 00010000

#include <stdio.h>
int main()
{
    int a,n,x = 0b1;
    printf("Enter a number: ");
    scanf("%d",&a);
    printf("Enter the bit to be Set: ");
    scanf("%d",&n);
    x = x<<n;
    x = ~x;
    a = a|x;
    printf("The updated number after setting %d bit is: %d\n",n,a);
    return 0;
}
