#### ARRAY

###### Note: Any changes made to the array inside the function are visible in the calling function. (we can not swap 2 numbers using call by value but can swap array using same.)

###### Note: Prints all the prime numbers less than 200. This method of finding out prime numbers is known as Sieve of Eratosthenes

```c
#include<math.h>`
`maine ()`
`{`
`int i,j,arr[200];`
`for(i=2;i<200;i++)`
`arr[i]=l;`
`for(i=2;i<=sqrt(200) ;i++)`
`for(j=i*2;j<200;j+=i)`

`arr[j]=O;`
`for(i=2;i<200;i++)`
`if(arr[i]==l)`
`printf("%d\t",i);`
`}
```



###### note: This program suppresses the negative numbers at the end of the array.

```c
main()
{
int a[10] ={2, -3, 4, -5, 6, 7,1,9, -10, -ll};
int i,j,x,k=O;
for(i=0;i<10;i++)
{
x=a[k];
if (x<0)
{
for(j=k;j<10;j++)
a[j]=a[j+1];
a[9]=x;
else
k++;
}
for(i=0;i<10;i++J
printf("%d ",a[i]);
printf ("\n");
}
```



```c
wrefxc
```

# Pointers

We have already seen that while declaring a pointer variable, **we have to mention the data type.** **The reason is that when we use the indirection operator, the number of bytes retrieved will be different for different data types**. The value of the pointer only tells the address of starting byte. For example suppose'we have a pointer ptr which contains the address 2000 and when we write. *ptr. the compiler knows that it has to access the information starting at address 2000. "So the compiler will look at the base type of the pointer and will retrieve the information depending on that base type. ,For example i~ base type is int then 2 bytes information will be retrieved and if base type is float, 4 bytes information will be retrieved and so on. The following figures illustrate this fact. The shaded portion shows the num1;ler of bytes retrieved.

**POINTER ARITHMATIC (USED in ARRAY)**

All types of arithmetic operations are not possible with pointers. The only valid operations that can be performed are as- •
(I) Addition of an integer to a pointer and increment operation. 
(2) Subtraction of an integer from a pointer and decrement operation
\(3) Subtraction of a pointer from another pointer of same type.

It is important to note that when we move a pointer somewhere else in memory by incrementing/decrementing or adding/subtracting integers then it not necessary that the pointer still points to a variable of same data type or a valid memory location.

We should take care that we move the pointers in such a way that they always point to valid memory locations

