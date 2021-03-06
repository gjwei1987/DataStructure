#include <iostream>
#include "my_linked_stack.h"
#include "my_linked_extended_queue.h"
#include "my_polynomial.h"

using namespace std;

bool do_command(char command, Stack &stored_polynomials)
{
   Polynomial p, q, r;
   switch (command) {
   case '?':
      p.read();
      if (stored_polynomials.push(p) == overflow)
         cout << "Warning: Stack full, lost polynomial" << endl;
      break;

   case '=':
      if (stored_polynomials.empty())
         cout << "Stack empty" << endl;
      else {
         stored_polynomials.top(p);
         p.print();
      }
      break;

   case '+':
      if (stored_polynomials.empty())
         cout << "Stack empty" << endl;
      else {
         stored_polynomials.top(p);
         stored_polynomials.pop();
         if (stored_polynomials.empty()) {
            cout << "Stack has just one polynomial" << endl;
            stored_polynomials.push(p);
         }

         else {
            stored_polynomials.top(q);
            stored_polynomials.pop();
            r.equals_sum(q, p);
            if (stored_polynomials.push(r) == overflow)
               cout << "Warning: Stack full, lost polynomial" << endl;
         }
      }
      break;

   //   Add options for further user commands.
    case 'q':
      cout << "Calculation finished." << endl;
      return false;
   }
   return true;
}

char get_command()
{
   char command;
   bool waiting = true;
   cout << "Select command and press <Enter>:";

   while (waiting) {
      cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' ) waiting = false;


      else {
         cout << "Please enter a valid command:"   << endl
              << "[?]push to stack   [=]print top" << endl
              << "[+] [-] [*] [/]   are arithmetic operations" << endl
              << "[Q]uit." << endl;
      }
   }
   return command;
}

int main()
{
   Stack stored_polynomials;
   
   while(do_command(get_command(), stored_polynomials));
}

