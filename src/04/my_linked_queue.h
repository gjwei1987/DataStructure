#ifndef __MY_LINKED_QUEUE_H__
#define __MY_LINKED_QUEUE_H__

#include "my_node.h"
#include "my_term.h"

typedef Term Queue_entry;

class Queue {
public:
//  standard Queue methods
   Queue();
   bool empty() const;
   Error_code append(const Queue_entry &item);
   Error_code serve();
   Error_code retrieve(Queue_entry &item) const;
//  safety features for linked structures
   ~Queue();
   Queue(const Queue &original);
   void operator =(const Queue &original);
protected:
   Node<Queue_entry> *front, *rear;
};


Queue::Queue()
{
  front = rear = NULL;
}

bool Queue::empty() const
{
  bool outcome = false;
  if(front == NULL) outcome = true;
  return outcome;
}

Error_code Queue::append(const Queue_entry &item)
{
  Node<Queue_entry> *new_rear = new Node<Queue_entry>(item);
  if (new_rear == NULL) return overflow;
  if (rear == NULL) front = rear = new_rear;
  else {
    rear->next = new_rear;
    rear = new_rear;
  }
  return success;
}


Error_code Queue::serve()
{
  if (front == NULL) return underflow;
  Node<Queue_entry> *old_front = front;
  front = old_front->next;
  if (front == NULL) rear = NULL;
  delete old_front;
  return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
{
  if (front == NULL) return underflow;
  item = front->entry;
  return success;
}

Queue::~Queue( )
{
  while (!empty())
    serve( );
}

Queue::Queue(const Queue &copy)
{
  Node<Queue_entry> *copy_node = copy.front;
  front = rear = NULL;
  while (copy_node != NULL) {
    append(copy_node->entry);
    copy_node = copy_node->next;
  }
}

void Queue::operator= (const Queue &copy)
{
  while (!empty())
  serve();
  Node<Queue_entry> *copy_node = copy.front;
  while (copy_node != NULL) {
    append(copy_node->entry);
    copy_node = copy_node->next;
  }
}

#endif /*__MY_lINKED_QUEUE_H__*/