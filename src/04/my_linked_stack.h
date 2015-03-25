#ifndef __MY_LINKED_STACK_H__
#define __MY_LINKED_STACK_H__

#include "my_node.h"
#include "my_polynomial.h"

typedef Polynomial Stack_entry;

class Stack {
public:
//  Standard Stack methods
   Stack();
   bool empty() const;
   Error_code push(const Stack_entry &item);
   Error_code pop();
   Error_code top(Stack_entry &item) const;
//  Safety features for linked structures
   ~Stack();
   Stack(const Stack &original);
   void operator=(const Stack &original);
protected:
   Node<Stack_entry> *top_node;
};

Stack::Stack()
{
  top_node = NULL;
}

Stack::Stack(const Stack &original) //  copy constructor
{
   Node<Stack_entry> *new_copy, *original_node = original.top_node;
   if (original_node == NULL) top_node = NULL;
   else {                         //  Duplicate the linked nodes.
      top_node = new_copy = new Node<Stack_entry>(original_node->entry);
      while (original_node->next != NULL) {
         original_node = original_node->next;
         new_copy->next = new Node<Stack_entry>(original_node->entry);
         new_copy = new_copy->next;
      }
   }
}

bool Stack::empty() const
{
  bool outcome = false;
  if (top_node == NULL) outcome = true;
  return outcome;
}

Error_code Stack::push(const Stack_entry &item)
{
   Node<Stack_entry> *new_top = new Node<Stack_entry>(item, top_node);
   if (new_top == NULL) return overflow;
   top_node = new_top;
   return success;
}


Error_code Stack::pop()
{
   Node<Stack_entry> *old_top = top_node;
   if (top_node == NULL) return underflow;
   top_node = old_top->next;
   delete old_top;
   return success;
}

Error_code Stack::top(Stack_entry &item) const
{
  if(top_node == NULL ) return underflow;
  item = top_node->entry;
  return success;
}

Stack::~Stack() //  Destructor
{
   while (!empty())
      pop();
}

void Stack::operator= (const Stack &original) //  Overload assignment
{
   Node<Stack_entry> *new_top, *new_copy, *original_node = original.top_node;
   if (original_node == NULL) new_top = NULL;
   else {                         //  Duplicate the linked nodes
      new_copy = new_top = new Node<Stack_entry>(original_node->entry);
      while (original_node->next != NULL) {
         original_node = original_node->next;
         new_copy->next = new Node<Stack_entry>(original_node->entry);
         new_copy = new_copy->next;
      }
   }
   while (!empty())               //  Clean out old Stack entries
      pop();
   top_node = new_top;            //  and replace them with new entries.
}




#endif /*__MY_LINKED_STACK_H__*/