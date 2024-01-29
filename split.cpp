/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  
  //create a temp pointer so we can null the original input
  Node* temp = in;
  in = nullptr;

  //if we have reached the end, set evens and odds to point to null
  //instead of a wrong pointer
  if (temp == nullptr) {
    evens = nullptr;
    odds = nullptr;
    return;
  }

  //if temp's value is even  
  if (temp->value % 2 == 0) {
    evens = temp;
    split(temp->next, odds, evens->next);
  }

  //if temp's value is not even
  else {
    odds = temp;
    split(temp->next, odds->next, evens);
  }

}

/* If you needed a helper function, write it here */
