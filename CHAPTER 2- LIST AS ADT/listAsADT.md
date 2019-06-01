

# CHAPTER 2: LIST AS AN ABSTRACT DATA TYPE

In general, a collection of objects which are of the same type form a list. A list can be a group of words, a group of car names or anything that follows the above-mentioned definition.

Now that we are aware of what an abstract data type is, Let define list as an abstract data type.

An abstract data type will only define the data to be stored and the associated operations for handling the data. 

In view of a list which contains a similar group of objects so the abstract view of it can be summarized as:



*   It contains a fixed number of elements of the same datatype
*   It allows accessing the element present at any location.
*   Write/Modify any element at any position

The abstract view is not limited to only these points. However, if we think of the concrete implementation for such an abstract data type, a familiar name that strikes is an **Array.**


## Array:

An array stores the items in contiguous memory locations. It can be seen as a concrete implementation of the abstract data type list. The contiguously allocated memory makes it easy to access the elements using the base address and indices. 

Based on the implementation, arrays can be categorized as static or dynamic. Static arrays have fixed memory already assigned at the time of definition. Dynamic arrays are capable to change the size as per the run time requirements.

_Note: In case of the dynamic array, whenever the maximum size of the array is reached, a new array with a larger size is created and the content of the previous array is copied to that array. (Because it is not possible to extend the size of the already created array)_

_The memory for the previous array is made free. Since the operation to copy content from one array to another is costly in terms of time, every time the array is full, a new array of double the capacity of previous is created._



![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/arrayDEMO.PNG)

Every element in an array is uniquely identified by the index. 


## Array Programs:

**PROGRAM 1: **Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. 


```
#include <iostream>
using namespace std;
void leftRotateByOne(int arr[],int n);
void leftRotate(int arr[],int k,int n);
void
leftRotate (int arr[], int k, int n)
{
  for (int i = 0; i < k; ++i)
    {
      leftRotateByOne (arr, n);
    }
}

void
leftRotateByOne (int arr[], int n)
{
  int temp = arr[0];
  int i;
  for (i = 0; i < n - 1; ++i)
    {
      arr[i] = arr[i + 1];

    }
  arr[i] = temp;
}

int
main ()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
  int n = sizeof (arr) / sizeof (arr[0]);
  leftRotate (arr, 2, n);
  for (int i = 0; i < n; ++i)
    {
      cout << arr[i];
      
    }
}
```


**Program:** Array Reversal


```
#include <iostream>
using namespace std;

int main(){
    int arr[]={ 1,2,3,4,5,6 }; //Input Array which has to be reversed.
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
   
        start++;
        end--;
    }
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
        cout<<arr[i];
    
}}
```


**Program:** Array Rearrangement such that if found element i should be at ith position.


```
#include <stdio.h>
using namespace std;

int main(){
    int arr[]={ 1,2,3,4,5,6 }; //Input Array which has to be reversed.
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;++i){
        if(arr[i]>=0 && arr[i] !=i){
            arr[arr[i]]=(arr[arr[i]]+arr[i])-(arr[i]=arr[arr[i]]);
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;++i){
        cout<<arr[i];
    }
}
```


## Limitations of Array:

Let us assume a fixed section of computer memory. 

![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/memory1.PNG)

Suppose each segment in the memory is of 1 byte. 

Now,

If a programmer types **int x;** in the program, the equivalent memory (4 Bytes) is allocated in the memory. Similar Happens with the array.

When an array is declared

**int arr[5];**

This means that 5 integer type elements are to be stored in the array. So, the space that would be required in memory would be 5 * 4 = 20 Bytes. Now, when it comes to memory allocation, **arrays require contiguous memory. **This requires that 20 bytes of memory (20 segments) should be continuously free in memory area else the array can’t be allocated memory.

This is one of the biggest limitations of the array.

**CONTIGUOUS MEMORY ALLOCATION AND ARRAY:**

The answer to why array requires contiguous memory is, array uses a base addressing for indexing the elements. Since the base address is increment sequentially to retrieve subsequent elements, the addresses in memory need to be contiguous too.

**NOTE:**

**_Dynamic Array Memory Allocation:_**_As it was mentioned earlier that dynamic array is capable to adjust its size, but the memory management somehow does not support the extension of array size if there is no contiguous memory available. To solve this a new array with the double size is created wherever the contiguous memory is found. If not found, the dynamic array can’t be created. _ 


## INTRODUCTION TO LINKED LIST

Starting off from the problem of memory management in case of arrays, it can be a solution that memory is sought for one individual element of the list, rather than the list (array) as a whole. 

In the linked list, the request to memory is made of one element at a time.

Again, if the previous example is considered. When 4 elements of integer types are to be stored, then instead of asking memory for the entire collection to be stored at one place, memory can be asked for separate units of data each linked to each other via some means. This means the need for contiguous memory has been overcome. 

  

 
![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/memory2.PNG)

Suppose there are two elements to be stored {4,5}. For each element, a new request for memory allocation is taken and memory is allocated for each element ( Not the entire list as a whole). It is also not required that the elements 4 and 5 be stored contiguously in the memory area. 

But somehow these two elements need to be linked to each other so that the list can be accessed continuously. For this purpose, pointers are used.

Technically, each entry in a linked list is called a node. A node is much more than the raw data to be inserted. A node contains the data and the link to traverse to the previous and next node.

So the node can be represented using the structure as:


```
struct node {
int data;
node* next;
}
```


![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/memory3.PNG)

In the above-mentioned code example, the second component of the structure is marked as **node*** which marks that the second field of the node will only store an address. 

In the linked list, the first node is also called the** head** node. The address field of the last node of the linked list points to null, which marks the end of the list. 

 The only information we need to have is the address of the head node. Once we have the address of the head node, we can traverse the entire list. Although it is advantageous in terms of memory, the drawback of using linked list is that no element of the list is directly accessible which means for accessing the 4th element, one would need to first access 1st, 2nd,and 3rd elements compulsorily. 

The time taken to access elements has O(n) complexity. (because each element has to be traversed and in the worst case the element to be searched will be the last element of this list.

