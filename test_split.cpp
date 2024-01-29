/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <map>

Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;
	
	if(!content.empty())
	{
		// create head
		head = new Node(content[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(content.cbegin());
		++nextValIter;

		for(; nextValIter != content.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}
	}

	return head;

}

void deleteList(Node * list)
{
	Node * currElement = list;

	while(currElement != nullptr)
	{
    std::cout << currElement->value << std::endl;
		Node * nextElement = currElement->next;

		delete currElement;

		currElement = nextElement;
	}
}

int main(int argc, char* argv[])
{
  Node* list = makeList({5, 6, 7, 9, 10, 72, 256, 256, 1111, 1111, 1111, 9009});
  Node* odds = nullptr;
	Node* evens = nullptr;

  split(list, odds, evens);

  std::cout << "odds" << std::endl;
  deleteList(odds);
  std::cout << "evens" << std::endl;
	deleteList(evens);
  
}