**Precedence Of Dereferencing Operator And Increment/** **Decrement Operators**

precedence of * operator and ++, -- operator are same and associativity is from right to left. (page 220 pdf)



**Pointer Comparisons**

The relational operators = =, != , < , <=, >, >= can be used with pointers. The operators = = and ...-. != are used to compare two pointers for finding whether they contain same address or not. They will be equal only if both are NULL or they contain address of same variable. The use of these operators is valid between pointers or same type or between NULL pointer and any other pointer, or. between void pointer and any other pointer.

**POINTER TO POINTER**

we can have a pointer to pointer to pointer variable and this concept can be extendeo to any limit, but in practice/0nly pointer
to pointer IS used.

Pointer to pointer is generally used while passing pointer variabl~s to functions.
The syntax of declaring a pointer to pointer is as- 

```c
data_type **pptr;

*arr -> Value of  0th element -> arr[0] ~ 5

*arr = arr[0]

arr = &arr[0]

*(arr+i)  = arr[i]
```

**Pointers And Functions**

In call by value method, any changes made to the formal arguments do not change the argument. in call by reference method any changes made to the formal arguments changes the actual arguments also. 



P8.16 Program to explain call by value* /

```c
#include<stdio.h>
main ( )
{
int a=5,b=8;
printf ("Before calling the function, a and bare %d, %d\n", a, b) ;
value(a,b) ;
printf ("After calling the function, a and bare %d, %d\n", a, b) ;
}
value(int
{
x, int y,:)
-
X; +~;
Y.++ ;,
printf("In function changes are %d,%d\n",x,y);
}
```

```c
Output:
Before calling the function, a and bare 5, 8
In functiqn changes are 6 , 9
After calling the function, a and' bare 5, 8
```

**Returning More Than One Value From A Function**

```c
/*P8.18 Program to show how to return more than one value from a function
using call by reference*/
#include<stdio.h>
main( )
{
int. a,b,sum,diff,prod;
a=6 ;
b=4;
func(a,b,&sum,&diff,&prod) ;
printf ("Sum = %d, Difference = %d, Product%d\n",sum,diff,prod) ;
}
func (int x, int y, int *ps, lIlt. *pd, int *pp)
{
*ps=X+y;
*pd=x-y;
*pp=x*y;
}
```

```c
Output:
Sum = 10, Difference = 2 , Product = 24
```

**Function Returning Pointer**

While returning a pointer, make sure that the memory address returned by the pointer will exist even after the termination of function.

For example a function of this form is invalid

```c
main()
{
int = *ptr;
ptr=func ( ) ;
}
int * func ()
{
int x=5;
int *p=&x;
return p;
}
```

The address returned by func( ) is assigned to pointer variable ptr inside main( ), so now ptr will contain address 2500. When we dereference ptr, we are trying to access the value of a variable that no longer exists. So **never return a pointer that points to a local variable**. Now we'll take a program that uses a function returning pointer.

**Passing a 1-D Array to a Function**

We can declare it as an unsized or sized array or we can declare it as a pointer.
func (int a[j]);

func (int a [5] ) ;

func (int *a);

/*P8.21 Program to verify the fact that when an array is passed to· a
function, the· receiving argument is declared as a pointer * /

```c
#include<stdio.h>
main( )
{
float f_arr[5]={1.4,2.5,3.7,4.1,5.9};
int i_arr[5]={1,2,3,4,5};
char c_arr[5]={ 'a', 'b', 'c', 'd', 'e'};
printf("Inside main( ");
printf("Size of arr %u\t",sizeof(f_arr));
printf("Size of arr %u\t",sizeof(i_arr));
printf("Size of arr %u\n",sizeof(c_arr));
func(f_arr,i_arr,c_arr);
}
func(float f[],int *i,char c[5])
{
printf("Inside func() ");
printf("Size of f %d\t",sizeof(f));
printf("Size of i %d\t",sizeof(i));
printf ("Size of c %d\n", sizeof (c));
}
```

```c
Output:
Inside main (): Size of Carr = 20 Size of i arr = 10 Size of carr = 5
II}side func( ) : Size of f = 2 Size of i = 2 Size of c = 2
```

Inside the function func( ), f, i, c are declared as pointers, and this is evident by the fact that the
size of each one of them is 2 bytes.

**Array Of Pointers**

The array of pointers can also contain addresses of elements of another array.
/*P8.24 Program for understanding array of pointers* /

```c
#include<sidio.h>
main( )
{
int i,arr[4]={5,lO,15,20};
int *pa[4];
for(i=O;i<4;i++)
pa[i] = &arr[i];
for(i=O;i<4;i++)
{
printf ("pa [%d]= %u \ t" , i, pa [ i] ) ;
printf (" *pa [%d]= %d\n",i,*pa[i]);
}
```

Output:

```c
pa[O] = 1000
pa[l] = 1002
pa[2] = 1004
pa[3] = 1006
*pa[O] = 5
*pa[l] = 10
*pa[2] = 15
*pa[3] = 20
```

Here 'pa' is declared as array of pointers. Each element of this array contains the address of each element of array 'arr'.

### **void Pointers**

**We cannot perform arithmetic on *void* pointers.**

A pointer to void is a generic pointer that can point any data type.

```c
void *vpt;
```


Here void is a keyword and vpt is declared as a pointer of void type. For example 

```c
int i = 2, *ip = &i;
float f= 2.3, *fp = &f;
double d;
void *vp;

vp = Ip;
vp = fp;
vp = &d;
```

We can assign address of any data type to a void pointer and a void pointer can be" assigned to a pointer of any data type.

A void pointer can't be dereferenced simply by u,S;ing indirection operator. Before dereferencing, it should' be type cast to appropriate pointer data type. For example if vp is a void pointer and it holds the address of an integer variable then we can't just by writing *vp. We'll have to write *(int *)vp,
derefe~~tice i~ .where leftmost asterisk is the indirection, operator and (int *) is used for typecasting. Similarly pointer arithmetic can't be performed on void pointers without typecasting.

**Dynamic Memory Allocation**

The process of allocating ,memory at the time of execution is called dynamic memory allocation (alloc.h and stdlib.ll' header files) 

```c
malloc()
Declaration: void *malloc(size_t size)
```

```c
calloc()
Declaration: void *calloc(size_t n, size_t size);
```

**The other difference between calloc( ) and malloc( ) is that the memory allocated by malloc, contains garbage value while the memory allocated by calloc( ) is initialized to zero. both returns NULL if there is not sufficient memory available in the heap.**

```c
realloc()
Declaration: void *realloc( void *ptr, size_t newsize);
```

We may want to increase or decrease the memory .allocated by malloc( ) or calloc( ). The function realloc( ) is used to change the size of the memory block. It alters the size of the memory block without losing the old data. This is known as reallocation of memory.

This function takes two arguments, first is a pointer to the block of memory that was previously allocated by malloc( ) or calloc( ) and second one is the new size for that block. For example 

```c
For example 
ptr= (int *) malloc ( size ); 
```

This statement allocates the memory of the specified size and thy starting address of this memory block is stored in the pointer variable ptr. If we want to change the size of this memory block, then we can use realloc( ) as 

```c
ptr= (int *) realloc ( ptr , newsize );
```

/ *P8. 29 program to understand the use of realloc () function* /

```c
#include<stdio.h>
#include<alloc.h>
main ( )
{
i,nt i, *ptr;
ptr=(int *)malloc(5*sizeof(int));
234
if (ptr==NULL)
{
C in Depth
printf ("Memory not available\n");
exit-(l) ;
}
printf ("Enter 5 integers ") ;
for(i=O;i<5;i++)
scanf("%d ",ptr+i);
ptr= (int *) realloc (ptr, 9 *sizeof (int) ); /*Allocate memory for 4 more integers*/
if (ptr==NULL)
{
printf ("Memory not available\n");
exit (1) ;
}
printf ("Enter 4 more integers: ");
for(i=5;i<9;i++)
scanf("%d",ptr+i);
for(i=O;i<9;i++)
printf ("%d ", * (ptr+i));
```

**The function free( ) is used to release the memory space allocated dynamically.**

```c
free()
Declaration: void free(void *p);
```

**Memory Leak** is a situation when we get some memory on the heap and do not free it when we are done using it.so our application is actually holding on to some unused memory in the heap, but why do we call it this situation **Memory Leak** and why does it happen due to improper use of dynamic memory only, due to improper use of heap.

Memory leaks in C happen for **three core reasons**:

- we do not free the memory that is no longer needed
- we do try to free the memory but we do not have the reference to it **(dangling pointer)**
- we try to free the memory using the wrong function

### **Pointers To Functions**

The code of a function resides in memory hence every function has an address like all other variables.

```c
/*Program to illustrate that every function has an address and how to access that address*/
#include<stdio.h>
main( )
{
int func1( );
printf ("Address of function main() is %u\n",main);
printf ("Address .of function func1() is %u\n",func1);
func1(); /*Function call */
}
int func1()
{
printf("India is great\n");
}
Output:
Address of function main() is : 657
Address of function func1( ) is : 691
India is great
```

**Declaring A Pointer To A Function**

```c
return type (*ptr_name )(type1, type2);
for example :    float (*fp)( int );
                 char (*func_p)(float, char);
here fp is a pointer that can point to any function that returns a float value and accepts an int value
argument.
```

```c
float (*fp)(int , int );/*Declaring a function pointer */
float func( int , int );/*Declaring a function*/
fp = func; /*Assign address of function func() to pointer fp*/
```

**Passing a Function's Address as an Argument to other Function**

We can send the function's address as an argument to other function in the same way as we send other arguments. To receive the function's address as an argument, a formal parameter of the appropriate type should be declared. We can then invoke the function sent as an argument by dereferencing the formal pointer variable. The following program will make this point clear.

```c
/ * P8. 36 Program to send a function's address as an argument to other function * /
#include<stdio.h>
main ( )
{
void func(char,void(*fp) (float)); //This is Function Decleration....!!!We can declare a function inside main also and alo in global space
void funl(float);
printf ("Function main () called\n");
func ('a', funl);
}
void func(char b,void (*fp) (float))  /*Address of funl stored in fp*/
{
printf ("Function func() called\n") ;
(*fp)(8.5); /*Calling void funl indirectly using pointer*/
}
void funl(float)
{          
printf ("Function funl () called");
}

Output:
Function main( ) called
Function func( ) called
Function fun1 ( ) called
```

```c
/* P8.37. Program to pass a pointer containing function's address as an argument*/
#include<stdio.h>
main ( )
{
void func(char,void (*fp)(float));
void funl (float) ;
void (*p) (float);
p=funl;
printf ("Function main ( called\n") ;
func('a',p);
}
void func(char b,void (*fp) (float)) / *Value of p stored in fp* /
{
printf ("Function func ( )called\n") ;
(*fp) (8.5); /*Calling funl indirectly using pointer*/
}
void funl(float f) 
{
printf ("Function funl () called\n");
}
      Output:
Function main()called
Function func() called
Function fun1() called
```

**Using Arrays Of Function Pointers**

why call a function using function pointer when it can l-e easily called using its name. Well in many applications we don't know in advance which function will be called. In that case we can take the addresses of different functions in an array and then call the appropriate function depending on some index number.

Let us take a program and understand this concept. In this program we'll add, subtract, multiply or divide two numbers depending on user's choice. For this of course we'll make four different functions The addresses of these functions will be stored in an array of function pointers.

```c
float add(float, int);             /*Dec1aration of functions */
float sub(float, int);
float mul(float,int);
float div(float, int);

float (*fp[4] )( float, int );    /*Declare an array of function pointers*/
fp[O] = add;                      /*Assigning address to elements of the array of function pointer*/
fp[l] = sub;
fp[2] = mul;
fp[3] = div;

Instead of the above assignment statements, we could have initialized the array as~
float (*fp[] )(float , int ) = {'add, sub, mul, div };
Now we can see that~
(*fp)[O]( a, b);				is equivalent to add(a, b);
(*fp)[l]( a, b);				is equivalent to sub(a, b);
(*fp)[2]( a, b);				is equivalent to mul(a, b);
(*fp)[3]( a, b);				is equivalent to div(a, b);

                                
In the following program, the function select( ) is used to display menu options and to input user's
choice. Depending on the choice of user, corresponding function is cal~ed.
/*P8.38 Program to understand the use of array of function pointers*/
#include<stdio.h>
int select (void) ;
float add(float,int);
float sub(float, int);
float mul(float,int);
float div(float,int);
main ( )
{
int i,b;
float a,r;
float (*fp[ ])(float, int)={add,sub,mul,div};
while(l)
{
i=select ();
if(i==5)
exit(l);
printf-( "Enter a float and a integer: ");
scanf ("%f %d", &a, &b) ;
r= ( * fp [i -1] ) (a, b) ;
printf("Result is %f\n",r);
}
}
int select (void)
{
int choice;
printf("l.Add\n") ;
prirttf("2.Subtract\n") ;
printf("3.Multiply\n") ;
printf("4.Divide\n") ;
printf("5.Exit\n") ;
printf("Enter your choice ");
scanf("%d",&choice) ;
return choice;
}
foat add (float a, int b)
return a+b;
foat sub (float a, int b)
return a-b;
float mul (float a, int b)
return a*b;
foat div (float a, int b)
return a/b;
```

```c
int *p;					 				 /*Pointer to int */
int **p;								 /*Pointer to pointer to int */
int *p[20];								 /* Array of 20 int pointers*/
int (*p)[20];							 /* Pointer to an array of 20 integers */
int *f(void); 							 /*Function that returns an int pointer*/
int (*fp)(void);						 /*Pointer to a function, function returns int */
int (*fp[4] )(void);					 /*An array of 4 pointers to functions, each function return 										int*/	
int *(*fp)(void); 						/*Pointer to a function, function returns an int pointer */
float *(*fp)(int, float);				 /*Pointer to a function, function takes two arguments of int 											and float type and returns a float pointer*/
float *(*fp[4] )(int, float);			 /*Pointer to a function, function takes two arguments of in
										and float type and returns a float pointer*/
```

Exercise Question:

```c
int main()
{
int i,arr[5]={25,30,35,40,45},*p;
p=&arr [4] ;
for(i=O;i<5;i++)
printf ("%d\t%d\t", * (p-i) ,p [-i]);
}
//Que 5 pdf page 260 c in depth
Output:
45 45 40 40 35 35 30 30 25 25
```

**arr is a constant pointer and it can't be changed.**

```c
main()
{
int i,arr[5]={25,40,55,70,85},*p=arr;
for(i=O;i<5;i++)
printf("%d ",*P++);
printf("\n");
for(i=O;i<5;i++)
printf("%d ",*--p);
printf (" \n") ;
}
output:
25 40 55 70 85
85 70 55 40 25
```

```c
main()
{
int i,arr[5]={25,40,55,70,85},*p=arr;
for(i=O;i<8;i++)
printf("%d ",++*p);
printf("\n");
for(i=0;i<7;i++)
printf("%d ",(*p)++);
printf("\n");
}
output:  26 27 28 29 30 31 32 33
		33 34 35 36 37 38 39
```

```c
int arr[4]={10,20,30,40};/*Assume base address of arr is 5000*/
int x=100,*ptr=arr;
printf("%u%d 	%d\n",ptr,*ptr,x);		5000 10 	100
x=*ptr++;//--->  x=*ptr=10 then ptr++ now ptr is pointing to 20 i.e 5002 address
printf("%u%d 	%d\n",ptr,*ptr,x);		5002 20 	10
x=*++ptr;//-----> ++ptr 5004 address *ptr is 30 & x stores 30 now 
printf ("%u %d	 %d\n", ptr, *ptr,x);	5004  30 	30
x=++*ptr;//-----> *ptr=30 pre increament 31  address 5004
printf ("%u%d 	%d\n" ,ptr, *ptr,x);	5004 31 	31
x=(*ptr)++;//----> *ptr was 31 x is 31 only post increament 32 address 5004 only 
printf("%u%d 	%d\n",ptr,*ptr,x);		5004 32 	31
```

```c
int x, arr[8]={ll, 22, 33, 44, 55, 66, 77, 88};
x = (arr+2)[3];---->(arr+2)[3] will be interpreted as *(arr+2+3) or as *(arr+5), which is same as arr[5].
printf ("%d\n", x);--->x=66
```

```c
int a=5.,b=10;
main( )
{
int . x:", 2 0 ,*ptr=&x;
printf("%d ",*ptr);
changel(ptr) ;
printf("%d ",*ptr);
change2 (&ptr) ;
printf("%d\n",*ptr) ;
}
changel (int *p)
{
p=&a;
}
change2(int **pp)
{
*pp=&b;
}
20 20 10
Since we need to change the value of ptr we have to send its address, and in the function we have to receive address of a pointer so we need a pointer to pointer,hence the function change2() will be able to change. the value of ptr and changel() can't change the value of ptr .
```

```c
int arr[3] [4] [5];           /*Assume base address of arr is 2000*/
={
    {{1,2,3,4,5},{6,7,8,9,10}{11,12,13,14,15},{16,17,18,19,20}},
    {{1,2,3,4,5},{6,7,8,9,10}{11,12,13,14,15},{16,17,18,19,20}},
    {{1,2,3,4,5},{6,7,8,9,10}{11,12,13,14,15},{16,17,18,19,20}},
    {{1,2,3,4,5},{6,7,8,9,10}{11,12,13,14,15},{16,17,18,19,20}},
    {{1,2,3,4,5},{6,7,8,9,10}{11,12,13,14,15},{16,17,18,19,20}}
 }
printf("%u\t",arr);--------->2000
printf("%u\t",arr[0]) ;-------->2000
printf("%u\t",arr[0] [0]);------->2000
printf("%u\n",&arr[0] [0] [0]);------->2000
printf("%d\t",sizeof(arr)) ;---------> size of hole array 3*4*5=60 i.e 120
printf("%d\t",sizeof(arr[0]));----->is 20 i.e 40
printf ("%d\t", sizeof (arr[0] [0]));-------> 10
printf("%d\n",sizeof(arr[0] [0] [0]));-----> 2
```

```c
int i,arr[3] [4] {{l0,11,12,13}, {20,21,22,23}, {30,31,32,33}}:
int *pa [3];
int (*p)[4];
p=arr;
for(i=0;i<3;i++)
par[i]=arr[i];
printf("%d %d %d\n",pa[0][0],pa[0][l],pa[2][3]);
printf("%d %d %d\n",p[0][0],P[0][l],P[2][3]);
output:
10 11 33
10 11 33
    pa is an array of 3 pointers, each of base type int, while p is a pointer to an array of 4 integers
```

### **STRING**

**sscanf():** sscanf() is used to read formatted input from the string

1. When we compare two identical strings using equality operator then we are actually comparing the addresses and not the strings. strcmp() used to compare strings.

2. when the string constant is used as an initializer for a character array then it does not represent, any address and it is not stored anywhere in memory. For example- ,
   char arr[5] = "Deep";
   Here the string constant "Deep" is not stored in memory and hence does not represent any address.

   ```c
   /*P9.3 Program to print the address and characters of the string usin pointer*/
   #include<stdio.h>
   main( )
   {
       char str [ ] ="India";
   	char *p;
   	p=str;
   	while(*p !='\'0')
       {
           printf ("Character = %c\ t" , *:p) ;
   		printf("Address=%u\n",p) ;
   		p++;
       }
   }
   ```

   scanf( ) stops reading as soon as it encounters a whitespace. So for entering string's with whitespaces we can use the function gets( ).

   **String Library Functions**

   1. **strlen( )** ----> returns length of the string. and takes single argument

   2. **strcmp( )**--> This function is used for comparison of two strings. If the two strings match, strcmp() returns value 0.

   3. **strcpy( )**--> used for copying one string to another string. strcpy( str1, str2 ) copies str2 to str1

   4. **strcat( )**---> used for concatenation of two strings.

      **String Pointers**

### **STRUCTURE**

**Assignment of Structure Variables**

**only Assignment (=) operator can be applied on structure variables.**

```c
We can assign values of a structure variable to another structure variable, if both variables are defining of the same structure type. For example-
struct student {
char name [20] ;
int .rollno;
float marks;
} ;
main ( )
{
struct student stul={"Oliver",12,98};
struct student stu2;
stu2=stul;
printf("stu1 %s %d %. 2f\n", stul.name, stul. rollno, stul.marks) ;
printf("stu2 %s %d %. 2f\n", stu2 .name, stu2. rollno, stu2.marks);
}
```

**Storage of Structures in Memory** :The members of structures are stored in consecutive memory locations.

**Size of Structure** we may need to find out the size of structure in some situations like reading and writing to files. to find out size we can use sizeof operator (sizeof(struct student))

***Some machines stores integers only at even address and long ints onnly at address which are multiple of 4. this is called aligning of data*** 

**Array of Structures**--> Each element of array is of structure type : struct student stu[10]

```c
stu[0].name		 stu[0] .rollno		stu[0].marks
.							.							.
stu[9].name		  stu[9].rollno			stu[9].marks
   /*Program to understand array of structures*/
#inc1ude<stdio.h>
struct student {
char name [20] i
int rollno;
float marks;
};
main ( )
{
int i;
struct student stuarr [10] ;
for(i=0;i<10;i++)
{
printf ("Enter name, rollno and marks ") i
scanf("%s %d %f",stuarr[i].name,&stuarr[i].rollno,&stuarr[i].marks);
}
for(i=0;i<10;i++)
printf("%s %d %f \n",stuarr[i].name,stuarr[i] .rollno,stuarr[i].marks);
```

**Nested Structures (Structure Within Structure)**

The members of a structure can be of any data type including another structure type i.e. we can include a structure within another structure. A structure variable can be a member of another structure. it is called nesting of structures.
struct tagl {
					memberl;
					member2;
									struct tag2 {
														memberl;
														member2;
														member m;
														}varl;
									member n;
									}var2;
For accessing member1 of inner structure we'll write **var2.varl.memberl**

**Pointers to Structures	**

```c
struct student { 
			char name [ 20] ;
			int rollno;
			int marks;
			} ;
			struct student stu, *ptr;   
			int ptr= &stu; So to access members of a structure vanable (*ptr).name or ptr->name
```

**Pointers Within Structures**

```c
struct student { char name[20]; int *ptrmem;};  
struct student stu, *stuptr=&stu;
access the va-lue of ptrmem, we'll write stu.ptrmem or stuptr->ptrmem
```

**Passing Structure Members As Arguments** 

```c
struct student{
char name [20] ;
int rollno;
int marks;
} ;
display (char name [], int rollno, int marks);
main ( )
{
struct student stu1= {"John" , 12,87};
struct student stu2;
strcpy(stu2.name, "Mary");
stu2.rollno=18;
stu2.marks=90;
display(stul.name,stul.rollno,stul.marks);
display(stu2.name,stu2.rollno,stu2.marks);
}
display(char name[],int rollno,int marks)
{ 
printf( "Name %s \ t" ,name) ;
printf("Rollno %d\t",rollno) ;
printf ("Marks %d\n" ,marks);
}
Output:
Name - John Rollno - 12 Marks - 87
Name - Mary Rollno - 18 Marks - 90
```

**Passing Structure Variable As Argument**

Passing individual members to function becomes cumbersome when there are many members and the relationship between the members is also lost. We can pass the whole structure as an argument.

display (struct student stu)

**Passing Pointers To Structures, As Arguments** if the size of structure is very large it is not efficient to pass the whole structure to the function since the copy of it has to be made inside the called function. in this case better to send address of structure 

```c
/*Program to understand how a pointer to structure variable is send to a function*/
#include<stdio.h>
struct student {
char name [20] ;
int rollno;
int marks;
} ;
displaylay(struct student *);
inc_arks (struct student *);
main()
{
struct student stu1= {"John", 12,87};
struct student stu2= { "Mary" , 18,90} ;
inc_marks (&stu1) ;
-nc_marks(&stu2) ;
display(&stu1) ;
display(&stu2) ;
inc_marks (struct student * stuptr)
{
	(stuptr->marks)++;
}
display ( struct student *stuptr)
{
	printf ("Name %s\t",stuptr->name) ;
	printf ("Rollno %d\t",stuptr->rollno);
	printf ("Marks %d\n",stuptr->marks);
}
Output
Name - John Rollno - 12 Marks - 88
Name - Mary Rollno - 18 Marks - 91
```

**Returning A Structure Variable From Function**

```c
/*P10 .10 Program to understand how a structure variable is returned from a function*/
#include<stdio.h>
struct student {
				char name [20];
				int ro11no;
				int marks;
				};
void display (struct student);
struct student change (struct studertt stu);
main()
{
	struct student stu1= {"John" , 12,87};
	struct student stu2= {"Mary", 18,90};
	stu1=change(stu1} ;
	stu2=change(stu2} ;
	display(stul} ;
	dispYay (stu2) ;
}
struct student change (struct student stu)
{
	stu.marks=stu.marks+5;
	stu.rollno=stu.rollno-10;
	return stu;
}
void display (struct. student stu)
{
printf ("Name %s\t",stti.name) ;
printf ("Rollno %d\t",stu.rollno) ;
printf ("Marks %d\n",stu.marks} ;
}
Output
Name - John Rollno - 12 Marks - 88
Name - Mary Rollno - 18 Marks - 91

```

**Returning A Pointer To Structure From A Function** refer to page 318 pdf

**Passing Array Of Structures As Argument**

### **Union**

The main difference between union and structure is in the way memory is allocated for the members. In a structure each member has its own memory location, whereas members of union share the same memory location. union is declared, compiler allocates sufficient memory to hold the largest member in the union. Since all members share the same memory location hence we can use only one member at a time. Thus union is used for saving memory.

addresses of members of a union are same while the addresses of members of a structure are different.

(1) Arrays of unions can be declared.
(2) Functions can take union variable as arguments and can return union variables.
(3) Pointers to unions can be declared.
(4) Unions can be nested:
(5) Unions can be self referential like structures.

```c
We can use unions declare an array that can hold values -of different data type. The program below shows this-

/*Program that uses an - array of union to hold values of differel
data types */
#include<stdio.h>
union num{
			int i;
			long int 1;
			float f;
			double d;
			} ;
main()
union num arr [10J; /*Size of this array will 10*sizeof (double)*/
arr[0].i=12;
arr[1].l=400000;
arr[2J.f=11.12;
arr[3].d=23 .34;
printf ("%d\t",arr[0] .i);
'printf("%ld\t",arr[1].1);
pr int f ( "%f\t", arr [2].f) ;
printf("%f\n",arr[3] .d);
}
Output:
12 	400000 	11.120000 	23.340000
```

### BIG ENDIAN AND LITTLE ENDIAN

big- endian	-	Most significant byte is stored at the lowest address
little-endian	-	Least significant byte is stored at the lowest address.

```c
#include<stdio.h>
main()
{
int a=1;
char *p=(char *)&a;
if(*p==1)
printf("Little endian\n");
else
printf ("Big Endian\n");
}
```

### **typedef**

The type definition facility allows us to define a new name for an existing data type.  **typedef data_type new_name**
typedef int age, marks, units;
In the above typedef statement, we have defined three names for the data type int. **Since typedef is syntactically considered as a storage class, so we can't include a storage class in typedef statement.**

**INVALID**							 **typedef static char schar;**
											 **typedef exten int marks;**

**1.Pointers**

typedef float *fptr;
After this statement, fptr is a synonym for float * or pointer to float. Now consider this **fptr p, q, *r;** here p and q are declared as pointer to float, while r is pointer to pointer.

**2.Array**

typedef int intarr [10]; ----> intarr a,b,c[15]; ----->(Equivalent to int[10], int b[10], c [15][10)

**3.Functions**

typedef float funct(float, int); funct is any function that takes two values, one float and one int and returns a float now consider this  funct add, sub, mul, div;----> floatadd(float, int); 
												float sub(float, int);
												float mul(float, int);
												float ,div(float, int);

**4.Structures**

struct studentrec {
							char name[20];
							int marks;
							} ;

Student stu1, stu2; (Equivalent to -> struct studentrec stu 1, stu2;)

**Advantages of using typedef**

1. It makes our programs more readable and understandable since we can document our program by giving meaningful and descriptive names for existing types.

2. In structures it is important since we can give a single name to the structure, we need not write struct keyword repeatedly.

3. It makes our programs more portable. When program is run on a different machine on which standard data types are represented by' different number of bytes, only typedef statement has to be changed.

  **The typedef declarations may seem similar to #define directives, but they are different. The basic difference is that the typedef declarations are interpreted by the compiler while #define directives are, processed by the preprocessor. In #define directive we can define an expansion for any text while in typedef we can only define new names for data types only.**

  ```c
  /*Prograrn to understand the difference between #define and typedef*/
  #include<stdio.h>
  #define fp float*
  main( )
  {
  fp p1, p2 , p3 ;
  typedef float * fptr;
  fptr ptrl, ptr2, ptr3;
  printf ("%u %u %u\n", sizeof (pl), sizeof (p2), sizeof (p3));
  printf ("%u %u %u\n", sizeof (ptrl) ,sizeof (ptr2) ,sizeof (ptr3) ) ;
  Output:
  	2	4	4
  	2	2	2
          from output we can see that p1 is declared as a pointer to float while p2 and p3 are declared as variables. Actually the preprocessor expanded the declaration as float *pl, p2, p3;
  ```

  

#### **compilation consist of 4 phases** 

1. **Pre-processing** ---> Removal of comment, Expansion of macro and include file takes place. --> (Expanded source code .i file)

2. **Compilation** ---> Assembly level instructions are generated (.asm file) which is understandable by assembler.

3. **Assembly** ---> Assembly level instruction are converted to machine code (but the function printf etc. are not resolve yet) --> .obj file 

4. **Linking** ---> Linker resolve function calls Linker knows which function is define where. (.exe file )

   **Task of loader come this program has to be loaded in main memory i.e RAM loader does that**

   ### **Pre processor**

   The lines starting with the symbol # are known as preprocessor directives. When the preprocessor finds a line starting with the symbol #, it considers it as a command for itself and works accordingly. All the directives are executed by the preprocessor, and the compiler does not receive any line starting with # symbol.
   **The main functions performed by the preprocessor directives are·**
   1.Simple Macro Substitution
   2.Macros with arguments
   3.Conditional Compilation 
   4.Including 'files
   5.Error generation, pragmas and predefined macro names.
   The preprocessor directives that perform these functions are as given below-
   #define	#else	#error	#if	#elif	#line #ifdef	#endif	#pragma	#ifndef 	#undef

   There are three operators that are used with these directives-
   Defined operator										defined( )
   Stringizing operator   								#
   Token pasting operator							  ##
   Apart from the facilities provided through directives, **another important task that preprocessor performs is that it replaces each comment by a single space.**

   ##### **#define**

   The C preprocessor replaces all the occurrences of macro_name with the macro_expansion. For example	#deflne TRUE 1
   													 #define FALSE 
   													 #define PI 3.14159265
   													 #define MAX 100
   													#define RETIRE AGE 58

   C preprocessor searches for macro_name in the C source code and replaces it with the macro_expressions For example wherever the macro name TRUE appears in the code, it is replaced by 1. These type of constants are known as symbolic constants. These constants increase the readability of the program for example it is better to use the name PI 'instead of the value itself.

   we can have macro expansions of any sort. Here are some more examples

   #define AND &&
   #define OR I I
   #define BEGIN main() {
   #define END }
   #define INFINITE while( 1 )
   #define NEW_LINE printf("\n");
   #define ERROR printf("An error has occurred\n");

   **Macros with Arguments**

   ```c
   #define SUM(x, y) ((x)+(y))---> s = SUM(5,6);---> ((5)+(6));
   #define PROD(x, y) ((x)*(y))----> p=((m)*(n));---> ((m)*(n));
   ```

   ```c
   Let us see some more examples of macros with arguments
   #define SQUARE(x) ( (x)*(x) )
   #define MAX( x, y ) ( (x) > (y) ? (x) : (y) )
   #define MIN( x, y ) ( (x) < (y) ? (x) : (y)
   #define ISLOVER(c) ( c >= 97 && c <= 122 )
   #define ISUPPER(c) ( c >= 65 && c <= 90 )
   #define TOUPPER(c) ( (c) + 'A' - 'a' )
   #define ISLEAP(y) ( (y%400 = = 0) || y%100!=0 && y%4 = = 0) )
   #define BLANK_LINES(n) { int i; for( i = 0; i < n; i++ ) printf("\n"); }
   #define CIRCLE_AREA(rad) ( 3.14 * (rad) *(rad) )
   ```

   **Nesting in Macros**

   One macro name can also be used for defining another macro name i.e. the macro expansion can also contain the name of another macro. For example-
   #define PI 3. 14
   #define PISQUARE PI*PI

   #define ISLOWER(c) (c >= 97 && c <= 122)
   #define TOUPPER(c) ISLOWER(c ) ?((c) + 'A' - 'a') : c

   ```c
   #include<stdio.h>
   #define ISLOWER(c) (c>=97 && c<=122)
   #define ISUPPER(c) (c>=60 && c<=90)
   #define ISALFANUM(c) ISLOWER(c) || ISUPPER(C)
   #define ISNUM(c) (c>=48 && c<=57)   //0 to 9 NUMBER
   int main()
   {
   char ch;
   printf("Enter a character : \n");
   scanf("%c",&ch);
   if(ISALPHANUM(ch))
   printf (" %c is an alphanumeric character\n", ch) ;
   else
   printf ("%c is not an alphanumeric character\n", ch);
   }
   ```

   If the macro name appears inside its own expansion, then it is not expanded. So don't try to write recursive macros like this one-

   **#define FACTORIAL(k) k = = 0 ? 1 : k * FACTORIAL(k-l)   /*Incorrect*/**

   ##### Problems with Macros

   ```c
   /*In the following program we have defined a macro PROD without any parentheses in the macro expansion*/
   #include<stdio.h>
   #define PROD(x,y) x*y
   main ( )
   {
   	printf("%d\t",PROD(2,4));
   	printf("%d\n",PROD(3+4,5+1));
   }
   output:	8	24
   ```

   ```c
   consider this program and we will find another sort of problem.
   #include<stdio.h>
   #define SQUARE (x) ((x) *(x))
   main( )
   {
   int k=5, s;
   s=SQUARE(k++) ;
   printf("s"= %d, k %d \ n" , s , k);
   }
   output : 	s=25 	k=7
   here the statement s = SQUARE(k++); is expanded as s = ( (k++) * (k++) );
   in this case it is better if we use a function instead of macro.
   ```

   ```c
   #include<stdio.h>
   int square (int x)
   
   {return x*x;}
   main ()
   {
       int k=5,s;
   s==square(k++);
   printf ("s .== %d, k %d\n",s,k);
   }
   output: s=25	k=6
   ```

   ```c
   #include<stdio.h>
   #define SWAP(dtype, x,y) {dtype t, t=x, x=y, y=t;}
   main()
   {
       int s=2, t=5;
       SWAP(int, s, t)
           printf("s=%d	t=%d\n",s,t);
   }
   output s=2	t=5
   When the macro was expanded, there was a conflict between variable t declared inside the block, and the variable t declared outside the block in main(). To avoid such type of problems, we can use some naming convention for local variables declared in macros.example we may decide to then in capita is write.
   ```

### Macros Vs Functions

macro is expanded into inline code so the text of macro is inserted into the code for each macro call. Hence macros make the code lengthy and the compilation time increases.

On the other, hand the code of  a function is written only at one place, regardless of the number of times it is called so the use of functions makes the code smaller. So functions are slow but take less memory while macros are fast but occupy more memory due
duplicity of code. If the macro is small it is good but if it is large and is called many times ther is better to change it into a function since it may increase the size of the program considerably.

sometimes macros can prove very useful and also improve the execution spe~d. For example in file stdio.h, getchar( ) and putchar( ) are defined as macros.

So whether to use a macro or a function depends on the memory available, your requirement and nature of the task to be performed.

**Generic Functions**

We can define macros that be used to generate functions for different data types. These types of macros are called generic function. These macros generally take the function name and data type as arguments and the macro call is replace by a function definition.

```c
/*P12.11 Program to understand generic functions */
#inc1ude<stdio.h>
#define MAX(FNAME,DTYPE)			 \
DTYPE FNAME (DTYPE X, DTYPE Y)		 \
{								   \
return X>Y ? X:Y;					\
}
MAX(max_int,int)
MAX (max_float, float)
MAX (max_double, double)
main ( )
{
int p;
float q;
double r;
p=max_int(3,9) ;
q=max_f1oat(7.4,5.7) ;
r=max_double(12.34,13.54) ;
printf("p = %d,q = %.2f,r
\
%.2lf \n",p,q,r);
}
Output:
p = 9, q = 7.40, r = 13.54
       
MAX(max_int, int)		int max_int (int X, int Y)
						{
							return X>Y? X : Y;
						}
MAX(max_float, float)	float max_float (float X, float Y)
						{
							return X>Y? X : Y;
						}

MAX(max_double, double)  double max_double (double X, double Y)
      					 {
						return X>Y? X : Y;
                         	}
```

**#undef**

