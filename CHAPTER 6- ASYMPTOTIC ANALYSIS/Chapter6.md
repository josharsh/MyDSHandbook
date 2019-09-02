# Chapter 6:  Asymptotic Analysis


## Time Complexity of a Program:

A program to find the total number of prime numbers between a given range can be solved by two approaches. One is to iterate from **1** to **n-1** and check the satisfying numbers to be prime while the other is to iterate till **square root of n**, onto the same conditions. 

When we talk about time complexity of a program, we generally deal with large input sizes, because the factor of time does not simply imply to smaller input values. In the above given condition to find number of prime numbers till a number n.

 \
Let n= 10000;

Suppose each iteration takes 1 ms to complete. 

**Case 1:** Iterating till **n-1**: 

	Total number of iterations = 99999

	Total Time Taken = 99999*10^-3= 99.999= 1 minute 40 Seconds 

**Case2:** Iterating till **sqrt(n):**

	Total number of iterations: 315 (approx)

	Total Time Taken= 315 ms = 0.315 seconds

 The performance of both cases regarding the time taken to execute it very evident with the previous example. This is why Time Complexity plays a crucial role in programming solutions for problems requiring large inputs. 


## Basics Of Asymptotic Notations:

Time complexity of an algorithm can be determined and expressed mathematically using Asymptotic Notations. When we talk about Time complexity, we always refer to the associated algorithm and not the computer program. Complexity of an algorithm can be measured in space and in time. There are three ways to measure it namely best case, average case and the worst case.

There are different types of asymptotic notations widely used to mathematically represent time complexity. One of the most common one is the **big-O** notation. The big-O notation generally deals with the large inputs. It gives complexity in terms of **input size, N.** The big-O notation is used to test the worst case complexity. big-O is expressed as **O(complexity term).** 

**Big-O Basics:**



*   Constants are ignored i.e. O(5n) is same is O(n)
*   Order of complexity is:
    *   **O(1) < O(log n) < O(n) < O (nlogn) < O(n^2) < O(2^n) < O(n!)** 

**Side Note: [https://www.bigocheatsheet.com/](https://www.bigocheatsheet.com/)** is a great tool to learn more about big-O 

Suppose to solve a problem, two algorithms have been devised. Let the running time of algorithm A is a function **f(n)** and the running time of other algorithm is **g(n).** If **g(n)** grows faster than **f(n)** then there must be some values of **n** for which **g(n)** is larger than **f(n).**

**Explanation:** There is a function f(n) and another function g(n). The faster growth of functions means that for different values of the independent variable n, the function return larger values. The larger the return values, faster is the growth!   

Now, if g(n) grows faster than f(n) simply means that there must be one independent value of n, let’s say **n*** for which and for values larger than **n*** the value returned by **g(n)** will always be greater than **f(n).** 


### **i.e g(n*)>=f(n*)**

This can also be written as **f(n*)<= C.g(n)** where C is a constant. 


### Now, we can say that f(n) is contained in O(g(n)).
