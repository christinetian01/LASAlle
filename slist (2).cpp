

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
    LinkedList(){
      head = NULL;
      previousNode = NULL;
      elements=0;
    }

     // Destructor
    ~LinkedList(){
      cout << "Class desctructed" << endl;
    }

    // add(value)				//Adds a new value to the end of this list.
    void add(Node * newNode){
      //Node* newNode = new Node();
      //newNode->data = newNode->data;
      //newNode-> next = NULL;
      if (head==NULL){
        head=newNode;
        previousNode=newNode;
      }
      else{
        previousNode -> next = newNode;
        previousNode = newNode;
      }
      elements++;
    }

    // clear()					//Removes all elements from this list.
    void clear(){
      Node * address = head;
      while((head->next)!=0){
        head -> next = address->next;
        delete address;
      }
    }

    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(LinkedList list){
      Node * thisAddress = head->next;
      bool equal=true;
      for (int i=0;i<elements;i++){
        if (list.get(0)!=thisAddress){
          equal=false;
          break;
        }
        thisAddress = thisAddress->next;
      }
      return equal;
    }

    //get(index)				//Returns the element at the specified index in this list.
    Node * get(int index){
      Node * thisAddress = head;
      int i=0;
      while (thisAddress!=NULL){
        if (i==index){
          return thisAddress;
        }
        thisAddress = thisAddress ->next;
        i++;
      }
      /*while (i!=index){
        thisAddress = thisAddress->next;
        i++;
      }*/
      return thisAddress;
    }

    //insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index, Node * value){
      int * currentIndex=0;
      Node * current = head->next;
      for (int i=0;i<index-1;i++){
        current = current->next;
      }
      
      Node * oldNext = current;
      current->next = value;
      value->next = oldNext;
    }

    //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int index1, int index2){
      Node * payload1= get(index1);
      Node * payload2 = get(index2);

      Node * tempData = payload1->data;
      payload1->data = (payload2->data);
      payload2->data = tempData; 
    }

    //swap(index1,index2)		//Swaps node located at index1 with node at index2
    void swap(int index1, int index2){
      Node * node1= get(index1);
      Node * node2 = get(index2);

      Node * tempData = node1->data;
      Node * tempAddress = node1->next;
      node1->next = node2->next;
      node1->data = (node2->data);
      node2->data = tempData; 
      node2->next = tempAddress;
    }

    // size()					//Returns the number of elements in this list.
    int size(){
      return elements;
    }

    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty(){
      return (head->next==0);
    }

    // remove(index)			//Removes the element at the specified index from this list.
    void remove(int index){
      Node * lastNode = get(index-1);
      Node * removedNode = get(index);
      Node * nextNode = removedNode->next;

      lastNode->next = nextNode;
    }

    // set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int index, Node * value){
      Node * nodeValue = get(index);
      nodeValue -> data = value;
    }

    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    LinkedList * subList(int start, int length){
      LinkedList * newList = new LinkedList();
      for (int i=start;i<=(start+length);i++){
        newList->add(get(i));
      }

      return newList;
    }

};
