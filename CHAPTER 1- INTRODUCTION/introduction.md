
# DATA STRUCTURES


## CHAPTER 1: AN INTRODUCTION

One of the most fundamental concepts in programming and computer science is the concept of data structures.Data structures refer to the way of organizing data for efficient usage. The data stored on your hard drive, the data on the RAM, data on pen drives, CD ROMs and all other places you can think of, the key underlying concept is of data structures that powers these devices to work efficiently. 

_NOTE: Data structures not just describe the storage of data piled into a memory unit, rather describe the data management alongside storing the data._ 


#### **HOTS:** It is easier to search a word from a dictionary because the words in the dictionary have been organized for that purpose.  


### WHY SO MANY OF DATA STRUCTURES FOR A SIMPLE PURPOSE:

Different kind of data exists and a different set of organization techniques and tools are adhered to while storing data and hence there required is a need for different types of data structures.

e.g. A key-value pair data cannot be simply stored in a simple static array.

Other factors which govern the choice of data structures is memory management, system utilization, usage, etc.


### HOLD ON!! IT’S PERHAPS NOT WHAT YOU THOUGHT:

It was earlier mentioned that the data stored on devices like hard drives and pen drives is powered with the data structures. This statement has high chances of getting misinterpreted because data structures are not physical structures rather logical ones.

_“A physical data structure refers to the actual organization of data on a storage device. The logical data structure refers to how the information appears to a program or user. For example, a data file is a collection of information stored together. This is its logical structure”_

**DEFINITION: **A data structure is a format for data organization, management, and storage which enables efficient access and updating. 


### WAYS TO LOOK AT AN DATA STRUCTURE: 

Whatever is being talked about in this section does not specify the types of data structures rather it talks about the two perspectives data structures should be looked at with.



1. LOGICAL VIEW
2. IMPLEMENTATIONAL VIEW

Two eyes, Two perspectives! It’s one for each. Let’s dive into details:

** **

The logical view of data structures defines the associated operations that would be carried out. 

_So, this perspective of data structure does not do anything, it only defines stuff and hence is never used in the actual implementation but it is handy because it is the backbone of the actual implementation_. 

Wohaa! That was a long sentence to understand in one go.

In simpler words, logical view describes **WHAT** but not **HOW. **It is because of this reason that these data structures are called** Abstract Data Types. **

_“Abstract Data type (ADT) is a type (or class) for objects whose behavior is defined by a set of value and a set of operations.” - GeeksForGeeks_

Let’s break it down with an example: 

There is something called a Car. The attributes of a car (only to name a few) are:



*   It has four wheels.
*   It provides roof
*   It drives us to place we want to go

Okay! Now, do we actually in practice own something called the car in our daily lives. We actually own an extension of the car. We might own a Maruti Swift Desire or even a Honda Amaze. These are cars too but these are the ones actually used (Implementational View).

The attributes are (Honda Amaze):



*   Mileage: 23.8 kmpl 
*   Engine Displ. : 1498 cc
*   Transmission: Automatic 
*   Fuel Type: Diesel
*   Boot Space: 420

If you are familiar with the concepts of **Aggregation and Association **and** is-a relationship** you might be finding it easy. Otherwise, think of it as there are some generic data structures which only define the operations which the structure will carry out without talking about how will it do it. And then come the implemented data structures (concrete data structures) which extend the Abstract data types (generic data structures) to describe how will the operations actually implemented.

One of the example in terms of programming is: 

A list is an abstract data type which defines that there is some capacity for the elements to be stored in sequential order here and array extends it to define explicit properties and operations describing the extended properties.
