# Character Array and Pointers
In C, Strings are represented using character arrays. 

### How are strings stored?
Size of character array should be = length of string +1 
The extra space of 1 is required to indicate that the string is over. A null character is put on the end of string. So the rule in C is, the strings are null terminated.
~~~C
#include<stdio.h>
#include<string.h> 
int main()
{
char C[20];
c[0]= ‘H’;
c[1]= ‘A’;
c[2]= ‘R’;
c[3]= ‘S’;
c[4]= ‘H’;
printf(“%s”,C); //Prints something else after “HARSH” because string is not null terminated.
c[5]= ‘\0’;
printf(“%s”,C); //Correctly Prints
int len=strlen(C); //It also counts till null character i.e. len=5
~~~
}

But while giving string literal the null termination is implicit. i.e. c[20]= “Harsh”, does not require explicit null termination because it is implicitly done.
