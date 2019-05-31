

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



![drawing](//PresentationResources/listADT.png)

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



<!-- Docs to Markdown version 1.0β17 -->
