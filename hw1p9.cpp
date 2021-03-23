/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 9
    C++ program that contains a function for a linked list that sorts the list 
    so that first all odd numbers are listed and then all even numbers.
*/

#include <iostream>
#include <list>

using namespace std;

// linked list node
class Node
{
    public: 
    int data;
    Node* next;
};

// function to create new node
Node* newNode (int key)
{
    Node *temp = new Node;
    temp -> data = key;
    temp -> next = NULL;
    return temp;
}

// function that lists odd numbers first and then even numbers
void sortList (Node * head)
{
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    Node *current = head -> next;
    Node *previous = head;

    while(current != NULL)
    {
        if(current->data % 2 == 0)
        {
            previous->next = current->next;
            current->next = head;
            head = current;
        } else
        {
            previous = previous->next;
        }
        current = previous->next;
    }
}

void printList (Node* node)
{
    while (node != NULL)
    {
        cout << node->data <<",";
        node = node->next;
    }
    cout << "NULL" <<endl;
}

int main() 
{ 
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
  
    cout << "Given Linked List\n"; 
    printList(head); 
  
    sortList(head); 
  
    cout << "\nModified Linked List\n"; 
    printList(head); 
  
    return 0; 
} 
