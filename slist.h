#include "slist.h"

#include <iostream>
#include <sstream>
using namespace std;

/*
Class Library File
*/

class Node{
  public:
    Node * data;
    Node * next;
};

class LinkedList{
  public:
    Node * head;
    Node * previousNode;
    int elements;

  public: 
    // Constructor
    LinkedList()

     // Destructor
    ~LinkedList()

    // add(value)				//Adds a new value to the end of this list.
    void add(Node * newNode)

    // clear()					//Removes all elements from this list.
    void clear()

    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(LinkedList list)

    //get(index)				//Returns the element at the specified index in this list.
    Node * get(int index)

    //insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index, Node * value)

    //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int index1, int index2)

    //swap(index1,index2)		//Swaps node located at index1 with node at index2
    void swap(int index1, int index2)

    // size()					//Returns the number of elements in this list.
    int size()

    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty()

    // remove(index)			//Removes the element at the specified index from this list.
    void remove(int index)

    // set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int index, Node * value)

    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    LinkedList * subList(int start, int length)

    // toString()				//Converts the list to a printable string representation.
   string toString()
};
