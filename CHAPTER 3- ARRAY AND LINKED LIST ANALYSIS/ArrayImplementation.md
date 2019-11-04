# Array Implementation 
## In C
~~~C
int A[100] //To create an integer array of size 100
int *A =(int*) malloc (100*sizeof(int));
//To create integer array of size 100 using malloc.
~~~
## In C++
Since C++ supports backward compatibilty and since it was developed over C so the concepts associated with C stand true(Mostly) in C++ as well. Same goes for arrays. Arrays in C++ can also be created as in C. But in C++ there is a robust way of dealing with elements of same types called a Vector. 
A vector can be seen as a powerful implementation over Array. 

#### Vector Declaration:
~~~cpp
vector<int> A;
vector<int> A(100); //size 100
~~~
#### Accessing Elements:
~~~Cpp 
V[i] // i refers to the index
~~~
#### Size:
~~~Cpp 
V.size();
~~~
#### Addition on next Index:
~~~Cpp 
V.push_back(1) // Assuming V is integer Vector
~~~
#### Deletion From Last Index:
~~~Cpp 
V.pop_back() // Deletes last element from Vector
~~~
## Java
In Java, there are many ways to use Arrays. One of the best way is to Use ArrayList which relates to the Collections in Java. 

#### Syntax:
~~~java
ArrayList<Integer> A = new ArrayList<Integer>(); // declares an empty integer array. O(1)
    ArrayList<Integer> A = new ArrayList<Integer>(B); // creates a copy of list B.  O(size of B)
~~~

## Python
Lists in python are majorly used as storeplaces of elements. 

#### Syntax:
~~~python
A=[]
A[i] //i is the index
A.append(value) //To add new Element
len(A) //Getting size of list.
~~~

 
