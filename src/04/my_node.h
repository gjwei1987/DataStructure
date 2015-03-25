#ifndef __MY_NODE_H__
#define __MY_NODE_H__

#include "my_term.h"

//typedef int Node_entry;
enum Error_code{underflow, overflow, success};

template<class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node *next;
//  constructors
   Node();
   Node(Node_entry item, Node *add_on = NULL);
};

template<class Node_entry>
Node<Node_entry>::Node()
{
   next = NULL;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on)
{
   entry = item;
   next = add_on;
}

#endif /*__MY_NODE_H__*/