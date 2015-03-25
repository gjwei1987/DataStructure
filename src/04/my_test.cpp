#include <iostream>
#include "my_linked_stack.h"
#include "my_linked_extended_queue.h"

using namespace std;

//typedef int Stack_entry;

int main()
{
  Stack* stack = new Stack();
  Extended_queue* queue = new Extended_queue();
  queue->append(1);
  stack->push(1);
  cout << stack->empty() << endl;
  cout << "hello world" << endl;
  return 0;
}