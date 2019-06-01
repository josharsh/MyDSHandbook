# CHAPTER 3: ARRAY & LINKED LIST ANALYSIS

Before starting this chapter, it should be clear that it is not suited to say one data structure is better than other. The usage of every data structure comes along different applications of it.

E.g if there’s a requirement to quickly access elements and memory is sufficient, an array can be used but if memory has to managed efficiently and access time is not given priority, Linked List is a good option to use.

 The differences between the data structures can be measured as functions or in terms of **cost**, **speed**, etc. Some of these parameters are:


## Accessing Elements : 

**Array:** Since an array is a contiguous block of memory, it takes constant time to access elements in the array. It as also mentioned earlier that the array utilizes base addressing to access the elements. 

Time Complexity: O(1)

**Linked List: **There are independent nodes stored in discontinuous memory locations. Initially, the address of the head node is given and to access the elements in a list we need to traverse sequentially. So it takes linear time.

Time Complexity: O(n)


## Memory Usage : 

**Array:** To declare an array we need to know the memory needed before inserting values in it because contiguous memory is required for the array. To achieve the flexibility of insertion, we initially assign a large block of memory to the array is utilize only some part for initially storing the values. So there is a heavy chance of memory wastage in the array.

**Linked List: **Since the linked list does not need to be contiguously allocated and each node is inserted in memory at the time it is created, there is no memory wastage involved in the linked list. Although in a linked list, extra memory is used for pointer variables.

NOTE: Memory usage differs from memory management. When it comes to usage, a linked list also uses the amount of memory which is used by array because of pointer overhead.

Here’s an example:



<p id="gdcalert1" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline drawings not supported directly from Docs. You may want to copy the inline drawing to a standalone drawing and export by reference. See <a href="https://github.com/evbacher/gd2md-html/wiki/Google-Drawings-by-reference">Google Drawings by reference</a> for details. The img URL below is a placeholder. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert2">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![drawing](https://github.com/josharsh/MyDSHandbook/blob/master/PresentationResources/arrayvsLinked.PNG)

But this case would differ and the linked list would be useful is the data part is very large and the pointer is small.