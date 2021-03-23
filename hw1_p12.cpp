/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 12
    C++ program that demonstrates insertion and deletion in the correct
    position of a doubly linked list
*/
#include <iostream>
#include <list>
using namespace std;
  
// A doubly linked list node
struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

// This function prints contents of linked list starting from the given node
void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }

/* Given a node as prev_node, insert a new node after the given node */
void insert_After(struct Node* prev_node, int new_data)
{
   //check if prev node is null
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
}
   //allocate memory for new node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data = new_data;
  
   //set next of newnode to next of prev node
   newNode->next = prev_node->next;
  
   //set next of prev node to newnode
   prev_node->next = newNode;
  
   //now set prev of newnode to prev node
   newNode->prev = prev_node;
  
   //set prev of new node's next to newnode
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}

int main ()
{
    struct Node* head = NULL;
    insert_After (head -> next, 30);

    cout<<"The list is as follows: "<<endl;
    displayList(head);
    return 0;
}