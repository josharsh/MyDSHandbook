# Concept Of Pointers in C/C++

Pointers are the variable which hold the address of other variables. Pointers are used to carry references to other variables. Pointer Variables are strongly typed. A pointer variable of a particular data type is need to store the address of corresponding variable. For an integer type variable the pointer has to be integer, this extends to the fact that a char value can only be pointed by a character pointer and also goes similar for other data types. 

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

