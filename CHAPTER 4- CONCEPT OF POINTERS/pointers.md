# Concept Of Pointers in C/C++

Pointers are the variable which hold the address of other variables. Pointers are used to carry references to other variables. Pointer Variables are strongly typed. A pointer variable of a particular data type is needed to store the address of corresponding variable. For an integer type variable the pointer has to be integer, this extends to the fact that a char value can only be pointed by a character pointer and also goes similar for other data types. 

When we talk  about memory management in programming, we generally deal with the Random Access Memory. Whenever a variable is declared, certain amount of memory in the RAM is allocated which is based on the datatype of the variable being used in the program. This allocation in memory in allocated while the program is in running and the addresses allocated to the variables might be different every time a program runs. A pointer variable is represented using an Asterisk.

**EXAMPLE**: 

A working example of pointers in c++ :


```
int a;
a=5;
Int *p;
p=&a;
cout << a << endl;
cout << p << endl;
cout << *p << endl;
```


Let us assume a fixed section of computer memory. 

![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/memory1.PNG)


Suppose each segment in the memory is of 1 byte. 

Now,

If a programmer types **int x;** in the program, the equivalent memory (4 Bytes) is allocated in the memory. When a **pointer *p** for x is created, the pointer points to **integer x** and** *p** stores the value of **a** whereas** p** stores the address of **a**.


## WHY DIFFERENT DATA TYPES FOR DIFFERENT POINTERS?

It might strike that why do pointers have to be strongly typed when they only need to store addresses. The answer is pointers do a lot more than simply storing the addresses. Pointers are also used to dereference the addresses so that we can access and modify the values in these addresses.  


### HOW ARE NUMBERS ACTUALLY STORED?



![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/pointers.PNG)


This is the binary representation of 1010 

In modern day compilers, an integer takes 4 bytes. The memory is byte addressable. 

The leftmost bit stores the information whether the integer is positive or negative. This bit is also called the **sign bit. **


```
int a = 1010;
int *p=&a;
```


if the value of **p** is printed, **202** is printed because the address of **byte 0** is used to address the integer variable. Now, if we print *p, the machine understands that p is an integer pointer hence it has 4 bytes beginning with address 202. This is because different pointer data types are needed. 

**NOTE: The way the information is stored for float, char and different data types is different in memory. **


<table>
  <tr>
  </tr>
</table>



```
#include <stdio.h>

int main()
{
    int a=1010;
    int *p;
    p=&a;
    printf("Value of p is %d and value of *p is %d",p,*p);
    char *c;
    c=(char*)p;
    printf("Value of c is %d and value of *c is %d",c,*c);
}

/*OUTPUT:
Value of p is -629538260 and value of *p is 1010 Value of c is -629
538260 and value of *c is -14                                     
                                                                  
...Program finished with exit code 0                              
Press ENTER to exit console.  */
```


This happens because char is allocated one byte in memory, once the char pointer points to the typecasted integer it only takes the leftmost byte i.e. Least Significant Byte (LSB) and since it is char so does not extend to check memory for 4 next bytes and outputs decimal equivalent of LSB of binary 1010.


## Void Pointer:

A void pointer is a generic pointer type which does not correspond to any particular data type and thus is called void. A void pointer can not be dereferenced i.e. * can not be used with a void pointer

e.g: 


```
int a=1010;
void *v;
v= &a;
int *p;
p=&a;
v=p //Correct 
printf("%d", v*); //Incorrect Because Void Pointer can not be dereferenced.
```



# Pointer To Pointer Concept:

It was made clear in the previous text that pointers are strongly typed. A pointer can point to an memory location which contains the corresponding data type. 


```
int a;
int *p;
p=&a;
```


But there’s an interesting fact that a pointer can point to another pointer variable. It is represented using double aistrick **. 


```
int a;
int *p;
p=&a;
int **q;
q=&p;


```

# USE CASES:


## As Function Arguments (Call By Reference):

Memory is reserved for a program in execution and it is split as:




![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/heapstack.PNG)

These portions in memory describe the type of data they hold during the execution of the program. Out of these Stack,Static/Global and Code(Text) are fixed whereas Heap is resizable during the execution of the program. 

Codes stores all the instructions. This includes declarations and statements. The static and global variables are deal with a specific memory assigned. The local variables and methods are stores in the Stack. 	

Suppose there’s a program,


```
#include <stdio.h>
void increment(int a)
{
a=a+1;
}
int main()
{
int a;
a=10;
increment(a);
printf("%d",a);
}
```


The program intends to increase value of a variable named a but it outputs 10 and does not show the incremented value.  

This is because:

