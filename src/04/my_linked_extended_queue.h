#ifndef __MY_LINKED_EXTENDED_QUEUE_H__
#define __MY_LINKED_EXTENDED_QUEUE_H__

#include "my_linked_queue.h"

class Extended_queue: public Queue {
public:
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
};

bool Extended_queue::full() const
{
  return false;
}

int Extended_queue::size() const
{
   Node<Queue_entry> *window = front;
   int count = 0;
   while (window != NULL) {
      window = window->next;
      count++;
   }
   return count;
}

void Extended_queue::clear()
{
  while (!empty())
  serve();
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item)
{
  if (front == NULL) return underflow;
  Node<Queue_entry> *old_front = front;
  item = old_front->entry;
  front = old_front->next;
  if (front == NULL) rear = NULL;
  delete old_front;
  return success;
}

#endif /*__MY_LINKED_EXTENDED_QUEUE_H__*/