When the program is in execution, at first main method is triggered so all the information associated with main function is stored in the **stack**. This information typically includes local variable, returning to which function, etc. So, some part of stack memory is occupied with information about the main function, which is called a **stack frame**. Each function has a stack frame in stack. 

When the main function calls increment function, the execution of main function is stopped for some time and the control is passed to the called function. Now, another stack frame is created for increment function. In this stack frame, local variables related to increment function are created. 



![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/stackmemory.PNG)

The real problem was, when the** a=a+1** statement is called, the local variable pertaining to stack frame of function increment gets incremented which only got the value of **a** from the main function as the argument. The value of** a** was copied to local variable of increment function and the same got incremented and thus did not result in incrementing the local variable of main function because the local variables are not accessible outside the **stack frame**. 

Once the control is passed back to main function, the stack frame created for increment function is cleared. This implies that **the lifetime of a local variable is till the time the function is executing**.

The above described scenario is called Call By Value.

If we look from a different perspective called Call By Reference, The code would look like,


```
#include <stdio.h>
int increment( int *p)
{ *p= (*p)+1;
}
int main()
{
int a;
a=10;
increment(&a);
printf("%d", a); //Prints 11
}
```


While executing the value which is stored in the local variable p ( for function increment) is the address of memory location where a ( of function main) is stored, Hence the value of a is incremented using call By reference. 


# Concept of Array and Pointers:

When talking about an array, the concept of pointers is very crucial. 




![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/arraypointer.PNG)

Suppose the array named A is allocated memory as shown above. Since one integer takes 4 bytes the address of next integer will be 4 bytes more than the previous address.

int a= { 2 , 4 , 6 , 8 , 10 }

To print the address of initial element we can print &a[0] or we can also print the name of the array.  To print the initial value** *a** can be used and for every subsequent value ***(a + 1) **


```
#include <stdio.h>
int main()
{
    int a[]= {2,4,6,8,10};
    printf("Array is: { 2 , 4 , 6 , 8 , 10 } \n"); 
    printf("First Address Using printing &a[0]: %d \n",&a[0]);
    printf("First Address Using printing a :%d \n",a);
    printf("Value at First Address Using *&a[0] is : %d \n",*&a[0]);
    printf("Value at First Address Using *a is : %d \n",*a);
    printf("Value at First Address Using *(a+1) is : %d \n",*(a+1));
}
```



## Array as Function Arguments

Pointer have a role to play when array is passed as function argument.

e.g. To print the sum of an array, the code can be like


```
#include <stdio.h>
int calculateSum(int a[], int n){
    int i,sum;
    for(i=0;i<n;++i){
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[]= {2,4,6,8,10};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=calculateSum(a,n);
    printf("%d",sum);
}

```


This code calls calculateSum function from main and passes the array and size of array to it. It calculates the sum and outputs 30.

But if we wanted to calculate the size of array in the function calculateSum(), the code would look like,


```
#include <stdio.h>
int calculateSum(int a[]){
    int i,sum;
    int n=sizeof(a)/sizeof(a[0]);
    printf("%d \n",n);
    for(i=0;i<n;++i){
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[]= {2,4,6,8,10};
    int sum=calculateSum(a);
    printf("%d",sum);
}
```


But this outputs the incorrect sum

This is because whenever the array is passed as function argument, the compiler understands it as a pointer to the first element of the array. This is done to save memory because arrays can be really large and to create a local array and copy content would require large amount of memory in many cases. So the local memory created for the function calculateSum points to the array in main function using pointer.



# Pointers and Dynamic Memory

Memory assigned to a program is divided in 4 segments as mentioned earlier.


![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/newheapstack.PNG)

There 4 segments of memory are used to store various components of a program. The memory assigned for stack,static/global and code segments can’t be changed during run time.When we talk about stack, it is used for the local storage while the program is running. 

When a function is called, a stack frame is allocated for the function and the required memory is assigned. The most recent called function sits on top of the stack and after the function is done processing, the stack frame is cleared. 

_The memory for the stack is assigned by the operating system but the actual allocation of memory for each function (the local variables etc. for the function) happens during the runtime._ 

If the number of functions are too many or by any other reason the memory assigned to the stack if totally utilized, it is called **Stack Overflow.**

One of the common example of stack overflow is when the recursion goes infinitely. 

The allocation and deallocation of memory in the stack happens by a set rule, When a function is called it is pushed on the top of the stack and when it finishes execution it is popped out from the stack. The scope of variable does not change when the function is in stack.

**Example for Demonstration:**


```
#include <stdio.h>
int total;
int Square(int x)
{
return x*x;
}
int SquareOfSum(int x , int y)
{
int z = Square(x+y);
return z;
}
int main()
{
int a= 4, b= 8;
total=SquareOfSum(a,b);
printf("Output = %d" , total);
}
```




![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/stackinphases1.PNG)


![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/stackinphases2.png)

Most Recently Called Function Sits on Top of the stack and is also the one to be popped first.

**PHASE 1:** main() is called and the program begins.

**PHASE 2:** main() calls SumOfSquares()

**PHASE 3:** SumOfSquares() calls Square()

**PHASE 4:** Square returns value and memory for Square() is deallocated 

**PHASE 5:** Control is passed back to main

**PHASE 6:** Program finishes, main() is popped of stack and stack memory is empty


## Heap:

Unlike the stack and other segments, the memory for heap is not fixed. It’s size can change during the run time. Also, there is no set rule for memory allocation and deallocation ( like push and pop in stack).

 A programmer can decide the amount of memory to be used and the duration for which the memory has to be used. A heap can grow as long as the system does not run out of memory. 

**_Note: When talking about memory associated with heap or stack, it is always referred to the Random Access Memory._**

Heap is also called a free pool of memory. The actual implementation of heap is complex and varies from system to system, but the abstract view of heap can be seen as a free pool of memory.

Heap is also called dynamic memory. Using heap is also called dynamic memory allocation. 

**_NOTE: The term “Heap” is also used to denote a data structure but when talking about memory, it does not refer to the “Heap” as used in data structures. Although the data structure “Stack” is the same in memory as in data structures. The implementation of stack, the data structure is used in memory but in terms of heap in memory, it only refers to a free pool of memory._**


## Dynamic Memory Allocation In C:

Dynamic Memory allocation in C is carried out using 4 functions



1. malloc
2. calloc
3. realloc
4. free

Dynamic Memory Allocation in C++ is carried out using 2 operators



1. new
2. delete 

**_Note: Since C++ has backward compatibility, the functions of C can also be used in C++._**

**C Program for Dynamic Memory Allocation:**


```
#include <stdio.h>
#include <stdlib.h>
int main()
{
int a; //Since it is a local variable, it goes to stack
int *p;
p = (int*) malloc (sizeof(int));
/* Malloc returns a void pointer to the starting address of the memory block assigned. We have to typecast because it returns void pointer */ 
*p=10;
// free(p);
p= (int*) malloc(sizeof(int));
*p=20;
/* a new memory block to store 20 is assigned at some other address in heap and the previous is not cleared */
free(p);
p=(int*) malloc (20*sizeof(int));
```




![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/heapdemo1.PNG)

![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/heapdemo2.PNG)



**IMPORTANT POINTS:**



*   Memory in heap is not cleared when the pointer is changed, it needs to be cleared every time when the the value/variable stored is not required
*   The malloc(size) function returns a void pointer to the address of memory in heap so the void pointer has to be converted to integer pointer for storing integer values.
*   To allocate memory for array in heap, the malloc function needs to be given the size of array:
    *   For integer: 4 * Number of Elements
    *   For Character Array: 1 * Number of Elements
*   Assigning/Changing values in heap is only done using referencing i.e. obtaining a pointer to the address of heap and then assigning the value using aistrick. ( *p =10 )



## Dynamic Memory Allocation in C++

In C++ the two operators used are New and Delete. They are used similar to malloc and free functions in C. The difference is they are typesafe which means that the typecasting in not required. 

**Syntax:**


```
int *p;
p = new int;
*p = 10;
p= new int[20];
delete[] p;
```



## Malloc,Calloc, Realloc and Free in C


### Malloc:

**	**Malloc is most frequently used function for dynamic memory allocation. 

**Definition: `void* malloc( size_t size)`**



*   It returns a void pointer which has to be typecasted
*   size_t means only positive number can be entered (unsigned)
*   Assignment can only be done using dereferencing (Using pointers)

**Syntax:  `int *p=(int*) malloc(sizeof(int));`**


### Calloc:

Calloc is similar to malloc but takes in two parameters. The first argument is the number of elements of particular data type and second argument is the size of the data type.

**Syntax:**


```
int *p = (int*) calloc(1,sizeof(int));
```


Another difference between malloc and calloc is that, **malloc** initializes the assigned memory location with some garbage values while **calloc** does not initialize the values. 


### Calloc:

If we already have a dynamic block of memory and we need to change the size of the memory, then realloc is used.

**Syntax:**


```
int *p = (int*) realloc(void *ptr, size_t size);
```


*ptr= Address of initial block. 


## EXAMPLES:


```
#include <stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int *arr=(int*) malloc(n*sizeof(int));
  arr[0]=1;
  printf("%d",arr[0]);
}
```



```
#include <stdio.h>

int main()
{
  int *p;
  p=(int*)malloc(sizeof(int));
  *p=10;
  printf("%d",*p);
}
```


